#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> values;
        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if (values.find(compliment) != values.end()) {
                return {values[compliment], i};
            }
            values[nums[i]] = i;
        }
        return {};
    }
};
