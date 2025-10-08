#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > dp;

    bool _isMatch(string s, string p, int i, int j, int n, int m) {

        if (j == m) return i == n;

        //cout << "s[:i]: " << s.substr(0, i + 1) << " p[:j]: " << p.substr(0, j + 1) << " i: " << i << " j: " << j << endl;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool nextIsStar = j < m - 1 && p[j + 1] == '*';
        if (nextIsStar) {
            // don't read
            if (_isMatch(s, p, i, j + 2, n, m))
                return dp[i][j] = true;

            // if * matches then try reading
            if (i == n)
                return dp[i][j] = false;

            bool match = s[i] == p[j] || p[j] == '.';
            if (match && _isMatch(s, p, i + 1, j, n, m))
                return dp[i][j] = true;

            return dp[i][j] = false;
        }
        if (i < n && (s[i] == p[j] || p[j] == '.')) {
            return dp[i][j] = _isMatch(s, p, i + 1, j + 1, n, m);
        }
        return dp[i][j] = false;
    }

    void print2dArr(vector<vector<int> > arr) {
        for (auto tarr: arr) {
            for (auto element: tarr)
                cout << element << ' ';
            cout << endl;
        }
    }

public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        dp = vector(n + 1, vector(m + 1, -1));

        return = _isMatch(s, p, 0, 0, n, m);
    }
};


int main() {
    Solution s;

    cout << s.isMatch("aaaaabaccbbccababa", "a*b*.*c*c*.*.*.*") << endl;
}
