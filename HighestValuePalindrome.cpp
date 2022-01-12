#include <iostream>
#include <string>

using namespace std;

int main (void) {

    int n, k;
    int i = 0;
    string num;

    cin >> n >> k >> num;

    if (k >= n) {
        cout << string(n, '9') << '\n';
    } else {
        int changes = 0;
        for (i = 0; i < n/2; i++) {
            if (num[i] != num[n-1-i])
                changes++;
        }

        if (changes > k) {
            cout << "-1\n";
        } else {
            for (i = 0; i < n/2; i++) {
                if (num[i] == '9') {
                    if (num[n-1-i] != '9') {
                        num[n-1-i] = '9';
                        k--;
                        changes--;
                    }
                } else {
                    if (num[i] == num[n-1-i]) {
                        if (k - changes >= 2) {
                            num[i] = '9';
                            num[n-1-i] = '9';
                            k -= 2;
                        }
                    } else {
                        if (num[n-1-i] == '9') {
                            num[i] = '9';
                            k--;
                            changes--;
                        } else if (k - changes >= 1) {
                            num[i] = '9';
                            num[n-1-i] = '9';
                            changes--;
                            k -= 2;
                        } else {
                            char max = num[i] > num[n-1-i] ? num[i] : num[n-1-i];
                            num[i] = max;
                            num[n-1-i] = max;
                            changes--;
                            k--;
                        }
                    }
                }
            }

            if (k > 0 && n % 2)
                num[n/2] = '9';

            cout << num << '\n';
        }
    }

    return 0;
}
