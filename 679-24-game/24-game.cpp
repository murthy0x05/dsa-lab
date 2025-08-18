class Solution {
    const double e = 0.00000001;
    bool backtrack(vector<double>& cards) {
        int n = cards.size();
        if (1 == n) {
            return std::abs(cards[0] - 24.0) < e;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> newCards;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    newCards.push_back(cards[k]);
                }

                bool ans = false;
                newCards.push_back(cards[i] + cards[j]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                newCards.push_back(cards[i] - cards[j]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                newCards.push_back(cards[j] - cards[i]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                newCards.push_back(cards[i] * cards[j]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                newCards.push_back(cards[i] / (double)cards[j]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                newCards.push_back(cards[j] / (double)cards[i]);
                if (!ans) ans = backtrack(newCards);
                newCards.pop_back();
                if (ans) return ans;
            }
        }

        return false;
    }
public:
    bool judgePoint24(vector<int>& cards_i) {
        vector<double> cards_d = {(double)cards_i[0], (double)cards_i[1],
                                  (double)cards_i[2], (double)cards_i[3]};

        return backtrack(cards_d);
    }
};