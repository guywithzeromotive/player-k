#include <stdbool.h>
#include <stdio.h>

#include "../include/utils.h"

void test();

int main() {
    int choice;
    while (true) {
        printf("\nEntry:\n1. About V-ANSI \n2. Video Player \n3. Test \n0. Exit\n Choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Sth about me says project");
                break;
            case 2:
                printf("vid player");
                break;
            case 3:
                test();
                break;
            case 0:
                printf("Exiting...\n\n\n");
                fflush(stdout);
                return 0;
            default:
                printf("Wrong choice. Please try again.");
                fflush(stdout);
        }
    }
}

void test() {
    Window_Dimensions dimensions = get_tty_dimensions();
    printf("width : %d , height : %d\n\n" , dimensions.tty_width , dimensions.tty_height);
}
