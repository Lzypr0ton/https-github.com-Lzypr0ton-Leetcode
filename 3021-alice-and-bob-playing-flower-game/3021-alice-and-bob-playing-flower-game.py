class Solution(object):
    def flowerGame(self, n, m):
        oddX, evenX = (n + 1) // 2, n // 2
        oddY, evenY = (m + 1) // 2, m // 2
        return oddX * evenY + evenX * oddY

        