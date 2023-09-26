#include<bits/stdc++.h>
using namespace std;

class A
{
    int x,y;
    public:
    friend class B;
    void getinfo();
};

class B
{
    int z;
    public:
    void getinfo();
    int sum(A t);
};

void A :: getinfo()
{
    cout<<"Enter X and Y: ";
    cin >> x >> y;
}

void B :: getinfo()
{
    cout<<"Enter Z: ";
    cin >> z;
}

int B :: sum(A t)
{
    int sum;
    sum = z + t.x + t.y;
    return sum;
}

int main()
{
    A a;
    B b;
    a.getinfo();
    b.getinfo();
    cout<<"SUM: "<<b.sum(a);
    return 0;
}