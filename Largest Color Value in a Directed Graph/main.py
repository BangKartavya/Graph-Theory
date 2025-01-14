class Solution:
    def cycle(self):
        indegree = [0]*self.n

        for i in range(self.n):
            for it in self.adj[i]:
                indegree[it]+=1
        
        q = deque()

        for i in range(self.n):
            if(indegree[i] == 0):
                q.append(i)

        res = []
        
        while q:
            node = q.popleft()
            res.append(node)
            for it in self.adj[node]:
                indegree[it]-=1

                if(indegree[it] == 0):
                    q.append(it)
        
        return len(res) != self.n

    def dfs(self,node):
        if(self.vis[node]):
            return 0
        
        self.vis[node] = True

        colorIndex = ord(self.colors[node]) - ord('a')
        self.count[node][colorIndex] = 1

        for it in self.adj[node]:
            self.dfs(it)
            for i in range(26):
                self.count[node][i] = max(self.count[node][i], (1 if i == colorIndex else 0) + self.count[it][i])
        
        return max(self.count[node])

    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        self.n = len(colors)
        self.colors = colors
        self.adj = [[] for i in range(self.n)]

        for edge in edges:
            self.adj[edge[0]].append(edge[1])
        
        if(self.cycle()): return -1

        self.count = [[0]*26 for i in range(self.n)]
        self.vis = [False]*self.n

        maxi = 0

        for i in range(self.n):
            maxi = max(maxi,self.dfs(i))

        
        return maxi
