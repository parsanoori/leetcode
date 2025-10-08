#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<bool> > dp;
    int n, m;
    string str, pat;

    void print2dArr(vector<vector<int> > arr) {
        for (auto tarr: arr) {
            for (auto element: tarr)
                cout << element << ' ';
            cout << endl;
        }
    }

public:
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();

        str = s;
        pat = p;

        dp = vector(n + 1, vector(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;

                if (i == 0) {
                    dp[i][j] = pat[j - 1] == '*' && dp[i][j - 2];
                }

                dp[i][j] =
                        pat[j - 1] == '*' && (pat[j - 2] == '.' || pat[j - 2] == str[i - 1]) && dp[i - 1][j] ||
                        pat[j - 1] == '*' && dp[i][j - 2] ||
                        (pat[j - 1] == '.' || pat[j - 1] == str[i - 1]) && dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};


int main() {
    Solution s;
    cout << s.isMatch("a", "..*") << endl;
}
