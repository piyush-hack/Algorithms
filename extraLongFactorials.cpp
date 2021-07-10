#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

int multiply(int n, int *arr, int reSize){

    int carry = 0;

    for (int i = 0; i < reSize; i++)
    {
        int prod = arr[i]*n + carry;

        arr[i] = prod % 10;
        
        carry = prod/10;

    }

    while(carry){
        arr[reSize] = carry%10;
        
        carry = carry/10;

        reSize++;
    }
    
    return reSize;
}

void extraLongFactorials(int n) {

    int arr[500];
    arr[0] = 1;
    int reSize = 1;

    for (int i = 2; i <= n; i++)
    {
        reSize = multiply( i,  arr, reSize);
    }
    
    for (int i=reSize-1; i>=0; i--)
		cout << arr[i];
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
