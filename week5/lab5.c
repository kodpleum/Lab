#include <stdio.h>
#include <windows.h>
#include <conio.h>

void draw_ship(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("<-0->");
}

void erase_ship(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("     ");
}

int check_x(int x, char ch)
{
    if (x == 0 && ch == 'a')
    {
        return x;
    }
    if (x == 80 && ch == 'd')
    {
        return x;
    }
    if (ch == 'a')
    {
        return x - 1;
    }
    if (ch == 'd')
    {
        return x + 1;
    }
}
int check_y(int y, char ch)
{
    if (y == 0 && ch == 'w')
    {
        return y;
    }
    if (y == 50 && ch == 's')
    {
        return y;
    }
    if (ch == 'w')
    {
        return y - 1;
    }
    if (ch == 's')
    {
        return y + 1;
    }
}

int main()
{
    char ch = ' ';
    int x = 10, y = 10;
    draw_ship(x, y);
    while (ch != 'x')
    {
        if (_kbhit())
        {
            erase_ship(x, y);
            ch = _getch();
            if (ch == 'a')
            {
                x = check_x(x, ch);
                draw_ship(x, y);
            }
            if (ch == 'd')
            {
                x = check_x(x, ch);
                draw_ship(x, y);
            }
            if (ch == 'w')
            {
                y = check_y(y, ch);
                draw_ship(x, y);
            }
            if (ch == 's')
            {
                y = check_y(y, ch);
                draw_ship(x, y);
            }
            fflush(stdin);
        }
        Sleep(1);
    }
    return 0;
}