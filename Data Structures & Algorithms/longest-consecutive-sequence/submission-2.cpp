class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> added;
        for (int n : nums)
            added[n] = n;

        int max = 0;

        for (int n : nums) {
            if (added.find(n-1) == added.end()) {
                int count = 0;
                int curr = n;
                while (added.find(curr) != added.end()) {
                    count++;
                    curr++;
                }
                if (count > max)
                    max = count;
            }
        }

        return max;
    }
};
