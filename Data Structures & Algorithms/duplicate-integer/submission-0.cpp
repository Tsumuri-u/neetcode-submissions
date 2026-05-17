#include <map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;
            } else {
                freq[nums[i]] = freq[nums[i]] + 1;
            }
        }

        for (auto i : freq) {
            if (i.second > 1) {
                return true;
            }
        }

        return false;
    }
};