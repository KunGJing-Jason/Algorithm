#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>



int main()
{
    int n;
    scanf("%d ", &n);
    while (n-- > 0)
    {
        char s1[1000];
        char s2[1000];
        getline(s1);
        gets(s2);
        int i = 0, j = 0;
        while (i < strlen(s1) && j < strlen(s2))
        {
            printf("%c", s1[i]);
            printf("%c", s2[j]);
            i++;
            j++;
        }
        while (i < strlen(s1))
        {
            printf("%c", s1[i]);
            i++;
        }
        while (j < strlen(s2))
        {
            printf("%c", s2[j]);
            j++;
        }
        printf("\n");
    }

    return 0;
}