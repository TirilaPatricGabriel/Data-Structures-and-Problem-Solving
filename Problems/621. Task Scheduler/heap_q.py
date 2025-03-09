from collections import Counter, deque
import heapq 

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap = []
        freq = Counter(tasks)
        time = 0
        q = deque()

        for key, value in freq.items():
            heapq.heappush(heap, -value)

        while heap or q:
            time += 1
            if heap:
                task = heapq.heappop(heap)
                if task < -1:
                    q.append((task, time+n))
            
            if q and q[0][1] == time:
                task = q[0][0]
                q.popleft()
                heapq.heappush(heap, task+1)

        return time
        

        