class Solution:
    def mergeStones(self, stones: list[int], k: int) -> int:
        n = len(stones)
        if (n - 1) % (k - 1) != 0:
            return -1
        prefix = [0]*(n+1)
        for i in range(n):
            prefix[i+1] = prefix[i] + stones[i]
        dp = [[0]*n for _ in range(n)]
        for length in range(2, n+1):
            for i in range(0, n-length+1):
                j = i + length - 1
                best = float('inf')
                idx = i
                while idx < j:
                    best = min(best, dp[i][idx] + dp[idx+1][j])
                    idx += k - 1
                if (length - 1) % (k - 1) == 0:
                    best += prefix[j+1] - prefix[i]
                dp[i][j] = best
        return dp[0][n-1]