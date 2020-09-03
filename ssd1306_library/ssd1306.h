/**
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 *
 * https://github.com/afiskon/stm32-ssd1306
 */

#ifndef __SSD1306_H__
#define __SSD1306_H__

#include <stddef.h>

//#include "stm32l4xx.h"

#include "ssd1306_fonts.h"

// un-comment your SSD1306 OLED type (this will also select correct addressing as they are not the same)
#define SSD1306_128x32
//#define SSD1306_128x64

// make sure SSD1306_128x32 or SSD1306_128x64 has been chosen
#if defined SSD1306_128x32 //
#elif defined SSD1306_128x64
#else
#error "You must define either SSD1306_128x32 or SSD1306_128x64"
#endif
#if ((defined SSD1306_128x32) && (defined SSD1306_128x64))
#error "Select only one SSD1306 size"
#endif

// SSD1306 OLED height in pixels
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT          64 	// Warning: this is just for buffer size calculation. OLED with height 32 still needs 64 defined here because of
									// different addressing mode (in page mode only every second y line is valid - for 8 bits sent only 4 bits are valid data)
#endif

// SSD1306 width in pixels
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH           128 // some LEDs don't display anything in first two columns (#define   SSD1306_WIDTH   130)
#endif

// Enumeration for screen colors
typedef enum {
    Black = 0x00, // Black color, no pixel
    White = 0x01  // Pixel is set. Color depends on OLED
} SSD1306_COLOR;

// Struct to store transformations
typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t Inverted;
    uint8_t Initialized;
} SSD1306_t;

// Procedure definitions
void ssd1306_Init(void);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_UpdateScreen(void);
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color);
void ssd1306_SetCursor(uint8_t x, uint8_t y);

// Low-level procedures
void ssd1306_Reset(void);
void ssd1306_WriteCommand(uint8_t byte);
void ssd1306_WriteData(uint8_t* buffer, size_t buff_size);

#endif // __SSD1306_H__
