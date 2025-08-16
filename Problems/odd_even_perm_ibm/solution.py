def odd_even_perm(n: int) -> list:
    def backtrack(curr, used, started_odd):
        if len(curr) == n:
            return [curr[:]]
        
        res = []

        pos = len(curr)
        need_odd = True
        if started_odd == True:
            need_odd = (pos % 2 == 0)
        else:
            need_odd = (pos % 2 == 1)

        for i in range(1, n+1):
            if i%2 == need_odd and (i not in used or used[i] == False):
                used[i] = True
                res.extend(backtrack(curr + [i], used, started_odd))
                used[i] = False

        return res

    full_sol = []
    full_sol.extend(backtrack([], {}, True))
    full_sol.extend(backtrack([], {}, False))
    full_sol.sort()
    print(full_sol)



if __name__ == '__main__':
    odd_even_perm(4)


# 1 



# n == 4 =>
# [1 2 3 4]
# [1 4 3 2]
# [2 1 4 3]
# [2 3 4 1]
# [3 2 1 4]
# [3 4 1 2]
# [4 1 2 3]
# [4 3 2 1]