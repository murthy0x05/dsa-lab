class DSU {
    List<Integer> parent, rank;
    public DSU(int n) {
        this.parent = new ArrayList<>();
        this.rank = new ArrayList<>(Collections.nCopies(n, 0));
        for (int i = 0; i < n; i++)
            parent.add(i);
    }
    int find(int i) {
        if (parent.get(i) != i)
            parent.set(i, find(parent.get(i)));
        return parent.get(i);
    }
    boolean unite(int i, int j) {
        int i_root = find(i);
        int j_root = find(j);
        if (i_root == j_root)
            return false;
        
        if (rank.get(i_root) < rank.get(j_root))
            parent.set(i_root, j_root);
        else if (rank.get(i_root) > rank.get(j_root))
            parent.set(j_root, i_root);
        else {
            parent.set(i_root, j_root);
            rank.set(j_root, rank.get(j_root) + 1);
        }

        return true;
    }
}

class Solution {
    public int minCost(int n, int[][] edges, int k) {
        DSU dsu = new DSU(n);
        Arrays.sort(edges, Comparator.comparingInt(edge -> edge[2]));
        
        // Using Lambda Substraction:
        // Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        // a[2] - b[2] iff -ve mean a should come first
        // a[2] - b[2] iff +ve mean a should come after b.

        List<Integer> used = new ArrayList<>();
        for (int[] edge: edges) {
            if (dsu.unite(edge[0], edge[1])) {
                used.add(edge[2]);
            }
        }

        Collections.sort(used, Comparator.comparingInt((Integer weight) -> weight).reversed());

        if (used.size() < k)
            return 0;
        return used.get(k - 1);
    }
}