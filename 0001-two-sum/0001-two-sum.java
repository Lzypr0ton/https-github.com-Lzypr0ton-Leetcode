import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store the number and its index
        HashMap<Integer, Integer> map = new HashMap<>();

        // Fill the HashMap
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        // Search for the two elements that sum up to the target
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            int rem = target - x;

            // Check if the remainder is in the map and not the same element
            if (map.containsKey(rem)) {
                int index = map.get(rem);
                if (index != i) {
                    return new int[]{i, index}; // Return the two indices
                }
            }
        }

        // Return an empty array if no solution is found
        return new int[]{};
    }
}

