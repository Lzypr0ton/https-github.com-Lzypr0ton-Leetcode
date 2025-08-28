class Solution:
    def sortMatrix(self, grid):
        n = len(grid)

        # helper to collect, sort, and refill diagonal
        def process(i, j, reverse):
            cells = []
            x, y = i, j
            while x < n and y < n:
                cells.append(grid[x][y])
                x += 1
                y += 1

            cells.sort(reverse=reverse)

            x, y = i, j
            for val in cells:
                grid[x][y] = val
                x += 1
                y += 1

        # bottom-left incl. main diagonal (reverse=True for descending)
        for i in range(n):
            process(i, 0, True)

        # top-right diagonals (reverse=False for ascending)
        for j in range(1, n):
            process(0, j, False)

        return grid

