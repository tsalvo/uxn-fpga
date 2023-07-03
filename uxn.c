#include "uxn.h"

/*
Copyright (u) 2022-2023 Devine Lu Linvega, Andrew Alderwick, Andrew Richards

Permission to use, copy, modify, and distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE.
*/

#define T s->dat[s->ptr - 1]
#define N s->dat[s->ptr - 2]
#define L s->dat[s->ptr - 3]
#define H2 PEEK2(s->dat + s->ptr - 3)
#define T2 PEEK2(s->dat + s->ptr - 2)
#define N2 PEEK2(s->dat + s->ptr - 4)
#define L2 PEEK2(s->dat + s->ptr - 6)

/* Registers

[ . ][ . ][ . ][ L ][ N ][ T ] <
[ . ][ . ][ . ][   H2   ][ T ] <
[   L2   ][   N2   ][   T2   ] <

*/

#define HALT(c) { return uxn_halt(u, ins, (c), pc - 1); }
#define SET(mul, add) { if(mul > s->ptr) HALT(1) tmp = (mul & k) + add + s->ptr; if(tmp > 254) HALT(2) s->ptr = tmp; }
#define PUT(o, v) { s->dat[(Uint8)(s->ptr - 1 - (o))] = (v); }
#define PUT2(o, v) { tmp = (v); s->dat[(Uint8)(s->ptr - o - 2)] = tmp >> 8; s->dat[(Uint8)(s->ptr - o - 1)] = tmp; }
#define PUSH(x, v) { z = (x); if(z->ptr > 254) HALT(2) z->dat[z->ptr++] = (v); }
#define PUSH2(x, v) { z = (x); if(z->ptr > 253) HALT(2) tmp = (v); z->dat[z->ptr] = tmp >> 8; z->dat[z->ptr + 1] = tmp; z->ptr += 2; }
#define DEO(a, b) { u->dev[(a)] = (b); if((deo_mask[(a) >> 4] >> ((a) & 0xf)) & 0x1) uxn_deo(u, (a)); }
#define DEI(a, b) { PUT((a), ((dei_mask[(b) >> 4] >> ((b) & 0xf)) & 0x1) ? uxn_dei(u, (b)) : u->dev[(b)]) }

int
uxn_eval(Uxn *u, Uint16 pc)
{
	int t, n, l, k, tmp, opc, ins;
	Uint8 *ram = u->ram;
	Stack *s, *z;
	if(!pc || u->dev[0x0f]) return 0;
	for(;;) {
		ins = ram[pc++] & 0xff;
		k = ins & 0x80 ? 0xff : 0;
		s = ins & 0x40 ? &u->rst : &u->wst;
		opc = !(ins & 0x1f) ? (0 - (ins >> 5)) & 0xff : ins & 0x3f;
		switch(opc) {
			/* IMM */
			case 0x00: /* BRK   */ return 1;
			case 0xff: /* JCI   */ pc += !!s->dat[--s->ptr] * PEEK2(ram + pc) + 2; break;
			case 0xfe: /* JMI   */ pc += PEEK2(ram + pc) + 2; break;
			case 0xfd: /* JSI   */ PUSH2(&u->rst, pc + 2) pc += PEEK2(ram + pc) + 2; break;
			case 0xfc: /* LIT   */ PUSH(s, ram[pc++]) break;
			case 0xfb: /* LIT2  */ PUSH2(s, PEEK2(ram + pc)) pc += 2; break;
			case 0xfa: /* LITr  */ PUSH(s, ram[pc++]) break;
			case 0xf9: /* LIT2r */ PUSH2(s, PEEK2(ram + pc)) pc += 2; break;
			/* ALU */
			case 0x01: /* INC  */ t=T;            SET(1, 0) PUT(0, t + 1) break;
			case 0x21:            t=T2;           SET(2, 0) PUT2(0, t + 1) break;
			case 0x02: /* POP  */                 SET(1,-1) break;
			case 0x22:                            SET(2,-2) break;
			case 0x03: /* NIP  */ t=T;            SET(2,-1) PUT(0, t) break;
			case 0x23:            t=T2;           SET(4,-2) PUT2(0, t) break;
			case 0x04: /* SWP  */ t=T;n=N;        SET(2, 0) PUT(0, n) PUT(1, t) break;
			case 0x24:            t=T2;n=N2;      SET(4, 0) PUT2(0, n) PUT2(2, t) break;
			case 0x05: /* ROT  */ t=T;n=N;l=L;    SET(3, 0) PUT(0, l) PUT(1, t) PUT(2, n) break;
			case 0x25:            t=T2;n=N2;l=L2; SET(6, 0) PUT2(0, l) PUT2(2, t) PUT2(4, n) break;
			case 0x06: /* DUP  */ t=T;            SET(1, 1) PUT(0, t) PUT(1, t) break;
			case 0x26:            t=T2;           SET(2, 2) PUT2(0, t) PUT2(2, t) break;
			case 0x07: /* OVR  */ t=T;n=N;        SET(2, 1) PUT(0, n) PUT(1, t) PUT(2, n) break;
			case 0x27:            t=T2;n=N2;      SET(4, 2) PUT2(0, n) PUT2(2, t) PUT2(4, n) break;
			case 0x08: /* EQU  */ t=T;n=N;        SET(2,-1) PUT(0, n == t) break;
			case 0x28:            t=T2;n=N2;      SET(4,-3) PUT(0, n == t) break;
			case 0x09: /* NEQ  */ t=T;n=N;        SET(2,-1) PUT(0, n != t) break;
			case 0x29:            t=T2;n=N2;      SET(4,-3) PUT(0, n != t) break;
			case 0x0a: /* GTH  */ t=T;n=N;        SET(2,-1) PUT(0, n > t) break;
			case 0x2a:            t=T2;n=N2;      SET(4,-3) PUT(0, n > t) break;
			case 0x0b: /* LTH  */ t=T;n=N;        SET(2,-1) PUT(0, n < t) break;
			case 0x2b:            t=T2;n=N2;      SET(4,-3) PUT(0, n < t) break;
			case 0x0c: /* JMP  */ t=T;            SET(1,-1) pc += (Sint8)t; break;
			case 0x2c:            t=T2;           SET(2,-2) pc = t; break;
			case 0x0d: /* JCN  */ t=T;n=N;        SET(2,-2) pc += !!n * (Sint8)t; break;
			case 0x2d:            t=T2;n=L;       SET(3,-3) if(n) pc = t; break;
			case 0x0e: /* JSR  */ t=T;            SET(1,-1) PUSH2(&u->rst, pc) pc += (Sint8)t; break;
			case 0x2e:            t=T2;           SET(2,-2) PUSH2(&u->rst, pc) pc = t; break;
			case 0x0f: /* STH  */ t=T;            SET(1,-1) PUSH((ins & 0x40 ? &u->wst : &u->rst), t) break;
			case 0x2f:            t=T2;           SET(2,-2) PUSH2((ins & 0x40 ? &u->wst : &u->rst), t) break;
			case 0x10: /* LDZ  */ t=T;            SET(1, 0) PUT(0, ram[t]) break;
			case 0x30:            t=T;            SET(1, 1) PUT2(0, PEEK2(ram + t)) break;
			case 0x11: /* STZ  */ t=T;n=N;        SET(2,-2) ram[t] = n; break;
			case 0x31:            t=T;n=H2;       SET(3,-3) POKE2(ram + t, n) break;
			case 0x12: /* LDR  */ t=T;            SET(1, 0) PUT(0, ram[pc + (Sint8)t]) break;
			case 0x32:            t=T;            SET(1, 1) PUT2(0, PEEK2(ram + pc + (Sint8)t)) break;
			case 0x13: /* STR  */ t=T;n=N;        SET(2,-2) ram[pc + (Sint8)t] = n; break;
			case 0x33:            t=T;n=H2;       SET(3,-3) POKE2(ram + pc + (Sint8)t, n) break;
			case 0x14: /* LDA  */ t=T2;           SET(2,-1) PUT(0, ram[t]) break;
			case 0x34:            t=T2;           SET(2, 0) PUT2(0, PEEK2(ram + t)) break;
			case 0x15: /* STA  */ t=T2;n=L;       SET(3,-3) ram[t] = n; break;
			case 0x35:            t=T2;n=N2;      SET(4,-4) POKE2(ram + t, n) break;
			case 0x16: /* DEI  */ t=T;            SET(1, 0) DEI(0, t) break;
			case 0x36:            t=T;            SET(1, 1) DEI(1, t) DEI(0, t + 1) break;
			case 0x17: /* DEO  */ t=T;n=N;        SET(2,-2) DEO(t, n) break;
			case 0x37:            t=T;n=N;l=L;    SET(3,-3) DEO(t, l) DEO(t + 1, n) break;
			case 0x18: /* ADD  */ t=T;n=N;        SET(2,-1) PUT(0, n + t) break;
			case 0x38:            t=T2;n=N2;      SET(4,-2) PUT2(0, n + t) break;
			case 0x19: /* SUB  */ t=T;n=N;        SET(2,-1) PUT(0, n - t) break;
			case 0x39:            t=T2;n=N2;      SET(4,-2) PUT2(0, n - t) break;
			case 0x1a: /* MUL  */ t=T;n=N;        SET(2,-1) PUT(0, n * t) break;
			case 0x3a:            t=T2;n=N2;      SET(4,-2) PUT2(0, n * t) break;
			case 0x1b: /* DIV  */ t=T;n=N;        SET(2,-1) if(!t) HALT(3) PUT(0, n / t) break;
			case 0x3b:            t=T2;n=N2;      SET(4,-2) if(!t) HALT(3) PUT2(0, n / t) break;
			case 0x1c: /* AND  */ t=T;n=N;        SET(2,-1) PUT(0, n & t) break;
			case 0x3c:            t=T2;n=N2;      SET(4,-2) PUT2(0, n & t) break;
			case 0x1d: /* ORA  */ t=T;n=N;        SET(2,-1) PUT(0, n | t) break;
			case 0x3d:            t=T2;n=N2;      SET(4,-2) PUT2(0, n | t) break;
			case 0x1e: /* EOR  */ t=T;n=N;        SET(2,-1) PUT(0, n ^ t) break;
			case 0x3e:            t=T2;n=N2;      SET(4,-2) PUT2(0, n ^ t) break;
			case 0x1f: /* SFT  */ t=T;n=N;        SET(2,-1) PUT(0, n >> (t & 0xf) << (t >> 4)) break;
			case 0x3f:            t=T;n=H2;       SET(3,-1) PUT2(0, n >> (t & 0xf) << (t >> 4)) break;
		}
	}
}

int
uxn_boot(Uxn *u, Uint8 *ram)
{
	Uint32 i;
	char *cptr = (char *)u;
	for(i = 0; i < sizeof(*u); i++)
		cptr[i] = 0;
	u->ram = ram;
	return 1;
}
