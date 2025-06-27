class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;

        int i = 1, x;
        int result = 1;
        int top = 0, bottom = 0;
        while (i < n) {
            if (ratings[i] == ratings[i-1]) {
                i += 1;
                result += 1;
                continue;
            }
            top = 1;
            while (i < n && ratings[i] > ratings[i-1]) {
                top++;
                result += top;
                i++;                
            }
            bottom = 1;
            while (i < n && ratings[i] < ratings[i-1]) {
                result += bottom;
                bottom++;
                i++;
            }
            if (top < bottom) {
                result += bottom - top;
            }
        }     

        return result;    
    }
}