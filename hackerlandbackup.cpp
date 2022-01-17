#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

int hackerlandRadioTransmitters(vector<int> x, int k)
{

    int n = *max_element(x.begin(), x.end());

    int arr[n + 1] = {0};
    int towers[n + 1] = {0};

    for (int i = 0; i < x.size(); i++)
    {
        arr[x[i]] = x[i];
    }

    int ttowers = 0;
    int ctsnull = 0;
    int tnull = 0;
    int lnonnull = 0;
    int counter = 0;

    for (int i = 1; i < n + 1; i++)
    {
        // std::cout << " " << counter << " " << ctsnull << std::endl;

        if (counter == k || i == n)
        {
            if (ctsnull != k )
            {
                // std::cout << "i is " << i << std::endl;
                if (arr[i] == 0)
                {
                    if (arr[i + 1] != 0 && lnonnull >= (arr[i + 1] - k))
                    {
                        towers[i + 1] = 1;
                        // cout << "y addding tower at : " << i + 1 << endl;
                        ttowers++;
                        i = i + 1 + k;
                    }
                    else
                    {

                        towers[lnonnull] = 1;
                        ttowers++;
                        // cout << "x addding tower at : " << lnonnull << endl;
                        i = lnonnull + k;
                    }
                }
                else
                {
                    towers[i] = 1;
                    // cout << "y addding tower at : " << i << endl;

                    ttowers++;
                    i = i + k;
                }
            }else{
                i--;
            }

            counter = 0;
            ctsnull = 0;
            tnull = 0;
            // std::cout << "i is " << i << std::endl;
            // std::cout << std::endl;
        }
        else
        {
            if (arr[i] == 0)
            {
                ctsnull++;
                tnull++;
                // std::cout << "inc ctsnull and tnull at i " << i << std::endl;
            }
            else
            {
                ctsnull = 0;
                lnonnull = arr[i];
                // std::cout << "reset ctsnull at i " << i << std::endl;
            }

            counter++;
        }
    }

    // for (int i = 0; i < n + 1; ++i)

    // {

    //     cout << arr[i] << "  ";
    // }
    // cout << endl;
    // cout << ttowers;
    return ttowers;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
