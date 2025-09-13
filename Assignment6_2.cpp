#include <iostream>
#include <string>
using namespace std;

//............................... Base class: Employee................................
class Employee {
protected:
    int id;
    double salary;

public:

    Employee() : id(0), salary(0.0) {}
    Employee(int i, double s) : id(i), salary(s) {}

    virtual ~Employee() {}


    int getId()   { return id; }
    void setId(int i) { id = i; }

    double getSalary()   { return salary; }
    void setSalary(double s) { salary = s; }


    virtual void display()   {
        cout << "Employee[ID=" << id << ", Salary=" << salary << "]" << endl;
    }

    virtual void accept() = 0;
};

// ..............................Derived class: Manager...............................
class Manager : public Employee {
protected:
    double bonus;

public:
    Manager() : Employee(), bonus(0.0) {}
    Manager(int id_, double salary_, double bonus_)
        : Employee(id_, salary_), bonus(bonus_) {}


    void setBonus(double b) { bonus = b; }
    double getBonus()   { return bonus; }


protected:
    void acceptManager() {
        cout<<"Enter Manager ID: ";
        cin>>this->id;
        cout<<"Enter Manager Salary: ";
        cin>>this->salary;
        cout<<"Enter Manager Bonus: ";
        cin>>this->bonus;
     }

    void displayManager()   {
        cout << "Manager[ID=" << id
             << ", Salary=" << salary
             << ", Bonus=" << bonus << "]" << endl;
    }

public:

    void display()     {
        displayManager();
    }

    void accept()   {
        acceptManager();
    }
};

// ..............................Derived class: Salesman...............................

class Salesman : public Employee {
protected:
    double commission;

public:
    Salesman() : Employee(), commission(0.0) {}
    Salesman(int id_, double salary_, double commission_)
        : Employee(id_, salary_), commission(commission_) {}

    void setCommission(double c) { commission = c; }
    double getCommission()   { return commission; }

protected:
    void acceptSalesman(){ 
        cout<<"Enter Salesman ID: ";
        cin>>this->id;
        cout<<"Enter Salesman Salary: ";
        cin>>this->salary;
        cout<<"Enter Salesman Commission: ";
        cin>>this->commission;
    }

    void displaySalesman()   {
        cout << "Salesman[ID=" << id
             << ", Salary=" << salary
             << ", Commission=" << commission << "]" << endl;
    }

public:

    void display()     {
        displaySalesman();
    }

    void accept()   {
        acceptSalesman();
    }
};
// ..............................Indirect Derived class: SalesManager...............................

class SalesManager : public Manager, public Salesman {
public:
    SalesManager()
        : Manager(), Salesman() {}

    SalesManager(int id_, double salary_, double bonus_, double commission_)
        : Manager(id_, salary_, bonus_), Salesman(id_, salary_, commission_) {}

    void display()     {
        cout << "SalesManager[ID=" << Manager::getId()
             << ", Salary=" << Manager::getSalary()
             << ", Bonus=" << Manager::getBonus()
             << ", Commission=" << Salesman::getCommission() << "]" << endl;
    }

    void accept()   {  
        Manager::acceptManager();
        Salesman::acceptSalesman();
      }
};


int main() {
    // Manager tests
    Manager manager(101, 75000.0, 5000.0);
    cout << "Manager initial display: ";
     manager.display();
     manager.setBonus(6000.0);
    cout << "Manager bonus updated: ";
     manager.display();
    cout << "Manager ID: " <<  manager.getId() << ", Salary: " <<  manager.getSalary() << ", Bonus: " <<  manager.getBonus() << endl;
    cout << "Accepting new manager data:" << endl;
     manager.accept();
    cout << "Manager after accept: ";
     manager.display();

    // Salesman tests
    Salesman salesman(202, 50000.0, 3000.0);
    cout << "\nSalesman initial display: ";
    salesman.display();
    salesman.setCommission(3500.0);
    cout << "Salesman commission updated: ";
    salesman.display();
    cout << "Salesman ID: " << salesman.getId() << ", Salary: " << salesman.getSalary() << ", Commission: " << salesman.getCommission() << endl;
    cout << "Accepting new salesman data:" << endl;
    salesman.accept();
    cout << "Salesman after accept: ";
    salesman.display();

   // SalesManager tests
    SalesManager salesmanager(303, 100000.0, 12000.0, 4500.0);
    cout << "\nSalesManager initial display: ";
    salesmanager.display();
    cout << "Accepting new salesmanager data:" << endl;
    salesmanager.accept();
    cout << "SalesManager after accept: ";
    salesmanager.display();
    cout << "SalesManager ID from Manager: " << salesmanager.Manager::getId() << endl;
    cout << "SalesManager Salary from Manager: " << salesmanager.Manager::getSalary() << endl;
    cout << "SalesManager Bonus from Manager: " << salesmanager.Manager::getBonus() << endl;
    cout << "SalesManager ID from Salesman: " << salesmanager.Salesman::getId() << endl;
    cout << "SalesManager Salary from Salesman: " << salesmanager.Salesman::getSalary() << endl;
    cout << "SalesManager Commission from Salesman: " << salesmanager.Salesman::getCommission() << endl;

    return 0;
}