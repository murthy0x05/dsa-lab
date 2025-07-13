class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int i = 0, j = 0;
        int ilen = g.size();
        int jlen = s.size();
        for(; i < ilen && j < jlen; i++, j++) {
            if (g[i] <= s[j])
                result++;
            else
                i--;
        }

        return result;
    }
};