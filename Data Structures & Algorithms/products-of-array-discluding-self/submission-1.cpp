class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), suffix(nums.size());
        int preprod = 1, sufprod = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = preprod;
            preprod *= nums[i];
            cout << prefix[i] << "\n";
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = sufprod;
            sufprod *= nums[i];
            cout << suffix[i] << "\n";
        }

        vector<int> output(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            output[i] = prefix[i] * suffix[i];
        }

        return output;
    }
};
