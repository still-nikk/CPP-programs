#include<bits/stdc++.h>
using namespace std;

class employee
{
    string Name;
    int Age;

    public:
    friend class developer;
    employee()
    {
        Name = "Nikunj";
        Age = 19;
    }

    employee(string name, int age)
    {
        Name = name;
        Age = age;
    }

};

class developer : public employee
{
    string Favlanguage;

    public:
    developer(string favlanguage)
    {
        Favlanguage = favlanguage;
    }
    
    developer(string name,int age,string favlanguage) : employee(name,age)
    {
        Favlanguage = favlanguage;
    }

    void fixedbug(employee& e1)
    {
        cout << e1.Name <<" is fixing bugs using "<<Favlanguage<<endl;
    }
};

int main()  
{
    employee e1;
    developer d1("C++");
    d1.fixedbug(e1);
    return 0;
}