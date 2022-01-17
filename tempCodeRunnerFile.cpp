long getWays(int n, vector<long> c)
{

    sort(c.begin(), c.end());
    int64_t no = n;
    int64_t ts = 0;
    vector<int64_t> v;
    vector<int64_t> loc(c[c.size() - 1] , 0);
    for (int64_t i = 0; i < (no / c[0]); i++)
    {
        v.push_back(c[0]);
    }
    for (int64_t i = 0; i < c.size(); i++)
    {
        loc[c[i]] = i;
    }
    // for (int64_t a = 0; a < v.size(); a++)
    //     cout << v[a] << " ";

    // cout << endl;    

    int64_t sum = c[0] * (no / c[0]);
    if (sum == no)
    {
        ts++;
    }
    int64_t j = 0;
    while (v.size() > 0)
    {
        sum = sum - v[v.size() - 1];
        // auto it = find(c.begin(), c.end(), v[v.size() - 1]);
        // int64_t y = it - c.begin();
        int64_t y = loc[v[v.size() - 1]];
        // cout << "Sum After Pop : " << sum << " Trying To add > " << y << endl;
        v.pop_back();
        int64_t temp = sum;
        while (temp <= no)
        {
            if (temp + c[y + 1] <= no)
            {
                v.push_back(c[y + 1]);
                if ((temp + c[y + 1]) == no)
                {
                    // for (int64_t a = 0; a < v.size(); a++)
                    //     cout << v[a] << " ";

                    // cout << endl;    
                    ts++;
                }
                sum = sum + c[y + 1];
                // cout << "Sum After Push : " << sum << endl;
            }
            temp = temp + c[y + 1];
        }


    }

    cout << ts << endl;
    return ts;
}
