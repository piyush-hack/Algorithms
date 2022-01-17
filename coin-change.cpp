#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c)
{

    sort(c.begin(), c.end());
    int64_t no = n;
    int64_t ts = 0;
    vector<int64_t> v;
    vector<int64_t> loc(51 , 0);
    for (int64_t i = 0; i < (no / c[0]); i++)
    {
        v.push_back(c[0]);
    }
    for (int64_t i = 0; i < c.size(); i++)
    {
        loc[c[i]] = i;
    }
    // for (int64_t a = 0; a < v.size(); a++)
    //     cout << v[a] << " ";

    // cout << endl;    

    int64_t sum = c[0] * (no / c[0]);
    if (sum == no)
    {
        ts++;
    }
    int64_t j = 0;
    while (v.size() > 0)
    {
        int64_t last =  v[v.size() - 1];
        sum = sum - last;
        // auto it = find(c.begin(), c.end(), v[v.size() - 1]);
        // int64_t y = it - c.begin();
        int64_t y = loc[last];
        // cout << "Sum After Pop : " << sum << " Trying To add > " << y << endl;
        v.pop_back();
        int64_t temp = sum;
        while (temp <= no)
        {
            if (temp + c[y + 1] <= no)
            {
                v.push_back(c[y + 1]);
                if ((temp + c[y + 1]) == no)
                {
                    // for (int64_t a = 0; a < v.size(); a++)
                    //     cout << v[a] << " ";

                    // cout << endl;    
                    ts++;
                }
                sum = sum + c[y + 1];
                // cout << "Sum After Push : " << sum << endl;
            }
            temp = temp + c[y + 1];
        }


    }

    cout << ts << endl;
    return ts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++)
    {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
