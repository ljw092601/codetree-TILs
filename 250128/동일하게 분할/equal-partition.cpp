#include <iostream>

using namespace std;

int n;
int arr[100];
int dp[200000];
int temp[200000];
int sum = 0;

void copy() {
    for(int i=0; i<=sum; i++) {
        dp[i] = temp[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % 2) {
        cout << "No";
        return 0;
    }

    sum /= 2;
    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int p=0; p<sum; p++) {
            if(dp[p]) temp[p + arr[i]]++;
        }
        copy();
    }

    cout << (dp[sum] ? "Yes" : "No");

    return 0;
}
