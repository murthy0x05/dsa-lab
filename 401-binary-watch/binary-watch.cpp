class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> options = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

        int h = 0, m = 0, used = 0;
        vector<string> combs;
        function<void(int)> backtrack = [&] (int id) {
            if (id < 0 || used > turnedOn) {
                if (h < 12 && m < 60 && used == turnedOn) {
                    string time = to_string(h) + ":" + ((m < 10) ? "0" : "") + to_string(m);
                    combs.push_back(time);
                }

                return ;
            }

            backtrack(id - 1);

            if (id < 4) {
                h += options[id]; used++;
                backtrack(id - 1);
                h -= options[id]; used--;
            } else {
                m += options[id]; used++;
                backtrack(id - 1);
                m -= options[id]; used--;
            }
        };
        backtrack(9);

        return combs;
    }
};