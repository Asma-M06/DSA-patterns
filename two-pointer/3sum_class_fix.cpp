#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    auto res = sol.threeSum(nums);
    for (auto &trip : res) {
        cout << "[";
        for (int i = 0; i < (int)trip.size(); ++i) {
            if (i) cout << ", ";
            cout << trip[i];
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
