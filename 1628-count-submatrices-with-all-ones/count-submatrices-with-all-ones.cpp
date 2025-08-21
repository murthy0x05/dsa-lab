class Solution {
    typedef tuple<int, int, int> state;
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int result = 0;
        vector<int> histogram(m, 0);
        for (auto& row: mat) {
            stack<state> st;
            st.push(make_tuple(-1, -1, 0));
            // tuple definition: {height, index, prevCount}

            for (int j = 0; j < m; ++j) {
                if (row[j]) histogram[j]++;
                else histogram[j] = 0;
            }

            for (int j = 0; j < m; ++j) {
                while (get<0>(st.top()) >= histogram[j]) {
                    st.pop();
                }
                int curr = histogram[j] * (j - get<1>(st.top())) + get<2>(st.top());
                st.push(make_tuple(histogram[j], j, curr));
                result += curr;
            }
        }

        return result;
    }
};