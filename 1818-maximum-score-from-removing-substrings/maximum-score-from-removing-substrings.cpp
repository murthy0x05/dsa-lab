class Solution {
    #define psb push_back
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        stack<char> st;
        char open, close;
        if (x > y) {
            open = 'a';
            close = 'b';
        } else {
            open = 'b';
            close = 'a';
        }
            
        int points = 0;
        function<int(char, char, int)> getPoints = [&s](char open, char close, int p) {
            stack<char> st;
            int points = 0;
            int n = s.size();

            for (int i = 0; i < n; i++) {
                if (!st.empty() && st.top() == open && s[i] == close) {
                    points += p;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }

            s = string(st.size(), '*');
            int index = st.size() - 1;
            while (index >= 0) {
                s[index--] = st.top();
                st.pop();
            }

            return points;
        };

        int totalPoints = 0;
        if (x > y) {
            totalPoints += getPoints('a', 'b', x);
            totalPoints += getPoints('b', 'a', y);
        } else {
            totalPoints += getPoints('b', 'a', y);
            cout << s << endl;
            totalPoints += getPoints('a', 'b', x);
        }

        return totalPoints;
    }
};