#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */
int checkadj(int i, int j, vector<vector<int>> A)
{

    int adjTop = 0;
    if ((i - 1) >= 0)
    {
        adjTop = A[i - 1][j];
    }

    int adjRight = 0;
    if ((j+1) < A[i].size())
    {
        adjRight = A[i][j + 1];
    }

    int adjBottom = 0;
    if ((i+1) < A.size())
    {
        adjBottom = A[i + 1][j];
    }

    int adjLeft = 0;
    if ((j-1) >= 0)
    {
        adjLeft = A[i][j - 1];
    }

    int darea = 6 + (A[i][j] - 1) * 4;
    int da = A[i][j];

    int area = darea - min(da, adjTop) - min(da, adjRight) - min(da, adjBottom) - min(da, adjLeft);

    return area;
}
int surfaceArea(vector<vector<int>> A)
{

    int rarea = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            // cout << A[i][j] << " ";
            if (A[i][j] != 0)
            {
                rarea += checkadj(i, j, A);
                // std::cout << "area is "<<rarea << std::endl;
            }
        }

        // std::cout << rarea << std::endl;
        // cout << endl;
    }

    return rarea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++)
    {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++)
        {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

    fout << result << "\n";

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
