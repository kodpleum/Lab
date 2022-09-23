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

void draw_star()
{
    int x, y;
    x = rand() % 71 + 10; // (10,70)
    y = rand() % 6 + 2;   // (2,5)
    setcolor(5, 0);
    gotoxy(x, y);
    printf("x");
}

void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
    {
        return '\0';
    }
    else
    {
        return buf[0];
    }
}

int main()
{
    setcursor(0);
    srand(time(NULL));
    char ch = ' ';
    int x = 38, y = 20;
    int bulletstate[5] = {0, 0, 0, 0, 0}, bulletX[5] = {0, 0, 0, 0, 0}, bulletY[5] = {0, 0, 0, 0, 0};
    int directionleft = 0, directionright = 0;
    int score = 0;
    for (int i = 0; i < 20; i++)
    {
        draw_star();
    }
    setcolor(2, 0);
    draw_ship(x, y);
    int i = 0;
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
                Beep(700, 10);
                bulletX[i] = x + 2;
                bulletY[i] = y + 1;
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
        for (int i = 0; i < 5; i++)
        {
            if (bulletstate[i] == 1)
            {
                erase_bullet(bulletX[i], bulletY[i]);
                if (bulletY[i] > 0 && cursor(bulletX[i], bulletY[i] - 1) != 'x')
                {
                    draw_bullet(bulletX[i], --bulletY[i]);
                }
                else if (cursor(bulletX[i], bulletY[i] - 1) == 'x')
                {
                    erase_bullet(bulletX[i], bulletY[i] - 1);
                    draw_star();
                    score++;
                    Beep(900, 25);
                    bulletstate[i] = 0;
                }
                else
                {
                    bulletstate[i] = 0;
                }
            }
        }
        setcolor(6, 0);
        gotoxy(90, 3);
        printf("Score : %d", score);
        Sleep(30);
    }
    return 0;
}
