/*****************************************************************************
 * FileName:        DSPIC_Test_2.c
 * Processor:       PIC24F, PIC24H, dsPIC
 * Compiler:        MPLAB C30/XC16 (see release notes for tested revision)
 * Linker:          MPLAB LINK30/XC16
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright(c) 2012 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * AUTO-GENERATED CODE:  Graphics Resource Converter version: 3.29.06
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Includes
 *****************************************************************************/
#include <Graphics/Graphics.h>
#include "HardwareProfile.h"

/*****************************************************************************
 * SECTION:  Graphics Library Firmware Check
 *****************************************************************************/
#if(GRAPHICS_LIBRARY_VERSION != 0x0306)
#warning "It is suggested to use Graphics Library version 3.06 with this version of GRC."
#endif


/*****************************************************************************
 * Converted Resources
 * -------------------
 *
 *
 * Fonts
 * -----
 * DroidSans_6 - Height: 8 pixels, 1 bit per pixel, Range: ' ' to '�'
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * TTF Font File Structure
 * Label: DroidSans_6
 * Description:  Height: 8 pixels, 1 bit per pixel, Range: ' ' to '�'
 ***********************************/
#ifdef USE_GFX_FONT_IN_PROGRAM_SECTION
extern GFX_FONT_SPACE char __DroidSans_6[] __attribute__((section("grc_text"), aligned(2)));
#else
extern GFX_FONT_SPACE char __DroidSans_6[] __attribute__((aligned(2)));
#endif

const FONT_FLASH DroidSans_6 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__DroidSans_6
};

#ifdef USE_GFX_FONT_IN_PROGRAM_SECTION
asm(".section grc_text, code");
#else
asm(".section .const, psv, page");
#endif
asm(".global ___DroidSans_6");
asm(".align 2");
asm("___DroidSans_6:");
/****************************************
 * Font header
 ****************************************/
asm(".byte 0x00");           // Font ID
asm(".byte 0x00");           // Font information:  1 bit per pixel, Characters zero degress rotation
asm(".byte 0x00, 0x00");     // First Character
asm(".byte 0xFF, 0x00");     // Last Character
asm(".byte 0x08, 0x00");     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x08, 0x04, 0x00");       // Character - 0, offset (0x00000408)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x10, 0x04, 0x00");       // Character - 1, offset (0x00000410)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x18, 0x04, 0x00");       // Character - 2, offset (0x00000418)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x20, 0x04, 0x00");       // Character - 3, offset (0x00000420)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x28, 0x04, 0x00");       // Character - 4, offset (0x00000428)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x30, 0x04, 0x00");       // Character - 5, offset (0x00000430)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x38, 0x04, 0x00");       // Character - 6, offset (0x00000438)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x40, 0x04, 0x00");       // Character - 7, offset (0x00000440)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x48, 0x04, 0x00");       // Character - 8, offset (0x00000448)
asm(".byte 0x00");              // width of the glyph
asm(".byte 0x50, 0x04, 0x00");       // Character - 9, offset (0x00000450)
asm(".byte 0x00");              // width of the glyph
asm(".byte 0x50, 0x04, 0x00");       // Character - 10, offset (0x00000450)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x50, 0x04, 0x00");       // Character - 11, offset (0x00000450)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x58, 0x04, 0x00");       // Character - 12, offset (0x00000458)
asm(".byte 0x00");              // width of the glyph
asm(".byte 0x60, 0x04, 0x00");       // Character - 13, offset (0x00000460)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x60, 0x04, 0x00");       // Character - 14, offset (0x00000460)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x68, 0x04, 0x00");       // Character - 15, offset (0x00000468)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x70, 0x04, 0x00");       // Character - 16, offset (0x00000470)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x78, 0x04, 0x00");       // Character - 17, offset (0x00000478)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x80, 0x04, 0x00");       // Character - 18, offset (0x00000480)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x88, 0x04, 0x00");       // Character - 19, offset (0x00000488)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x90, 0x04, 0x00");       // Character - 20, offset (0x00000490)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x98, 0x04, 0x00");       // Character - 21, offset (0x00000498)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xA0, 0x04, 0x00");       // Character - 22, offset (0x000004A0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xA8, 0x04, 0x00");       // Character - 23, offset (0x000004A8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xB0, 0x04, 0x00");       // Character - 24, offset (0x000004B0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xB8, 0x04, 0x00");       // Character - 25, offset (0x000004B8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xC0, 0x04, 0x00");       // Character - 26, offset (0x000004C0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xC8, 0x04, 0x00");       // Character - 27, offset (0x000004C8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xD0, 0x04, 0x00");       // Character - 28, offset (0x000004D0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xD8, 0x04, 0x00");       // Character - 29, offset (0x000004D8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xE0, 0x04, 0x00");       // Character - 30, offset (0x000004E0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xE8, 0x04, 0x00");       // Character - 31, offset (0x000004E8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xF0, 0x04, 0x00");       // Character - 32, offset (0x000004F0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xF8, 0x04, 0x00");       // Character - 33, offset (0x000004F8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x00, 0x05, 0x00");       // Character - 34, offset (0x00000500)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x08, 0x05, 0x00");       // Character - 35, offset (0x00000508)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x10, 0x05, 0x00");       // Character - 36, offset (0x00000510)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x18, 0x05, 0x00");       // Character - 37, offset (0x00000518)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x20, 0x05, 0x00");       // Character - 38, offset (0x00000520)
asm(".byte 0x01");              // width of the glyph
asm(".byte 0x28, 0x05, 0x00");       // Character - 39, offset (0x00000528)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x30, 0x05, 0x00");       // Character - 40, offset (0x00000530)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x38, 0x05, 0x00");       // Character - 41, offset (0x00000538)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x40, 0x05, 0x00");       // Character - 42, offset (0x00000540)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x05, 0x00");       // Character - 43, offset (0x00000548)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x50, 0x05, 0x00");       // Character - 44, offset (0x00000550)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x58, 0x05, 0x00");       // Character - 45, offset (0x00000558)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x60, 0x05, 0x00");       // Character - 46, offset (0x00000560)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x68, 0x05, 0x00");       // Character - 47, offset (0x00000568)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x70, 0x05, 0x00");       // Character - 48, offset (0x00000570)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x78, 0x05, 0x00");       // Character - 49, offset (0x00000578)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x80, 0x05, 0x00");       // Character - 50, offset (0x00000580)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x88, 0x05, 0x00");       // Character - 51, offset (0x00000588)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x90, 0x05, 0x00");       // Character - 52, offset (0x00000590)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x98, 0x05, 0x00");       // Character - 53, offset (0x00000598)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA0, 0x05, 0x00");       // Character - 54, offset (0x000005A0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA8, 0x05, 0x00");       // Character - 55, offset (0x000005A8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB0, 0x05, 0x00");       // Character - 56, offset (0x000005B0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB8, 0x05, 0x00");       // Character - 57, offset (0x000005B8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xC0, 0x05, 0x00");       // Character - 58, offset (0x000005C0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xC8, 0x05, 0x00");       // Character - 59, offset (0x000005C8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xD0, 0x05, 0x00");       // Character - 60, offset (0x000005D0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xD8, 0x05, 0x00");       // Character - 61, offset (0x000005D8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE0, 0x05, 0x00");       // Character - 62, offset (0x000005E0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE8, 0x05, 0x00");       // Character - 63, offset (0x000005E8)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xF0, 0x05, 0x00");       // Character - 64, offset (0x000005F0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xF8, 0x05, 0x00");       // Character - 65, offset (0x000005F8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x00, 0x06, 0x00");       // Character - 66, offset (0x00000600)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x08, 0x06, 0x00");       // Character - 67, offset (0x00000608)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x10, 0x06, 0x00");       // Character - 68, offset (0x00000610)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x18, 0x06, 0x00");       // Character - 69, offset (0x00000618)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x20, 0x06, 0x00");       // Character - 70, offset (0x00000620)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x28, 0x06, 0x00");       // Character - 71, offset (0x00000628)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x30, 0x06, 0x00");       // Character - 72, offset (0x00000630)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x38, 0x06, 0x00");       // Character - 73, offset (0x00000638)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x40, 0x06, 0x00");       // Character - 74, offset (0x00000640)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x06, 0x00");       // Character - 75, offset (0x00000648)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x50, 0x06, 0x00");       // Character - 76, offset (0x00000650)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x58, 0x06, 0x00");       // Character - 77, offset (0x00000658)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x60, 0x06, 0x00");       // Character - 78, offset (0x00000660)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x68, 0x06, 0x00");       // Character - 79, offset (0x00000668)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x70, 0x06, 0x00");       // Character - 80, offset (0x00000670)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x78, 0x06, 0x00");       // Character - 81, offset (0x00000678)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x80, 0x06, 0x00");       // Character - 82, offset (0x00000680)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x88, 0x06, 0x00");       // Character - 83, offset (0x00000688)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x90, 0x06, 0x00");       // Character - 84, offset (0x00000690)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x98, 0x06, 0x00");       // Character - 85, offset (0x00000698)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA0, 0x06, 0x00");       // Character - 86, offset (0x000006A0)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xA8, 0x06, 0x00");       // Character - 87, offset (0x000006A8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB0, 0x06, 0x00");       // Character - 88, offset (0x000006B0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB8, 0x06, 0x00");       // Character - 89, offset (0x000006B8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xC0, 0x06, 0x00");       // Character - 90, offset (0x000006C0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xC8, 0x06, 0x00");       // Character - 91, offset (0x000006C8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xD0, 0x06, 0x00");       // Character - 92, offset (0x000006D0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xD8, 0x06, 0x00");       // Character - 93, offset (0x000006D8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE0, 0x06, 0x00");       // Character - 94, offset (0x000006E0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xE8, 0x06, 0x00");       // Character - 95, offset (0x000006E8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xF0, 0x06, 0x00");       // Character - 96, offset (0x000006F0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xF8, 0x06, 0x00");       // Character - 97, offset (0x000006F8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x00, 0x07, 0x00");       // Character - 98, offset (0x00000700)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x08, 0x07, 0x00");       // Character - 99, offset (0x00000708)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x10, 0x07, 0x00");       // Character - 100, offset (0x00000710)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x18, 0x07, 0x00");       // Character - 101, offset (0x00000718)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x20, 0x07, 0x00");       // Character - 102, offset (0x00000720)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x28, 0x07, 0x00");       // Character - 103, offset (0x00000728)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x30, 0x07, 0x00");       // Character - 104, offset (0x00000730)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x38, 0x07, 0x00");       // Character - 105, offset (0x00000738)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x40, 0x07, 0x00");       // Character - 106, offset (0x00000740)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x07, 0x00");       // Character - 107, offset (0x00000748)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x50, 0x07, 0x00");       // Character - 108, offset (0x00000750)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x58, 0x07, 0x00");       // Character - 109, offset (0x00000758)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x60, 0x07, 0x00");       // Character - 110, offset (0x00000760)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x68, 0x07, 0x00");       // Character - 111, offset (0x00000768)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x70, 0x07, 0x00");       // Character - 112, offset (0x00000770)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x78, 0x07, 0x00");       // Character - 113, offset (0x00000778)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x80, 0x07, 0x00");       // Character - 114, offset (0x00000780)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x88, 0x07, 0x00");       // Character - 115, offset (0x00000788)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x90, 0x07, 0x00");       // Character - 116, offset (0x00000790)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x98, 0x07, 0x00");       // Character - 117, offset (0x00000798)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA0, 0x07, 0x00");       // Character - 118, offset (0x000007A0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xA8, 0x07, 0x00");       // Character - 119, offset (0x000007A8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB0, 0x07, 0x00");       // Character - 120, offset (0x000007B0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB8, 0x07, 0x00");       // Character - 121, offset (0x000007B8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xC0, 0x07, 0x00");       // Character - 122, offset (0x000007C0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xC8, 0x07, 0x00");       // Character - 123, offset (0x000007C8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xD0, 0x07, 0x00");       // Character - 124, offset (0x000007D0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xD8, 0x07, 0x00");       // Character - 125, offset (0x000007D8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE0, 0x07, 0x00");       // Character - 126, offset (0x000007E0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xE8, 0x07, 0x00");       // Character - 127, offset (0x000007E8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xF0, 0x07, 0x00");       // Character - 128, offset (0x000007F0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xF8, 0x07, 0x00");       // Character - 129, offset (0x000007F8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x00, 0x08, 0x00");       // Character - 130, offset (0x00000800)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x08, 0x08, 0x00");       // Character - 131, offset (0x00000808)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x10, 0x08, 0x00");       // Character - 132, offset (0x00000810)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x18, 0x08, 0x00");       // Character - 133, offset (0x00000818)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x20, 0x08, 0x00");       // Character - 134, offset (0x00000820)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x28, 0x08, 0x00");       // Character - 135, offset (0x00000828)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x30, 0x08, 0x00");       // Character - 136, offset (0x00000830)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x38, 0x08, 0x00");       // Character - 137, offset (0x00000838)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x40, 0x08, 0x00");       // Character - 138, offset (0x00000840)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x48, 0x08, 0x00");       // Character - 139, offset (0x00000848)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x50, 0x08, 0x00");       // Character - 140, offset (0x00000850)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x58, 0x08, 0x00");       // Character - 141, offset (0x00000858)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x60, 0x08, 0x00");       // Character - 142, offset (0x00000860)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x68, 0x08, 0x00");       // Character - 143, offset (0x00000868)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x70, 0x08, 0x00");       // Character - 144, offset (0x00000870)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x78, 0x08, 0x00");       // Character - 145, offset (0x00000878)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x80, 0x08, 0x00");       // Character - 146, offset (0x00000880)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x88, 0x08, 0x00");       // Character - 147, offset (0x00000888)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x90, 0x08, 0x00");       // Character - 148, offset (0x00000890)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x98, 0x08, 0x00");       // Character - 149, offset (0x00000898)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xA0, 0x08, 0x00");       // Character - 150, offset (0x000008A0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xA8, 0x08, 0x00");       // Character - 151, offset (0x000008A8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xB0, 0x08, 0x00");       // Character - 152, offset (0x000008B0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xB8, 0x08, 0x00");       // Character - 153, offset (0x000008B8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xC0, 0x08, 0x00");       // Character - 154, offset (0x000008C0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xC8, 0x08, 0x00");       // Character - 155, offset (0x000008C8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xD0, 0x08, 0x00");       // Character - 156, offset (0x000008D0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xD8, 0x08, 0x00");       // Character - 157, offset (0x000008D8)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xE0, 0x08, 0x00");       // Character - 158, offset (0x000008E0)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xE8, 0x08, 0x00");       // Character - 159, offset (0x000008E8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xF0, 0x08, 0x00");       // Character - 160, offset (0x000008F0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xF8, 0x08, 0x00");       // Character - 161, offset (0x000008F8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x00, 0x09, 0x00");       // Character - 162, offset (0x00000900)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x08, 0x09, 0x00");       // Character - 163, offset (0x00000908)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x10, 0x09, 0x00");       // Character - 164, offset (0x00000910)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x18, 0x09, 0x00");       // Character - 165, offset (0x00000918)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x20, 0x09, 0x00");       // Character - 166, offset (0x00000920)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x28, 0x09, 0x00");       // Character - 167, offset (0x00000928)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x30, 0x09, 0x00");       // Character - 168, offset (0x00000930)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x38, 0x09, 0x00");       // Character - 169, offset (0x00000938)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x40, 0x09, 0x00");       // Character - 170, offset (0x00000940)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x09, 0x00");       // Character - 171, offset (0x00000948)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x50, 0x09, 0x00");       // Character - 172, offset (0x00000950)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x58, 0x09, 0x00");       // Character - 173, offset (0x00000958)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x60, 0x09, 0x00");       // Character - 174, offset (0x00000960)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x68, 0x09, 0x00");       // Character - 175, offset (0x00000968)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x70, 0x09, 0x00");       // Character - 176, offset (0x00000970)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x78, 0x09, 0x00");       // Character - 177, offset (0x00000978)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x80, 0x09, 0x00");       // Character - 178, offset (0x00000980)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x88, 0x09, 0x00");       // Character - 179, offset (0x00000988)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x90, 0x09, 0x00");       // Character - 180, offset (0x00000990)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x98, 0x09, 0x00");       // Character - 181, offset (0x00000998)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xA0, 0x09, 0x00");       // Character - 182, offset (0x000009A0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xA8, 0x09, 0x00");       // Character - 183, offset (0x000009A8)
asm(".byte 0x01");              // width of the glyph
asm(".byte 0xB0, 0x09, 0x00");       // Character - 184, offset (0x000009B0)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xB8, 0x09, 0x00");       // Character - 185, offset (0x000009B8)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xC0, 0x09, 0x00");       // Character - 186, offset (0x000009C0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xC8, 0x09, 0x00");       // Character - 187, offset (0x000009C8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xD0, 0x09, 0x00");       // Character - 188, offset (0x000009D0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xD8, 0x09, 0x00");       // Character - 189, offset (0x000009D8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xE0, 0x09, 0x00");       // Character - 190, offset (0x000009E0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE8, 0x09, 0x00");       // Character - 191, offset (0x000009E8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xF0, 0x09, 0x00");       // Character - 192, offset (0x000009F0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xF8, 0x09, 0x00");       // Character - 193, offset (0x000009F8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x00, 0x0A, 0x00");       // Character - 194, offset (0x00000A00)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x08, 0x0A, 0x00");       // Character - 195, offset (0x00000A08)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x10, 0x0A, 0x00");       // Character - 196, offset (0x00000A10)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x18, 0x0A, 0x00");       // Character - 197, offset (0x00000A18)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x20, 0x0A, 0x00");       // Character - 198, offset (0x00000A20)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x28, 0x0A, 0x00");       // Character - 199, offset (0x00000A28)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x30, 0x0A, 0x00");       // Character - 200, offset (0x00000A30)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x38, 0x0A, 0x00");       // Character - 201, offset (0x00000A38)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x40, 0x0A, 0x00");       // Character - 202, offset (0x00000A40)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x0A, 0x00");       // Character - 203, offset (0x00000A48)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x50, 0x0A, 0x00");       // Character - 204, offset (0x00000A50)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x58, 0x0A, 0x00");       // Character - 205, offset (0x00000A58)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x60, 0x0A, 0x00");       // Character - 206, offset (0x00000A60)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x68, 0x0A, 0x00");       // Character - 207, offset (0x00000A68)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x70, 0x0A, 0x00");       // Character - 208, offset (0x00000A70)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x78, 0x0A, 0x00");       // Character - 209, offset (0x00000A78)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x80, 0x0A, 0x00");       // Character - 210, offset (0x00000A80)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x88, 0x0A, 0x00");       // Character - 211, offset (0x00000A88)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x90, 0x0A, 0x00");       // Character - 212, offset (0x00000A90)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x98, 0x0A, 0x00");       // Character - 213, offset (0x00000A98)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xA0, 0x0A, 0x00");       // Character - 214, offset (0x00000AA0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA8, 0x0A, 0x00");       // Character - 215, offset (0x00000AA8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xB0, 0x0A, 0x00");       // Character - 216, offset (0x00000AB0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xB8, 0x0A, 0x00");       // Character - 217, offset (0x00000AB8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xC0, 0x0A, 0x00");       // Character - 218, offset (0x00000AC0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xC8, 0x0A, 0x00");       // Character - 219, offset (0x00000AC8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xD0, 0x0A, 0x00");       // Character - 220, offset (0x00000AD0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xD8, 0x0A, 0x00");       // Character - 221, offset (0x00000AD8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE0, 0x0A, 0x00");       // Character - 222, offset (0x00000AE0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xE8, 0x0A, 0x00");       // Character - 223, offset (0x00000AE8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xF0, 0x0A, 0x00");       // Character - 224, offset (0x00000AF0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xF8, 0x0A, 0x00");       // Character - 225, offset (0x00000AF8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x00, 0x0B, 0x00");       // Character - 226, offset (0x00000B00)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x08, 0x0B, 0x00");       // Character - 227, offset (0x00000B08)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x10, 0x0B, 0x00");       // Character - 228, offset (0x00000B10)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x18, 0x0B, 0x00");       // Character - 229, offset (0x00000B18)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x20, 0x0B, 0x00");       // Character - 230, offset (0x00000B20)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x28, 0x0B, 0x00");       // Character - 231, offset (0x00000B28)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x30, 0x0B, 0x00");       // Character - 232, offset (0x00000B30)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x38, 0x0B, 0x00");       // Character - 233, offset (0x00000B38)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x40, 0x0B, 0x00");       // Character - 234, offset (0x00000B40)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x48, 0x0B, 0x00");       // Character - 235, offset (0x00000B48)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x50, 0x0B, 0x00");       // Character - 236, offset (0x00000B50)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x58, 0x0B, 0x00");       // Character - 237, offset (0x00000B58)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x60, 0x0B, 0x00");       // Character - 238, offset (0x00000B60)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x68, 0x0B, 0x00");       // Character - 239, offset (0x00000B68)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x70, 0x0B, 0x00");       // Character - 240, offset (0x00000B70)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x78, 0x0B, 0x00");       // Character - 241, offset (0x00000B78)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x80, 0x0B, 0x00");       // Character - 242, offset (0x00000B80)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x88, 0x0B, 0x00");       // Character - 243, offset (0x00000B88)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x90, 0x0B, 0x00");       // Character - 244, offset (0x00000B90)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x98, 0x0B, 0x00");       // Character - 245, offset (0x00000B98)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA0, 0x0B, 0x00");       // Character - 246, offset (0x00000BA0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xA8, 0x0B, 0x00");       // Character - 247, offset (0x00000BA8)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xB0, 0x0B, 0x00");       // Character - 248, offset (0x00000BB0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xB8, 0x0B, 0x00");       // Character - 249, offset (0x00000BB8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xC0, 0x0B, 0x00");       // Character - 250, offset (0x00000BC0)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xC8, 0x0B, 0x00");       // Character - 251, offset (0x00000BC8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xD0, 0x0B, 0x00");       // Character - 252, offset (0x00000BD0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xD8, 0x0B, 0x00");       // Character - 253, offset (0x00000BD8)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xE0, 0x0B, 0x00");       // Character - 254, offset (0x00000BE0)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE8, 0x0B, 0x00");       // Character - 255, offset (0x00000BE8)
/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 0
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 1
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 2
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 3
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 4
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 5
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 6
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 7
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 8
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 9
 ***********************************/
// This character does not contain any raster information

/***********************************
 * Character - 10
 ***********************************/
// This character does not contain any raster information

/***********************************
 * Character - 11
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 12
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 13
 ***********************************/
// This character does not contain any raster information

/***********************************
 * Character - 14
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 15
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 16
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 17
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 18
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 19
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 20
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 21
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 22
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 23
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 24
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 25
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 26
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 27
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 28
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 29
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 30
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 31
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 32
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 33
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 34
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 35
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 36
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 37
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x0D");        // * **    
asm(".byte 0x16");        //  ** *   
asm(".byte 0x1E");        //  ****   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 38
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x0D");        // * **    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 39
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 40
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 41
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 42
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 43
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 44
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 45
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 46
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 47
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 48
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 49
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 50
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 51
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 52
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 53
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x03");        // **      
asm(".byte 0x04");        //   *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 54
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 55
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 56
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 57
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 58
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 59
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 60
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 61
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 62
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 63
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 64
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0E");        //  ***    
asm(".byte 0x1F");        // *****   
asm(".byte 0x1B");        // ** **   
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         

/***********************************
 * Character - 65
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 66
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 67
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 68
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 69
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 70
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 71
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x01");        // *       
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 72
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 73
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 74
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 75
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 76
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 77
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x12");        //  *  *   
asm(".byte 0x1A");        //  * **   
asm(".byte 0x16");        //  ** *   
asm(".byte 0x14");        //   * *   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 78
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 79
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 80
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 81
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         

/***********************************
 * Character - 82
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 83
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 84
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 85
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 86
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 87
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x15");        // * * *   
asm(".byte 0x17");        // *** *   
asm(".byte 0x1B");        // ** **   
asm(".byte 0x0A");        //  * *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 88
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 89
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 90
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 91
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 92
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 93
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 94
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 95
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      

/***********************************
 * Character - 96
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 97
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 98
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 99
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 100
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x04");        //   *     
asm(".byte 0x04");        //   *     
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 101
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 102
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 103
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         

/***********************************
 * Character - 104
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 105
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 106
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 107
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 108
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 109
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x1E");        //  ****   
asm(".byte 0x16");        //  ** *   
asm(".byte 0x14");        //   * *   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 110
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 111
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 112
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 113
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         

/***********************************
 * Character - 114
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 115
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 116
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 117
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 118
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 119
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x0B");        // ** *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 120
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 121
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 122
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 123
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 124
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 125
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 126
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 127
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 128
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 129
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 130
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 131
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 132
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 133
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 134
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 135
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 136
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 137
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 138
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 139
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 140
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 141
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 142
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 143
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 144
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 145
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 146
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 147
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 148
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 149
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 150
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 151
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 152
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 153
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 154
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 155
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 156
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 157
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 158
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 159
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 160
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 161
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 162
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 163
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 164
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 165
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 166
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 167
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 168
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 169
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x13");        // **  *   
asm(".byte 0x13");        // **  *   
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 170
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 171
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x04");        //   *     
asm(".byte 0x03");        // **      
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 172
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 173
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 174
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x17");        // *** *   
asm(".byte 0x17");        // *** *   
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 175
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 176
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 177
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 178
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 179
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 180
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 181
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 182
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 183
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 184
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 185
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 186
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 187
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 188
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x04");        //   *     
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 189
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x04");        //   *     
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 190
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 191
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         

/***********************************
 * Character - 192
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 193
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 194
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 195
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 196
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 197
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 198
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0E");        //  ***    
asm(".byte 0x06");        //  **     
asm(".byte 0x0E");        //  ***    
asm(".byte 0x0D");        // * **    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 199
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         

/***********************************
 * Character - 200
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 201
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 202
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 203
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 204
 ***********************************/
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 205
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 206
 ***********************************/
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 207
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 208
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 209
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 210
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 211
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 212
 ***********************************/
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 213
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 214
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 215
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 216
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x0D");        // * **    
asm(".byte 0x0B");        // ** *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 217
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 218
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 219
 ***********************************/
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 220
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 221
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 222
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 223
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 224
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 225
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 226
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 227
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 228
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 229
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 230
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x1E");        //  ****   
asm(".byte 0x1F");        // *****   
asm(".byte 0x1F");        // *****   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 231
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x05");        // * *     
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 232
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 233
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 234
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 235
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 236
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 237
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 238
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 239
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 240
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x04");        //   *     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 241
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 242
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 243
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 244
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 245
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 246
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 247
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 248
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 249
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 250
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 251
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 252
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 253
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

/***********************************
 * Character - 254
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 255
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x03");        // **      
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         

asm(".section .const, psv, page");
