// Week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "Program Start: Press 1 to begin" << endl;
    int a;
    cin >> a;
    
    if (a == 1)
    {
        int Array1[12] = {12, 10, 8, 6 , 4, 2};
        
        for (int I = 0; I < 12; I++)
        {
            if (Array1[I] < 1)
            {
                Array1[I] = Array1[-(I - 12 + 1)];
            }
            if (I < 11)
            {
                cout << Array1[I] << " - ";
            }
            else
            {
                cout << Array1[I];
            }
        }
    }
    
    return 0;
}