#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto i : freq) {
            buckets[i.second].push_back(i.first);
        }

        int count = 0;
        vector<int> output;

        for (int i = buckets.size() - 1; i >= 0; i--) {
            if (!buckets[i].empty()) {
                for (int j : buckets[i]) {
                    output.push_back(j);
                }
                count += buckets[i].size();
            }

            if (count == k) break;
        }

        return output;
    }
};