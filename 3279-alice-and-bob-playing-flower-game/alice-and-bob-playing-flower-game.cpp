class Solution {
    typedef long long ll;
    typedef pair<int, int> pii;
public:
    long long flowerGame(int n, int m) {
        ll result = 0;

        // lane 1
        // pii definition: {odd_count, even_count}
        pii lane1, lane2;
        if (n & 1) {
            lane1 = make_pair(n/2 + 1, n/2);
        } else {
            lane1 = make_pair(n/2, n/2);
        }
        if (m & 1) {
            lane2 = make_pair(m/2 + 1, m/2);
        } else {
            lane2 = make_pair(m/2, m/2);
        }

        return (lane1.first * (ll)lane2.second) +
               (lane1.second * (ll)lane2.first);


    }
};