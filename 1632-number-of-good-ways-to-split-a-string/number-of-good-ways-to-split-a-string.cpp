class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26, 0),
                    right(26, 0);

        int leftDistinct = 0, rightDistinct = 0;
        for (const char& c: s) {
            if (0 == right[c - 'a']) rightDistinct++;
            right[c - 'a']++;
        }
        
        int ans = 0;
        for (const char& c: s) {
            right[c - 'a']--;
            if (0 == right[c - 'a']) rightDistinct--;
            if (0 == left[c - 'a']) leftDistinct++;
            left[c - 'a']++;
            if (leftDistinct == rightDistinct) ans++;
        }

        return ans;
    }
};