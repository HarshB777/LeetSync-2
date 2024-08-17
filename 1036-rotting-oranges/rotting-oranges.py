from queue import Queue

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = Queue()
        r = len(grid)
        c = len(grid[0])

        vis = set()

        for i in range(r):
            for j in range(c):
                if grid[i][j] == 2:
                    q.put((i,j,0))
                    vis.add((i,j))
        
        drow = [1,-1,0,0]
        dcol = [0,0,1,-1]

        ans = 0
        cnt = 0
        while not q.empty():
            i,j,ct = q.get()
            cnt += 1
            for k in range(4):
                ci = i + drow[k]
                cj = j + dcol[k]

                if (ci >= 0 and ci < r and cj >= 0 and cj < c) and ((ci,cj) not in vis) and (grid[ci][cj] == 1):
                    #print("inside if")
                    q.put((ci,cj,ct+1))
                    vis.add((ci,cj))
                    ans = ct+1
        
        
        
        
        
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1 and ((i,j) not in vis):
                    return -1
        
        return ans



        