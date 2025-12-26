class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int yes = count(customers.begin(), customers.end(), 'Y');
        int no = 0;

        int penalty = yes, hour = -1;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                yes--;
                if (penalty > yes + no) {
                    penalty = yes + no;
                    hour = i;
                }
            } else {
                no++;
            }
        }

        return hour + 1;
    }
};