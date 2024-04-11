// gcc -o hotel hotel.c -lncurses
// ./hotel

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void headerFooter();
char menu();
void report();
void roomAvl();
void hotelInfo();
void res();
void bill();

int sR = 10, kR = 20, tR = 30, totalRes = 0;

struct Reservation
{
    char customerName[30], roomType;
    int dD, dM, dY, perDay, noOfPer, resId, noOfRoom;
    float billAmt;
} sRes[90];

void headerFooter()
{
    move(5, 2);
    printf("+==========================================================+");
    move(5, 3);
    printf("|                   HOTEL  BOOKING SYSTEM                  |");
    move(5, 4);
    printf("+==========================================================+");
}

char menu()
{
    char choice;
    clear();
    headerFooter();
    printf("+--------------------------------+\n");
    printf("|       D: Data                  |\n");
    printf("|       H: Hotel Information     |\n");
    printf("|       A: Availability          |\n");
    printf("|       R: Reservation           |\n");
    printf("|       E: Exit                  |\n");
    printf("+--------------------------------+\n");
    printf("Enter your choice : ");
    scanf(" %c", &choice); // Read user input
    return choice;
}


void report()
{
    int i;
    clear();
    headerFooter();
    move(10, 5);
    if (totalRes == 0)
    {
        printf("\n No Information to Display");
    }
    else
    {
        for (i = 0; i < totalRes; i++)
        {
            printf("\n ID: %4D   Name: %s", sRes[i].resId, sRes[i].customerName);
            printf("\n Date: %d-%d  Days: %d  Room: %c", sRes[i].dD, sRes[i].dM, sRes[i].perDay, sRes[i].roomType);
            printf("\n Person: %d  Number of Room: %d  AMT: %6.0f", sRes[i].noOfPer, sRes[i].noOfRoom, sRes[i].billAmt);
            printf("\n+------------------------------------------------------------------------+\n");
        }
    }
}

void roomAvl()
{
    clear();
    headerFooter();
    move(5, 5);
    printf("Room Information: ");
    move(3, 7);
    printf("Suite: TOTAL = %d", sR);
    move(3, 8);
    printf("King: TOTAL = %d", kR);
    move(3, 9);
    printf("Travel: TOTAL = %d", tR);
}

void hotelInfo()
{
    clear();
    headerFooter();
    move(3, 6);
    printf("It is a 5-star hotel.");
    move(3, 7);
    printf("There are a total of 2 restaurants and 60 bedrooms.");
    move(3, 9);
    printf("Amenities: ");
    move(15, 9);
    printf("Wi-Fi, Telephone, 24-hour Bar, Restaurant and Room Service");
    move(3, 10);
    printf("Near by: ");
    move(15, 10);
    printf("The nearest airport is 30 minutes away");

    move(3, 13);
    printf("Room Information: ");
    move(3, 14);
    printf("+-----------+--------------------------------------+-------+");
    move(3, 15);
    printf("| Room Type |             Information              | Price |");
    move(3, 16);
    printf("+-----------+--------------------------------------+-------+");
    move(3, 17);
    printf("|   Suite   | 2Rooms, 120Sq-Mtr, Sofa and King Bed | 1000/- |");
    move(3, 18);
    printf("+-----------+--------------------------------------+-------+");
    move(3, 19);
    printf("|   King    | 60Sq-Mtr, Sofa, Table and King Bed   | 500/- |");
    move(3, 20);
    printf("+-----------+--------------------------------------+-------+");
    move(3, 21);
    printf("|   Travel  | 40Sq-Mtr, Table, Queen Bed           | 250/- |");
    move(3, 22);
    printf("------------------------------------------------------------");
}

void res()
{
    clear();
    headerFooter();
    printf("\n\nEnter your name: ");
    scanf("%29[^\n]", sRes[totalRes].customerName); 
    while(getchar() != '\n'); 
    getchar(); 
    printf("Enter Check-in Date (dd/mm/yy): ");
    scanf("%d/%d/%d", &sRes[totalRes].dD, &sRes[totalRes].dM, &sRes[totalRes].dY);
    while(getchar() != '\n'); 
    getchar(); 
    printf("Enter the number of days you will stay: ");
    scanf("%d", &sRes[totalRes].perDay);
    while(getchar() != '\n'); 
    getchar(); 
    printf("Enter room type: 's' for Suite, 'k' for King, 't' for Travel: ");
    scanf(" %c", &sRes[totalRes].roomType);
    while(getchar() != '\n');
    getchar(); 
    printf("Enter number of people: ");
    scanf("%d", &sRes[totalRes].noOfPer);
    while(getchar() != '\n'); 

    sRes[totalRes].noOfRoom = 1;
    if (sRes[totalRes].noOfPer > 3)
    {
        sRes[totalRes].noOfRoom = 1 + ((sRes[totalRes].noOfPer - 1) / 3);
    }
    bill();
}


void bill()
{
    float damt;
    char ty[10];
    switch (sRes[totalRes].roomType)
    {
    case 's':
    case 'S':
        strcpy(ty, "Suite");
        damt = 1000;
        sR = sR - (sRes[totalRes].perDay * sRes[totalRes].noOfRoom);
        break;
    case 'k':
    case 'K':
        strcpy(ty, "King");
        damt = 500;
        kR = kR - (sRes[totalRes].perDay * sRes[totalRes].noOfRoom);
        break;
    case 't':
    case 'T':
        strcpy(ty, "Travel");
        damt = 250;
        tR = tR - (sRes[totalRes].perDay * sRes[totalRes].noOfRoom);
        break;
    }
    sRes[totalRes].billAmt = sRes[totalRes].perDay * damt * sRes[totalRes].noOfRoom;

    move(3, 13);
    printf("Bill: ");
    move(3, 14);
    printf("+------------------------------------------------------------+");
    move(3, 15);
    printf("| Room Type | Total Days | Per Day | Number of Rooms | Price |");
    move(3, 16);
    printf("+------------------------------------------------------------+");
    move(3, 17);
    printf("|    %8s    |    %10d    |  %5.0f  |      %5.0d      | %8.0f |",
           ty, sRes[totalRes].perDay, damt, sRes[totalRes].noOfRoom, sRes[totalRes].billAmt);
    move(3, 18);
    printf("+------------------------------------------------------------+");
    move(3, 19);
    printf("| Total Bill:                                          %8.0f |", sRes[totalRes].billAmt);
    move(3, 20);
    printf("|____________________________________________________________|");

    // Generating a random reservation ID
    srand(time(NULL));
    sRes[totalRes].resId = rand() % 1000;
    move(3, 22);
    printf("Reservation ID = %d", sRes[totalRes].resId);
    totalRes++;
}

int main()
{
    char option;
    do
    {
        option = menu();
        printf("DEBUG: Selected option: %c\n", option); // Debug print
        switch (option)
        {
        case 'd':
        case 'D':
            report();
            break;

        case 'h':
        case 'H':
            hotelInfo();
            break;

        case 'a':
        case 'A':
            roomAvl();
            break;

        case 'r':
        case 'R':
            res();
            break;

        case 'e':
        case 'E':
            move(20, 22);
            printf("Thank you! Visit again... %c", 2);
            break;
        }
        // Clear input buffer
        while (getchar() != '\n');
    } while (option != 'e' && option != 'E');

    return 0;
}
