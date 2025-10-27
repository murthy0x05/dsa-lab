class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r = bank.size();
        int c = bank[0].size();

        int i = 0, prev = 0;
        do {
            for (int j = 0; j < c; j++) {
                if (bank[i][j] == '1') {
                    prev++;
                }
            }
            i++;
        } while (i < r && prev == 0);

        int result = 0;
        for (; i < r;) {
            int curr = 0;
            do {
                for (int j = 0; j < c; j++) {
                    if (bank[i][j] == '1') {
                        curr++;
                    }
                }
                i++;
            } while (i < r && curr == 0);

            result += curr * prev;
            prev = curr;
        }

        return result;
    }
};