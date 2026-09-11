class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        result = []

        for word in words:
            W = word.lower()

            cset = ""
            if W[0] in "qwertyuiop":
                cset = "qwertyuiop"
            elif W[0] in "asdfghjkl":
                cset = "asdfghjkl"
            else:
                cset = "zxcvbnm"
            
            for i in range(1, len(W)):
                if W[i] not in cset:
                    break
            else:
                result.append(word)
            
        return result