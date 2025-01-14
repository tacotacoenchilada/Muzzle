#pragma once
#ifdef MUZZLE_DEPS
    #define FONTSTASH_IMPLEMENTATION
    #define GLFONTSTASH_IMPLEMENTATION
#endif


#include <stdio.h>					// malloc, free, fopen, fclose, ftell, fseek, fread
#include <string.h>					// memset
#include "../deps/fontstash/fontstash.h"
#include "../backend.h"
#include "../deps/fontstash/glfontstash.h"
#include "Error.h"
#include "tint.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef FONScontext font_manager;
static int __fons_initialized = 0;


typedef struct font
{
    int fn;
    FONScontext* context;
} font;

// Load Font
font load_font(const char* filepath, const char* name);


/*
 * WARNING
 * =======
 *
 * Loading fonts to a font manager is no longer supported in Muzzle.
 * If you still wish to use a font manager not created by the Muzzle `load_font` API Function
 * Simply dispose of the provided font manager, and pass a pointer to a new manager to the `context`
 * struct member.
 *
 * What ever pointer is set in the `context` struct member **will** be used in text drawing operations
 *
*/


// Draw Text
void draw_text(font font_used, const char *text, float x, float y, float font_size, tint color_drawn);
void draw_text_vec2(font font_used, const char *text, vec2 pos, float font_size, tint color_drawn);

void draw_blurred_text(font font_used, const char *text, float x, float y, float intensity, float font_size, tint color_drawn);
void draw_shadow_text(font font_used, const char *text, float x, float y, tint shadow_color, float intensity, float font_size, tint color_drawn);

void draw_blurred_text_vec2(font font_used, const char *text, vec2 position, float intensity, float font_size, tint color_drawn);
void draw_shadow_text_vec2(font font_used, const char *text, vec2 position, tint shadow_color, float intensity, float font_size, tint color_drawn);

#ifdef __cplusplus
}
#endif
