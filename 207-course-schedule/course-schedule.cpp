class Solution {
    bool doDFS(auto& adjlist, int* state, int node) {
        if (state[node] == 1) {
            return true;
        } else if (state[node] == 2) {
            return false;
        } else {
            state[node] = 1;
            bool hasCycle = false;
            for (int& neighbour: adjlist[node]) {
                if (!hasCycle) {
                    hasCycle = doDFS(adjlist, state, neighbour);
                }
            }
            state[node] = 2;
            return hasCycle;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto& prerequisite: prerequisites) {
            adjlist[prerequisite[1]].push_back(prerequisite[0]);
        }

        int* state = new int[numCourses]{0};
        bool hasCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (!hasCycle && state[i] == 0) {
                hasCycle = doDFS(adjlist, state, i);
            }
        }

        return !hasCycle;
    }
};