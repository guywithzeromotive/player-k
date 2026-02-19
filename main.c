#include <stdio.h>
#include "colors.h"


void set_bg_rgb(int r, int g, int b) {
    printf("\033[48;2;%d;%d;%dm color \033[0m\n", r, g, b);
}

int main() {
    //Never run this cause it a war to print all the true colors out there which is technically 255^3 worth of iteration
    for (int i = 0 ; i < 256 ; i++) {
        for (int j = 0 ; j < 256 ; j++) {
            for (int k = 0 ; k < 256 ; k++) {
                set_bg_rgb(i, j, k);
            }
        }
    }
    return 0;
}
