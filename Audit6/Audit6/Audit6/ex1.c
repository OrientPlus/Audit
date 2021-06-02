#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <ctype.h>

int CheckSymbol(char *pswd, int n);
char strcasestr(const char* str, const char* pattern);

int main()
{
    setlocale(0, "ru");

    int n = 0, label = 0, q = 0,
        safetyPoint[4] = { 0,0,1,0 },
        database[] = { 13, 8, 35, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
       65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,
       85,86,87,88,89,90,95,45,46,44,97,98,99,100,101,102,103,104,
       105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
       120,121,122,42,47,63,64,92 };
    char dataBaseStr[][40] = { "qwerty", "qwert", "qwer", "qwe", "login", "password", "passwd", "pass" };
    char badPas;
    printf("Количество символов в пароле:");
    scanf_s("%d", &n);
    printf("\nРазрешенные симолы в пароле: ' A-Z, a-z, 0-9, -, /, @, ?, *, #, back slash; ' \n");
    char *pswd = (char*)malloc(n * sizeof(char)), c;
    do
    {
        c = _getch();
        for (int i = 0; i < 74; i++)
        {
            if ((c != database[i]) & (i==73))
            {
                printf("\nВы ввели недопустимый символ!");
                exit(1);
            }
            else if (c == database[i])
            {
                break;
            }
        }
        if ((c == 8) & (q != 0))
        {
            q--;
            printf_s("\b \b");
            continue;
        }
        if (c == 13)
        {
            label = 1;
            break;
        }
        if (c != 8 || q != 0)
        {
            printf("*");
            pswd[q] = c;
            q++;
        }
    } while (q < n);
    if (label == 0)
    {
        printf_s("\nВаш пароль:");
        for (int i = 0; i < n; i++)
        {
            printf_s("%c", pswd[i]);
        }
    }
    safetyPoint[0] = CheckSymbol(&pswd[0], n);   //one 
    if (n >= 10) safetyPoint[1] = 1;             // two 
    for (int i = 0; i < n; i++)
    {
        if (pswd[i] == (pswd[i + 1] - 1) == (pswd[i + 2] - 2))
            safetyPoint[2] = 0;                                 //three
    }
    
    for (int i = 0; i < 7; i++)
    {
        badPas = strcasestr(dataBaseStr[i], pswd);
        if (badPas == NULL)
        {
            safetyPoint[3] = 1;
        }
        else {
            printf("\nThis password is not secure! Popular sequence!\n");
            return 0;
        }
    }


    if (safetyPoint[0] + safetyPoint[1] + safetyPoint[2] + safetyPoint[3] == 5)
    {
        printf("\nYour password passed all four security checks!\n");
    }

    else if (safetyPoint[3]!=0 & safetyPoint[0]>=1 & safetyPoint[2]!=0)
        printf("\nWANING! Only part of the checks passed the password! It is recommended to change your password!\n");
    
    else 
        printf("\nDANGEROUS! Bad passorwd!\n");

    free(pswd);
    system("pause");
    return 0;
}

int CheckSymbol(char *pswd, int n)
{
    int point[4] = { 0,0,0,0 }, p=0,
        database[] = { 13, 8, 35, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
        65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,
        85,86,87,88,89,90,95,45,46,44,97,98,99,100,101,102,103,104,
        105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
        120,121,122,42,47,63,64,92 };

    for (int i = 0; i < n; i++)
    {
        if (pswd[i] > 47 & pswd[i] < 58)   //  0-9
        {
            point[0]++;
        }
        if (pswd[i] > 64 & pswd[i] < 91) // A-Z
        {
            point[1]++;
        }
        if (pswd[i] == 42 || pswd[i] == 47 || pswd[i] == 63 || pswd[i] == 64 || pswd[i] == 95 || pswd[i] == 92 || pswd[i] == 35) // ' # - / @ ? * \ '
        {
            point[2]++;
        }
        if (pswd[i] > 96 & pswd[i] < 123) // a-z
        {
            point[3]++;
        }
    }
    if (point[0] >= 2 & point[1] >= 2 & point[2] >= 2 & point[3] >= 4)
    {
        p = 2;
        return p;
    }
    else if (point[2] >= 3 & point[3] >= 5)
    {
        p = 1;
        return p;
    }
}

char strcasestr(const char* str, const char* pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper((unsigned char)*str) == toupper((unsigned char)*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper((unsigned char)str[i]) != toupper((unsigned char)pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}