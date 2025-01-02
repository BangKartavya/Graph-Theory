class Solution:
    def dfs(self,node):
        self.vis[node] = True
        self.curr_path[node] = True

        for i in self.adj[node]:
            if(not self.vis[i]):
                if(self.dfs(i)): return True
            elif (self.curr_path[i]): return True
        
        self.curr_path[node] = False
        return False

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        self.adj = graph
        self.n = len(graph)
        self.curr_path = [False]*self.n
        self.vis = [False]*self.n


        for i in range(self.n):
            if(not self.vis[i]):
                self.dfs(i)
        
        ans = []

        for i in range(self.n):
            if(not self.curr_path[i]): ans.append(i)

        return ans
