class Solution {
public:
    char kthCharacter(int k) {
        if (k == 1) return 'a';
        int currSize = 1;
        string prevWord = "a";
        while (currSize < k) {
            string currWord(prevWord);
            int i = 0, len = prevWord.size();
            if (currSize + len >= k) break;
            while (i < len) {
                currWord.push_back(((prevWord[i] - 'a' + 1) % 26) + 'a');
                i += 1;
            }
            currSize += len;
            prevWord = currWord;
        }
        return (((prevWord[k - currSize - 1] - 'a' + 1) % 26) + 'a');
    }
};