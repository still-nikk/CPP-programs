#include<bits/stdc++.h>
using namespace std;

// class A
// {

//     public:
//     int X;
//     A()
//     {
//         X = 10;
//     }
//     void show()
//     {
//         cout << "Class A"<< endl;
//     }
//     void displayval(A &a)
//     {
//         cout << a.X << endl;
//     }

// };

// class B : public A
// {
//     public:
//     int Y;
//     B()
//     {
//         Y = 20;
//     }
//     void show()
//     {
//         cout << "Class B"<< endl;
//     }
// };

// int main()
// {
//     A a;
//     a.X = 30;
//     B b;
//     a.show();
//     b.show();
//     b.displayval(a);
//     return 0;
// }



class animal
{
    public:
    virtual void eat()
    {
        cout << "I am eating generic food." << endl;
    }
};

class cat : public animal
{
    public:
    void eat()
    {
        cout << "I am eating a rat." << endl;
    }

};

class rat: public cat
{
    public:
    void eat()
    {
        cout << "I eat stuff." << endl;
    }
};

void function1(animal* xyz)
{
    xyz -> eat();
}

int main()
{
    animal a;
    animal* ptr;
    cat catobj;
    rat r;
    ptr = &catobj;        //late binding
    function1(ptr);
    r.eat();
    a.eat();
    catobj.eat();
    return 0;
}