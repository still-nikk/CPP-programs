#include<bits/stdc++.h>
using namespace std;
class seriessum
{
    int Noofterms;

    public:
    seriessum()
    {
        Noofterms = 1;
    }

    seriessum(int val)
    {
        Noofterms = val;
    }

    void getterms()
    {
        cin >> Noofterms;
    }

    void sumofseries()
    {
        int sum = 0;
        int temp = 0;
        int count = 0;
        while(count != Noofterms)
        {
            temp = temp * 10 + 9;
            sum = sum + temp;
            count ++;
        }
        cout << sum;
    }
};
int main()
{
    seriessum s1(5);
    // s1.getterms();
    s1.sumofseries();
    return 0;
}