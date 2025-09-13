#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int i, double s) : id(i), salary(s) {}
    virtual ~Employee() {}

    int getId() { return id; }
    void setId(int i) { id = i; }
    double getSalary() { return salary; }
    void setSalary(double s) { salary = s; }

    virtual void display() {
        cout << "Employee[ID=" << id << ", Salary=" << salary << "]" << endl;
    }

    virtual void accept() = 0;
    virtual string designation() = 0;
};

class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager() : Employee(), bonus(0.0) {}
    Manager(int id_, double salary_, double bonus_)
        : Employee(id_, salary_), bonus(bonus_) {}

    void setBonus(double b) { bonus = b; }
    double getBonus() { return bonus; }

protected:
    void acceptManager() {
        cout << "Enter Manager ID: ";
        cin >> this->id;
        cout << "Enter Manager Salary: ";
        cin >> this->salary;
        cout << "Enter Manager Bonus: ";
        cin >> this->bonus;
    }

    void displayManager() {
        cout << "Manager[ID=" << id
             << ", Salary=" << salary
             << ", Bonus=" << bonus << "]" << endl;
    }

public:
    void display() {
        displayManager();
    }

    void accept() {
        acceptManager();
    }
    string designation() { return "Manager"; }
};

class Salesman : virtual public Employee {
protected:
    double commission;

public:
    Salesman() : Employee(), commission(0.0) {}
    Salesman(int id_, double salary_, double commission_)
        : Employee(id_, salary_), commission(commission_) {}

    void setCommission(double c) { commission = c; }
    double getCommission() { return commission; }

protected:
    void acceptSalesman() {
        cout << "Enter Salesman ID: ";
        cin >> this->id;
        cout << "Enter Salesman Salary: ";
        cin >> this->salary;
        cout << "Enter Salesman Commission: ";
        cin >> this->commission;
    }

    void displaySalesman() {
        cout << "Salesman[ID=" << id
             << ", Salary=" << salary
             << ", Commission=" << commission << "]" << endl;
    }

public:
    void display() {
        displaySalesman();
    }

    void accept() {
        acceptSalesman();
    }
    string designation() { return "Salesman"; }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager()
        : Manager(), Salesman() {}

    SalesManager(int id_, double salary_, double bonus_, double commission_)
        : Manager(id_, salary_, bonus_), Salesman(id_, salary_, commission_) {}

    void display() {
        cout << "SalesManager[ID=" << Manager::getId()
             << ", Salary=" << Manager::getSalary()
             << ", Bonus=" << Manager::getBonus()
             << ", Commission=" << Salesman::getCommission() << "]" << endl;
    }

    void accept() {
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    string designation() { return "SalesManager"; }
};

int main() {
    vector<Employee*> employees;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Manager\n";
        cout << "2. Add Salesman\n";
        cout << "3. Add SalesManager\n";
        cout << "4. Display the count of all employees with respect to designation\n";
        cout << "5. Display All Managers\n";
        cout << "6. Display All Salesmen\n";
        cout << "7. Display All SalesManagers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Manager* manager = new Manager();
                manager->accept();
                employees.push_back(manager);
                break;
            }
            case 2: {
                Salesman* salesman = new Salesman();
                salesman->accept();
                employees.push_back(salesman);
                break;
            }
            case 3: {
                SalesManager* salesManager = new SalesManager();
                salesManager->accept();
                employees.push_back(salesManager);
                break;
            }
            case 4: {
                int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;
                for (size_t i = 0; i < employees.size(); ++i) {
                    if (employees[i]->designation() == "Manager")
                        managerCount++;
                    else if (employees[i]->designation() == "Salesman")
                        salesmanCount++;
                    else if (employees[i]->designation() == "SalesManager")
                        salesManagerCount++;
                }
                cout << "Number of Managers: " << managerCount << endl;
                cout << "Number of Salesmen: " << salesmanCount << endl;
                cout << "Number of SalesManagers: " << salesManagerCount << endl;
                break;
            }
            case 5: {
                cout << "All Managers:\n";
                for (size_t i = 0; i < employees.size(); ++i) {
                    if (employees[i]->designation() == "Manager")
                        employees[i]->display();
                }
                break;
            }
            case 6: {
                cout << "All Salesmen:\n";
                for (size_t i = 0; i < employees.size(); ++i) {
                    if (employees[i]->designation() == "Salesman")
                        employees[i]->display();
                }
                break;
            }
            case 7: {
                cout << "All SalesManagers:\n";
                for (size_t i = 0; i < employees.size(); ++i) {
                    if (employees[i]->designation() == "SalesManager")
                        employees[i]->display();
                }
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    for (size_t i = 0; i < employees.size(); ++i) {
        delete employees[i];
    }
    employees.erase(employees.begin(), employees.end());

    return 0;
}