class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = []

        for i in range(0, len(temperatures)):
            if stack:
                top = stack[len(stack)-1]
                while top != -1 and temperatures[top] < temperatures[i]:
                    days = i - top

                    answer[top] = days

                    stack.pop()
                    if stack:
                        top = stack[len(stack)-1]
                    else:
                        top = -1
            stack.append(i)
        return answer