#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
    string name;
    int prn;
    student () {}

};

class marks : public student
{
    public:
    marks() {}
    int marks1;
    int marks2;
    int marks3;
};

class result : public marks
{
    public:
    result() {}
    void getdata()
    {
        cout << "Enter Name and PRN: ";
        cin >> name >> prn;
        cout << "Enter marks in English, Hindi and Maths: ";
        cin >> marks1 >> marks2 >> marks3;
    }
    void putdata()
    {
        cout << "Name and PRN: "<<endl;
        cout << name << " " << prn << endl;
        cout << "Marks in English, Hindi and Maths: "<<endl;
        cout << marks1 << " " << marks2 << " " << marks3 << endl;
    }
};

int main()
{
    result r1;
    r1.getdata();
    r1.putdata();
    return 0;
}