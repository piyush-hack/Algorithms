#include <bits/stdc++.h>

using namespace std;

int check(int *arr, int N, int i)
{
    // cout<<"printing";
    // for (int j = 0; j<N; j++) 
    //     cout << arr[j]<< " ";

    cout<<endl;
    if (arr[i] == arr[i + 1])
    {
        arr[i] = 0;
        i++;
        // cout << "Calling check again with " << i<<endl;;
        check(arr, N, i);
        // break;
    }
    else
    {
        arr[i] =0;
        // cout << "Returning from else " << i<<endl;;
        return i;
    }
    // cout << "Returning " << i<<endl;
    // return i;
};

int main()
{
    int N;
    int noOfOp = 0;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    
    for (int i = 0; i < N; i++)
    {

        i = check(arr, N, i);
        // cout << "Now i is " << i<<endl;
        noOfOp++;

    }

    cout<<noOfOp;
}
