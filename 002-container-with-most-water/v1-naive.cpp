#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        for (int i = 1; i < height.size(); i++) {
            for (int j = 0; j < i; j++) {
                res = max(res, min(height[i], height[j]) * (i - j));
            }
        }
        return res;
    }
};

int main() {
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(v) << endl;;
}
