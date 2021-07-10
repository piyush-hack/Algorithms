#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int n;
map<pair<int , int>, int> q;

int right(int rq, int cq){

    int attacks = 0;
    while(cq<n){
        cq++;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int left(int rq, int cq){

    int attacks = 0;
    while(cq>1){
        cq--;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int top(int rq, int cq){

    int attacks = 0;
    while(rq<n){
        rq++;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int bottom(int rq, int cq){

    int attacks = 0;
    while(rq>1){
        rq--;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int top_right(int rq, int cq){

    int attacks = 0;
    while(rq<n && cq < n){

        rq++;
        cq++;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int bottom_right(int rq, int cq){

    int attacks = 0;
    while(rq>1 && cq < n){

        rq--;
        cq++;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int bottom_left(int rq, int cq){

    int attacks = 0;
    while(rq>1 && cq > 1){

        rq--;
        cq--;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int top_left(int rq, int cq){

    int attacks = 0;
    while(rq<n && cq > 1){

        rq++;
        cq--;

        if(q[{rq, cq}]){
            break;
        }
        attacks++;
    }
    return attacks;
}

int queensAttack(int N, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    for (auto i = 0; i < obstacles.size(); i++)
    {
        q[{obstacles[i][0], obstacles[i][1]}] = 1;
        
    }

    n = N;


    int a  = right(r_q, c_q) + left(r_q, c_q) + top(r_q, c_q) + bottom(r_q, c_q) + top_right(r_q, c_q)+
            bottom_right(r_q, c_q) + bottom_left(r_q, c_q) + top_left(r_q, c_q);
    
    // cout << right(r_q, c_q) << " " << left(r_q, c_q)<<" " << top(r_q, c_q) <<" " << bottom(r_q, c_q) <<" " << top_right(r_q, c_q)<<" " <<
    //         bottom_right(r_q, c_q) <<" " << bottom_left(r_q, c_q) <<" " << top_left(r_q, c_q) << endl;
    // std::cout << "a is : "<< a << std::endl;
    return a; 

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
