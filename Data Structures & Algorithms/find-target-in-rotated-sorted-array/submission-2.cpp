class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = (r - l) / 2;

        while (l <= r) {
            if (nums[l] == target)
                return l;
            if (nums[r] == target)
                return r;
            if (nums[mid] == target)
                return mid;
            if (l == mid || r == mid)
                break;
            
            if (nums[l] < nums[mid]) {
                if (target < nums[l] || target > nums[mid]) {
                    l = mid;
                    mid = l + (r - l) / 2;
                }
                else {
                    r = mid;
                    mid = l + (r - l) / 2;
                }
            }
            else {
                if (target > nums[l] || target < nums[mid]) {
                    r = mid;
                    mid = l + (r - l) / 2;
                }
                else {
                    l = mid;
                    mid = l + (r - l) / 2;
                }
            }
        }
        return -1;
    }
};
