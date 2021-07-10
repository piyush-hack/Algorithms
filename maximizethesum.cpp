#include <bits/stdc++.h>

using namespace std;

void sortarr(int *arr, int N, int K)
{
	int point = arr[0];
	int *arr2 = new int[N];
	sort(arr, arr + N);

	int ans = 0;
	// cout << "\nArray after sorting using "
	// 		"default sort is : \n";
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << " ";

	// cout << endl;

	int reSum = 0;
	bool isrepeating = false;
	for (int i = 0; i < N; i++)
	{
		reSum = arr[i];
		if (arr[i] >= 0)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (arr[i] == arr[j])
				{
					reSum += arr[j];
					arr[j] = -1;
					isrepeating = true;
				}
			}
			if (isrepeating == true)
			{
				arr[i] = reSum;
			}
			isrepeating = false;
		}
	}

	// cout << "\nArray after adding repeat:  \n";
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << " ";
	// cout<<endl;


	sort(arr, arr + N);

	int i = 0;
	int n = N - 1;
	while (i < K)
	{
		int check = arr[n - i];
		// cout << check << arr[n - i - 2] << endl;
		if (ans + arr[n - i] >= ans)
		{
			ans += arr[n - i];
			// cout << i << " time sum after adding " << arr[n - i] << " is " << ans << endl;
		}
		else
		{
			// cout << i << " time break with ans:" << ans << endl;

			break;
		}

		i++;
	}

	// cout << "my ans is " << ans;
	cout << ans << endl;
}

void takeinput(int T)
{
	int N = 0;
	int K;
	cin >> N >> K;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sortarr(arr, N, K);
}

int main()
{
	int T;
	int N = 0;
	int K;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		takeinput(T);
	}
	cin >> K >> N;
	int *arr = new int[N];
}
