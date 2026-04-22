class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const int N = queries.size();

        vector<string> result;
        for (const string& query: queries) {
            for (const string& word: dictionary) {
                int mismatch = 0;
                for (int i = 0; i < word.size(); i++) {
                    mismatch += query[i] != word[i];
                    if (mismatch > 2) {
                        break;
                    } 
                }
                if (mismatch <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }

        return result;
    }
};