#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

struct values
{
    int i;
    vector<int> weights;
};

values v;
values check(int i, char a, string s, bool repeat)
{
    if (s[i] == a)
    {
        if (repeat == false)
        {
            int weight = int(a) - 96;
            v.weights.push_back(weight);
        }
        else
        {
            int weight = int(a) - 96 + *(v.weights.end() - 1);
            v.weights.push_back(weight);
        }
    }
    else
    {
        v.i = i;
        return v;
    }


    if (s[i + 1] == a)
    {
        v.i = i++;
        return check(i++, a, s, true);
    }
    else
    {
        v.i = i;
        return v;
    }
}

vector<string> weightedUniformStrings(string s, vector<int> queries)
{

    vector<string> ans{};
    vector<int> myweights{};
	std::vector<int>::iterator it;

    // Strings can be added at any time with push_back
    // Print Strings stored in Vector
    for (int i = 0; i < s.length(); i++)
    {
        for (char a = 'a'; a <= 'z'; a++)
        {
            i = check(i, a, s, false).i;
            myweights = check(i, a, s, false).weights;
        }
    }

    for (auto i = queries.begin(); i != queries.end(); ++i)
    {
        int ser = *i;
        it = find(myweights.begin(), myweights.end(), ser);
        if (it != myweights.end())
        {
            ans.push_back("Yes");
            // std::cout << "Element " << ser <<" found at position : " ;
            // std::cout << it - vec.begin() << " (counting from zero) \n" ;
        }
        else
        {
            ans.push_back("No");
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

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
