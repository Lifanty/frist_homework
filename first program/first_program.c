#include <stdio.h>

int main(void)
 {
    /* Все переменные объявляем в начале блока */
    char filename[] = "numbers.txt";
    FILE *file;
    int a[1000];
    int n;
    int possible;
    int skip, j;
    int all_equal;
    int first_val;
    int found_first;

    n = 0;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Ошибка: файл не найден\n");
        return 1;
    }

    while (fscanf(file, "%d", &a[n]) == 1) {
        n++;
        if (n >= 1000) {
            break;
        }
    }

    fclose(file);

    if (n == 0) {
        printf("Чисел нет\n");
        return 0;
    }

    if (n <= 2) {
        printf("Верно для любых чисел, в количестве меньше 2\n");
        return 0;
    }

    possible = 0;

    for (skip = 0; skip < n; skip++) {
        all_equal = 1;
        first_val = 0;
        found_first = 0;

        for (j = 0; j < n; j++) {
            if (j == skip) {
                continue;
            }

            if (!found_first) {
                first_val = a[j];
                found_first = 1;
            } else {
                if (a[j] != first_val) {
                    all_equal = 0;
                    break;
                }
            }
        }

        if (all_equal) {
            possible = 1;
            break;
        }
    }

    if (possible) {
        printf("Можно\n");
    } else {
        printf("Нельзя\n");
    }

    return 0;
}