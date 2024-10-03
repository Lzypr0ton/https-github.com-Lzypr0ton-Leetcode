class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0; // Use 'remainder' to store the mod value of the sum of array.

        // Calculate the sum of nums mod p.
        for (int& num : nums) {
            remainder = (remainder + num) % p;
        }

        // If the remainder is 0, the whole array satisfies the condition.
        if (remainder == 0) {
            return 0;
        }

        // Use a hashmap to store the most recent index where a certain mod value was seen.
        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1;
        int n = nums.size(); // The length of the nums array.
        int minLength = n; // Initialize minLength with the maximum possible length.
        int currentSum = 0; // Running sum of the elements.

        // Iterate through the nums array.
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate the target mod value that could potentially reduce the running sum to a multiple of p.
            int target = (currentSum - remainder + p) % p;

            // If the target is found in the map, update the minLength with the shortest length found so far.
            if (modIndexMap.count(target)) {
                minLength = min(minLength, i - modIndexMap[target]);
            }

            // Update the map with the current cumulative mod value and current index.
            modIndexMap[currentSum] = i;
        }

        // If minLength is not changed, return -1 for no such subarray, otherwise return the minLength.
        return minLength == n ? -1 : minLength;
    }
};