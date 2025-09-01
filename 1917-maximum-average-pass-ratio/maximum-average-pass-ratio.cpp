class Solution {
    #pragma GCC optimize("O3,no-stack-protector")
    typedef pair<double, int> pdi;
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        /*
            pdi definition:
            first = increase in each class for adding one extra student
            second = index of the class for calc. next inc. after popping
        */
        function<bool(const pdi&, const pdi&)> cmp = [](const pdi& a, const pdi& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        };
        priority_queue<pdi, vector<pdi>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            double inc = ((classes[i][0] + 1.0) / (classes[i][1] + 1.0)) - (classes[i][0] / (double)classes[i][1]);
            pq.push(make_pair(inc, i));   
        }

        while (extraStudents--) {
            pdi curr = pq.top(); pq.pop();
            int i = curr.second;
            classes[i][0] += 1;
            classes[i][1] += 1;
            double inc = (classes[i][0] + 1.0) / (classes[i][1] + 1.0) - (classes[i][0] / (double)classes[i][1]);
            pq.push(make_pair(inc, i));
        }

        double ratio = 0.0;
        for (int i = 0; i < n; i++) {
            ratio += (classes[i][0] / (classes[i][1] * 1.0));
        }

        return ratio / n;
    }
};