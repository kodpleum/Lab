#include <stdio.h>
#include <string.h>
// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

int main()
{
    char str[10000];
    int num = 0;
    scanf("%[a-z,A-Z,0-9]", str);
    int lenght = strlen(str);
    for (int i = 0; i < lenght; i++)
    {
        int x = str[i];
        if (x <= '9' && x >= '0')
        {
            num = num * 10 + (x - '0'); // I cannot think about it anymore. hint me plz KONGHUMYAI
        }
        if (x >= 'A')
        {
            if (num == 0)
            {
                printf("%c", x);
            }
            // for (int j = 0; j < max(n, 1); j++)
            // {
            //     printf("%c", x);
            // }
            for (int j = 0; j < num; j++)
            {
                printf("%c", x);
            }
            num = 0;
        }
    }

    return 0;
}