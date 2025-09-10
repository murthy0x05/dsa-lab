class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> users;
        vector<unordered_set<int>> knows(500);
        for (auto& relation: friendships) {
            int ui = relation[0], vi = relation[1];
            if (knows[ui - 1].size() == 0) {
                for (int& lang: languages[ui - 1]) {
                    knows[ui - 1].insert(lang);
                }
            }
            bool canTalk = false;
            for (int& lang: languages[vi - 1]) {
                if (knows[ui - 1].count(lang)) {
                    canTalk = true;
                    break;                    
                }
            }

            if (!canTalk) {
                users.insert(ui - 1);
                users.insert(vi - 1);
            }
        }

        vector<int> langs(n, 0);
        for (const int& user: users) {
            for (int& lang: languages[user]) {
                langs[lang - 1]++;
            }
        }

        return users.size() - *max_element(langs.begin(), langs.end());
    }
};