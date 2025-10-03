class Solution {
    class Block implements Comparable<Block> {
        public int height;
        public int i, j;
        public Block(int h, int i, int j) {
            this.height = h;
            this.i = i;
            this.j = j;
        }
        
        @Override
        public int compareTo(Block other) {
            if (this.height != other.height) {
                return this.height - other.height;
            } else {
                if (this.i != other.i) {
                    return this.i - other.i;
                } else {
                    return this.j - other.j;
                }
            }
        }
    }
    public int trapRainWater(int[][] heightMap) {
        int r = heightMap.length;
        int c = heightMap[0].length;

        PriorityQueue<Block> pq = new PriorityQueue<>();
        boolean[][] visited = new boolean[r][c];

        for (int i = 0; i < r; i++) {
            pq.offer(new Block(heightMap[i][0], i, 0));
            pq.offer(new Block(heightMap[i][c - 1], i, c - 1));
            visited[i][0] = visited[i][c - 1] = true;
        }
        for (int j = 1; j < c - 1; j++) {
            pq.offer(new Block(heightMap[0][j], 0, j));
            pq.offer(new Block(heightMap[r - 1][j], r - 1, j));
            visited[0][j] = visited[r - 1][j] = true;
        }

        int water = 0,
            dir[] = {-1, 0, 1, 0, -1};
        while (!pq.isEmpty()) {
            Block block = pq.poll();
            for (int d = 0; d < 4; d++) {
                int ni = block.i + dir[d];
                int nj = block.j + dir[d + 1];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && !visited[ni][nj]) {
                    water += Math.max(0, block.height - heightMap[ni][nj]);
                    pq.offer(new Block(Math.max(heightMap[ni][nj], block.height), ni, nj));
                    visited[ni][nj] = true;
                }
            }
        }

        return water;
    }
}