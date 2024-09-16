class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int curMax = nums[0];  // Current max product
        int curMin = nums[0];  // Current min product
        int maxProduct = nums[0];  // Overall max product
        
        for (int i = 1; i < nums.size(); i++) {
            // Since the current number can flip the sign, we calculate the new curMax and curMin
            if (nums[i] < 0) {
                std::swap(curMax, curMin);  // Swap if current number is negative
            }

            // Update curMax and curMin by either taking the current number alone or multiplying it
            curMax = std::max(nums[i], curMax * nums[i]);
            curMin = std::min(nums[i], curMin * nums[i]);

            // Update the overall maximum product
            maxProduct = std::max(maxProduct, curMax);
        }

        return maxProduct;
    }
};
