#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {

        int N;
        int K;
        string S;

        cin >> N;
        cin >> K;
        cin >> S;

        int length = S.length();
        int maxRem = 0;
        for (int i = 0; i < length; i++)
        {

            string repStr = S;
            repStr.erase(repStr.begin() + i);
            // cout << "After erase : " << repStr << endl;
            int num = stoi(repStr);
            int rem = num - (floor(num / K) * K);
            if (rem > maxRem)
            {
                maxRem = rem;
            }
        }

        cout << "Answer is " << maxRem<<endl;
        // cout<<maxRem<<endl;

        T--;
    }
}
