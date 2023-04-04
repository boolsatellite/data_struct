#include <stdio.h>

int isLeapYear(int year)
{
    int flag;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                flag = 1;
            else
                flag = 0;
        }
        else
            flag = 1;
    }
    else
        flag = 0;
    return flag;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int year;
        printf("Please enter a year: ");
        scanf("%d", &year);
        if (isLeapYear(year))
        {
            printf("%d is a leap year.\n", year);
        }
        else
        {
            printf("%d is not a leap year.\n", year);
        }
    }
    return 0;
}
