class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> added;
        for (int n : nums)
            added[n] = n;

        int out = 0;

        for (pair n : added) {
            if (added.find(n.first-1) == added.end()) {
                int count = 0;
                int curr = n.first;
                while (added.find(curr) != added.end()) {
                    count++;
                    curr++;
                }
                out = max(out, count);
            }
        }

        return out;
    }
};
