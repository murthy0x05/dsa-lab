class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = count(moves.begin(), moves.end(), 'L');
        int r = count(moves.begin(), moves.end(), 'R');
        int _ = count(moves.begin(), moves.end(), '_');

        return max((l + _) - r, (r + _) - l);
    }
};