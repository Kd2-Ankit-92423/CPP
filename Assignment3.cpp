/*Write a class to find volume of a Cylinder by using following members. (volume of 
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI) 
Class having following member functions: 
Cylinder() 
Cylinder(double radius, double height) 
getRadius() 
setRadius() 
getHeight() 
setHeight() 
calculateVolume() 
Initialize members using constructor member initializer list.*/
#include<iostream>
using namespace std;
class Cylinder{
    static const float PI;
    double radius;
    double height;
    public: 
    Cylinder(): radius(0), height(0)    //parameterless constructor
    { }
    Cylinder(double radius, double height): radius(radius), height(height)  //constructor with 2 parameters
    {} 
    double getRadius(){
        return radius;
    }
    double setRadius(){
        cout<<"Enter the radius: ";
        cin>>radius;
    }
    double getHeight(){
        return height;
    }
    double setHeight(){
        cout<<"Enter the height: ";
        cin>>height;
    }
    double calculateVolume(){
        return Cylinder::PI*height*radius*radius;
    }
};
const float Cylinder::PI = 3.14;
int main(){
    Cylinder c1; 
    cout<<"Radius: "<<c1.getRadius()<<endl;
    cout<<"Height: "<<c1.getHeight()<<endl;
    cout<<"The volume of cylinder by default contructor is : "<<c1.calculateVolume()<<endl;
    Cylinder c2(19,22);
    cout<<"Radius: "<<c2.getRadius()<<endl;
    cout<<"Height: "<<c2.getHeight()<<endl;
    cout<<"The volume of cylinder is : "<<c2.calculateVolume()<<endl;
    Cylinder c3;
    c3.setRadius();
    c3.setHeight();
    cout<<"The new radius and height is"<<endl;
    cout<<"Radius: "<<c3.getRadius()<<endl;
    cout<<"Height: "<<c3.getHeight()<<endl;
    cout<<"The volume of cylinder is : "<<c3.calculateVolume();
    return 0;
}