#include <iostream>
#include <random>
#include <ctime>
#include "array.h"

using namespace std;

int main()
{
    srand(time(0));
    Array arr;
    int input;
    do
    {
        cout << "Enter the type of array filling (1 - random numbers, 2 - manually using the keyboard, 9 - exit the program):" << endl;
        cin >> input;
        arr.typeOfFilling(input);
    }
    while (input != 9);
    return 0;
}

void Array::typeOfFilling(int input)
{
    if (input == 1)
        fillWithRandomNumbers();
    else if (input == 2)
        fillUsingKeyboard();
    else return;
    cout << "Your array: ";
    print();
    cout << "Choose an array processing option (4, 5, 7, 10 or 11):" << endl;
    cin >> input;
    processElements(input);
    cout << "New (changed) array: ";
    print();
}
