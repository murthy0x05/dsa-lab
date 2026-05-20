class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> result;
        set<int> unmatched;
        for (int i = 0, matched = 0; i < N; i++) {
            if (unmatched.find(-A[i]) != unmatched.end()) {
                unmatched.erase(-A[i]);
                matched++;
            } else {
                unmatched.insert(A[i]);
            }
            if (unmatched.find(B[i]) != unmatched.end()) {
                unmatched.erase(B[i]);
                matched++;
            } else {
                unmatched.insert(-B[i]);
            }

            result.push_back(matched);
        }

        return result;
    }
};