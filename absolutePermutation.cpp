#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(int n, int k)
{

    map<int, int> mp;
    vector<int> vec;
    int diff = 0;
    for (int i = 1; i <= n; i++)
    {
        mp.insert({i, i});
    }

    // map<int, int>::iterator itr;


    // for (itr = mp.begin(); itr != mp.end(); ++itr)
    // {
    //     cout << itr->first<<" " ;
    // }
    // std::cout <<std::endl;

    //find its corresponding i such that |given no - i| exists in map 
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            diff = i + k;

            if(!(mp[diff])){
                int temp = i - k;
                if(mp[temp]){
                    diff = temp;
                }
            }
        }
        else
        {
            diff = i - k;
            
            if(!(mp[diff])){
                int temp = i + k;
                if(mp[temp]){
                    diff = temp;
                }
            }
        }
        // std::cout << diff << std::endl;

        if (mp[diff])
        {
            vec.push_back(diff);
            mp.erase((diff));
            // std::cout <<"pusshed and deleted " << diff<< std::endl;

        }
        else
        {
            // std::cout << "no is "<< i <<" " << diff << " not found hence breaking"<< std::endl;
            vector<int> dum;
            dum.push_back(-1);
            return dum;
            break;
        }
    }

    return vec;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++)
        {
            cout << result[i];

            if (i != result.size() - 1)
            {
                cout << " ";
            }
        }

        cout << "\n";
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
