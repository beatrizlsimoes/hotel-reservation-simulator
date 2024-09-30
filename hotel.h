#ifndef HOTEL_H
#define HOTEL_H

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

struct Reservation
{
    char customerName[30];
    char roomType;
    int dD, dM, dY, perDay, noOfPer, resId, noOfRoom;
    float billAmt;
};


int sR, kR, tR, totalRes;
struct Reservation sRes[90];

#endif /* HOTEL_H */
