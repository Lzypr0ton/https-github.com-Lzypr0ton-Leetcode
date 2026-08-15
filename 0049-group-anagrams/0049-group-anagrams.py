from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = {}
        
        for i in range(len(strs)):
            word = strs[i]
            sorted_key = "".join(sorted(word))
            
            if sorted_key not in anagram_map:
                anagram_map[sorted_key] = []
                
            anagram_map[sorted_key].append(word)
            
        return list(anagram_map.values())
