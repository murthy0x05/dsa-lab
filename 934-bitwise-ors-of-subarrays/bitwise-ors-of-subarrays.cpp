class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> uniqueORs;
        unordered_set<int> prevORs, currORs;

        for (int i = 0; i < n; i++) {
            currORs.insert(arr[i]);
            for (int prevOR: prevORs) {
                currORs.insert(prevOR | arr[i]);
            }
            uniqueORs.insert(currORs.begin(), currORs.end());
            prevORs = currORs;
            currORs.clear();
        }

        return uniqueORs.size();
    }
};