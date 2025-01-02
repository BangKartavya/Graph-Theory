class Solution:
    def shortestAlternatingPaths(
        self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]
    ) -> List[int]:
        redAdj = []
        blueAdj = []
        redVis = [False] * n
        blueVis = [False] * n
        ans = [-1] * n

        for i in range(n):
            redAdj.append([])
            blueAdj.append([])

        for i in redEdges:
            redAdj[i[0]].append(i[1])

        for i in blueEdges:
            blueAdj[i[0]].append(i[1])

        q = deque()

        q.append([0, 0, -1])  # [node , dist, edgecolour]

        while q:
            node, dis, col = q.popleft()

            if ans[node] == -1:
                ans[node] = dis

            if col != 1:
                # currently blue, visit red
                for i in redAdj[node]:
                    if not redVis[i]:
                        redVis[i] = True
                        q.append([i, dis + 1, 1])

            if col != 0:
                # currently red, visit blue
                for i in blueAdj[node]:
                    if not blueVis[i]:
                        blueVis[i] = True
                        q.append([i, dis + 1, 0])

        return ans
