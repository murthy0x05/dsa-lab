class Solution {
    int r, c;
    void mark(vector<vector<int>>& visited, int x, int y) {
        for (int i = x + 1; i < r && visited[i][y] != -1; i++) {
            visited[i][y] = 1;
        }
        for (int i = x - 1; i >= 0 && visited[i][y] != -1; i--) {
            visited[i][y] = 1;
        }
        for (int j = y + 1; j < c && visited[x][j] != -1; j++) {
            visited[x][j] = 1;
        }
        for (int j = y - 1; j >= 0 && visited[x][j] != -1; j--) {
            visited[x][j] = 1;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        this -> r = m;
        this -> c = n;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (const vector<int>& wall: walls) {
            visited[wall[0]][wall[1]] = -1;
        }
        for (const vector<int>& guard: guards) {
            visited[guard[0]][guard[1]] = -1;
        }

        for (const vector<int>& guard: guards) {
            mark(visited, guard[0], guard[1]);
        }

        int result = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result += (visited[i][j] == 0);
            }
        }

        return result;
    }
};