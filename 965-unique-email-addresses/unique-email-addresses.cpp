class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> seen;

        int counter = 0;
        for (int i = 0, n = emails.size(); i < n; i++) {
            bool plus = false;
            bool amp = false;
            string filtered;
            for (int j = 0, len = emails[i].size(); j < len; j++) {
                if (!amp && emails[i][j] == '.') {
                    continue;
                } else if (emails[i][j] == '+') {
                    plus = true;
                } else if (emails[i][j] == '@') {
                    amp = true;
                }
                
                if (amp || !plus) filtered.push_back(emails[i][j]);
            }
            if (seen.insert(filtered).second) counter++;
        }

        return counter;
    }
};