class Solution:

    def dfs(self,node):
        self.vis[node] = True
        changes = 0
        for i in self.adj[node]:
            if(not self.vis[abs(i)]):
                changes += self.dfs(abs(i)) + (i > 0)
        return changes

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        self.adj = []
        self.vis = [False] * n
        for i in range(n): self.adj.append([])

        for i in connections:
            self.adj[i[0]].append(i[1])
            self.adj[i[1]].append(-i[0])
        

        return self.dfs(0)
