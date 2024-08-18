from queue import Queue
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        r = len(mat)
        c = len(mat[0])

        vis = set()
        ans = [[0 for j in range(c)]for i in range(r)]
        q = Queue()

        for i in range(r):
            for j in range(c):
                if mat[i][j] == 0:
                    q.put((i,j,0))
                    vis.add((i,j))

        drow = [1,-1,0,0]
        dcol = [0,0,1,-1]
        
        while not q.empty():
            i,j,cdist = q.get()
            ans[i][j] = cdist

            for k in range(4):
                ci = i + drow[k]
                cj = j + dcol[k]

                if (ci >=0 and ci < r and cj >= 0 and cj < c and ((ci,cj) not in vis)):
                    q.put((ci,cj,cdist+1))
                    vis.add((ci,cj))
        
        return ans

        