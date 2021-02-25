#include <stdio.h>

int showMenu () {
    int option = 0;
    char menu[256] = "1. Add new Word.\n0. Exit\n";
    printf (menu);
    scanf ("%d", &option);
    return option;
}

int main (int argc, char *argv[]) {
    int option = 0;
    do {
        option = showMenu ();
        switch (option) {
            case 1:
                printf ("Hello");
                break;
            case 0:
                printf ("Hello0000");
                break;
            default:
                printf ("No");
        }
    } while (option != 0);
}