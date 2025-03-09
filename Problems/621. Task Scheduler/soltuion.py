class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        taskdict = {}
        for task in tasks:
            if task not in taskdict.keys():
                taskdict[task] = [1, 0]
            else:
                taskdict[task][0] += 1
        
        res = 0
        
        while True:
            usedtask = -1
            availabletask = -1

            for task in taskdict.keys():
                if taskdict[task][0] > 0:
                    availabletask = task
                    if taskdict[task][1] <= 0:
                        if usedtask == -1:
                            usedtask = task
                        if taskdict[task][0] > taskdict[usedtask][0]:
                            usedtask = task
                taskdict[task][1] -= 1

            if availabletask != -1:
                res += 1
            else:
                return res
            
            if usedtask != -1:
                taskdict[usedtask][0] -= 1
                taskdict[usedtask][1] = n

            


        

        