// gcc -o test test.c -lncurses
// ./test

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


void res();
void report();
void hotelInfo();

char simulated_user_input[] = {
    'r', '\0', '1', '1', '/', '1', '1', '/', '1', '1', '3', 's', '2', 'd', 'h', 'e'
};

char read_next_command() {
    static int current_input_index = 0;
    char next_command = simulated_user_input[current_input_index++];
    return next_command;
}

int mainTest() {
    char option;
    do {
        option = read_next_command();
        printf("DEBUG: Selected option: %c\n", option);
        switch (option) {
            case 'r':
            case 'R':
                res();
                break;

            case 'd':
            case 'D':
                report();
                break;

            case 'h':
            case 'H':
                hotelInfo();
                break;

            case 'e':
            case 'E':
                printf("Thank you! Visit again... %c\n", 2);
                break;
        }
    } while (option != 'e' && option != 'E');

    return 0;
}
