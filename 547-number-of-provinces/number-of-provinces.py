from queue import Queue
class Solution:
    def bfs(self, curr, vis, isc):
        q = Queue()
        q.put(curr)
        vis[curr] = True

        while not q.empty():
            curr = q.get()

            for adj in isc[curr]:
                if not vis[adj]:
                    q.put(adj)
                    vis[adj] = True
        
            




    def findCircleNum(self, isc: List[List[int]]) -> int:
        V = len(isc)
        vis = [False]*V

        adj = []

        for i in range(V):
            here = []
            for j in range(V):        
                if i!=j and isc[i][j]==1:
                    here.append(j)
            adj.append(here)

        ans = 0
        for i in range(V):
            if not vis[i]:
                ans+=1
                self.bfs(i,vis,adj)
        
        return ans