// Week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Faren() // Aka Farenheight Math Sum Thingy
{
    float Inputnum;
    cout << endl << "Input ?F" << endl << endl;
    cin >> Inputnum;

    float Celci = (Inputnum - 32) * 5 / 9;
    cout << endl << Inputnum << "F in C is: " << Celci << "C" << endl;

    return true;
}

int Add()
{
    float A;
    float B;

    cout << endl << "Enter 2 Values to ADD: " << endl << endl;
    cin >> A;
    cout << "+" << endl;
    cin >> B;

    float R = A + B;
    cout << endl << "Result: " << R << endl;

    return true;
}

int Minus()
{
    float A;
    float B;

    cout << endl << "Enter 2 Values to MINUS: " << endl << endl;
    cin >> A;
    cin >> B;

    float R = A - B;
    cout << endl << "Result: " << R << endl;

    return true;
}

int Multi()
{
    float A;
    float B;

    cout << endl << "Enter 2 Values to MULTIPLY: " << endl << endl;
    cin >> A;
    cin >> B;

    float R = A * B;
    cout << endl << "Result: " << R << endl;

    return true;
}

int Divide()
{
    float A;
    float B;

    cout << endl << "Enter 2 Values to DIVIDE: " << endl << endl;
    cin >> A;
    cin >> B;

    float R = A / B;
    cout << endl << "Result: " << R << endl;

    return true;
}

int Menu()
{
    int todo;
    cout << "Would you like to do: " << endl;
    cout << "1 = Farenheit Operator" << endl;
    cout << "2 = Add" << endl;
    cout << "3 = Minus" << endl;
    cout << "4 = Multiply" << endl;
    cout << "5 = Divide" << endl << endl;
    cin >> todo;

    if (todo == 1) { Faren(); }
    if (todo == 2) { Add(); }
    if (todo == 3) { Minus(); }
    if (todo == 4) { Multi(); }
    if (todo == 5) { Divide(); }
    if (todo > 5) { cout << "Unknown Operation" << endl; }

    return true;
}

int main()
{
    Menu();

    cout << endl << "End of Application." << endl;
}

