class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        int sz = n.size();

        int i = 0;
        while (i < sz) {
            char Max = *max_element(n.begin() + i, n.end());
            if (n[i] < Max) {
                int idx = n.rfind(Max);
                swap(n[i], n[idx]);
                return stoi(n);
            } else {
                i++;
            }
        }

        return num;
    }
};