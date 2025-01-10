class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        vis = [False] * n
        col = [-1] * n

        q = deque()

        for i in range(n):
            if(not vis[i]):
                q.append((i,0))
                col[i] = 0
                vis[i] = True

                while q:
                    node,colour = q.popleft()

                    for it in graph[node]:
                        if(not vis[it]):
                            vis[it] = True
                            col[it] = not colour
                            q.append((it,not colour))
                        else:
                            if(col[it] == colour): return False
        

        return True