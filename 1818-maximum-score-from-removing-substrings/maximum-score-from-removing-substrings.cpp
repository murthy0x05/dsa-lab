class Solution {
    #define psb push_back
    #define endl '\n'
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int points = 0;

        function<int(char, char, int)> getPoints = [&s, &n](char open, char close, int p) {
            stack<char> st;
            int points = 0, index = -1;

            for (int i = 0; i < n; i++) {
                if (index > -1 && s[index] == open && s[i] == close) {
                    points += p;
                    index--;
                } else {
                    s[++index] = s[i];
                }
            }

            n = index + 1;

            return points;
        };

        char open = 'a', close = 'b';
        if (y > x) swap(open, close);
        int totalPoints = 0;

        totalPoints += getPoints(open, close, max(x, y));
        totalPoints += getPoints(close, open, min(x, y));
        

        return totalPoints;
    }
};