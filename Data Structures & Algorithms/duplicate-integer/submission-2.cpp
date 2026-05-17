#include <map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};