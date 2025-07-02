// class Solution {
// public:
//     int possibleStringCount(string word, int k) {
//         const int MOD = 1e9 + 7;
//         vector<int> groups;
//         int n = word.size(), i = 0;

//         // Group the consecutive characters
//         // Here, we are considering contigious groups.
//         while (i < n) {
//             int j = i;
//             while (i < n && word[i] == word[j]) i++;
//             groups.push_back(i - j);
//         }

//         // Total ways (multiply options from each group)
//         // calculating possibilites / ways using basic P&C
//         long long total = 1;
//         for (int g : groups)
//             total = (total * g) % MOD;

//         int m = groups.size();
//         if (m >= k) return total;

//         // DP to subtract number of shorter strings (< k)
//         vector<long long> dp(k + 1, 0);
//         dp[0] = 1;

//         for (int g : groups) {
//             vector<long long> new_dp(k, 0);
//             long long window = 0;
//             for (int j = 0; j < k; ++j) {
//                 window = (window + dp[j]) % MOD;
//                 if (j >= g)
//                     window = (window - dp[j - g] + MOD) % MOD;
//                 new_dp[j] = window;
//             }
//             dp = new_dp;
//         }

//         long long shorter = 0;
//         for (int i = 0; i < k; ++i)
//             shorter = (shorter + dp[i]) % MOD;

//         return (total - shorter + MOD) % MOD;
//     }
// };
class Solution {
public:
	int possibleStringCount(string word, int k) {
		const vector<int> groups = getConsecutiveLetters(word);
		const int totalCombinations =
		    accumulate(groups.begin(), groups.end(), 1L,
		[](long acc, int group) {
			return acc * group % kMod;
		});
		if (k <= groups.size())
			return totalCombinations;

		// dp[j] := the number of ways to form strings of length j using
		// groups[0..i]
		vector<int> dp(k);
		dp[0] = 1;  // Base case: empty string

		for (int i = 0; i < groups.size(); ++i) {
			vector<int> newDp(k);
			int windowSum = 0;
			int group = groups[i];
			for (int j = i; j < k; ++j) {
				newDp[j] = (newDp[j] + windowSum) % kMod;
				windowSum = (windowSum + dp[j]) % kMod;
				if (j >= group)
					windowSum = (windowSum - dp[j - group] + kMod) % kMod;
			}
			dp = std::move(newDp);
		}

		const int invalidCombinations =
		    accumulate(dp.begin(), dp.end(), 0,
		[](int acc, int count) {
			return (acc + count) % kMod;
		});
		return (totalCombinations - invalidCombinations + kMod) % kMod;
	}

private:
	static constexpr int kMod = 1e9 + 7;

	// Returns consecutive identical letters in the input string.
	// e.g. "aabbbc" -> [2, 3, 1].
	vector<int> getConsecutiveLetters(const string& word) {
		vector<int> groups;
		int group = 1;
		for (int i = 1; i < word.length(); ++i)
			if (word[i] == word[i - 1]) {
				++group;
			} else {
				groups.push_back(group);
				group = 1;
			}
		groups.push_back(group);
		return groups;
	}
};