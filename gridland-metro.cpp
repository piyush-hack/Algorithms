#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const bool debugOn = false;

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */

long long gridlandMetro(long long n, long long m, int k, std::vector<std::vector<int>> track)
{
    long long ans = 0;

    std::unordered_map<int, std::vector<std::pair<int, int>>> rows;

    for(int i = 0; i < k; ++i)
    {
        int row = track[i][0];
        int col1 = track[i][1];
        int col2 = track[i][2];

        if(rows.count(row) == 0)
        {
            std::vector<std::pair<int, int>> v = { std::make_pair(col1, col2) };
            rows.emplace(row, v);
            continue;
        }

        rows[row].push_back(std::make_pair(col1, col2));
    }

    for(auto rowItr = rows.begin(); rowItr != rows.end(); ++rowItr)
    {
        if(rowItr->second.empty()) continue;
        std::sort(rowItr->second.begin(), rowItr->second.end());
        auto itr = rowItr->second.begin();
        auto nextItr = itr + 1;

        do
        {
            if(nextItr == rowItr->second.end()) break;

            if(itr->first == nextItr->first)
            {
                if(itr->second > nextItr->second)
                {
                    // nextItr is merged into itr. //
                    if(debugOn)
                    {
                        std::cout << nextItr->first << "," << nextItr->second << " merged into " << itr->first << "," << itr->second << " ";
                        std::cout << "Result is " << itr->first << "," << itr->second << "\n";
                    }

                    // Delete the nextItr here.
                    //
                    nextItr = rowItr->second.erase(nextItr);
                }
                else
                {
                    // itr is merged into itr. //
                    if(debugOn)
                        std::cout << itr->first << "," << itr->second << " merged into " << nextItr->first << "," << nextItr->second << " ";

                    itr->second = nextItr->second;

                    if(debugOn)
                        std::cout << "Result is " << itr->first << "," << itr->second << "\n";

                    // Delete the nextItr here.
                    //
                    nextItr = rowItr->second.erase(nextItr);
                }
            }
            else if(itr->first < nextItr->first)
            {
                if(itr->second >= nextItr->first)
                {
                    // There is an overlap. Merge nextItr into itr. //
                    if(debugOn)
                        std::cout << nextItr->first << "," << nextItr->second << " merged into " << itr->first << "," << itr->second << " ";

                    itr->second = std::max(itr->second, nextItr->second);
                    if(debugOn)
                        std::cout << "Result is " << itr->first << "," << itr->second << "\n";

                    // Delete the nextItr here.
                    //
                    nextItr = rowItr->second.erase(nextItr);
                }
                else
                {
                    // There is no overlap.
                    //
                    if(debugOn)
                    {
                        std::cout << itr->first << "," << itr->second << " cannot merged into " << nextItr->first << "," << nextItr->second << " ";
                        std::cout << "Result is " << itr->first << "," << itr->second << "\n";
                    }

                    itr = nextItr;
                    ++nextItr;
                }
            }
        } while(itr != rowItr->second.end() || nextItr != rowItr->second.end());
    }

    for(auto rowItr = rows.begin(); rowItr != rows.end(); ++rowItr)
    {
        for(auto itr = rowItr->second.begin(); itr != rowItr->second.end(); ++itr)
        {
            //std::cout << "Occupying " << itr->first << "," << itr->second << "\n";
            ans += (itr->second - itr->first);
            ++ans;
        }
    }

    return ( n * m ) - ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<int>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    long long result = gridlandMetro(n, m, k, track);

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