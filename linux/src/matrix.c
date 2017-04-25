#include <iostream>
#include <vector>
#include <windows>
#include <cstdio>
#include <algorithm>
#include "define.h"

using namespace std;

const int max_x = 80; //console width
const int max_y = 24; //console height
const int col1 = 10; //color code for higlighted char
const int col2 = 2; //color code for normal char
const int col3 = 0; //color code for background
const int c_min = 32; //char minimum ascii code
const int c_max = 126; //char maximum ascii code

const inline char rc(int m1, int m2) //random char
{
    return (rand()%(m2-m1))+m1;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcol(int fore, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore + back*16);
}

void clrscr()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR) ' ',
                cellCount,
                homeCoords,
                &count
            )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count
            )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

void At(char chr, int x, int y) //print char at x-y pos in console
{
    if (y>=0 && y<=max_y)
    {
        gotoxy(x,y);
        printf("%c",chr);
    }
}

class FallChar //falling char
{
public:
    int X, Y;
    char code;
    int speed;
    FallChar();
};

FallChar::FallChar()
{
    X=rand()%max_x;
    Y=0;
    code=rc(c_min,c_max);
    speed=rand()%3+1;
}

int matrix()
{
    vector<FallChar> chars;
    FallChar* cchar;

    while (1)
    {
        chars.push_back(FallChar());
        chars.push_back(FallChar());
        chars.push_back(FallChar());
        random_shuffle(chars.begin(), chars.end()); //shuffle to make flashing more equally distributed
        for (int i=0; i<chars.size(); i++)
        {
            cchar = &chars[i];
            if (cchar->Y!=max_y+4)
            {
                setcol(col1,col3);
                At(cchar->code, cchar->X, cchar->Y);
                At(rc(c_min,c_max), cchar->X, cchar->Y-1);
                setcol(col2,col3);
                At(rc(c_min,c_max), cchar->X, cchar->Y-2);
                At(rc(c_min,c_max), cchar->X, cchar->Y-3);
                At(rc(c_min,c_max), cchar->X, cchar->Y-4);
                cchar->Y+=cchar->speed;
            }
            else
            {
                chars.erase(chars.begin()+i);
                i--;
            }
        }
        Sleep(30);
        clrscr();
    }
}
