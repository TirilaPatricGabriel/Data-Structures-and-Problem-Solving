class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s)-1

        while l < r:
            if s[l] != s[r]:
                return False
            l+=1
            r-=1
            
        return True

def main():
    solution = Solution()

    print(solution.isPalindrome('caac'))

if __name__ == '__main__':
    main()