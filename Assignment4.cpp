/*. Create a class Date with data memebrs day,month and year. 
Cretae a class Person with data members name,address and birthdate. The birthdate should be of 
type Date. 
Create a class Student with data members id, marks, course and joining date, end date. The joining 
date and end date should be of type date. 
Implement above classes. Test all functionalities in main(). 
(Note - Only Perform the Association in the above case. No need of Inheritance)*/
#include<iostream>
using namespace std;

class Date {
    int day, month, year;
public:
    Date() : day(0), month(0),year(0) { }  

    Date(int day, int month, int year) : day(day), month(month), year(year) { }

    void acceptDate() {
        cout << "\nDay: "; cin >> day;
        cout << "Month: "; cin >> month;
        cout << "Year: "; cin >> year;
    }

    void printDate() const {
        cout << "\nPrinting Date:";
        cout << "\nDay: " << day << "\nMonth: " << month << "\nYear: " << year << endl;
    }
};

class Person {
    string name, address;
    Date* birthDate;
public:
    Person() : name(" "), address(" "), birthDate(NULL) { }

    Person(string name, string address) : name(name), address(address), birthDate(NULL) { }

    Person(string name, string address, int day, int month, int year)
        : name(name), address(address)
    {
        birthDate = new Date(day, month, year);
    }

    void acceptPerson() {
        cout << "\nName: "; cin >> name;
        cout << "Address: "; cin >> address;
        cout << "Birth Date:";
        acceptBirthDate();
    }

    void acceptBirthDate() {
        if (birthDate) {
            delete birthDate;
            birthDate = NULL;
        }
        birthDate = new Date();
        birthDate->acceptDate();
    }

    void printPerson() const {
        cout << "\nName: " << name << "\nAddress: " << address << endl;
        if (birthDate) birthDate->printDate();
    }

    ~Person() {
        delete birthDate;
        birthDate = NULL;
    }
};

class Student {
    int id, marks;
    string courses;
    Date* joinDate;
    Date* endDate;
public:
    Student() :id(0), marks(0), courses(" "), joinDate(NULL), endDate(NULL) { }

    Student(int id, int marks, string courses)
        : id(id), marks(marks), courses(courses), joinDate(NULL), endDate(NULL) { }

    Student(int id, int marks, string courses,
            int jDay, int jMonth, int jYear,
            int eDay, int eMonth, int eYear)
        : Student(id, marks, courses)
    {
        joinDate = new Date(jDay, jMonth, jYear);
        endDate = new Date(eDay, eMonth, eYear);
    }

    void acceptStudent() {
        cout << "\nEnter student id: "; cin >> id;
        cout << "Enter marks: "; cin >> marks;
        cout << "Enter the course: "; cin >> courses;

        cout << "Enter the join Date:";
        acceptStudentJoinDate();

        cout << "Enter the end Date:";
        acceptStudentEndDate();
    }

    void acceptStudentJoinDate() {
        if (joinDate) {
            delete joinDate;
            joinDate = NULL;
        }
        joinDate = new Date();
        joinDate->acceptDate();
    }

    void acceptStudentEndDate() {
        if (endDate) {
            delete endDate;
            endDate = NULL;
        }
        endDate = new Date();
        endDate->acceptDate();
    }

    void printStudent() const {
        cout << "\nStudent ID: " << id << "\nCourse: " << courses << "\nMarks: " << marks << endl;
        cout << "\nJoin Date:";
        if (joinDate) joinDate->printDate();
        cout << "\nEnd Date:";
        if (endDate) endDate->printDate();
    }

    ~Student() {
        delete joinDate;
        delete endDate;
        joinDate = endDate = NULL;
    }
};

int main() {
    Date d;
    cout << "\nDate value through default constructor:";
    d.printDate();

    cout << "\nUser enter the dates:";
    d.acceptDate();
    d.printDate();

    Person p;
    cout << "\n...Person Class....";
    cout << "\n...Person Default Values....";
    p.printPerson();

    cout << "\nPerson with parameters:";
    Person p1("Ankit", "Pune", 18, 12, 2001);
    p1.printPerson();

    cout << "\nPerson with user input:";
    p.acceptPerson();
    p.printPerson();

    Student s;
    cout << "\n\n\nStudent Class:";
    cout << "\nStudent Default Values:";
    s.printStudent();

    cout << "\nStudent with parameters:";
    Student s1(3, 100, "DAC", 21, 8, 2025, 21, 8, 2029);  // corrected constructor
    s1.printStudent();

    cout << "\nStudent with user input:";
    s.acceptStudent();
    s.printStudent();

    return 0;
}