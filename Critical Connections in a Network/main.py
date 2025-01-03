class Solution:
    def dfs(self,node,parent):
        self.vis[node] = True

        self.time[node] = self.timer
        self.low[node] = self.timer

        self.timer += 1

        for i in self.adj[node]:
            if(i == parent): continue

            if(not self.vis[i]):
                self.dfs(i,node)
                self.low[node] = min(self.low[node],self.low[i])

                if(self.low[i] > self.time[node]): 
                    self.ans.append([node,i])
            else:
                self.low[node] = min(self.low[node],self.low[i])
                

    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        self.adj = []
        self.ans = []
        for i in range(n): self.adj.append([])

        for u,v in connections:
            self.adj[u].append(v)
            self.adj[v].append(u)
        
        self.vis = [False] * n
        self.time = [10**9] * n
        self.low = [10**9] * n
        self.timer = 1

        self.dfs(0,-1)

        return self.ans

