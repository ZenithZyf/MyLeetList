class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # if s has a pattern, then s must contains in "ss"[1:-1]
        # if not, then s definitely not with in it
        return s in (s + s)[1 : -1]
