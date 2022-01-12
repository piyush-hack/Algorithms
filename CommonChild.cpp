#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */


int commonChild(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int max = 0;
    vector<vector<int>> grid(n+1, vector<int>(m+1));

    for (int i = 1; i < n+1 ; i++) {
        for (int j = 1; j < m+1; j++) {
            if(s1[i-1] != s2[j-1]){
                if(grid[i-1][j] > grid[i][j-1]){
                    grid[i][j] = grid[i-1][j];
                }
                else {
                    grid[i][j] = grid[i][j-1];
                }
            }
            else{
                grid[i][j] = grid[i-1][j-1]+1;
                if(grid[i][j] > max){
                    max = grid[i][j];
                }
            }
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
