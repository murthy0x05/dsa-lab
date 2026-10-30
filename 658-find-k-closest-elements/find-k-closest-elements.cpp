class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();

        vector<int> ids(N);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&] (const int& id1, const int& id2) {
            if (abs(arr[id1] - x) != abs(arr[id2] - x)) {
                return abs(arr[id1] - x) < abs(arr[id2] - x);
            } else {
                return id1 < id2;
            }
        });

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = arr[ids[i]];
        }

        sort(result.begin(), result.end());
        return result;
    }
};