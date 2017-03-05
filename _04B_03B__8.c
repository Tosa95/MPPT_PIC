/*****************************************************************************
 * FileName:        _04B_03B__8.c
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
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
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
 * _04B_03B__8 - Height: 8 pixels, 1 bit per pixel, Range: ' ' to '~'
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * TTF Font File Structure
 * Label: _04B_03B__8
 * Description:  Height: 8 pixels, 1 bit per pixel, Range: ' ' to '~'
 ***********************************/
#ifdef USE_GFX_FONT_IN_PROGRAM_SECTION
extern GFX_FONT_SPACE char ___04B_03B__8[] __attribute__((section("grc_text"), aligned(2)));
#else
extern GFX_FONT_SPACE char ___04B_03B__8[] __attribute__((aligned(2)));
#endif

const FONT_FLASH _04B_03B__8 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)___04B_03B__8
};

#ifdef USE_GFX_FONT_IN_PROGRAM_SECTION
asm(".section grc_text, code");
#else
asm(".section .const, psv, page");
#endif
asm(".global ____04B_03B__8");
asm(".align 2");
asm("____04B_03B__8:");
/****************************************
 * Font header
 ****************************************/
asm(".byte 0x00");           // Font ID
asm(".byte 0x00");           // Font information:  1 bit per pixel, Characters zero degress rotation
asm(".byte 0x20, 0x00");     // First Character
asm(".byte 0x7E, 0x00");     // Last Character
asm(".byte 0x08, 0x00");     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x84, 0x01, 0x00");       // Character - 32, offset (0x00000184)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x8C, 0x01, 0x00");       // Character - 33, offset (0x0000018C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x94, 0x01, 0x00");       // Character - 34, offset (0x00000194)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x9C, 0x01, 0x00");       // Character - 35, offset (0x0000019C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xA4, 0x01, 0x00");       // Character - 36, offset (0x000001A4)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xAC, 0x01, 0x00");       // Character - 37, offset (0x000001AC)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xB4, 0x01, 0x00");       // Character - 38, offset (0x000001B4)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xBC, 0x01, 0x00");       // Character - 39, offset (0x000001BC)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xC4, 0x01, 0x00");       // Character - 40, offset (0x000001C4)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xCC, 0x01, 0x00");       // Character - 41, offset (0x000001CC)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xD4, 0x01, 0x00");       // Character - 42, offset (0x000001D4)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xDC, 0x01, 0x00");       // Character - 43, offset (0x000001DC)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0xE4, 0x01, 0x00");       // Character - 44, offset (0x000001E4)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xEC, 0x01, 0x00");       // Character - 45, offset (0x000001EC)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xF4, 0x01, 0x00");       // Character - 46, offset (0x000001F4)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xFC, 0x01, 0x00");       // Character - 47, offset (0x000001FC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x04, 0x02, 0x00");       // Character - 48, offset (0x00000204)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x0C, 0x02, 0x00");       // Character - 49, offset (0x0000020C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x14, 0x02, 0x00");       // Character - 50, offset (0x00000214)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x1C, 0x02, 0x00");       // Character - 51, offset (0x0000021C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x24, 0x02, 0x00");       // Character - 52, offset (0x00000224)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x2C, 0x02, 0x00");       // Character - 53, offset (0x0000022C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x34, 0x02, 0x00");       // Character - 54, offset (0x00000234)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x3C, 0x02, 0x00");       // Character - 55, offset (0x0000023C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x44, 0x02, 0x00");       // Character - 56, offset (0x00000244)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x4C, 0x02, 0x00");       // Character - 57, offset (0x0000024C)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x54, 0x02, 0x00");       // Character - 58, offset (0x00000254)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x5C, 0x02, 0x00");       // Character - 59, offset (0x0000025C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x64, 0x02, 0x00");       // Character - 60, offset (0x00000264)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x6C, 0x02, 0x00");       // Character - 61, offset (0x0000026C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x74, 0x02, 0x00");       // Character - 62, offset (0x00000274)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x7C, 0x02, 0x00");       // Character - 63, offset (0x0000027C)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x84, 0x02, 0x00");       // Character - 64, offset (0x00000284)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x8C, 0x02, 0x00");       // Character - 65, offset (0x0000028C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x94, 0x02, 0x00");       // Character - 66, offset (0x00000294)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x9C, 0x02, 0x00");       // Character - 67, offset (0x0000029C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xA4, 0x02, 0x00");       // Character - 68, offset (0x000002A4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xAC, 0x02, 0x00");       // Character - 69, offset (0x000002AC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xB4, 0x02, 0x00");       // Character - 70, offset (0x000002B4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xBC, 0x02, 0x00");       // Character - 71, offset (0x000002BC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xC4, 0x02, 0x00");       // Character - 72, offset (0x000002C4)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0xCC, 0x02, 0x00");       // Character - 73, offset (0x000002CC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xD4, 0x02, 0x00");       // Character - 74, offset (0x000002D4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xDC, 0x02, 0x00");       // Character - 75, offset (0x000002DC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xE4, 0x02, 0x00");       // Character - 76, offset (0x000002E4)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xEC, 0x02, 0x00");       // Character - 77, offset (0x000002EC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xF4, 0x02, 0x00");       // Character - 78, offset (0x000002F4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xFC, 0x02, 0x00");       // Character - 79, offset (0x000002FC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x04, 0x03, 0x00");       // Character - 80, offset (0x00000304)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x0C, 0x03, 0x00");       // Character - 81, offset (0x0000030C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x14, 0x03, 0x00");       // Character - 82, offset (0x00000314)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x1C, 0x03, 0x00");       // Character - 83, offset (0x0000031C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x24, 0x03, 0x00");       // Character - 84, offset (0x00000324)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x2C, 0x03, 0x00");       // Character - 85, offset (0x0000032C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x34, 0x03, 0x00");       // Character - 86, offset (0x00000334)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x3C, 0x03, 0x00");       // Character - 87, offset (0x0000033C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x44, 0x03, 0x00");       // Character - 88, offset (0x00000344)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x4C, 0x03, 0x00");       // Character - 89, offset (0x0000034C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x54, 0x03, 0x00");       // Character - 90, offset (0x00000354)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x5C, 0x03, 0x00");       // Character - 91, offset (0x0000035C)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x64, 0x03, 0x00");       // Character - 92, offset (0x00000364)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x6C, 0x03, 0x00");       // Character - 93, offset (0x0000036C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x74, 0x03, 0x00");       // Character - 94, offset (0x00000374)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x7C, 0x03, 0x00");       // Character - 95, offset (0x0000037C)
asm(".byte 0x03");              // width of the glyph
asm(".byte 0x84, 0x03, 0x00");       // Character - 96, offset (0x00000384)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x8C, 0x03, 0x00");       // Character - 97, offset (0x0000038C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x94, 0x03, 0x00");       // Character - 98, offset (0x00000394)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x9C, 0x03, 0x00");       // Character - 99, offset (0x0000039C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xA4, 0x03, 0x00");       // Character - 100, offset (0x000003A4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xAC, 0x03, 0x00");       // Character - 101, offset (0x000003AC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xB4, 0x03, 0x00");       // Character - 102, offset (0x000003B4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xBC, 0x03, 0x00");       // Character - 103, offset (0x000003BC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xC4, 0x03, 0x00");       // Character - 104, offset (0x000003C4)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xCC, 0x03, 0x00");       // Character - 105, offset (0x000003CC)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xD4, 0x03, 0x00");       // Character - 106, offset (0x000003D4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xDC, 0x03, 0x00");       // Character - 107, offset (0x000003DC)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0xE4, 0x03, 0x00");       // Character - 108, offset (0x000003E4)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0xEC, 0x03, 0x00");       // Character - 109, offset (0x000003EC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xF4, 0x03, 0x00");       // Character - 110, offset (0x000003F4)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0xFC, 0x03, 0x00");       // Character - 111, offset (0x000003FC)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x04, 0x04, 0x00");       // Character - 112, offset (0x00000404)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x0C, 0x04, 0x00");       // Character - 113, offset (0x0000040C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x14, 0x04, 0x00");       // Character - 114, offset (0x00000414)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x1C, 0x04, 0x00");       // Character - 115, offset (0x0000041C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x24, 0x04, 0x00");       // Character - 116, offset (0x00000424)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x2C, 0x04, 0x00");       // Character - 117, offset (0x0000042C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x34, 0x04, 0x00");       // Character - 118, offset (0x00000434)
asm(".byte 0x06");              // width of the glyph
asm(".byte 0x3C, 0x04, 0x00");       // Character - 119, offset (0x0000043C)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x44, 0x04, 0x00");       // Character - 120, offset (0x00000444)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x4C, 0x04, 0x00");       // Character - 121, offset (0x0000044C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x54, 0x04, 0x00");       // Character - 122, offset (0x00000454)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x5C, 0x04, 0x00");       // Character - 123, offset (0x0000045C)
asm(".byte 0x02");              // width of the glyph
asm(".byte 0x64, 0x04, 0x00");       // Character - 124, offset (0x00000464)
asm(".byte 0x04");              // width of the glyph
asm(".byte 0x6C, 0x04, 0x00");       // Character - 125, offset (0x0000046C)
asm(".byte 0x05");              // width of the glyph
asm(".byte 0x74, 0x04, 0x00");       // Character - 126, offset (0x00000474)
/***********************************
 * Font Characters
 ***********************************/
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
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 34
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 35
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0A");        //  * *    
asm(".byte 0x1F");        // *****   
asm(".byte 0x0A");        //  * *    
asm(".byte 0x1F");        // *****   
asm(".byte 0x0A");        //  * *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 36
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0E");        //  ***    
asm(".byte 0x05");        // * *     
asm(".byte 0x0F");        // ****    
asm(".byte 0x0A");        //  * *    
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 37
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x13");        // **  *   
asm(".byte 0x0B");        // ** *    
asm(".byte 0x04");        //   *     
asm(".byte 0x1A");        //  * **   
asm(".byte 0x19");        // *  **   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 38
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x01");        // *       
asm(".byte 0x1F");        // *****   
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 39
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
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
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 41
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 42
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 43
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x07");        // ***     
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
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 45
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
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
asm(".byte 0x10");        //     *   
asm(".byte 0x08");        //    *    
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 48
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 49
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 50
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 51
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 52
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 53
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 54
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 55
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 56
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 57
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 58
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 59
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 60
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 61
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 62
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 63
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 64
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x1F");        // *****   
asm(".byte 0x11");        // *   *   
asm(".byte 0x1D");        // * ***   
asm(".byte 0x15");        // * * *   
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 65
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 66
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x05");        // * *     
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 67
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 68
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 69
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 70
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 71
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0D");        // * **    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 72
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 73
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 74
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0C");        //   **    
asm(".byte 0x08");        //    *    
asm(".byte 0x08");        //    *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 75
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x07");        // ***     
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 76
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 77
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x1F");        // *****   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 78
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x0B");        // ** *    
asm(".byte 0x0D");        // * **    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 79
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 80
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 81
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0D");        // * **    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 82
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x05");        // * *     
asm(".byte 0x0D");        // * **    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 83
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 84
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
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
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 86
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x05");        // * *     
asm(".byte 0x05");        // * *     
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 87
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x1F");        // *****   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 88
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x06");        //  **     
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 89
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 90
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x06");        //  **     
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 91
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 92
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x08");        //    *    
asm(".byte 0x10");        //     *   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 93
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 94
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
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
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 96
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
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
asm(".byte 0x0E");        //  ***    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 98
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 99
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x01");        // *       
asm(".byte 0x07");        // ***     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 100
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x08");        //    *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 101
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x05");        // * *     
asm(".byte 0x0E");        //  ***    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 102
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0E");        //  ***    
asm(".byte 0x02");        //  *      
asm(".byte 0x0F");        // ****    
asm(".byte 0x02");        //  *      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 103
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x04");        //   *     
asm(".byte 0x00");        //         

/***********************************
 * Character - 104
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 105
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 106
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
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
asm(".byte 0x01");        // *       
asm(".byte 0x09");        // *  *    
asm(".byte 0x07");        // ***     
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 108
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
 * Character - 109
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x1F");        // *****   
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 110
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 111
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 112
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         

/***********************************
 * Character - 113
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         

/***********************************
 * Character - 114
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x07");        // ***     
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 115
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x02");        //  *      
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 116
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x02");        //  *      
asm(".byte 0x07");        // ***     
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 117
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 118
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 119
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x15");        // * * *   
asm(".byte 0x15");        // * * *   
asm(".byte 0x1F");        // *****   
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 120
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x05");        // * *     
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
asm(".byte 0x09");        // *  *    
asm(".byte 0x09");        // *  *    
asm(".byte 0x0F");        // ****    
asm(".byte 0x08");        //    *    
asm(".byte 0x00");        //         

/***********************************
 * Character - 122
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x0F");        // ****    
asm(".byte 0x04");        //   *     
asm(".byte 0x0F");        // ****    
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 123
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x06");        //  **     
asm(".byte 0x02");        //  *      
asm(".byte 0x01");        // *       
asm(".byte 0x02");        //  *      
asm(".byte 0x06");        //  **     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 124
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x01");        // *       
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 125
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x03");        // **      
asm(".byte 0x02");        //  *      
asm(".byte 0x04");        //   *     
asm(".byte 0x02");        //  *      
asm(".byte 0x03");        // **      
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

/***********************************
 * Character - 126
 ***********************************/
asm(".byte 0x00");        //         
asm(".byte 0x0A");        //  * *    
asm(".byte 0x05");        // * *     
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         
asm(".byte 0x00");        //         

asm(".section .const, psv, page");
