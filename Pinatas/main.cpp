#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxCandies(const vector<int>& pinatas) {
    int n = pinatas.size();
    vector<int> extendedPinatas(n + 2, 1);
    for (int i = 0; i < n; ++i) {
        extendedPinatas[i + 1] = pinatas[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int length = 1; length <= n; ++length) {
        for (int left = 1; left <= n - length + 1; ++left) {
            int right = left + length - 1;
            for (int i = left; i <= right; ++i) {
                dp[left][right] = max(dp[left][right],
                    extendedPinatas[left - 1] * extendedPinatas[i] * extendedPinatas[right + 1]
                    + dp[left][i - 1] + dp[i + 1][right]);
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> pinatas = { 3, 1, 5, 8};
    cout << "Max number candies: " << maxCandies(pinatas) << endl;


    return 0;
}
