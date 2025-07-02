// class Solution {
//     public int possibleStringCount(String word, int k) {
        
//     }
// }

// class Solution {
//     public int possibleStringCount(String word, int k) {
//         final int MOD = 1_000_000_007;
//         List<Integer> groups = new ArrayList<>();
//         int n = word.length(), i = 0;

//         while (i < n) {
//             int j = i;
//             while (i < n && word.charAt(i) == word.charAt(j)) i++;
//             groups.add(i - j);
//         }

//         long total = 1;
//         for (int g : groups)
//             total = total * g % MOD;

//         int m = groups.size();
//         if (m >= k) return (int) total;

//         long[] dp = new long[k + 1];
//         dp[0] = 1;

//         for (int g : groups) {
//             long[] newDp = new long[k + 1];
//             long window = 0;
//             for (int len = 0; len <= k; len++) {
//                 window = (window + dp[len]) % MOD;
//                 if (len - g - 1 >= 0)
//                     window = (window - dp[len - g - 1] + MOD) % MOD;
//                 newDp[len] = window;
//             }
//             dp = newDp;
//         }

//         long shorter = 0;
//         for (int len = 0; len < k; len++)
//             shorter = (shorter + dp[len]) % MOD;

//         return (int) ((total - shorter + MOD) % MOD);
//     }
// }

class Solution {
	public int possibleStringCount(String word, int k) {
		List<Integer> groups = getConsecutiveLetters(word);
		final int totalCombinations =
		    (int) groups.stream().mapToLong(Integer::longValue).reduce(1L, (a, b) -> a * b % MOD);
		if (k <= groups.size())
			return totalCombinations;

		// dp[j] := the number of ways to form strings of length j using
		// groups[0..i]
		int[] dp = new int[k];
		dp[0] = 1; // Base case: empty string

		for (int i = 0; i < groups.size(); ++i) {
			int[] newDp = new int[k];
			int windowSum = 0;
			int group = groups.get(i);
			for (int j = i; j < k; ++j) {
				newDp[j] = (newDp[j] + windowSum) % MOD;
				windowSum = (windowSum + dp[j]) % MOD;
				if (j >= group)
					windowSum = (windowSum - dp[j - group] + MOD) % MOD;
			}
			dp = newDp;
		}

		final int invalidCombinations = Arrays.stream(dp).reduce(0, (a, b) -> (a + b) % MOD);
		return (totalCombinations - invalidCombinations + MOD) % MOD;
	}

	private static final int MOD = 1_000_000_007;

	// Returns consecutive identical letters in the input string.
	// e.g. "aabbbc" -> [2, 3, 1].
	private List<Integer> getConsecutiveLetters(final String word) {
		List<Integer> groups = new ArrayList<>();
		int group = 1;
		for (int i = 1; i < word.length(); ++i)
			if (word.charAt(i) == word.charAt(i - 1)) {
				++group;
			} else {
				groups.add(group);
				group = 1;
			}
		groups.add(group);
		return groups;
	}
}