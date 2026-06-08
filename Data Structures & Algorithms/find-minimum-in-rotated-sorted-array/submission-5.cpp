class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid = (right - left) / 2;

        while (left < right) {
            if ((right - left) < 2)
                return min(nums[left], nums[right]);
            if (nums[left] < nums[mid] && nums[left] < nums[right])
                return nums[left];
            
            if (nums[left] > nums[mid]){
                right = mid;
                mid = left + (right - left) / 2;
            }
            else {
                left = mid;
                mid = left + (right - left) / 2;
            }
        }
        return nums[left];
    }
};
