class Solution:
    def threeSumMulti(self, arr: list[int], target: int) -> int:
        N = len(arr)
        MOD = 10 ** 9 + 7
        
        nC2 = lambda n: (n * (n - 1)) // 2

        result = 0
        seen = defaultdict(int)
        seen[arr[0]] += 1
        seen[arr[1]] += 1
        for k in range(2, N):
            need = target - arr[k]
            if need < 0:
                continue
            
            for a in range(0, (need + 1) >> 1):
                result += seen[a] * seen[need - a]

            if need % 2 == 0:
                result += nC2(seen[need // 2])
            
            seen[arr[k]] += 1
            
        return result % MOD