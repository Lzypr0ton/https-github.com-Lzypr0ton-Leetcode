class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Check if the mid element is the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[start] <= nums[mid]) {
                // Target is within the sorted left half
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // Target is within the sorted right half
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        // Target not found
        return -1;
    }
};
