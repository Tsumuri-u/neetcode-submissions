#include <map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;

        for (int i : nums) {
            if (freq.count(i)) {
                return true;
            }
            freq.insert(std::pair<int, int>(i, 1));
        }
        return false;
    }
};