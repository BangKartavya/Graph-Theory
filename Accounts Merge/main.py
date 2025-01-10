class DisjointSet:
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)
        self.size = [1] * (n + 1)

    def findUltimateParent(self, node):
        if node == self.parent[node]:
            return node

        self.parent[node] = self.findUltimateParent(self.parent[node])

        return self.parent[node]

    def unionByRank(self, u, v):
        ultimateParentOfu = self.findUltimateParent(u)
        ultimateParentOfv = self.findUltimateParent(v)

        rankOfu = self.rank[ultimateParentOfu]
        rankOfv = self.rank[ultimateParentOfv]

        if rankOfu < rankOfv:
            self.parent[ultimateParentOfu] = ultimateParentOfv
        elif rankOfv < rankOfu:
            self.parent[ultimateParentOfv] = ultimateParentOfu
        else:
            self.parent[ultimateParentOfv] = ultimateParentOfu
            self.rank[ultimateParentOfu] += 1

    def unionBySize(self, u, v):
        ultimateParentOfu = self.findUltimateParent(u)
        ultimateParentOfv = self.findUltimateParent(v)

        sizeOfu = self.size[ultimateParentOfu]
        sizeOfv = self.size[ultimateParentOfv]

        if sizeOfu <= sizeOfv:
            self.parent[ultimateParentOfu] = ultimateParentOfv
            self.size[ultimateParentOfv] += sizeOfu
        else:
            self.parent[ultimateParentOfv] = ultimateParentOfu
            self.size[ultimateParentOfu] += sizeOfv


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        ds = DisjointSet(n)
        mp = {}

        for i in range(n):
            for j in range(1,len(accounts[i])):
                if(accounts[i][j] in mp):
                    ds.unionByRank(mp[accounts[i][j]],i)
                else:
                    mp[accounts[i][j]] = i
        
        temp = [[accounts[i][0]] for i in range(n)]

        for mail,owner in mp.items():
            ultimateParent = ds.findUltimateParent(owner)
            
            temp[ultimateParent].append(mail)


        result = []

        for t in temp:
            if(len(t) > 1): 
                result.append([t[0]]+sorted(t[1:]))

        return result 




        

        