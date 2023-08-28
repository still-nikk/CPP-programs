#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int number;
    float price;

    void getdata(int a , float b);

    void printinfo(){
        cout<<number<<", ";
        cout<<price;
    }
}x,y,z;

inline void student::getdata(int a, float b){
    number = a;
    price = b;
}

int main(){
    x.number = 1;
    cout<<x.number<<endl;
    y.getdata(2,25.5);
    y.printinfo();
    return 0;
}