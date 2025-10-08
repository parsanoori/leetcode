#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > dp;
    int n, m;
    string str, pat;

    bool _isMatch(int i, int j) {
        if (j == 0) {
            return i == 0;
        }


        bool isStar = pat[j - 1] == '*';
        if (i > 0) {
            if (isStar) {
                if (pat[j - 2] == str[i - 1] || pat[j - 2] == '.')
                    return _isMatch(i - 1, j) || _isMatch(i, j - 2); // read or not
                else return _isMatch(i, j - 2);
            } else {
                return (pat[j - 1] == str[i - 1] || pat[j - 1] == '.') && _isMatch(i - 1, j - 1);
            }
        }
        return isStar && _isMatch(i, j - 2);
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
        n = s.length();
        m = p.length();

        str = s;
        pat = p;

        return _isMatch(n, m);
    }
};


int main() {
    Solution s;
    cout << s.isMatch("a", "..*") << endl;
}
