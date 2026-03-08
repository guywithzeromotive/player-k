#include <stdio.h>

#include "../include/utils.h"
int main() {

    Window_Dimensions dimensions = get_tty_dimensions();
    printf("width : %d , height : %d\n\n" , dimensions.tty_width , dimensions.tty_height);
    return 0;
}