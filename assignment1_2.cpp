/*Write a menu driven program for Date in a CPP language using structure and also using class. 
Date is having data members day, month, year. Implement the following functions. 
void initDate(); 
void printDateOnConsole(); 
void acceptDateFromConsole(); 
bool isLeapYear(); */
#include <iostream>
using namespace std;
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
    cout <<"Date: "<<ptrDate->day<<"/"<<ptrDate->month<<"/"<<ptrDate->year<<endl;
}
void acceptDateFromConsole(struct Date* ptrDate)
{
    cout<<"Input Date---"<<endl;
    cout<<"Date (day month year): ";
    cin>>ptrDate->day >>ptrDate->month>>ptrDate->year;
}
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}
int main()
{
    struct Date date;
    int choice;
    do
    {
        cout << "1. Initialize Date" << endl;
        cout << "2. Accept Date from console" << endl;
        cout << "3. Print Date on console" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                initDate(&date);
                cout<<"Date initialized to default value."<<endl;
                printDateOnConsole(&date);
                break;
            case 2:
                acceptDateFromConsole(&date);
                cout<<"Date accepted from console."<<endl;
                printDateOnConsole(&date);
                break;
            case 3:
                printDateOnConsole(&date);
                break;
            case 4:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 4);
    return 0;
}   