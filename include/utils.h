//
// Created by zero on 3/8/26.
//
#ifndef V_ANSI_UTILS_H
#define V_ANSI_UTILS_H

typedef struct { int tty_width; int tty_height; } Window_Dimensions;
extern Window_Dimensions get_tty_dimensions();

#endif //V_ANSI_UTILS_H