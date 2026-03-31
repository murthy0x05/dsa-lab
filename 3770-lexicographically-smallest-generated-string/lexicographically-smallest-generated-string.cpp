class Solution {
public:
    string generateString(string str1, string str2) {
        const int N = str1.size(),
                  M = str2.size();

        string str3(N + M - 1, '*');
        for (int i = 0; i < N; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < M; j++) {
                    if (str3[i + j] != '*' && str3[i + j] != str2[j]) {
                        return "";
                    }
                    str3[i + j] = str2[j];
                }
            }
        }

        string str4 = str3;
        for (int i = 0; i < (N + M - 1); i++) {
            if (str4[i] == '*') {
                str4[i] = 'a';
            }
        }

        for (int i = 0; i < N; i++) {
            if (str1[i] == 'F') {
                if (str4.substr(i, M) == str2) {
                    int j = M - 1;
                    while (j >= 0) {
                        if (str3[i + j] == '*') {
                            str4[i + j] = 'b';
                            break;
                        }
                        j--;
                    }
                    if (j < 0) {
                        return "";
                    }
                }
            }
        }

        return str4;
    }
};