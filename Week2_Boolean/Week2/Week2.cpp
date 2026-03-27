#include <iostream>
using namespace std;

bool porchDoorOpen = true;
bool innerDoorOpen = true;

int startup()
{
    int choice;
    
    cout << "The Doors Are Currently" << endl << endl;
    if (not porchDoorOpen) {cout << "Porch Door: Open" << endl;}
    else {cout << "Porch Door: Closed" << endl;}
    
    if (not innerDoorOpen) {cout << "Inner Door: Open" << endl;}
    else {cout << "Inner Door: Closed" << endl << endl;}
    
    cout << "What would you like to do: " << endl << "1: Press Outer Button" << endl << "2: Press Inner Button" << endl << endl;
    cin >> choice;
    
    if (choice == 1)
    {
        porchDoorOpen = not porchDoorOpen;
    }
    else if (choice == 2)
    {
        innerDoorOpen = not innerDoorOpen;
    }
    else
    {
        cout << "ERROR";
    }
    
    return choice;
}

int main()
{
    startup();
    if (not porchDoorOpen and not innerDoorOpen)
    {
        cout << "The cat has escaped";
    }
    else
    {
        main();
    }
}
