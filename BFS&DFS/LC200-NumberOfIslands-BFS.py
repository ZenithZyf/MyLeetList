class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # Get the size of the input map
        m = len(grid)
        n = len(grid[0])
        # A bfs search 
        l = collections.deque()
        
        num_islands = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    # find one island
                    num_islands += 1
                    # visited
                    grid[i][j] = '0'
                    l.append((i, j))
                    # bfs until no neighbors equal to "1"
                    while l:
                        r, c = l.popleft()
                        # check the four neighboring
                        for y, x in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
                            if 0 <= y < m and 0 <= x < n and grid[y][x] == '1':
                                # we will visit it soon
                                l.append((y, x))
                                grid[y][x] = '0'
        
        return num_islands
                                
                    
                    
        
        
