#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    int N = 0;
    int K;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N = 0;
        int K;
        cin >> N >> K;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        // cout << "sum is : " << sum << endl;

        float n = 0;
        int comp = floor((sum) / (N + n));
        int ans = 0;
        while (comp > K)
        {
            if (floor((sum) / (N + n)) > K)
            {
                comp = floor((sum) / (N + n));
                // cout << "At " << n << " Comp is " << comp << endl;
                n++;
            }
            else
            {
                ans = n;
                // cout << "At " << n << " Comp is " << comp << endl;

                break;
            }
        }

        // n = (float)(sum -N*K)/K;
        // cout<<"my n is "<<n<<" and sum is "<<sum<<endl;
        // float intcheck = n - floor(n);
        // if(intcheck == 0){
        //     n = (int)(n-1);
        //     cout<<"enetered";
        // }else{
        //     n = (int)floor(n);
        // }
        // cout << n << endl;
    }
}
