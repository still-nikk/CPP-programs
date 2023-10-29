#include<bits/stdc++.h>
using namespace std;

class abstractedemployee
{
    virtual void ispromoted() = 0;
};

class employee : abstractedemployee
{
    protected:
    string Name;
    string Company;
    int Age;

    public:
    void setname(string name)
    {
        Name = name;
    }
    void setcompany(string company)
    {
        Company = company;
    }
    void setage(int age)
    {
        Age = age;
    }
    void getname()
    {
        cout << Name;
    }
    void getcompany()
    {
        cout << Company;
    }
    void getage()
    {
        cout << Age;
    }

    employee()
    {
        Name = "Steve";
        Company = "Microsoft";
        Age = 19;
    }

    employee(string name, string company , int age)
    : Name(name), Company(company), Age(age) {}

    employee(employee &ex)
    {
        Name = ex.Name;
        Company = ex.Company;
        Age = ex.Age;
    }

    void ispromoted()
    {
        if(Age >= 18)
        {
            cout << Name << " is promoted" << endl;
        }

        else{
            cout << Name <<",Sorry you are not promoted" << endl;
        }
    }

    virtual void work()    //virtual fucntion and polymorphism
    {
        cout << Name << " is working on many things but nothing is specified" << endl;
    }
};

class developer : public employee
{
    public:
    string Favlanguage;

    developer(string name, string company , int age, string favlanguage) : employee(name,company,age)
    {
        Favlanguage = favlanguage;
    }

    developer(string favlanguage)
    {
        Favlanguage = favlanguage;
    }

    void fixedbug()
    {
        cout << Name<< " fixed bug using " <<Favlanguage << endl;
    }

    void work()    //polymorphism
    {
        cout << Name << " is working on fixing bugs using " << Favlanguage <<endl;
    }
};

class teacher: public employee    //inherited class teacher to parent/super class employee as public which allows teacher to access all private as well as protected members of employee
{
    public:
    string Subject;

    teacher(string name, string company , int age, string subject):employee(name,company,age)
    {
        Subject = subject;
    }

    teacher(string subject)
    {
        Subject = subject;
    }

    void teaching()
    {
        cout << Name << " is teaching " << Subject << endl;
    }

    void work()    //polymorphism
    {
        cout << Name << " is very busy teaching " << Subject << endl;
    }
};

int main()
{
    employee e1 = {"Nikunj","Amazon",19};
    e1.ispromoted();
    employee e2;
    e2.ispromoted();

    developer d1 = {"C++"};
    d1.getname();
    cout<<endl;
    d1.fixedbug();
    d1.work();

    teacher t1 = {"John","Amazon",35,"Maths"};
    t1.work();

    employee* e3 = &d1;
    employee* e4 = &t1;

    e3->work();
    e4->work();
    return 0;
}