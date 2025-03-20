class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = [w.strip() for w in s.split()]
        return len(words[len(words)-1])