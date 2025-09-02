class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def bt(curr, open_count, close_count):
            if len(curr) == 2*n:
                res.append(curr)

            if open_count < n:
                bt(curr + '(', open_count + 1, close_count)

            if close_count < open_count:
                bt(curr + ')', open_count, close_count + 1)

        bt("", 0, 0)

        return res