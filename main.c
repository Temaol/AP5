
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

void Print(int, ...);
int ReturnDe(char* str);

int main()
{
    char a[30], b[30], c[30];
    puts("Введіть ваші пятіркові числа");
    gets(a);
    gets(b);
    gets(c);
    Print(3, a, b, c);

    getchar();
    getchar();
    return 0;
}

void Print(int kst, ...)            //#include<stdarg.h>
{
    va_list vl;
    char* str;
    int num;
    va_start(vl, kst);
    for (int i = 0; i < kst; i++) {
        puts("");
        str = va_arg(vl, char*);
        num = ReturnDe(str);
        printf("\n%s - ", str);
        if (num == -1)
            printf("error");
        else
            printf("%d", num);
    }
    va_end(vl);
}

int ReturnDe(char* str)
{
    char* p = str;
    int num = 0;
    while (*p != '\0')
    {
        num *= 5;
        if (*p == '0')
            num += 0;
        else if (*p == '1')
            num += 1;
        else if (*p == '2')
            num += 2;
        else if (*p == '3')
            num += 3;
        else if (*p == '4')
            num += 4;
        else
            return -1;
        p++;
    }
    return num;
}
