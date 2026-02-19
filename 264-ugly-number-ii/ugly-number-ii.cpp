class Solution {
    using ll = long long;
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        pq.push(1LL);
        while (n > 1) {
            ll top = pq.top(); pq.pop();
            while (!pq.empty() && pq.top() == top) {
                pq.pop();
            }
            pq.push(2 * top);
            pq.push(3 * top);
            pq.push(5 * top);

            n--;
        }


        return pq.top();
    }
};