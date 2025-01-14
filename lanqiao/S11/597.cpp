#include <iostream>
using namespace std;
int main()
{
    int d;
    for (int y = 2000; y <= 2020; y++)
    {
        cout << "\n"
             << y << "\n";
        for (int m = 1; m <= 12; m++)
        {
            if ((y == 2000 || y == 2004 || y == 2008 || y == 2012 || y == 2016 || y == 2020) && m == 2)
            {
                for (int num = 1; num <= 28; num++)
                {
                    cout << num<<" ";
                    if(num%7==0){
                        cout<<"\n";
                    }
                }
                cout<<"\n";
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11)
            {
                for (int num = 1; num <= 30; num++)
                {
                    cout << num<<" ";
                    if(num%7==0){
                        cout<<"\n";
                    }
                }
                cout<<"\n";
            }
            else
            {
                for (int num = 1; num <= 31; num++)
                {
                    cout << num<<" ";
                    if(num%7==0){
                        cout<<"\n";
                    }
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
}