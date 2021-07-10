#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
bool issorted(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < a[i + 1])
        {
        }
        else
        {
            return false;
            std::cout << " not sort" << std::endl;
            break;
        }
    }
    std::cout << "is sort" << std::endl;
    return true;
}

void almostSorted(vector<int> arr)
{

    vector<int> a = arr;
    auto it = a.insert(a.begin(), -1);
    a.push_back(2000000);

    vector<int> aa = arr;
    auto ite = aa.insert(aa.begin(), -1);
    aa.push_back(2000000);

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }

    int N = a.size();

    if (is_sorted(a.begin(), a.end()))
    {
        std::cout << "YES" << std::endl;
        return;
    }
    
    bool set = false;
    int rrset = 0;
    int rd = 0;
    int rr = rd;
    int c;
    int next;
    int prev;
    int d;
    int r;
    bool swapped = false;
    for (int i = 1; i < N - 1; i++)
    {
        if (a[i] > a[i + 1] && set == false)
        {
            rd = i;
            rr = rd;
            c = i;
            next = a[i + 1];
            prev = a[i - 1];
            set = true;
            // std::cout << "set a[c] as "<< a[c] << " with c as" << c << std::endl;
            continue;
        }

        if (set == true && rrset == 0)
        {

            if (a[i+1] <a[i])
            {
                rr = i;
                // std::cout << "rr now is " << i << std::endl;
            }
            else
            {
                rr++;
                // std::cout << "set rr to "<< rr << std::endl;
                rrset = 1;
            }
        }

        if (set == true && a[c] <= a[i + 1] && a[c] >= a[i - 1] && a[i] <= next && a[i] >= prev)
        {
            
            swap(a[c], a[i]);
            d = c;
            r = i;
            swapped = true;
            // std::cout << "swapping " << a[c] << " and " << a[i] << std::endl;
            break;
        }
    }


    if (is_sorted(a.begin(), a.end()))
    {

        std::cout << "yes" << std::endl;
        std::cout << "swap " << d << " " << r << std::endl;
        return;
    }

    if (set == true & rrset == 1)
    {
        // std::cout << " sorting subset for rd "<< rd<<" and rr "<< rr << std::endl;
        sort(aa.begin() + rd, aa.begin() + rr + 1); 
    }

    // for (int i = 0; i < aa.size(); i++)
    // {
    //     cout << aa[i] << " ";
    // }

    if (is_sorted(aa.begin(), aa.end()))
    {

        std::cout << "yes" << std::endl;
        std::cout << "reverse " << d << " " << r << std::endl;
        return;
    }

    std::cout << "no" << std::endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
