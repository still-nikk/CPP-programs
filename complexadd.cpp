#include<bits/stdc++.h>
using namespace std;

class complexno {
    float real;
    float imag;
    public:
    friend void addcom(complexno a,complexno b);
    // static int count;

    complexno()    //default constructor
    {
        float real;
        float imag;
    }

    complexno(float val1, float val2)    //parameterised constructor
    {
        real = val1;
        imag = val2;
    }

    complexno(float val)    //parameterised constructor
    {
        real = val;
        imag = val;
    }

    complexno(complexno &h)    //copu constructor
    {
        real = h.real;
        imag = h.imag;
    }

    // ~complexno()    //destructor
    // {

    // }

    void getdata()
    {
        cout<<endl<<"Enter the real part: ";
        cin >> real;
        cout <<endl<< "Enter the imaginary part: ";
        cin >> imag;
        cout <<endl<<"The number is: "<<real<<"+"<<imag<<"i";
        // count++;
        // cout << count;
    }
};

void addcom(complexno a, complexno b)
{
    complexno sum1;
    sum1.real = a.real + b.real;
    sum1.imag = a.imag + b.imag;
    cout<<endl<<"The sum is: "<<sum1.real<<"+"<<sum1.imag<<"i";
}

// class cube
// {
//     public:
//     int side;
//     cube(){     //default constructor
//         side = 10;
//     }
//     cube(int a)    //parametrised constructor
//     {
//         side = a;
//     }
//     cube(cube &haha)    //copy constructor
//     {
//         side = haha.side;
//     }
// };

int main()
{
    cout << "Enter the first complex number: ";
    complexno c1, c2;
    c1.getdata();
    cout<<endl<<"Enter the second complex number: ";
    c2.getdata();
    addcom(c1,c2);
    // cube c;
    // cout << c.side << endl;
    // cube s(1);
    // cout << s.side << endl;
    // cube b(c);
    // cout << b.side << endl;
    return 0;
}