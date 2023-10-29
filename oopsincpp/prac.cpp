#include<bits/stdc++.h>
using namespace std;

class media
{
    string title;
    float price;
    public:
    // media()
    // {
    //     title = "A";
    //     price = 200;
    // }
    virtual void display()
    {
        cout << "A is priced at Rs. 150" <<endl;
    }   
};

class book : public media
{
    int pages;
    public:
    // book()
    // {
    //     pages = 100;
    // }
    void display()
    {
        cout << "The book named B has 100 pages "<< endl;
    }
};

class tape : public media
{
    int playtime;
    public:
    // tape()
    // {
    //     playtime = 300;
    // }
    void display()
    {
        // media :: display();
        cout << "The tape named C plays for 300 seconds." << endl;
    }
};

void show(media* obj)
{
    obj -> display();
}

int main()
{
    media m1;
    media* m2;
    media* m3;
    media* m4;
    // media* m4;
    book b1;
    tape t1;
    // m1.title = "B";
    // m1.price = 150;
    // m2->title = "Verity";
    // m2->price = 200;
    // m3->title = "C";
    // m3->price = 200;
    m2 = &b1;
    m3 = &t1;
    show(m2);
    show(m3);
    // show(m4);
    m1.display();
    m2->display();
    m3->display();
    return 0;
}