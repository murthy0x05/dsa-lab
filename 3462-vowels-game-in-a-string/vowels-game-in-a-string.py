class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        vowels = [vowel for vowel in "aeiou"]
        for vowel in vowels:
            if vowel in s:
                return True
        
        return False