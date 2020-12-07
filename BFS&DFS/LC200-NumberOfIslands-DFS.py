class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # Get the size of the input map
        m = len(grid)
        n = len(grid[0])
        
        num_islands = 0
        # dfs to find number of islands
        for i in range(m):
            for j in range(n):
                # if encounter a "1", then dfs:
                if grid[i][j] == '1':
                    num_islands += 1
                    self.dfs(grid, i, j)
        
        return num_islands
    
    def dfs(self, grid: List[List[str]], i: int, j: int) -> None:
        # we have visited it
        grid[i][j] = '0'
        
        # we will visit four neighbors
        for y, x in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
            if 0 <= y < len(grid) and 0 <= x < len(grid[0]) and grid[y][x] == '1':
                self.dfs(grid, y, x)
                                
                    
                    
        
        
