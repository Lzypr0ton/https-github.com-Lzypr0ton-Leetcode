class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        m, n = len(mat), len(mat[0])
        result = []
        
        # Traverse over all possible sums of indices (diagonals)
        for d in range(m + n - 1):
            temp = []
            # Collect elements in this diagonal
            for i in range(max(0, d - n + 1), min(m, d + 1)):
                j = d - i
                temp.append(mat[i][j])
            
            # Reverse every alternate diagonal
            if d % 2 == 0:
                temp.reverse()
            
            result.extend(temp)
        
        return result
