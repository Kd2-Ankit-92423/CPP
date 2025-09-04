/* Write a menu driven program to calculate volume of the box(length * width * height). 
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor. 
Create the local objects in respective case and call the function to caluclate area. 
Menu options ->  
1. Calculate Volume with default values 
2. Calculate Volume with length,breadth and height with same value 
3. Calculate Volume with different length,breadth and height values.*/
#include <iostream>
using namespace std;
class Box
{
    private:
        float length;
        float breadth;
        float height;
    public:
        // Parameterless constructor
        Box() : length(1.0), breadth(1.0), height(1.0) {}
        
        // Single parameterized constructor
        Box(float side) : length(side), breadth(side), height(side) {}
        
        // Parameterized constructor with three parameters
        Box(float l, float b, float h) : length(l), breadth(b), height(h) {}
        
        float calculateVolume()
        {
            return length * breadth * height;
        }
};
int main()
{
    int choice;
    do
    {
        cout<<"Menu Options:"<<endl;
        cout<<"1. Calculate Volume with default values"<<endl;
        cout<<"2. Calculate Volume with same length, breadth and height"<<endl;
        cout<<"3. Calculate Volume with different length, breadth and height"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch (choice)
        {
            case 1:
            {
                Box box; // Parameterless constructor
                cout<<"Volume of Box with default values: "<<box.calculateVolume()<<endl;
                break;
            }
            case 2:
            {
                float side;
                cout<<"Enter the value for length, breadth and height: ";
                cin>>side;
                Box box(side); // Single parameterized constructor
                cout<<"Volume of Box with same length, breadth and height: "<<box.calculateVolume()<<endl;
                break;
            }
            case 3:
            {
                float length, breadth, height;
                cout<<"Enter length, breadth and height: ";
                cin>>length>>breadth>>height;
                Box box(length, breadth, height); // Parameterized constructor with three parameters
                cout<<"Volume of Box with different length, breadth and height: "<<box.calculateVolume()<<endl;
                break;
            }
            case 4:
                cout<<"Exiting the program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 4);
    
    return 0;
}