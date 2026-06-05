class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int left, right, sum;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i >= 1 && nums[i] == nums[i-1])
                continue;

            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                vector<int> triplet = {nums[left], nums[i], nums[right]};
                if (sum == 0)
                    output.push_back(triplet);

                int pleft = left;
                int pright = right;

                if (sum <= 0) {
                    while (left < nums.size() && nums[left] == nums[pleft]) 
                        left++;
                }
                else if (sum >= 0) {
                    while (right > 0 && nums[right] == nums[pright])
                        right--;
                }
            }
        }
        return output;
    }
};
