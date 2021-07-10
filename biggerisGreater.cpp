#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string biggerIsGreater(string w)
{

    int arr[w.length()];
    int len = w.length();
    for (int i = 0; i < w.length(); i++)
    {
        char a = w[i];
        arr[i] = int(a);
    }

    // for (int i = 0; i < w.length(); i++)
    // {
    //     std::cout << arr[i] << " ";
    // }

    int changeFrom = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            changeFrom = i;
            break;
        }
    }

    // cout << endl;
    std::cout << changeFrom << std::endl;

    if (changeFrom > 0)
    {
        sort(arr + changeFrom, arr + len);

        for (int i = changeFrom; i < len; i++)
        {
            if (arr[changeFrom - 1] < arr[i])
            {
                int temp = arr[changeFrom - 1];
                arr[changeFrom - 1] = arr[i];
                arr[i] = temp;
                break;
            }
        }

        string s = "";
        for (int i = 0; i < len; i++)
        {
            s += char(arr[i]);
        }

    //    std::cout << s << std::endl;
       return s;
    }
    else
    {
        return "no answer";
    }

    return "test";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
    }

    fout.close();

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
