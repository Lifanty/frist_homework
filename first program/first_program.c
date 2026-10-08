int can_be_equal_after_removing_one(FILE *f)
{
    int first_val;
    int second_val = 0;
    int has_second = 0;
    int current;
    
    int n = 0;
    int diff_count = 0;

    /* Считываем первое число */
    if (fscanf(f, "%d", &first_val) != 1)
    {
        printf("File is empty\n");
        return 0;
    }
    
    n = 1;

    /* Читаем остальные числа */
    while (fscanf(f, "%d", &current) == 1)
    {
        n++;

        if (current != first_val)
        {
            diff_count++;

            if (!has_second)
            {
                second_val = current;
                has_second = 1;
            }
            else if (current != second_val)
            {
                return 0; /* Третье уникальное число — сразу NO */
            }
        }
    }

    /* Все случаи (включая n=1 и n=2) перекрываются этим условием */
    if (diff_count <= 1 || diff_count == n - 1)
    {
        return 1;
    }

    return 0;
}
