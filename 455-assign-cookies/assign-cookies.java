class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int result = 0;
        int i = 0, j = 0;
        int ilen = g.length;
        int jlen = s.length;
        for(; i < ilen && j < jlen; i++, j++) {
            if (g[i] <= s[j])
                result++;
            else
                i--;
        }

        return result;
    }
}