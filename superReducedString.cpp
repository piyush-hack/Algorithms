#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s)
{

    string str = "";
    int j = 0;
    bool repeat = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            str += s[i];
            // cout << str << endl;

            if (str[j] == str[j - 1] && j > 0)
            {
                repeat = true;
                // cout << "Str repeat, method will be called again" << endl;
            }
            j++;
        }
        else
        {
            i++;
            // cout << "Repeat chr i++, i : " << i << endl;
        }
    }

    if (repeat == true)
    {
        // cout << "recursion" << endl;
        return superReducedString(str);
    }
    else
    {
        // cout << "Returning " << str << endl;
        string myans = str;
        // cout<<myans;
        if (str == "")
        {
            return "Empty String";
        }else{
            return myans;
        }
    }

    // return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string sa = superReducedString(s);
    cout << sa;
}
