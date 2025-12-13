#include <cctype>

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<int> finalized;
        for (int i = 0; i < n; i++) {
            if (isActive[i]) {
                if (code[i].empty()) {
                    isActive[i] = false;
                } else {
                    for (const char& c: code[i]) {
                        if (c != '_' && !isalnum(c)) {
                            isActive[i] = false;
                            break;
                        }
                    }

                    if (isActive[i]) {
                        if (businessLine[i] != "electronics" &&
                            businessLine[i] != "grocery" &&
                            businessLine[i] != "pharmacy" &&
                            businessLine[i] != "restaurant")
                        {
                            isActive[i] = false;
                        }
                    }
                }

                if (isActive[i]) {
                    finalized.push_back(i);
                }
            }
        }

        sort(finalized.begin(), finalized.end(), [&](const int& a, const int& b) {
            if (businessLine[a] != businessLine[b]) {
                return businessLine[a] < businessLine[b];
            } else {
                return code[a] < code[b];
            }
        });

        vector<string> codes;
        for (const int& id: finalized) {
            codes.push_back(code[id]);
        }

        return codes;
    }
};