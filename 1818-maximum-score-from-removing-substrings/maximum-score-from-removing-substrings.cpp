class Solution {
    #define psb push_back
    #define endl '\n'
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int points = 0;

        function<int(char, char, int)> getPoints = [&s](char open, char close, int p) {
            stack<char> st;
            int points = 0;
            int n = s.size(), index = -1;

            for (int i = 0; i < n; i++) {
                if (index > -1 && s[index] == open && s[i] == close) {
                    points += p;
                    index--;
                } else {
                    s[++index] = s[i];
                }
            }

            s = s.substr(0, index + 1);

            return points;
        };

        int totalPoints = 0;
        if (x > y) {
            totalPoints += getPoints('a', 'b', x);
            totalPoints += getPoints('b', 'a', y);
        } else {
            totalPoints += getPoints('b', 'a', y);
            totalPoints += getPoints('a', 'b', x);
        }

        return totalPoints;
    }
};