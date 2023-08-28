#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;

    //creating a function of student class
    void printinfo(){
        cout<<endl<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        if(gender == 0){
            cout<<"Gender: Female"<<endl;
        }
        if(gender == 1){
            cout<<"Gender: Male"<<endl;
        }
    }

    //creating a parameterised constructor function of student class
    student(string s,int a, int g){
        cout<<"Parameterised Constructor."<<endl;
        name = s;
        age = a;
        gender = g;
    }

    //default constructor function of student class
    student(){
        cout<<"Default Constructor."<<endl;
    }

    //copy constructor
    student(student &a){
        cout<<"Copy constructor."<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;
    }
};

int main(){
    student a("Nikunj",19,1);
    student b("Neha",19,0);
    // a.printinfo();
    // b.printinfo();
    student c;
    student d = a;
    // int n;
    // cout<<"Enter number of students: "<<endl;
    // cin>>n;
    // student arr[n];
    // for(int i = 0; i<n; i++){
    //     cout<<endl<<"Student Name: ";
    //     cin>>arr[i].name;
    //     cout<<endl<<"Age: ";
    //     cin>>arr[i].age;
    //     cout<<endl<<"Gender: ";
    //     cin>>arr[i].gender;
    // }

    // for(int i = 0 ; i<n; i++){
    //     arr[i].printinfo();
    // }
    return 0;
}