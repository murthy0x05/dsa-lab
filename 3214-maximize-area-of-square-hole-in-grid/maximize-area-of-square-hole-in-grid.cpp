class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hmax = 0, vmax = 0;
        int hcur = 1, vcur = 1;
        for (int i = 1, len = hBars.size(); i < len; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hmax = max(hmax, hcur);
                hcur = 1;
            }
        }
        for (int i = 1, len = vBars.size(); i < len; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vmax = max(vmax, vcur);
                vcur = 1;
            }
        }
        hmax = max(hmax, hcur);
        vmax = max(vmax, vcur);

        int maxsq = min(hmax, vmax) + 1;
        return maxsq * maxsq;
    }
};