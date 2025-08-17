def solve(n: int) -> list[list]:
    def backtrack(curr, used, start_odd = True):
        if len(curr) == n:
            return [curr[:]]
        
        res = []

        if start_odd == True:
            need_odd = (len(curr) % 2 == 0)
        else:
            need_odd = (len(curr) % 2 == 1)

        for i in range(1, n+1):
            if ((i%2==1 and need_odd) or (i%2==0 and not need_odd)) and (i not in used or used[i] == False):
                used[i] = True
                res.extend(backtrack(curr + [i], used, start_odd))
                used[i] = False

        return res

    res = []
    res.extend(backtrack([], {}, True))
    res.extend(backtrack([], {}, False))

    print(res)


if __name__ == '__main__':
    solve(4)