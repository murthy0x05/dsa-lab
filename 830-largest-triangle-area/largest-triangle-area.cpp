class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0.0;
        for (int i = 0, n = points.size(); i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    area = max<double>(area, 
                           abs(0.5 * (((points[i][0] * (points[j][1] - points[k][1])) +
                                       points[j][0] * (points[k][1] - points[i][1])) +
                                       points[k][0] * (points[i][1] - points[j][1]))));
                }
            }
        }

        return area;
    }
};