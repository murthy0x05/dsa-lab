class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1};
    int n, m, color;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    void doDFS(auto& image, auto& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];
            if (isValid(nx, ny) && !visited[nx][ny] && image[nx][ny] == image[x][y]) {
                doDFS(image, visited, nx, ny);
                image[nx][ny] = color;
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int _color) {
        n = image.size();
        m = image[0].size();
        color = _color;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        doDFS(image, visited, sr, sc);
        image[sr][sc] = color;
        return image;
    }
};