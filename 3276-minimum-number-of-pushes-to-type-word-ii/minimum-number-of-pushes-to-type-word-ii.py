class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [word.count(x) for x in set(word)]

        freq.sort(key = lambda x: -x)

        i = 0
        result = 0
        pos = 1
        while i < len(freq):
            result += pos * sum(freq[i:min(i + 8, len(freq))])
            i += 8
            pos += 1
        
        return result

