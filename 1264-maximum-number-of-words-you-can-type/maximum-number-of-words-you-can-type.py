class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = [False] * 26
        for bl in brokenLetters:
            broken[ord(bl) - ord('a')] = True
        
        result = 0
        for word in text.split(' '):
            result += 1
            for l in word:
                if broken[ord(l) - ord('a')]:
                    result -= 1
                    break
        
        return result