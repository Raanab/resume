using namespace std;

#ifndef ESSENTIAL_H
#define ESSENTIAL_H

#define DELAYTIME   2500
#define firstLine   4

#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

char choice;
char c218=218, c210=210, c196=196, c191=191, c176=176,
    c177=177, c178=178, c179=179, c198=198, c186=186,
    c202=202, c181=181, c192=192, c217=217, c205=205,
    c195=195, c208=208, c215=215, c180=180, c193=193,
    c194=194, c203 = 203;
int y = 0;

long long unsigned int ifor = 0, jfor = 0;

void cls(){
    system("CLS");
    y = firstLine;
}
COORD coord={0,0};
void gotoxy(int x, int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void rect(int x1,int y1,int x2,int y2){
    for(ifor=x1;ifor<x2;ifor++){
        gotoxy(ifor, y1);
        cout<<c196;
        gotoxy(ifor, y2);
        cout<<c196;
    }
    for(ifor=y1;ifor<y2;ifor++){
        gotoxy(x1, ifor);
        cout<<c179;
        gotoxy(x2, ifor);
        cout<<c179;
    }
    gotoxy(x1,y1);
    cout<<c218;
    gotoxy(x1,y2);
    cout<<c192;
    gotoxy(x2,y1);
    cout<<c191;
    gotoxy(x2,y2);
    cout<<c217;
}

void rectnew(int x1, int y1, int x2, int y2){
    rect(x1, y1, x2, y2);
    for(ifor=x1+1;ifor<x2;ifor++){
        gotoxy(ifor, y1+2);
        cout<<c205;
        gotoxy(ifor, y2-2);
        cout<<c205;
    }
    for(ifor=y1+2; ifor<=y2-2; ifor++){
        gotoxy(x1+4, ifor);
        cout<<c186;
    }
    gotoxy(x1, y1+2);
    cout<<c198;
    gotoxy(x2, y1+2);
    cout<<c181;
    gotoxy(x1+4, y1+2);
    cout<<c203;
    gotoxy(x1, y2-2);
    cout<<c198;
    gotoxy(x2, y2-2);
    cout<<c181;
    gotoxy(x1+4, y2-2);
    cout<<c202;
}

template <typename T1>
void p(int x, int y, T1 t){
    gotoxy(x, y);
    cout<<t<<endl;
}

#endif // ESSENTIAL_H
