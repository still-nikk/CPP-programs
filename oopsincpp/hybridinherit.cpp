#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
    string name;
    int prn;
    student () {}
    student(string name, int prn): name(name),prn(prn) {}

};

class utmarks : public student
{
    public:
    utmarks() {}
    int marks1;
    int marks2;
    int marks3;
};

class sports : public student
{
    public:
    sports() {}
    int markss;
};

class result : public utmarks, public sports
{   
    public:
    result() {}
    void getdata(student s1)
    {
        // cout << "Enter Name and PRN: ";
        // cin >> s1.name >> s1.prn;
        cout << "Enter marks in English, Hindi and Maths: ";
        cin >> marks1 >> marks2 >> marks3;
        cout << "Enter marks in sports: ";
        cin >> markss;
    }
    void putdata(student s1)
    {
        cout << "Name and PRN: "<<endl;
        cout << s1.name << " " << s1.prn << endl;
        cout << "Marks in English, Hindi and Maths: "<<endl;
        cout << marks1 << " " << marks2 << " " << marks3 << endl;
        cout << "Marks in sports: "<<endl;
        cout << markss << endl;
    }
};

int main()
{
    student s1("Nikunj",132);
    result r1;
    r1.getdata(s1);
    r1.putdata(s1);
    return 0;
}