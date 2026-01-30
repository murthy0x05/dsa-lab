class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        vector<int> p(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                st.push(i);
            } else if (s[i] == ']') {
                p[i] = st.top();
                p[st.top()] = i;
                st.pop();
            } else {
                p[i] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << ' ';
        }
        cout << endl;

        function<string(int, int)> decode = [&] (int l, int r) {
            string result("");

            for (int i = l; i <= r; i++) {
                cout << i << endl;
                if (s[i] >= 'a' && s[i] <= 'z') {
                    result.push_back(s[i]);
                } else {
                    int rep = 0;
                    while (s[i] >= '0' && s[i] <= '9') {
                        rep = rep * 10 + (s[i] - '0');
                        i++;
                    }
                    string decoded = decode(i + 1, p[i] - 1);
                    for (int j = 0; j < rep; j++) {
                        result += decoded;
                    }
                    i = p[i];
                }
            }

            return result;
        };

        return decode(0, n - 1);
    }
};