from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        greater_map = {}
        stack = []
        
        for num in nums2:
            while stack and num > stack[-1]:
                greater_map[stack.pop()] = num
            stack.append(num)
            
        while stack:
            greater_map[stack.pop()] = -1
            
        return [greater_map[num] for num in nums1]
