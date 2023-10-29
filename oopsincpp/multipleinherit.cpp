#include<bits/stdc++.h>
using namespace std;

class item
{
    public:
    string title;
    float price;
    item() {}
    item(string title, float price): title(title),price(price) {}
};

class sale
{
    public:
    int sales1;
    int sales2;
    int sales3;
    sale() {}
    sale(int a, int b, int c) : sales1(a), sales2(b), sales3(c) {}

};

class hwitem : public item, public sale
{
    public:
    hwitem() {}
    void getdata()
    {
        cout << "Enter the item title and price:  ";
        cin >> title >> price;
        cout << "Enter the sales of first second and third month: ";
        cin >> sales1 >> sales2 >> sales3 ;
    }
    void putdata()
    {
        cout << "The item title and price:  " << endl;
        cout << title << " " << price << " " << endl;
        cout << "The sales of first second and third month: " << endl;
        cout << sales1 << " " << sales2 << " " << sales3 << " " << endl;
    }
};

class switem : public item, public sale
{
    public:
    switem() {}
    void getdata()
    {
        cout << "Enter the item title and price:  ";
        cin >> title >> price;
        cout << "Enter the sales of first second and third month: ";
        cin >> sales1 >> sales2 >> sales3 ;
    }
    void putdata()
    {
        cout << "The item title and price:  " << endl;
        cout << title << " " << price << " " << endl;
        cout << "The sales of first second and third month: " << endl;
        cout << sales1 << " " << sales2 << " " << sales3 << " " << endl;
    }
};

int main()
{
    hwitem h1;
    switem s1;
    h1.getdata();
    h1.putdata();
    s1.getdata();
    s1.putdata();
    return 0;
}