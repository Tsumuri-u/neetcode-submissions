class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros = 0;
        for (int i : nums) {
            if (i != 0)
                product *= i;
            else
                zeros++;
        }
        vector<int> output(nums.size(), 0);

        cout << product << "\n";

        if (zeros >= 2)
            return output;

        for (int i = 0; i < nums.size(); i++) {
            if (zeros && !nums[i])
                output[i] = product;
            else if (!zeros)
                output[i] = product / nums[i];
        }

        return output;
    }
};
