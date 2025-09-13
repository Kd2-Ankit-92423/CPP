/* A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
should be menu driven and should not cause memory leakage. 
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3] */
#include<iostream>
using namespace std;
class Product{
    protected:
    int id;
    string title;
    string name;
    float price;
    public:
    Product(void): id(0), title(" "), name(" "), price(){ }
    void acceptId(int){
        cout<<"Enter Your Id: ";
        cin>>this->id;
    } 
    void getId(int){
        cout<<"ID: "<<id<<endl;
    }
    void acceptTitle(string){
        cout<<"Enter the title: ";
        cin>>this->title;
    } 
    void getTitle(string){
        cout<<"Title: "<<title<<endl;
    }
    void acceptName(string){
        cout<<"Enter Name: ";
        cin>>this->id;
    } 
    void getName(string){
        cout<<"Name: "<<id<<endl;
    }
    
    virtual void calculateDiscount(float)=0;
    void calcualteTotal(float price){
        cout<<"Total Price after discount: "<<price<<endl;
    }
};
class Book:public Product{
public:
   Book(){
    price=20;
   }
   void calculateDiscount(float price){
    price=price-(price*0.1);
   }
};
class Tape:public Product{
public:
    Tape(){
        price=300;
    }
    void calculateDiscount(float price){
        price=price-(price*0.05);
    }
    }

};
class Menulist{
    public: 
    void displayMenu() {
        cout<<"1. Book"<<endl;
        cout<<"2. Tape"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
    }
    int choice;
};
int main(){
    Menulist m;
    Product* arr[3];
    int i=0;
    do{
        m.displayMenu();
        cin>>m.choice;
        switch(m.choice){
            case 1:
            arr[i]=new Book();
            arr[i]->acceptId(0);
            arr[i]->acceptTitle(" ");
            arr[i]->acceptName(" ");
            arr[i]->calculateDiscount(0);
            arr[i]->calcualteTotal(0);
            i++;
            break;
            case 2:
            arr[i]=new Tape();
            arr[i]->acceptId(0);
            arr[i]->acceptTitle(" ");
            arr[i]->acceptName(" ");
            arr[i]->calculateDiscount(0);
            arr[i]->calcualteTotal(0);
            i++;
            break;
            case 3:
            cout<<"Exit"<<endl;
            break;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }while(m.choice!=3 && i<3);
    for(int j=0;j<i;j++){
        delete arr[j];
    }
    return 0;
}
