class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        stack<char> st;
        st.push(directions[0]);

        int collisions = 0;
        int stacked = directions[0] != 'S';
        for (int i = 1; i < n; i++) {
            if (directions[i] == 'L') {
                if (st.top() == 'R') {
                    collisions += 2;
                    collisions += (stacked - 1);
                    st.pop();
                    st.push('S');
                } else if (st.top() == 'S') {
                    collisions += 1;
                }
            } else if (directions[i] == 'R') {
                if (st.top() != 'R') {
                    stacked = 0;
                }
                st.push('R');
                stacked++;
            } else {
                if (st.top() == 'R') {
                    collisions += 1;
                    collisions += stacked - 1;
                }
                if (st.top() != 'S') {
                    st.push('S');
                }
            }
        }

        return collisions;
    }
};