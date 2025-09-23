class Solution {
public:
    int compareVersion(string v1, string v2) {
        v1 += ".0";
        v2 += ".0";

        int n1 = v1.size(),
            n2 = v2.size();

        size_t si = 0, ei = v1.find('.', 0);
        size_t sj = 0, ej = v2.find('.', 0);

        while (ei != string::npos || ej != string::npos) {
            int r1, r2;

            if (ei == string::npos) {
                r1 = stoi(v1.substr(si));
            } else {
                r1 = stoi(v1.substr(si, ei - si));
                si = ei + 1;
                ei = v1.find('.', si);
            }
            if (ej == string::npos) {
                r2 = stoi(v2.substr(sj));
            } else {
                r2 = stoi(v2.substr(sj, ej - sj));
                sj = ej + 1;
                ej = v2.find('.', sj);
            } 

            cout << r1 << ' ' << r2 << endl;

            if (r1 < r2) return -1;
            if (r1 > r2) return 1;   
        }

        return 0;
    }
};