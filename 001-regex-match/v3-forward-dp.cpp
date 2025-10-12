#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<bool> > dp;
    int n, m;
    string s, p;

public:
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();

        dp = vector(n + 1, vector(m + 1, false));

        // initial values for edge cases
        dp[0][0] = true;
        dp[1][1] = p[0] == s[0] || p[0] == '.';

        for (int i = 0; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                if (i == 0) {
                    dp[i][j] = p[j - 1] == '*' && dp[i][j - 2];
                    continue;
                }

                dp[i][j] =
                        p[j - 1] == '*' && (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j] ||
                        p[j - 1] == '*' && dp[i][j - 2] ||
                        (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};


int main() {
    Solution s;
    cout << s.isMatch("a", "..*") << endl;
}
