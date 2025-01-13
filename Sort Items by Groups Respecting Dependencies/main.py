class Solution:
    def isCycle(self,adj,deg,res):
        n = len(adj)

        q = deque()

        for i in range(n):
            if(deg[i] == 0): q.append(i)
        
        while q:
            node = q.popleft()
            res.append(node)

            for i in adj[node]:
                deg[i]-=1
                if(deg[i]==0): q.append(i)

        return len(res) == n

    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        k = m
        for i in range(n):
            if(group[i] == -1):
                group[i] = k
                k+=1
        
        adjItem = [[] for i in range(n)]
        degItem = [0 for i in range(n)]
        
        adjGroup = [[] for i in range(k)]
        degGroup = [0 for i in range(k)]

        for i in range(n):
            for it in beforeItems[i]:
                adjItem[it].append(i)
                degItem[i]+=1

                if(group[it] != group[i]):
                    adjGroup[group[it]].append(group[i])
                    degGroup[group[i]]+=1
        
        items = []
        groups = []

        its = self.isCycle(adjItem,degItem,items)
        grp = self.isCycle(adjGroup,degGroup,groups)

        if(its == 0 or grp == 0): return []

        mp = defaultdict(list)

        for i in items:
            mp[group[i]].append(i)
        
        res = []

        for grp in groups:
            for i in mp[grp]:
                res.append(i)
        
        return res