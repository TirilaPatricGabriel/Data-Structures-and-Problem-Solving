class Solution:
    def isHappy(self, n: int) -> bool:
        if n == 1 or n == 7:
            return True
        if n < 10:
            return False

        while n != 1 and n != 7:
            if n < 10:
                return False
                
            cn = n
            s = 0

            while cn > 0:
                c = cn%10
                cn //= 10
                s += c**2
            n = s

        return True if (n == 1 or n == 7) else False