class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        vowels = [vowel for vowel in "aeiou"]
        for c in s:
            if c in vowels:
                return True
        
        return False