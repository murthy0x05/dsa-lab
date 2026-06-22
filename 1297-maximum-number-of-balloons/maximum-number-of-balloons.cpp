class Solution {
public:
    int maxNumberOfBalloons(string text) {
        const int N = text.size();

        vector<int> balon(5, 0);
        for (int i = 0; i < N; i++) {
            if (text[i] == 'b') {
                balon[0]++;
            } else if (text[i] == 'a') {
                balon[1]++;
            } else if (text[i] == 'l') {
                balon[2]++;
            } else if (text[i] == 'o') {
                balon[3]++;
            } else if (text[i] == 'n') {
                balon[4]++;
            }
        }

        return min({balon[0], balon[1], balon[2] / 2, balon[3] / 2, balon[4]});
    }
};