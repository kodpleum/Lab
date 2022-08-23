#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000];
    scanf("%[a-z,A-Z,0-9]", str);
    int num = 1, k = 0, length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        int x = str[i];
        if (x <= '9' && x >= '0')
        {
            k = k * 10 + (x - '0');
            num = k;
        }
        if (x >= 'A')
        {
            if (num == 1)
            {
                printf("%c", x);
            }
            else
            {
                for (int j = 0; j < k; j++)
                {
                    printf("%c", x);
                }
            }
            num = 1;
            k = 0;
        }
    }

    return 0;
}