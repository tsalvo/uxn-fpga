#pragma once
#include "uintN_t.h"  // uintN_t types for any N

/* CUBE3D (assembly)
	( Cube3d: Just a cube, y'know )
	
	|00 @System &vector $2 &wst $1 &rst $1 &eaddr $2 &ecode $1 &pad $1 &r $2 &g $2 &b $2 &debug $1 &halt $1
	|20 @Screen &vector $2 &width $2 &height $2 &auto $1 &pad $1 &x $2 &y $2 &addr $2 &pixel $1 &sprite $1
	
	|0000
	
		@timer $1
		@cube &v0 $8 &v4 $8
		@center &x $2 &y $2
	
	|0100
	
	@on-reset ( -> )
		( | theme )
		#4fcd .System/r DEO2
		#4fc3 .System/g DEO2
		#dfc2 .System/b DEO2
		( | center )
		.Screen/width DEI2 #01 SFT2 #0040 SUB2 .center/x STZ2
		.Screen/height DEI2 #01 SFT2 #0040 SUB2 .center/y STZ2
		( | begin. )
		;on-frame .Screen/vector DEO2
	
	@on-frame ( -> )
		( | clear )
		#0000 DUP2 .Screen/x DEO2
		.Screen/y DEO2
		#80 .Screen/pixel DEO
		( | draw )
		.timer LDZk INC SWP STZ
		<draw-cube>
		BRK
	
	@<draw-cube> ( frame -- )
		( | create box )
		#0800
		&loop ( -- )
			STHk #00 .timer LDZ #00 STHkr INC #07 AND #60 SFT ADD2 #00ff AND2 ;table ADD2 LDA #01 SFT #00 .timer LDZ #00 STHkr #60 SFT ADD2 #00ff AND2 ;table ADD2 LDA #02 SFT #00 STHkr #62 SFT2 ADD2 .cube/v0 STHr DUP ADD ADD STZ2
			INC GTHk ?&loop
		POP2
		( | vertices )
		#0800
		&ver-loop ( -- )
			DUP DUP ADD .cube ADD LDZ2 <draw-vertex>
			INC GTHk ?&ver-loop
		POP2
		( lines ) #0400
		&line-loop ( -- )
			STHk .cube/v0 STHkr DUP ADD ADD .cube/v0 STHkr INC #03 AND DUP ADD ADD <draw-edge>
			.cube/v0 STHkr DUP ADD ADD .cube/v4 STHkr DUP ADD ADD <draw-edge>
			.cube/v4 STHkr DUP ADD ADD .cube/v4 STHr INC #03 AND DUP ADD ADD <draw-edge>
			INC GTHk ?&line-loop
		POP2 JMP2r
	
	@<draw-edge> ( a b -- )
		STH STH
		( ) #00 STHkr LDZ .center/x LDZ2 ADD2
		( ) #00 STHr INC LDZ .center/y LDZ2 ADD2
		( ) #00 STHkr LDZ .center/x LDZ2 ADD2
		( ) #00 STHr INC LDZ .center/y LDZ2 ADD2 #05 <draw-line>
		JMP2r
	
	@<draw-vertex> ( x y -- )
		#00 SWP #0004 SUB2 .center/y LDZ2 ADD2 .Screen/y DEO2
		#00 SWP #0003 SUB2 .center/x LDZ2 ADD2 .Screen/x DEO2
		;&icn .Screen/addr DEO2
		#05 .Screen/sprite DEO
		JMP2r
		&icn [ 0000 387c 7c7c 3800 ]
	
	@<draw-line> ( x1* y1* x2* y2* color -- )
		,&color STR
		,&y STR2
		,&x STR2
		,&y2 STR2
		,&x2 STR2
		,&x LDR2 ,&x2 LDR2 SUB2 abs2 ,&dx STR2
		#0000 ,&y LDR2 ,&y2 LDR2 SUB2 abs2 SUB2 ,&dy STR2
		#ffff [ LIT2 00 _&x2 ] LDR2 ,&x LDR2 lts2 DUP2 ADD2 ADD2 ,&sx STR2
		#ffff [ LIT2 00 _&y2 ] LDR2 ,&y LDR2 lts2 DUP2 ADD2 ADD2 ,&sy STR2
		[ LIT2 &dx $2 ] [ LIT2 &dy $2 ] ADD2 STH2
		&while ( -- )
			[ LIT2 &x2 $2 ] DUP2 .Screen/x DEO2
			[ LIT2 &x $2 ] EQU2 [ LIT2 &y2 $2 ] DUP2 .Screen/y DEO2
			[ LIT2 &y $2 ] EQU2 [ LIT2 &color $1 -Screen/pixel ] DEO
			AND ?&end
			STH2kr DUP2 ADD2 DUP2 ,&dy LDR2 lts2 ?&skipy
			STH2r ,&dy LDR2 ADD2 STH2 ,&x2 LDR2 [ LIT2 &sx $2 ] ADD2 ,&x2 STR2
		&skipy ( -- )
			,&dx LDR2 gts2 ?&while
		STH2r ,&dx LDR2 ADD2 STH2 ,&y2 LDR2 [ LIT2 &sy $2 ] ADD2 ,&y2 STR2
		!&while
		&end POP2r JMP2r
	
	@abs2 ( a* -- f )
		DUP2 #0f SFT2 EQU ?{ #0000 SWP2 SUB2 }
		JMP2r
	
	@lts2 ( a* b* -- f )
		#8000 STH2k ADD2 SWP2 STH2r ADD2 GTH2 JMP2r
	
	@gts2 ( a* b* -- f )
		#8000 STH2k ADD2 SWP2 STH2r ADD2 LTH2 JMP2r
	
	@table ( 256 xy )
		[
		f7f8 f9fa fbfc fcfd fefe ffff ffff ffff
		ffff ffff fffe fefd fcfc fbfa f9f8 f7f6
		f5f3 f2f0 efed ecea e8e6 e4e2 e0de dcda
		d8d5 d3d1 cecc c9c7 c4c1 bfbc b9b6 b3b0
		aeab a8a5 a29f 9c98 9592 8f8c 8986 8380
		7c79 7673 706d 6a67 6360 5d5a 5754 514f
		4c49 4643 403e 3b38 3633 312e 2c2a 2725
		2321 1f1d 1b19 1715 1312 100f 0d0c 0a09
		0807 0605 0403 0302 0101 0000 0000 0000
		0000 0000 0001 0102 0303 0405 0607 0809
		0a0c 0d0f 1012 1315 1719 1b1d 1f21 2325
		272a 2c2e 3133 3638 3b3e 4043 4649 4c4f
		5154 575a 5d60 6367 6a6d 7073 7679 7c7f
		8386 898c 8f92 9598 9c9f a2a5 a8ab aeb0
		b3b6 b9bc bfc1 c4c7 c9cc ced1 d3d5 d8da
		dcde e0e2 e4e6 e8ea eced eff0 f2f3 f5f6 ]
*/

#define ROM_SIZE 1024

uint8_t read_rom_byte(uint16_t read_address)
{
	static uint8_t uxn_rom[ROM_SIZE] = {
		0xA0, 0x4F, 0xCD, 0x80, 0x08, 0x37, 0xA0, 0x4F,
		0xC3, 0x80, 0x0A, 0x37, 0xA0, 0xDF, 0xC2, 0x80,
		0x0C, 0x37, 0x80, 0x22, 0x36, 0x80, 0x01, 0x3F,
		0xA0, 0x00, 0x40, 0x39, 0x80, 0x11, 0x31, 0x80,
		0x24, 0x36, 0x80, 0x01, 0x3F, 0xA0, 0x00, 0x40,
		0x39, 0x80, 0x13, 0x31, 0xA0, 0x01, 0x32, 0x80,
		0x20, 0x37, 0xA0, 0x00, 0x00, 0x26, 0x80, 0x28,
		0x37, 0x80, 0x2A, 0x37, 0x80, 0x80, 0x80, 0x2E,
		0x17, 0x80, 0x00, 0x90, 0x01, 0x04, 0x11, 0x60,
		0x00, 0x01, 0x00, 0xA0, 0x08, 0x00, 0x8F, 0x80,
		0x00, 0x80, 0x00, 0x10, 0x80, 0x00, 0xCF, 0x01,
		0x80, 0x07, 0x1C, 0x80, 0x60, 0x1F, 0x38, 0xA0,
		0x00, 0xFF, 0x3C, 0xA0, 0x03, 0x1A, 0x38, 0x14,
		0x80, 0x01, 0x1F, 0x80, 0x00, 0x80, 0x00, 0x10,
		0x80, 0x00, 0xCF, 0x80, 0x60, 0x1F, 0x38, 0xA0,
		0x00, 0xFF, 0x3C, 0xA0, 0x03, 0x1A, 0x38, 0x14,
		0x80, 0x02, 0x1F, 0x80, 0x00, 0xCF, 0x80, 0x62,
		0x3F, 0x38, 0x80, 0x01, 0x4F, 0x06, 0x18, 0x18,
		0x31, 0x01, 0x8A, 0x20, 0xFF, 0xB8, 0x22, 0xA0,
		0x08, 0x00, 0x06, 0x06, 0x18, 0x80, 0x01, 0x18,
		0x30, 0x60, 0x00, 0x70, 0x01, 0x8A, 0x20, 0xFF,
		0xF1, 0x22, 0xA0, 0x04, 0x00, 0x8F, 0x80, 0x01,
		0xCF, 0x06, 0x18, 0x18, 0x80, 0x01, 0xCF, 0x01,
		0x80, 0x03, 0x1C, 0x06, 0x18, 0x18, 0x60, 0x00,
		0x29, 0x80, 0x01, 0xCF, 0x06, 0x18, 0x18, 0x80,
		0x09, 0xCF, 0x06, 0x18, 0x18, 0x60, 0x00, 0x1A,
		0x80, 0x09, 0xCF, 0x06, 0x18, 0x18, 0x80, 0x09,
		0x4F, 0x01, 0x80, 0x03, 0x1C, 0x06, 0x18, 0x18,
		0x60, 0x00, 0x07, 0x01, 0x8A, 0x20, 0xFF, 0xC5,
		0x22, 0x6C, 0x0F, 0x0F, 0x80, 0x00, 0xCF, 0x10,
		0x80, 0x11, 0x30, 0x38, 0x80, 0x00, 0x4F, 0x01,
		0x10, 0x80, 0x13, 0x30, 0x38, 0x80, 0x00, 0xCF,
		0x10, 0x80, 0x11, 0x30, 0x38, 0x80, 0x00, 0x4F,
		0x01, 0x10, 0x80, 0x13, 0x30, 0x38, 0x80, 0x05,
		0x60, 0x00, 0x31, 0x6C, 0x80, 0x00, 0x04, 0xA0,
		0x00, 0x04, 0x39, 0x80, 0x13, 0x30, 0x38, 0x80,
		0x2A, 0x37, 0x80, 0x00, 0x04, 0xA0, 0x00, 0x03,
		0x39, 0x80, 0x11, 0x30, 0x38, 0x80, 0x28, 0x37,
		0xA0, 0x02, 0x3C, 0x80, 0x2C, 0x37, 0x80, 0x05,
		0x80, 0x2F, 0x17, 0x6C, 0x00, 0x00, 0x38, 0x7C,
		0x7C, 0x7C, 0x38, 0x00, 0x80, 0x6F, 0x13, 0x80,
		0x68, 0x33, 0x80, 0x5A, 0x33, 0x80, 0x5B, 0x33,
		0x80, 0x4D, 0x33, 0x80, 0x51, 0x32, 0x80, 0x47,
		0x32, 0x39, 0x60, 0x00, 0x9B, 0x80, 0x38, 0x33,
		0xA0, 0x00, 0x00, 0x80, 0x4C, 0x32, 0x80, 0x42,
		0x32, 0x39, 0x60, 0x00, 0x8B, 0x39, 0x80, 0x2A,
		0x33, 0xA0, 0xFF, 0xFF, 0xA0, 0x00, 0x28, 0x32,
		0x80, 0x2C, 0x32, 0x60, 0x00, 0x88, 0x26, 0x38,
		0x38, 0x80, 0x50, 0x33, 0xA0, 0xFF, 0xFF, 0xA0,
		0x00, 0x20, 0x32, 0x80, 0x24, 0x32, 0x60, 0x00,
		0x75, 0x26, 0x38, 0x38, 0x80, 0x56, 0x33, 0xA0,
		0x00, 0x00, 0xA0, 0x00, 0x00, 0x38, 0x2F, 0xA0,
		0x00, 0x00, 0x26, 0x80, 0x28, 0x37, 0xA0, 0x00,
		0x00, 0x28, 0xA0, 0x00, 0x00, 0x26, 0x80, 0x2A,
		0x37, 0xA0, 0x00, 0x00, 0x28, 0xA0, 0x00, 0x2E,
		0x17, 0x1C, 0x20, 0x00, 0x39, 0xEF, 0x26, 0x38,
		0x26, 0x80, 0xD7, 0x32, 0x60, 0x00, 0x3F, 0x20,
		0x00, 0x10, 0x6F, 0x80, 0xCD, 0x32, 0x38, 0x2F,
		0x80, 0xCD, 0x32, 0xA0, 0x00, 0x00, 0x38, 0x80,
		0xC6, 0x33, 0x80, 0xBB, 0x32, 0x60, 0x00, 0x30,
		0x20, 0xFF, 0xBC, 0x6F, 0x80, 0xB1, 0x32, 0x38,
		0x2F, 0x80, 0xBF, 0x32, 0xA0, 0x00, 0x00, 0x38,
		0x80, 0xB8, 0x33, 0x40, 0xFF, 0xA9, 0x62, 0x6C,
		0x26, 0x80, 0x0F, 0x3F, 0x08, 0x20, 0x00, 0x05,
		0xA0, 0x00, 0x00, 0x24, 0x39, 0x6C, 0xA0, 0x80,
		0x00, 0xAF, 0x38, 0x24, 0x6F, 0x38, 0x2A, 0x6C,
		0xA0, 0x80, 0x00, 0xAF, 0x38, 0x24, 0x6F, 0x38,
		0x2B, 0x6C, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC,
		0xFC, 0xFD, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
		0xFE, 0xFD, 0xFC, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8,
		0xF7, 0xF6, 0xF5, 0xF3, 0xF2, 0xF0, 0xEF, 0xED,
		0xEC, 0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE,
		0xDC, 0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC,
		0xC9, 0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6,
		0xB3, 0xB0, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F,
		0x9C, 0x98, 0x95, 0x92, 0x8F, 0x8C, 0x89, 0x86,
		0x83, 0x80, 0x7C, 0x79, 0x76, 0x73, 0x70, 0x6D,
		0x6A, 0x67, 0x63, 0x60, 0x5D, 0x5A, 0x57, 0x54,
		0x51, 0x4F, 0x4C, 0x49, 0x46, 0x43, 0x40, 0x3E,
		0x3B, 0x38, 0x36, 0x33, 0x31, 0x2E, 0x2C, 0x2A,
		0x27, 0x25, 0x23, 0x21, 0x1F, 0x1D, 0x1B, 0x19,
		0x17, 0x15, 0x13, 0x12, 0x10, 0x0F, 0x0D, 0x0C,
		0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03,
		0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
		0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0C, 0x0D, 0x0F, 0x10, 0x12,
		0x13, 0x15, 0x17, 0x19, 0x1B, 0x1D, 0x1F, 0x21,
		0x23, 0x25, 0x27, 0x2A, 0x2C, 0x2E, 0x31, 0x33,
		0x36, 0x38, 0x3B, 0x3E, 0x40, 0x43, 0x46, 0x49,
		0x4C, 0x4F, 0x51, 0x54, 0x57, 0x5A, 0x5D, 0x60,
		0x63, 0x67, 0x6A, 0x6D, 0x70, 0x73, 0x76, 0x79,
		0x7C, 0x7F, 0x83, 0x86, 0x89, 0x8C, 0x8F, 0x92,
		0x95, 0x98, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB,
		0xAE, 0xB0, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1,
		0xC4, 0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5,
		0xD8, 0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6,
		0xE8, 0xEA, 0xEC, 0xED, 0xEF, 0xF0, 0xF2, 0xF3,
		0xF5, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
  
  static uint32_t rdaddr;
  rdaddr = (uint32_t)(read_address);
  
  uint8_t rdata = uxn_rom_RAM_SP_RF_1(
	  rdaddr,	// read address
	  0, 		// write value
	  0			// write enable
  );
  
  return rdata;
}