class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int yes = count(customers.begin(), customers.end(), 'Y');
        int no = 0;

        int penalty = yes, hour = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                yes--;
            } else {
                no++;
            }
            if (penalty > yes + no) {
                penalty = yes + no;
                hour = i + 1;
            }
        }

        return hour;
    }
};