#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            res = max(min(height[i], height[j]) * (j - i), res);

            height[i] < height[j] ? ++i : --j;
        }

        return res;
    }
};

int main() {
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(v) << endl;;
}
