class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> blocks;

        for (string& block: allowed) {
            blocks[block.substr(0, 2)].push_back(block[2]);
        }

        unordered_map<string, bool> mem;
        function<bool(string&, string&, int)> backtrack = [&](string& next, string& bottom, int idx) {
            if (bottom.size() == 1) {
                return true;
            } else if (idx >= bottom.size() - 1) {
                if (mem.count(next)) {
                    return mem[next];
                } else {
                    string nextlayer = "";
                    return mem[next] = backtrack(nextlayer, next, 0); 
                }
            } else if (blocks.count(bottom.substr(idx, 2))) {
                bool result = false;
                for (char block: blocks[bottom.substr(idx, 2)]) {
                    next.push_back(block);
                    result = result || backtrack(next, bottom, idx + 1);
                    if (result) return result;
                    next.pop_back();
                }

                return result;
            } else {
                return false;
            }
        };

        string next = "";
        return backtrack(next, bottom, 0);
    }
};