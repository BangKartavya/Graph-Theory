class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        vis = [False] * numCourses
        adj = [[] for i in range(numCourses)]
        indegree = [0] * numCourses
        q = deque()

        for prerequisite in prerequisites:
            adj[prerequisite[1]].append(prerequisite[0])
        

        for i in range(numCourses):
            for it in adj[i]:
                indegree[it]+=1
        

        for i in range(numCourses):
            if(indegree[i]==0): 
                q.append(i)
        
        vis = 0
        while q:    
            node = q.popleft()
            vis+=1
            for i in adj[node]:
                indegree[i]-=1

                if(indegree[i] == 0):
                    q.append(i)
        

        return vis == numCourses
