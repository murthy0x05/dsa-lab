class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        string N = to_string(n);

        vector<int> ones(11);
        ones[0] = 0;

        int total = 0;
        for (int size = 1, len = N.size(); size < len; size++) {
            ones[size] = (ones[size - 1] * 9) + ((int)pow(10, size - 1));
            ones[size] += ones[size - 1];
        }


        int len = N.size();
        int oneCount = N.back() >= '1';
        for (int i = len - 2; i >= 0; i--) {
            if (i == 0) 
                oneCount += (N[i] - '1') * ones[len - i - 1];
            else
                oneCount += (N[i] - '0') * ones[len - i - 1];
            if (N[i] >= '1') {
                if (N[i] > '1') {
                    oneCount += pow(10, len - i - 1);
                } else {
                    oneCount += (stoi(N.substr(i + 1)) + 1);
                }
            }
        }
        ones[len] = oneCount;

        return oneCount + ones[len - 1];
    }
};