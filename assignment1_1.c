/* Write a menu driven program for Date in a C. Declare a structure Date having data members 
day, month, year. Implement the following functions. 
void initDate(struct Date* ptrDate); 
void printDateOnConsole(struct Date* ptrDate); 
void acceptDateFromConsole(struct Date* ptrDate); */
#include<stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate)
{
    ptrDate->day = 18;
    ptrDate->month = 12;
    ptrDate->year = 2001;
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Input Date---");
    printf("Date (day month year): ");
    scanf("%d %d %d", &ptrDate->day, &ptrDate->month, &ptrDate->year);   
}

int main()
{
    struct Date date;
    int choice;
    do
    {
        printf("1. Initialize Date\n");
        printf("2. Accept Date from console\n");
        printf("3. Print Date on console\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                initDate(&date);
                printf("Date initialized to default value.\n");
                printDateOnConsole(&date);
                break;
            acceptDateFromConsole(&date);
            printf("Date accepted from console.\n");
            printDateOnConsole(&date);
            break;
                acceptDateFromConsole(&date);
                break;
            case 3:
                printDateOnConsole(&date);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;

}