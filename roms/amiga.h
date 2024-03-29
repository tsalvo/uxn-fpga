#pragma once
#include "uintN_t.h"  // uintN_t types for any N

//AMIGA DEMO

#define ROM_SIZE 3380

uint8_t read_rom_byte(uint16_t read_address)
{
	static uint8_t uxn_rom[ROM_SIZE] = {
		0x80, 0x01, 0x80, 0x0A,
		0x11, 0xA0, 0x01, 0x48,
		0x80, 0x20, 0x37, 0xA0,
		0xAF, 0xF5, 0x80, 0x08,
		0x37, 0xA0, 0xAF, 0x00,
		0x80, 0x0A, 0x37, 0xA0,
		0xAF, 0x05, 0x80, 0x0C,
		0x37, 0xA0, 0x01, 0x40,
		0x80, 0x22, 0x37, 0xA0,
		0x01, 0x00, 0x80, 0x24,
		0x37, 0xA0, 0x00, 0x20,
		0x80, 0x00, 0x31, 0xA0,
		0x00, 0x20, 0x80, 0x02,
		0x31, 0xA0, 0x00, 0x03,
		0x80, 0x04, 0x31, 0xA0,
		0x00, 0x00, 0x80, 0x06,
		0x31, 0x60, 0x01, 0xE7,
		0x60, 0x01, 0x59, 0x00,
		0x80, 0x09, 0x90, 0x80,
		0x0A, 0x10, 0x18, 0x80,
		0x0C, 0x9B, 0x1A, 0x19,
		0x04, 0x11, 0x60, 0x00,
		0x41, 0x00, 0xB0, 0xA0,
		0xFF, 0xFF, 0x3E, 0x21,
		0x05, 0x31, 0x6C, 0x26,
		0xA0, 0x00, 0x10, 0x2B,
		0x20, 0x00, 0x0D, 0x26,
		0x80, 0x22, 0x36, 0xA0,
		0x00, 0x50, 0x39, 0x2A,
		0x20, 0x00, 0x01, 0x6C,
		0x80, 0x0A, 0x90, 0x80,
		0x0A, 0x1E, 0x04, 0x11,
		0x80, 0x04, 0x40, 0xFF,
		0xD5, 0x26, 0x80, 0x24,
		0x36, 0xA0, 0x00, 0x50,
		0x39, 0x2A, 0x20, 0x00,
		0x03, 0x40, 0x00, 0x05,
		0x80, 0x06, 0x40, 0xFF,
		0xC1, 0x6C, 0x80, 0x00,
		0x30, 0x80, 0x28, 0x37,
		0x80, 0x02, 0x30, 0x80,
		0x2A, 0x37, 0xA0, 0x03,
		0x64, 0x80, 0x2C, 0x37,
		0xA0, 0x71, 0x26, 0x17,
		0x80, 0xF8, 0xA0, 0x40,
		0x2F, 0x17, 0x01, 0x06,
		0x20, 0xFF, 0xF7, 0x02,
		0xA0, 0x76, 0x26, 0x17,
		0x80, 0x04, 0xB0, 0xAF,
		0x05, 0x31, 0x80, 0x00,
		0xB0, 0x6F, 0x38, 0x60,
		0xFF, 0x95, 0x05, 0x31,
		0x80, 0x08, 0x90, 0x01,
		0x06, 0x05, 0x11, 0x80,
		0x06, 0x08, 0x20, 0x00,
		0x03, 0x40, 0x00, 0x0F,
		0x80, 0x00, 0x80, 0x08,
		0x11, 0x80, 0x06, 0xB0,
		0x21, 0xAF, 0x05, 0x31,
		0x40, 0x00, 0x09, 0x80,
		0x06, 0xB0, 0xAF, 0x05,
		0x31, 0x40, 0x00, 0x00,
		0x80, 0x02, 0xB0, 0x6F,
		0x38, 0x60, 0xFF, 0x85,
		0x05, 0x31, 0x80, 0x00,
		0x30, 0xA0, 0x00, 0x08,
		0x38, 0x80, 0x28, 0x37,
		0x80, 0x02, 0x30, 0xA0,
		0x00, 0x08, 0x38, 0x80,
		0x2A, 0x37, 0xA0, 0x0E,
		0x34, 0x80, 0x2C, 0x37,
		0xA0, 0x66, 0x26, 0x17,
		0x80, 0xF9, 0xA0, 0x4F,
		0x2F, 0x17, 0x01, 0x06,
		0x20, 0xFF, 0xF7, 0x02,
		0x80, 0x09, 0x10, 0x06,
		0x80, 0x06, 0x1B, 0x01,
		0x80, 0x05, 0x1A, 0x80,
		0x40, 0x18, 0x80, 0x19,
		0x13, 0x80, 0x00, 0x30,
		0x80, 0x28, 0x37, 0x80,
		0x02, 0x30, 0x80, 0x2A,
		0x37, 0xA0, 0x0C, 0xAC,
		0x80, 0x2C, 0x37, 0xA0,
		0x66, 0x26, 0x17, 0x80,
		0xF9, 0xA0, 0x00, 0x2F,
		0x17, 0x01, 0x06, 0x20,
		0xFF, 0xF7, 0x02, 0x06,
		0x80, 0x06, 0x1B, 0x80,
		0x00, 0x08, 0x01, 0x80,
		0x05, 0x1A, 0x80, 0x40,
		0x18, 0x80, 0x26, 0x13,
		0x80, 0x00, 0x30, 0x80,
		0x28, 0x37, 0x80, 0x02,
		0x30, 0x80, 0x2A, 0x37,
		0x80, 0x06, 0x9B, 0x1A,
		0x19, 0x80, 0x00, 0x04,
		0xA0, 0x01, 0x88, 0x3A,
		0xA0, 0x03, 0x7C, 0x38,
		0x80, 0x2C, 0x37, 0xA0,
		0x66, 0x26, 0x17, 0x80,
		0xF9, 0xA0, 0x00, 0x2F,
		0x17, 0x01, 0x06, 0x20,
		0xFF, 0xF7, 0x02, 0x6C,
		0xA0, 0x01, 0x26, 0x17,
		0xA0, 0x03, 0x6C, 0x80,
		0x2C, 0x37, 0x80, 0x24,
		0x36, 0x80, 0x04, 0x3F,
		0x03, 0x80, 0x04, 0x19,
		0x80, 0x00, 0xA0, 0x00,
		0x20, 0x80, 0x28, 0x37,
		0x80, 0x00, 0x07, 0x80,
		0x40, 0x3F, 0xA0, 0x00,
		0x20, 0x38, 0x80, 0x2A,
		0x37, 0x80, 0x22, 0x36,
		0x80, 0x03, 0x3F, 0x03,
		0x80, 0x08, 0x19, 0x80,
		0x00, 0xA0, 0x0F, 0x2F,
		0x17, 0x01, 0x8A, 0x20,
		0xFF, 0xF7, 0x22, 0x01,
		0x8A, 0x20, 0xFF, 0xD2,
		0x22, 0xA0, 0x02, 0x26,
		0x17, 0xA0, 0x03, 0x74,
		0x80, 0x2C, 0x37, 0x80,
		0x22, 0x36, 0x80, 0x04,
		0x3F, 0x03, 0x80, 0x03,
		0x19, 0x80, 0x00, 0xA0,
		0x00, 0x27, 0x80, 0x2A,
		0x37, 0x80, 0x00, 0x07,
		0x80, 0x40, 0x3F, 0xA0,
		0x00, 0x19, 0x38, 0x80,
		0x28, 0x37, 0x80, 0x24,
		0x36, 0x80, 0x03, 0x3F,
		0x03, 0x80, 0x0A, 0x19,
		0x80, 0x00, 0xA0, 0x0F,
		0x2F, 0x17, 0x01, 0x8A,
		0x20, 0xFF, 0xF7, 0x22,
		0x01, 0x8A, 0x20, 0xFF,
		0xD2, 0x22, 0x6C, 0xA0,
		0x0C, 0xAC, 0xA0, 0x0E,
		0x34, 0xA0, 0x01, 0x88,
		0x60, 0x00, 0x1B, 0xA0,
		0x01, 0x88, 0xA0, 0x00,
		0x00, 0x26, 0xA0, 0x0E,
		0x34, 0x38, 0xB4, 0xA0,
		0xAA, 0x55, 0x3C, 0x24,
		0x35, 0x21, 0x21, 0xAA,
		0x20, 0xFF, 0xEE, 0x22,
		0x22, 0x6C, 0x24, 0x2F,
		0x27, 0x38, 0x24, 0x94,
		0xEF, 0x15, 0x61, 0x21,
		0xAA, 0x20, 0xFF, 0xF7,
		0x22, 0x22, 0x62, 0x6C,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xFF,
		0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x03, 0x04, 0x08, 0x30,
		0x00, 0x00, 0x07, 0x3F,
		0x18, 0x0C, 0x1F, 0x3F,
		0x00, 0xF4, 0xC1, 0x03,
		0x07, 0x0F, 0xBF, 0x8F,
		0x00, 0x40, 0x0C, 0xFC,
		0xE2, 0xC1, 0xC1, 0xC1,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0xA0, 0xE0, 0xE4,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x01, 0x01, 0x03, 0x03,
		0x60, 0xC0, 0x01, 0xE3,
		0xFB, 0xF0, 0xF0, 0xE0,
		0x7F, 0xFF, 0xFE, 0xFE,
		0xFC, 0x78, 0x00, 0x0F,
		0x81, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x01, 0x03,
		0x80, 0x40, 0xF8, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xF2, 0xF1, 0xF9, 0xF8,
		0x1C, 0x00, 0x03, 0x03,
		0x00, 0x00, 0x80, 0x80,
		0x40, 0x20, 0xB0, 0xE0,
		0x07, 0x07, 0x0F, 0x1F,
		0x27, 0x20, 0x20, 0x60,
		0xE0, 0xC0, 0xC0, 0x80,
		0x80, 0x00, 0xE0, 0xFC,
		0x0F, 0x1F, 0x1F, 0x3F,
		0x3F, 0x3F, 0x7F, 0x7F,
		0xE3, 0xFF, 0xF8, 0xF8,
		0xF8, 0xF0, 0xF0, 0xF0,
		0xFE, 0xFE, 0x7E, 0x0E,
		0x00, 0x01, 0x01, 0x03,
		0x01, 0x01, 0x01, 0x01,
		0x01, 0xC1, 0xF9, 0xFE,
		0xE0, 0xE0, 0xE0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF8,
		0x60, 0x60, 0x40, 0x41,
		0x41, 0x41, 0x01, 0x39,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFE, 0xFE, 0xFE,
		0x7F, 0x0F, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0xE0, 0xE0, 0xE0, 0x00,
		0x3C, 0x3F, 0x7F, 0x7F,
		0x03, 0x03, 0x07, 0x07,
		0x07, 0x87, 0xFF, 0xF1,
		0xFE, 0xFE, 0xFE, 0xFC,
		0xFC, 0xFC, 0xFC, 0xFC,
		0x18, 0x04, 0x06, 0x06,
		0x0E, 0x0E, 0x0E, 0x0E,
		0x3E, 0x1E, 0x1E, 0x1E,
		0x1E, 0x0E, 0x0F, 0x0F,
		0xFE, 0x1C, 0x00, 0x03,
		0x03, 0x03, 0x03, 0x03,
		0x00, 0x00, 0x00, 0x80,
		0xF1, 0xFF, 0xFE, 0xFE,
		0x7F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x3F, 0x07,
		0xF0, 0xE0, 0xE0, 0xE0,
		0xC0, 0xC0, 0x80, 0x80,
		0x38, 0x00, 0x07, 0x0F,
		0x0F, 0x1F, 0x1F, 0x3F,
		0x0E, 0x0C, 0x0C, 0xFC,
		0xE0, 0xC0, 0xC0, 0x80,
		0x0F, 0x09, 0x04, 0x00,
		0x00, 0x01, 0x00, 0x00,
		0x03, 0x03, 0xC3, 0x7B,
		0x3C, 0x3C, 0x9E, 0x1E,
		0xFC, 0xFC, 0xFC, 0xFC,
		0xF8, 0x18, 0x04, 0x0F,
		0x00, 0x00, 0x01, 0x01,
		0x03, 0x03, 0x07, 0x8F,
		0x80, 0xE0, 0xFE, 0xFF,
		0xFF, 0xFE, 0xFC, 0xF8,
		0x3F, 0x7F, 0x7F, 0x3E,
		0x06, 0x03, 0x07, 0x0E,
		0x80, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x0E, 0x1E, 0x05, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x0F, 0x0F, 0x0F, 0x4F,
		0x27, 0x03, 0x02, 0x00,
		0xFF, 0xE1, 0xC0, 0x80,
		0x03, 0x0F, 0x1E, 0x00,
		0xF0, 0xE0, 0x00, 0xF9,
		0xF8, 0xC0, 0x00, 0x00,
		0x3C, 0x70, 0xE0, 0xC0,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x02, 0x04, 0x08, 0x00,
		0x00, 0x01, 0x0F, 0x7C,
		0x10, 0x1C, 0x3F, 0xFF,
		0x00, 0xE7, 0x83, 0x07,
		0x0F, 0x3F, 0xFF, 0x0F,
		0x00, 0x40, 0x0C, 0xDC,
		0xC0, 0x83, 0x81, 0x01,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0xA0, 0xC0, 0xE4,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x03,
		0x01, 0x03, 0x03, 0x07,
		0x41, 0x83, 0x07, 0xEF,
		0xF3, 0xE0, 0xE0, 0xC0,
		0xFE, 0xFE, 0xFC, 0xF8,
		0xF0, 0x70, 0x18, 0x1F,
		0x01, 0x01, 0x01, 0x03,
		0x03, 0x03, 0x07, 0x07,
		0x01, 0xC1, 0xF9, 0xFE,
		0xFE, 0xFC, 0xFC, 0xFC,
		0xE2, 0xF3, 0xF1, 0xF8,
		0x18, 0x04, 0x07, 0x07,
		0x00, 0x00, 0x00, 0x80,
		0x40, 0x60, 0xB0, 0xC0,
		0x07, 0x0F, 0x3F, 0x1F,
		0x27, 0x21, 0x01, 0x01,
		0xC0, 0x80, 0x80, 0x00,
		0x00, 0x00, 0xE1, 0xFD,
		0x3F, 0x3F, 0x7F, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xEF, 0xF3, 0xF0, 0xE0,
		0xE0, 0xC0, 0xC0, 0xC0,
		0xFC, 0xFC, 0x7C, 0x0C,
		0x06, 0x07, 0x07, 0x07,
		0x03, 0x03, 0x03, 0x03,
		0x03, 0xC3, 0xFB, 0xFC,
		0xC0, 0xE0, 0xE0, 0xE4,
		0xE0, 0xE0, 0xF0, 0xF0,
		0x41, 0x41, 0x43, 0x43,
		0x43, 0x43, 0x43, 0x3B,
		0xFE, 0xFE, 0xFC, 0xFC,
		0xFC, 0xFC, 0xF8, 0xF8,
		0x7F, 0x0F, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x80, 0x80, 0x80, 0xC0,
		0xFC, 0xFF, 0xFF, 0xFF,
		0x0F, 0x0F, 0x0F, 0x1F,
		0x1F, 0x9F, 0xEF, 0xC1,
		0xFC, 0xF8, 0xF8, 0xF8,
		0xF8, 0xF8, 0xF0, 0xF0,
		0x10, 0x0C, 0x0E, 0x0E,
		0x0E, 0x1E, 0x1E, 0x1E,
		0x3C, 0x3C, 0x3C, 0x1C,
		0x3C, 0x1E, 0x0E, 0x0E,
		0xF8, 0x18, 0x04, 0x07,
		0x07, 0x07, 0x07, 0x07,
		0x01, 0x01, 0x03, 0x83,
		0xF3, 0xF9, 0xF8, 0xF8,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x3F, 0x06,
		0xC0, 0xC0, 0x80, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x30, 0x08, 0x1F, 0x1F,
		0x3F, 0x3F, 0x7F, 0x7F,
		0x1C, 0x1C, 0x1C, 0xFC,
		0xC0, 0xC4, 0x80, 0x00,
		0x0E, 0x08, 0x04, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x07, 0x07, 0xC7, 0xFF,
		0x78, 0x38, 0xBC, 0x1C,
		0xF8, 0xF8, 0xF0, 0xF0,
		0xF0, 0x10, 0x1C, 0x1F,
		0x01, 0x03, 0x03, 0x07,
		0x07, 0x0F, 0x0F, 0x9F,
		0x00, 0xE0, 0xFE, 0xFE,
		0xFC, 0xF8, 0xF0, 0xE0,
		0x7F, 0xFE, 0xFE, 0x3C,
		0x04, 0x07, 0x0F, 0x1E,
		0x00, 0x00, 0x00, 0x00,
		0x40, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x0C, 0x1E, 0x04, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x1F, 0x1F, 0x1F, 0xDF,
		0x26, 0x07, 0x02, 0x00,
		0xCF, 0xC1, 0x80, 0x01,
		0x07, 0x1F, 0x1C, 0x00,
		0xE0, 0xC0, 0x41, 0xFB,
		0xF0, 0x80, 0x00, 0x00,
		0x38, 0xF0, 0xE0, 0xC0,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x00, 0x01, 0x1F, 0xF8,
		0x00, 0x3C, 0xFE, 0xFE,
		0x00, 0xE7, 0x03, 0x0F,
		0x3F, 0x7F, 0x7F, 0x0E,
		0x00, 0x00, 0x1C, 0xD8,
		0x80, 0x03, 0x03, 0x03,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0xC0, 0xC0, 0xC4,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x03, 0x07, 0x07, 0x0F,
		0x03, 0x07, 0x0F, 0xFF,
		0xE3, 0xC0, 0xC0, 0x80,
		0xFC, 0xF8, 0xF0, 0xF0,
		0xE0, 0x40, 0x78, 0x7F,
		0x02, 0x03, 0x07, 0x07,
		0x0F, 0x0F, 0x1F, 0x1F,
		0x03, 0xC3, 0xFB, 0xF8,
		0xF8, 0xF8, 0xF8, 0xF8,
		0xE6, 0xE3, 0xE1, 0xF1,
		0x10, 0x0C, 0x0F, 0x0F,
		0x00, 0x00, 0x00, 0x80,
		0xC0, 0x60, 0xE0, 0xC0,
		0x0F, 0x1F, 0x3F, 0x3E,
		0x04, 0x03, 0x03, 0x03,
		0x80, 0x00, 0x00, 0x01,
		0x01, 0x03, 0xE3, 0xFB,
		0x7F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xC3, 0xC0, 0x80,
		0x80, 0x80, 0x00, 0x00,
		0xF8, 0xF0, 0x70, 0x00,
		0x0E, 0x1F, 0x1F, 0x1F,
		0x0F, 0x0F, 0x07, 0x07,
		0x07, 0xC7, 0xFF, 0xF0,
		0xC8, 0xC0, 0xC0, 0xC4,
		0xE0, 0xE0, 0xE0, 0xE2,
		0x03, 0x03, 0x07, 0x07,
		0x07, 0x07, 0x47, 0x7F,
		0xF8, 0xF8, 0xF8, 0xF8,
		0xF0, 0xF0, 0xF0, 0xF0,
		0x7F, 0x0E, 0x00, 0x01,
		0x03, 0x03, 0x03, 0x07,
		0x00, 0x00, 0x00, 0xC0,
		0xFC, 0xFF, 0xFF, 0xFF,
		0x1F, 0x3F, 0x3F, 0x3F,
		0x7F, 0xFF, 0x8F, 0x01,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xE0, 0xE0, 0xE0, 0xE0,
		0x00, 0x1C, 0x1E, 0x1E,
		0x1E, 0x1C, 0x3C, 0x3C,
		0x78, 0x38, 0x38, 0x38,
		0x3C, 0x1C, 0x1C, 0x1C,
		0xF0, 0x00, 0x1C, 0x1F,
		0x1F, 0x1F, 0x0F, 0x0F,
		0x07, 0x07, 0x07, 0x8F,
		0xFF, 0xF1, 0xF0, 0xE0,
		0xFF, 0xFF, 0xFE, 0xFE,
		0xFE, 0xFC, 0x3C, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x20, 0x38, 0x3F, 0x7F,
		0x7F, 0xFF, 0xFF, 0xFE,
		0x3C, 0x3C, 0x3C, 0xDC,
		0x80, 0x04, 0x08, 0x00,
		0x0C, 0x00, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x0F, 0x0F, 0xCF, 0xF7,
		0x70, 0x78, 0x38, 0x18,
		0xE0, 0xE0, 0xE0, 0xE0,
		0xE0, 0x20, 0x3C, 0x3F,
		0x07, 0x07, 0x0F, 0x0F,
		0x1F, 0x1F, 0x3F, 0xBF,
		0x01, 0xE1, 0xFD, 0xF8,
		0xF0, 0xF0, 0xE0, 0xC0,
		0xFE, 0xFC, 0xFC, 0x38,
		0x00, 0x0F, 0x1E, 0x3C,
		0x10, 0x00, 0x20, 0x00,
		0x40, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x1C, 0x1C, 0x04, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x3F, 0x3F, 0x3F, 0xFE,
		0x64, 0x07, 0x03, 0x00,
		0x8F, 0x01, 0x01, 0x03,
		0x0F, 0x3F, 0x18, 0x00,
		0x80, 0x80, 0xC3, 0xFF,
		0xE0, 0x08, 0x00, 0x00,
		0x78, 0xF0, 0xC0, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x03,
		0x00, 0x01, 0x1E, 0xF0,
		0x20, 0x7D, 0xFC, 0xF8,
		0x00, 0xC7, 0x07, 0x1F,
		0x7F, 0xFE, 0x7C, 0x0C,
		0x00, 0x80, 0x1C, 0x9A,
		0x04, 0x07, 0x07, 0x07,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0xC0, 0x80, 0xCC,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x03, 0x07, 0x07, 0x0F,
		0x07, 0x0F, 0x1F, 0xDF,
		0xC3, 0x80, 0x80, 0x01,
		0xF8, 0xF0, 0xE0, 0xC0,
		0x80, 0x80, 0xF8, 0xFF,
		0x06, 0x0F, 0x0F, 0x1F,
		0x1F, 0x3F, 0x3F, 0x7F,
		0x07, 0xC7, 0xF7, 0xF0,
		0xF0, 0xF0, 0xE0, 0xE0,
		0xC6, 0xC2, 0xE3, 0xE1,
		0x00, 0x1C, 0x1F, 0x1F,
		0x00, 0x00, 0x00, 0x80,
		0xC0, 0xC0, 0xE0, 0x80,
		0x0F, 0x1E, 0x3C, 0x3C,
		0x00, 0x07, 0x07, 0x07,
		0x01, 0x01, 0x03, 0x03,
		0x07, 0x07, 0xEF, 0xF3,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFE, 0xFC, 0xFC,
		0x9F, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0xE0, 0xE0, 0x60, 0x30,
		0x3E, 0x3F, 0x7F, 0x7F,
		0x1F, 0x1F, 0x1F, 0x1F,
		0x1F, 0xDF, 0xE7, 0xE0,
		0x88, 0x88, 0x80, 0xC4,
		0xC4, 0xC0, 0xC0, 0xC2,
		0x07, 0x07, 0x07, 0x0F,
		0x0F, 0x0F, 0x4F, 0x77,
		0xF0, 0xF0, 0xE0, 0xE0,
		0xE0, 0xE0, 0xE0, 0xC0,
		0x7C, 0x08, 0x06, 0x07,
		0x07, 0x0F, 0x0F, 0x0F,
		0x00, 0x00, 0x00, 0xC0,
		0xFC, 0xFE, 0xFE, 0xFE,
		0x7F, 0xFF, 0xFF, 0xFF,
		0xFF, 0x7F, 0x0F, 0x01,
		0xE0, 0xE0, 0xC0, 0xC0,
		0xC0, 0xC0, 0x80, 0x80,
		0x22, 0x3C, 0x3C, 0x3C,
		0x3C, 0x3C, 0x7C, 0x7C,
		0x70, 0x30, 0x38, 0x38,
		0x38, 0x18, 0x18, 0x1C,
		0xC0, 0x20, 0x3C, 0x3F,
		0x3F, 0x3F, 0x3F, 0x3F,
		0x1F, 0x1F, 0x1F, 0x9F,
		0xCF, 0xC1, 0xC0, 0xC0,
		0xFC, 0xFC, 0xFC, 0xF8,
		0xF8, 0xF0, 0x30, 0x08,
		0x00, 0x00, 0x00, 0x00,
		0x01, 0x01, 0x03, 0x03,
		0x40, 0x78, 0xFF, 0xFF,
		0xFF, 0xFE, 0xFE, 0xFC,
		0x7C, 0x7C, 0x78, 0x18,
		0x04, 0x04, 0x08, 0x10,
		0x0C, 0x02, 0x01, 0x01,
		0x00, 0x00, 0x00, 0x00,
		0x1F, 0x1F, 0xDF, 0xE7,
		0xE0, 0x70, 0x30, 0x38,
		0xC0, 0xC0, 0xC0, 0x80,
		0x80, 0x60, 0x7C, 0x7F,
		0x1F, 0x1F, 0x3F, 0x3F,
		0x3F, 0x7F, 0x7F, 0x7F,
		0x07, 0xE7, 0xF1, 0xF0,
		0xE0, 0xC0, 0x80, 0x80,
		0xFC, 0xF8, 0xF8, 0x30,
		0x08, 0x1F, 0x3E, 0x7C,
		0x10, 0x20, 0x20, 0x40,
		0x40, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x18, 0x1C, 0x02, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x7F, 0x7E, 0x3E, 0xFC,
		0x44, 0x0F, 0x01, 0x00,
		0x0F, 0x00, 0x03, 0x0F,
		0x1F, 0x3E, 0x18, 0x00,
		0x00, 0x03, 0xC7, 0xF7,
		0xC1, 0x08, 0x00, 0x00,
		0xF8, 0xE0, 0xC0, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x00, 0x01, 0x1C, 0xE0,
		0x60, 0xFF, 0xF8, 0xF0,
		0x00, 0x87, 0x0F, 0x3F,
		0xFE, 0xFC, 0x78, 0x00,
		0x00, 0x80, 0x3C, 0x1A,
		0x0D, 0x0F, 0x0F, 0x0F,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0x40, 0x80, 0x8C,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x03, 0x07, 0x07, 0x0E,
		0x0F, 0x1F, 0x3F, 0x9F,
		0x83, 0x01, 0x01, 0x03,
		0xE0, 0xC0, 0x80, 0x00,
		0x00, 0x80, 0xF8, 0xFE,
		0x0E, 0x1F, 0x3F, 0x3F,
		0x7F, 0x7F, 0xFF, 0xFF,
		0x0F, 0xDF, 0xE7, 0xE0,
		0xC0, 0xC0, 0xC0, 0xC0,
		0x86, 0x86, 0xC3, 0xC3,
		0x21, 0x3C, 0x3F, 0x3F,
		0x00, 0x00, 0x00, 0x80,
		0xC0, 0xC0, 0x60, 0x00,
		0x0E, 0x1C, 0x3C, 0x38,
		0x00, 0x0F, 0x0F, 0x0F,
		0x03, 0x07, 0x07, 0x0F,
		0x0F, 0x1F, 0xFF, 0xE3,
		0xFE, 0xFE, 0xFC, 0xFC,
		0xF8, 0xF8, 0xF8, 0xF0,
		0x1F, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x80, 0x80, 0x00, 0x70,
		0xFE, 0xFF, 0xFF, 0xFF,
		0x3F, 0x3F, 0x3F, 0x3F,
		0x3F, 0xFF, 0xC7, 0x80,
		0x08, 0x08, 0x88, 0x84,
		0x84, 0x84, 0x84, 0x82,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x1F, 0x1F, 0x5F, 0x67,
		0xC0, 0xC0, 0xC0, 0xC0,
		0xC0, 0x80, 0x80, 0x80,
		0x70, 0x00, 0x1E, 0x1F,
		0x1F, 0x1F, 0x3F, 0x3F,
		0x01, 0x01, 0x03, 0xC3,
		0xFF, 0xF8, 0xF8, 0xF8,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0x7F, 0x0F, 0x01,
		0x80, 0x80, 0x80, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x62, 0x7E, 0x7C, 0x7C,
		0x7C, 0xFC, 0xF8, 0xF8,
		0x60, 0x30, 0x30, 0x30,
		0x30, 0x18, 0x18, 0x18,
		0x80, 0x60, 0x7C, 0x7F,
		0x7F, 0x7F, 0x7F, 0x7F,
		0x3F, 0x7F, 0x7F, 0xFF,
		0x8F, 0x81, 0x80, 0x80,
		0xF0, 0xF0, 0xF0, 0xE0,
		0xE0, 0xE0, 0x00, 0x38,
		0x01, 0x01, 0x03, 0x03,
		0x03, 0x07, 0x07, 0x0F,
		0xC0, 0xF8, 0xFF, 0xFE,
		0xFE, 0xFC, 0xFC, 0xF8,
		0xF8, 0xF8, 0xF8, 0x18,
		0x04, 0x0C, 0x18, 0x10,
		0x08, 0x02, 0x03, 0x01,
		0x00, 0x00, 0x00, 0x00,
		0x3F, 0x3F, 0xFF, 0xC7,
		0xE0, 0x60, 0x70, 0x30,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0xE0, 0xFD, 0xFE,
		0x3F, 0x7F, 0x7F, 0xFF,
		0xFF, 0xFF, 0xFF, 0x7E,
		0x0F, 0xFF, 0xE1, 0xC0,
		0x80, 0x80, 0x00, 0x01,
		0xF8, 0xF0, 0xF0, 0x20,
		0x38, 0x7F, 0xFC, 0xF8,
		0x30, 0x20, 0x60, 0x40,
		0xC0, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x18, 0x18, 0x02, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x7C, 0x7C, 0x7C, 0xB8,
		0x40, 0x0F, 0x01, 0x00,
		0x0E, 0x02, 0x0F, 0x1F,
		0x3F, 0x7C, 0xD0, 0x00,
		0x03, 0x07, 0xCF, 0xE7,
		0x03, 0x18, 0x80, 0x00,
		0xF0, 0xE0, 0xC0, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x03, 0x07,
		0x00, 0x01, 0x18, 0xC0,
		0xE1, 0xFB, 0xF0, 0xE0,
		0x00, 0x87, 0x1F, 0x7E,
		0xFC, 0xF8, 0x70, 0x10,
		0x00, 0x80, 0x70, 0x12,
		0x0D, 0x1F, 0x1F, 0x1F,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x40, 0x10, 0x0C,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x03, 0x06, 0x06, 0x0C,
		0x0F, 0x3F, 0x7F, 0x9E,
		0x00, 0x03, 0x07, 0x07,
		0xC0, 0x80, 0x00, 0x00,
		0x00, 0x81, 0xFB, 0xFC,
		0x3E, 0x7F, 0x7F, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x3F, 0xFF, 0xC7, 0x80,
		0x80, 0x80, 0x00, 0x00,
		0x0C, 0x86, 0x87, 0x83,
		0x63, 0x7D, 0x7E, 0x7E,
		0x00, 0x00, 0x00, 0x80,
		0x80, 0xC0, 0x60, 0x10,
		0x0C, 0x18, 0x38, 0x30,
		0x08, 0x0F, 0x0F, 0x1F,
		0x0F, 0x0F, 0x1F, 0x1F,
		0x3F, 0x3F, 0x9F, 0x83,
		0xF8, 0xF8, 0xF8, 0xF0,
		0xF0, 0xE0, 0xE0, 0xE0,
		0x1F, 0x02, 0x01, 0x01,
		0x03, 0x03, 0x03, 0x07,
		0x00, 0x00, 0x80, 0xF0,
		0xFE, 0xFF, 0xFF, 0xFF,
		0x7E, 0x7F, 0x7F, 0x7F,
		0x7F, 0x3F, 0x07, 0x00,
		0x18, 0x08, 0x08, 0x0C,
		0x0C, 0x04, 0x04, 0x06,
		0x1F, 0x1F, 0x1F, 0x1F,
		0x1F, 0x1F, 0x7F, 0x67,
		0x80, 0x80, 0x80, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x40, 0x30, 0x3E, 0x7F,
		0x7F, 0x7F, 0x7F, 0xFF,
		0x07, 0x07, 0x0F, 0xCF,
		0xF3, 0xF0, 0xE0, 0xE0,
		0xFF, 0xFE, 0xFE, 0xFE,
		0xFE, 0x7C, 0x0C, 0x02,
		0x00, 0x00, 0x00, 0x00,
		0x01, 0x01, 0x01, 0x01,
		0xE6, 0xFE, 0xF8, 0xF8,
		0xF8, 0xF8, 0xF8, 0xF8,
		0x60, 0x20, 0x20, 0x30,
		0x30, 0x10, 0x10, 0x18,
		0x00, 0xE0, 0xFC, 0xFE,
		0xFE, 0xFE, 0xFE, 0x7E,
		0xFF, 0xFF, 0xFF, 0x7F,
		0x0F, 0x01, 0x00, 0x00,
		0xE0, 0xC0, 0xC0, 0xC0,
		0x80, 0x80, 0x40, 0xF8,
		0x07, 0x07, 0x07, 0x0F,
		0x0F, 0x1F, 0x1F, 0x1F,
		0xC1, 0xF9, 0xFC, 0xFC,
		0xF8, 0xF8, 0xF0, 0xF0,
		0xF8, 0xF0, 0xF0, 0x10,
		0x0C, 0x1C, 0x18, 0x30,
		0x08, 0x06, 0x03, 0x01,
		0x01, 0x00, 0x00, 0x00,
		0x7E, 0x7E, 0xBE, 0xC6,
		0xC1, 0xE1, 0x61, 0x30,
		0x00, 0x00, 0x01, 0x01,
		0x01, 0xE3, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFE, 0xFE, 0x7C,
		0x3F, 0xDF, 0x81, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0xE0, 0xE0, 0xC0, 0x00,
		0x79, 0xFE, 0xFC, 0xF0,
		0x30, 0x60, 0x60, 0xC0,
		0xC0, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x30, 0x08, 0x02, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0xF8, 0xF8, 0xF8, 0xB0,
		0x48, 0x0E, 0x01, 0x00,
		0x08, 0x0E, 0x1F, 0x3F,
		0x7E, 0xF8, 0xE1, 0x00,
		0x07, 0x0F, 0xDF, 0x87,
		0x03, 0x18, 0x80, 0x00,
		0xE0, 0xC0, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x03, 0x07, 0x0F, 0x3F,
		0x00, 0x01, 0x1F, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0xC0, 0xFC, 0xFE,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00,
		0x80, 0xE0, 0xF8, 0xFC,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03,
		0x03, 0x07, 0x07, 0x0F,
		0x7F, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0x00, 0x80, 0x80,
		0xC0, 0xE0, 0xF0, 0xF0,
		0x0F, 0x1F, 0x3F, 0x3F,
		0x3F, 0x3F, 0x7F, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xF8, 0xF8, 0xF8, 0xFC,
		0xFC, 0xFC, 0xFC, 0xFE,
		0x7F, 0x7F, 0x7F, 0x7F,
		0x7F, 0x7F, 0x7F, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFE, 0xFE, 0xFE,
		0xFE, 0xFE, 0xFE, 0xFE,
		0x7F, 0x3F, 0x3F, 0x3F,
		0x3F, 0x1F, 0x1F, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFE, 0xFE, 0xFC, 0xFC,
		0xFC, 0xFC, 0xF8, 0xF0,
		0x0F, 0x0F, 0x07, 0x03,
		0x01, 0x01, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0x7F,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFE,
		0xF0, 0xE0, 0xE0, 0xC0,
		0xC0, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x3F, 0x1F, 0x07, 0x01,
		0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x7F, 0x3F, 0x03, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xF8, 0x80, 0x00,
		0xFC, 0xF0, 0xE0, 0xC0,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
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