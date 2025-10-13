class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

        string prev = words[0];
        sort(prev.begin(), prev.end());

        for (int i = 1, n = words.size(); i < n; i++) {
            string curr = words[i];
            sort(curr.begin(), curr.end());
            if (prev != curr) {
                result.push_back(words[i]);
            }
            prev = curr;
        }

        return result;
    }
};