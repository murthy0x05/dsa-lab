class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        const int N = s.size();
        
        vector<int> occ(26, 0);
        for (const char& si: s) {
            occ[si - 'a']++;
        }

        string result;
        for (int i = 0; i < N; i++) {
            char t = target[i];
            if (occ[t - 'a'] > 0) {
                result.push_back(t);
                occ[t - 'a']--;
            } else {
                int j = t - 'a' + 1;
                while (j < 26) {
                    if (occ[j] > 0) {
                        result.push_back(j + 'a');
                        occ[j]--; 
                        break;
                    }
                    j++;
                }

                if (j < 26) {
                    for (int x = 0; x < 26; x++) {
                        result += string(occ[x], x + 'a');
                    }
                    return result;
                } else {
                    if (result.empty()) {
                        return "";
                    }

                    // char largest = result.back();
                    // occ[result.back() - 'a']++;
                    // result.pop_back();

                    // int k = i - 2;
                    // while (k >= 0) {
                    //     if (result.back() < largest) {
                    //         occ[result.back() - 'a']++;
                    //         result.pop_back();

                    //         result.push_back(largest);
                    //         occ[largest - 'a']--;

                    //         for (int x = 0; x < 26; x++) {
                    //             result += string(occ[x], x + 'a');
                    //         }
                    //         return result;
                    //     } else {
                    //         largest = result.back();
                    //     }

                    //     occ[result.back() - 'a']++;
                    //     result.pop_back();
                    //     k--;
                    // }

                    // return "";

                    // occ[result.back() - 'a']++;
                    // result.pop_back();
                    
                    int k = i - 1;
                    while (k >= 0) {
                        cout << result << endl;
                        for (int j = result.back() - 'a' + 1; j < 26; j++) {
                            if (occ[j] > 0) {
                                occ[result.back() - 'a']++;
                                result.pop_back();

                                result.push_back(j + 'a');
                                occ[j]--;

                                for (int x = 0; x < 26; x++) {
                                    result += string(occ[x], x + 'a');
                                }
                                return result;
                            }
                        }
                    
                        occ[result.back() - 'a']++;
                        result.pop_back();
                        k--;
                    }
                    
                    return "";
                }
            }
        }

        // occ[result.back() - 'a']++;
        // result.pop_back();
        
        int k = N - 1;
        while (k >= 0) {
            for (int j = result.back() - 'a' + 1; j < 26; j++) {
                if (occ[j] > 0) {
                    occ[result.back() - 'a']++;
                    result.pop_back();

                    result.push_back(j + 'a');
                    occ[j]--;

                    for (int x = 0; x < 26; x++) {
                        result += string(occ[x], x + 'a');
                    }
                    return result;
                }
            }
        
            occ[result.back() - 'a']++;
            result.pop_back();
            k--;
        }
        
        return "";
    }
};