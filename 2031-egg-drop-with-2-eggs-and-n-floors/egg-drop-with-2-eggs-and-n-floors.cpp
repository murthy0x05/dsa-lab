class Solution {
public:
    int twoEggDrop(int n) {
        if (n == 1) {
            return 1;
        }
        
        int x = 2;
        int N2 = 2 * n;
        while ((x * (x + 1)) < N2) {
            x++;
        }

        return x; 
    }
};