#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void scan(int arr[], int n, int head)
{
    int count = 0;
    vector<int> left, right;
    vector<int> sequence;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > head)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    sequence.push_back(head);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    string str;
    cout << "Enter direction" << endl;
    cin >> str;
    int x = 2;
    while (x--)
    {
        if (str == "left")
        {
            for (int i = left.size() - 1; i >= 0; i--)
            {
                sequence.push_back(left[i]);
                count += abs(head - left[i]);
                head = left[i];
            }
            str = "right";
        }
        else if (str == "right")
        {
            for (int i = 0; i < right.size(); i--)
            {
                sequence.push_back(right[i]);
                count += abs(head - right[i]);
                head = left[i];
            }
            str = "left";
        }
    }
    cout << "Total number of seek operations = "
         << count << endl;

    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < sequence.size(); i++)
    {
        cout << sequence[i] << endl;
    }
}
int main()
{
    int n;
    cout << "ENTER NUMBER OF REQUEST" << endl;
    cin >> n;
    int arr[n];
    cout << "A disk queue with requests for I/O to blocks on cylinders" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 200;
        cout << arr[i] << " ";
    }
    cout << endl;
    int h;
    cout << "Intial head position" << endl;
    cin >> h;
    cout << "\n Head start at:" << h << endl;
    // cout << "\n\nSuppose head start at:" << head << endl;
    scan(arr, n, h);
}