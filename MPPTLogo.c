/*****************************************************************************
 * FileName:        MPPTLogo.c
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
 * SECTION:  Graphics Bitmap Padding Check
 *****************************************************************************/
#ifdef USE_BITMAP_NO_PADDING_LINE
#error These bitmap resources have been converted with padding of the horizontal lines, but USE_BITMAP_NO_PADDING_LINE is defined in GraphicsConfig.h.
#endif

/*****************************************************************************
 * Converted Resources
 * -------------------
 *
 * Bitmaps
 * -------
 * MPPT_1bpp - 33x48 pixels, 1-bits per pixel
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  BITMAPS
 *****************************************************************************/

/*********************************
 * Bitmap Structure
 * Label: MPPT_1bpp
 * Description:  33x48 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __MPPT_1bpp[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH MPPT_1bpp =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__MPPT_1bpp
};
asm(".section grc_images, code");
asm(".global ___MPPT_1bpp");
asm(".align 2");
asm("___MPPT_1bpp:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x30, 0x00");     // Height
asm(".byte 0x21, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE");
asm(".byte 0xFF, 0xFF, 0xFF, 0x00, 0x0E, 0xE0, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF");
asm(".byte 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF");
asm(".byte 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF");
asm(".byte 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00, 0xFE, 0xEF, 0xFF, 0xFF, 0x00");
asm(".byte 0xFE, 0x0F, 0x00, 0xE0, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE");
asm(".byte 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF");
asm(".byte 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF");
asm(".byte 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0x86, 0xC3, 0xC1");
asm(".byte 0x00, 0x66, 0x76, 0xBB, 0xF7, 0x00, 0x96, 0x76, 0xBB, 0xF7, 0x00, 0xF6, 0x76, 0xBB, 0xF7, 0x00");
asm(".byte 0xF6, 0x86, 0xC3, 0xF7, 0x00, 0xF6, 0xF6, 0xFB, 0xF7, 0x00, 0xF6, 0xF6, 0xFB, 0xF7, 0x00, 0xF6");
asm(".byte 0xF6, 0xFB, 0xF7, 0x00, 0xF6, 0xF6, 0xFB, 0xF7, 0x00, 0xF6, 0xF6, 0xFB, 0xF7, 0x00, 0xFE, 0xFF");
asm(".byte 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF");
asm(".byte 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF");
asm(".byte 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

