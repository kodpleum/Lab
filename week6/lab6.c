#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf("<-0->");
}

void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("     ");
}

void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf("^");
}

void erase_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf(" ");
}

void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
    setcursor(0);
    srand(time(NULL));
    char ch = ' ';
    int x = 38, y = 20, i = 0;
    int bulletstate[5] = {0, 0, 0, 0, 0}, bulletX[5] = {0, 0, 0, 0, 0}, bulletY[5] = {0, 0, 0, 0, 0};
    int directionleft = 0, directionright = 0;
    setcolor(2, 0);
    draw_ship(x, y);
    while (ch != 'x')
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                directionleft = 1, directionright = 0;
            }
            if (ch == 'd')
            {
                directionleft = 0, directionright = 1;
            }
            if (ch == 's')
            {
                directionleft = 0, directionright = 0;
            }
            if (ch == 'f' && bulletstate[i] == 0)
            {
                bulletX[i] = x + 3;
                bulletY[i] = y;
                bulletstate[i] = 1;
                i++;
                if (i == 5)
                {
                    i = 0;
                }
            }
            fflush(stdin);
        }
        if (directionleft == 1)
        {
            erase_ship(x, y);
            if (x > 0)
            {
                draw_ship(--x, y);
            }
            else
            {
                draw_ship(x, y);
            }
        }
        if (directionright == 1)
        {
            erase_ship(x, y);
            if (x < 80)
            {
                draw_ship(++x, y);
            }
            else
            {
                draw_ship(x, y);
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (bulletstate[j] == 1)
            {
                erase_bullet(bulletX[j], bulletY[j]);
                if (bulletY[j] > 0)
                {
                    draw_bullet(bulletX[j], --bulletY[j]);
                }
                else
                {
                    bulletstate[j] = 0;
                }
            }
        }
        Sleep(30);
    }
    return 0;
}
