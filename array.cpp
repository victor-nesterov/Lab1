#include <sstream>
#include <iostream>
#include <random>
#include "array.h"

using namespace std;

void Array::fillWithRandomNumbers()
{
    cout << "How many array elements do you want to fill (maximum " << N << ")?" << endl;
    cin >> k;
    for (int i = 0; i < k; ++i)
        arr[i] = rand() % 100;
    cout << k << " elements of your array was filled!" << endl;
}

void Array::fillUsingKeyboard()
{
    string s;
    cin.ignore(256, '\n');
    getline(cin, s);
    stringstream ss;
    ss << s;
    int i;
    for (i = 0; i < N; ++i)
    {
        ss >> arr[i];
        if (!ss) break;
    }
    if (ss)
    {
        ss >> i;
        if (ss)
        {
            k = N;
            cout << "Only the first " << N << " elements are written" << endl;
            return;
        }
    }
    k = i;
    cout << k << " elements of your array was filled!" << endl;
}

void Array::print()
{
    for (int i = 0; i < k; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void Array::processElements(int type)
{
    if (type == 4)
    {
        for (int i = 0; i < 2; ++i)
        {
            int e = arr[k - 1];
            for (int u = k - 2; u >= 0; --u)
            {
                int t = arr[u];
                arr[u] = e;
                e = t;
            }
            arr[k - 1] = e;
        }
    }
    else if (type == 5)
    {
        for (int i = 0; i < 2; ++i)
        {
            int e = arr[0];
            for (int u = 1; u < k; ++u)
            {
                int t = arr[u];
                arr[u] = e;
                e = t;
            }
            arr[0] = e;
        }
    }
    else if (type == 7)
    {
        for (int i = 0; i + (k + 1) / 2 < k; ++i)
        {
            int e = arr[i];
            arr[i] = arr[i + (k + 1) / 2];
            arr[i + (k + 1) / 2] = e;
        }
        if (k % 2 == 1)
        {
            int e = arr[0];
            for (int u = 1; u < k / 2 + 1; ++u)
            {
                int t = arr[u];
                arr[u] = e;
                e = t;
            }
            arr[0] = e;
        }
    }
    else if (type == 10)
    {
        if (k < N)
        {
            int ind = 0;
            for (int i = 1; i < k; ++i)
                if (arr[i] > arr[ind])
                    ind = i;
            for (int i = k - 1; i > ind; --i)
            {
                arr[i + 1] = arr[i];
            }
            cout << "Enter the value of element you want to add:" << endl;
            cin >> arr[ind + 1];
            k = k + 1;
        }
        else cout << "The array is filled!";
    }
    else if (type == 11)
    {
        if (k < N)
        {
            int ind = 0;
            for (int i = 1; i < k; ++i)
                if (arr[i] > arr[ind])
                    ind = i;
            for (int i = k - 1; i >= ind; --i)
            {
                arr[i + 1] = arr[i];
            }
            cout << "Enter the value of element you want to add:" << endl;
            cin >> arr[ind];
            k = k + 1;
        }
        else cout << "The array is already full!" << endl;
    }
}
