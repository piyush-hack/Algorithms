#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k)
{

    char a = 'a';
    // char b = int(a) + 10;
    for (int i = 0; i < s.length(); i++)
    {
        for (char a = 'A'; a <= 'z'; ++a)
        {
            if (int(a) > 90 && int(a) <= 96)
            {
                a = 96;
                continue;
            }
            int incBy = k;
            int A = a;
            if (((int(a)) <= 122 && (int(a) + incBy) >= 97) && (int(a) + incBy) > 122)
            {
                // cout<<"enter 1"<<endl;
                int temp = incBy - floor(incBy / 26) * 26;

                if (int(a) + temp >= 123)
                {
                    // cout<<"entered"<<endl;
                    incBy = (int(a) + temp) - 123;
                    A = 'a';
                }
                else
                {
                    incBy = temp;
                }
            }

            if (((int(a)) <= 90 && (int(a) + incBy) >= 65) && ((int(a) + incBy) >= 91))
            {
                // cout<<"enter 2"<<endl;
                int temp = incBy - floor(incBy / 26) * 26;
                if (int(a) + temp >= 91)
                {
                    incBy = (int(a) + temp) - 91;
                    A = 'A';
                }
                else
                {
                    incBy = temp;
                };
            }

            if (s[i] == a)
            {
                char temp = s[i];
                s[i] = char(int(A) + incBy);
                // cout << "Changing " << temp << " at " << i << " to " << s[i] << " with incby as " << incBy <<" and A is "<<A<< endl;
                break;
            }
        }
    }

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    cout << result << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
