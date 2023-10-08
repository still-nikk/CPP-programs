#include<bits/stdc++.h>
using namespace std;

class complexno {
    public:
    float real;
    float imag;
    friend void addcom(complexno a,complexno b);
    
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

    complexno(complexno &h)    //copy constructor
    {
        real = h.real;
        imag = h.imag;
    }

    // ~complexno()    //destructor
    // {

    // }

    void getdata()
    {
        cout<<"Enter the real part: ";
        cin >> real;
        cout<< "Enter the imaginary part: ";
        cin >> imag;
        cout<<"The number is: "<<real<<"+"<<imag<<"i"<<endl;
        // count++;
        // cout << count;
    }

    void operator ++()
    {
        ++real;
        ++imag;
    }

    bool operator <(complexno m)
    {
        if(real < m.real )
        {
            return true;
        }
        if(real == m.real && imag < m.imag)
        {
            return true;
        }
        return false;
    }

    complexno operator +(complexno m)
    {
        complexno temp;
        temp.real = real + m.real;
        temp.imag = imag + m.imag;
        return temp;
    }

    void display()
    {
        cout << real << "+" << imag <<"i"<<endl;
    }

    //friend void operator --(complexno &m);
};

void operator --(complexno &m)
{
    m.real--;
    m.imag--;
}

void addcom(complexno a, complexno b)
{
    complexno sum1;
    sum1.real = a.real + b.real;
    sum1.imag = a.imag + b.imag;
    cout<<endl<<"The sum is: "<<sum1.real<<"+"<<sum1.imag<<"i"<<endl<<endl;
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
    complexno c1, c2, c3;
    c1.getdata();
    cout<<endl<<"Enter the second complex number: ";
    c2.getdata();
    // complexno c3 = c2;    //copy constructor
    // addcom(c1,c2);
    // addcom(c1,c3);
    // cube c;
    // cout << c.side << endl;
    // cube s(1);
    // cout << s.side << endl;
    // cube b(c);
    // cout << b.side << endl;
    cout<<endl<<"Menu: "<<endl;
    cout<<"1: Prefix Increment operator on the first complex number"<<endl;
    cout<<"2: Postfix Decrement operator on the first complex number"<<endl;
    cout<<"3: Complex Addition operator"<<endl;
    cout<<"4: Complex Comparison operator"<<endl;
    cout<<"5: Exit"<<endl;
    int choice;
    cin>>choice;
    while(choice != 5){
        
        switch(choice)
        {
            case 1:
            ++c1;
            cout<<"After increment: ";c1.display();
            cout<<endl;
            break;

            case 2:
            --c1;
            cout<<"After Decrement: ";c1.display();
            cout<<endl;
            break;

            case 3:
            c3 = c1 + c2;
            cout << "After addition: ";c3.display();
            break;

            case 4:
            cout << "On comparison: ";
            if(c1<c2)
            {
                cout<<"Second complex number is greater"<<endl<<endl;
            }
            else{
                cout << "First complex number is greater"<<endl<<endl;
            }
            break;
        }    
        cout<<"Menu: "<<endl;
        cout<<"1: Prefix Increment operator on the first complex number"<<endl;
        cout<<"2: Postfix Decrement operator on the first complex number"<<endl;
        cout<<"3: Complex Addition operator"<<endl;
        cout<<"4: Complex Comparison operator"<<endl;
        cout<<"5: Exit"<<endl;
        cin>>choice;
    }
    return 0;
}