class Solution {
    int count_subsequences(const string& seq, const string& subseq) {
        int result = 0;
        int n = seq.size(), m = subseq.size();

        int i = 0, j = 0;
        while (i < n) {
            if (seq[i] == subseq[j]) {
                i++; j++;
            } else {
                i++;
            }
            if (j == m) {
                j = 0;
                result += 1;
            }
        }

        return result;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int freq[26], n = s.size();
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] += 1;
        }

        set<char> validCharSet;
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                validCharSet.insert(i + 'a'); 
            }
        }

        queue<string> q;
        for (char validChar: validCharSet) {
            q.push(string(1, validChar));
        }
        string result = "";
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            result = curr;
            for (char validChar: validCharSet) {
                if (count_subsequences(s, curr + validChar) >= k) {
                    q.push(curr + validChar);
                }
            }
        }

        return result;



        
    }
};