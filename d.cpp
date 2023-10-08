#include<bits/stdc++.h>
using namespace std;

class addition
{

    public:
    int sum(int a, int b)
    {
        return a + b;
    }
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    addition a1;
    addition a2;
    cout << a1.sum(10,20,30)<<endl;
    cout << a2.sum(10,20);
    return 0;
}