#include <iostream>
#include <Windows.h>
#include <conio.h>


int main()
{

    char Complete;
    int max[2] = { 0, 0 };
    int* kmpl;
    int n, q = 0, c = 0, label = 0, flag = 0, Err=0;
    char* pswd;
    setlocale(0, "ru");
    do {
        printf("\nВведите номер задания в аудиторке:\n\t(1) - Первый номер \n\t(2) - Второй номер\n");
        scanf_s("%d", &flag);
        switch (flag)
        {
        case 2:
            printf("Количество символов в пароле:");
            scanf_s("%d", &n);
            pswd = (char*)malloc(n * sizeof(char));
            do
            {
                c = _getch();
                if ((c == 13) || (c == 8) || ((c >= 48) & (c <= 57)) || ((c >= 65) & (c <= 90)) || (c == 95) || (c == 45) || (c == 46) || (c == 44) || ((c >= 97) & (c <= 122)))
                {
                    if ((c == 8)&(q!=0))
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
                }
                else
                {
                    printf_s("\nВы ввели недопустимый символ!");
                    label = 1;
                    break;
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
            free(pswd);
            Err++;
            printf_s("\n");
            printf("Для продолжения нажмите любую клавишу. Чтобы свернуть программу, нажмите 'q'.\n");
            Complete = _getch();
            break;
        case 1:
            FILE * in;
            fopen_s(&in, "input.txt", "r");
            fscanf_s(in, "%d", &n);
            kmpl = (int*)malloc(n * 2 * sizeof(int));
            for (int i = 0; i < n * 2; i++)
            {
                fscanf_s(in, "%d", &kmpl[i]);
            }
            for (int i = 0; i < n * 2; i = i + 2)
            {
                if (kmpl[i + 1] < 0)
                {
                    printf("%d%di", kmpl[i], kmpl[i+1]);
                }
                else {
                    printf("%d + %di", kmpl[i], kmpl[i + 1]);
                }
                if (i % 2 == 0) { printf("\n"); }
            }
            for (int i = 0; i < n * 2; i++)
            {
                if (i % 2 == 0)
                {
                    if (abs(kmpl[i]) + abs(kmpl[i + 1]) > max[0] + max[1])
                    {
                        max[0] = abs(kmpl[i]);
                        max[1] = abs(kmpl[i + 1]);
                    }
                }
            }
            printf("max= %d+%di", max[0], max[1]);
            printf("\n");
            free(kmpl);
            fclose(in);
            Err++;
            printf("Для продолжения нажмите любую клавишу. Чтобы свернуть программу, нажмите 'q'.");
            Complete = _getch();
            break;
        default:
            printf("Вы ввели некорректный номер задания!\n Для продолжения нажмите любую клавишу. Чтобы свернуть программу, нажмите 'q'.");
            Complete = _getch();
            break;
        }
    } while ((Complete != 'q')&Err!=2);
    printf("\n");
    system("pause");
    return 0;
}
