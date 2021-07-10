#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s)
{

    int noOfLetters = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
            noOfLetters++;
    }

    return noOfLetters;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}
