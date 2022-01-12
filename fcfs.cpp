
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int head = 0;
    cout << "ENTER NUMBER OF REQUEST" << endl;
    cin >> n;
    n++;
    int arr[n];
    cout << "A list of  cylinders" << endl;
    for (int i = 1; i < n; i++)
    {
        arr[i] = rand() % 200;
        cout << arr[i] << " ";
    }
    cout << endl;
    int h;
    cout << "Intial head position" << endl;
    cin >> h;
    cout << "\n Head start at:" << h << endl;
    arr[0] = h;
    for (int i = 0; i < n - 1; i++)
        head += abs(arr[i + 1] - arr[i]);
    cout << "\nTotal head movement is (" << head << ")";
    cout << "\nSequence is" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}