#include <stdio.h>

int main()
{
    for (char i, num = 1, k = 0; (i = getchar()) != '\n';)
    {
        char ch = i;
        if ('0' <= ch && ch <= '9')
        {
            k = k * 10 + (ch - '0');
            num = k;
        }
        else
        {
            for (int j = 0; j < num; j++)
            {
                printf("%c", ch);
            }
            num = 1;
            k = 0;
        }
    }

    return 0;
}