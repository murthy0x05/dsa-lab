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
                if (st.top() != 'L') {
                    if (st.top() == 'R') {
                        collisions += stacked;
                        st.pop(); st.push('S');
                    }
                    collisions += 1;
                }
            } else if (directions[i] == 'R') {
                if (st.top() != 'R') {
                    stacked = 0;
                }
                st.push('R');
                stacked++;
            } else {
                if (st.top() != 'S') {
                    if (st.top() == 'R') {
                        collisions += stacked;
                    }
                    st.push('S');
                }
            }
        }

        return collisions;
    }
};