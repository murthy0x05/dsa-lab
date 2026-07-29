class Solution:
    def smallestPalindrome(self, s: str) -> str:
        N = len(s)

        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1

        id = 0
        smallest = [''] * N
        for i in range(26):
            if freq[i] & 1:
                smallest[N // 2] = chr(ord('a') + i)
                freq[i] -= 1

            while freq[i] > 0:
                smallest[id] = smallest[N - id - 1] = chr(ord('a') + i)
                freq[i] -= 2
                id += 1
                
        return ''.join(smallest)