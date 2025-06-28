class MinHeap {
    {
        this.heap = null;
        this.size = 0;
    }
    private int[] heap;
    private int capacity;
    private int size;
    private void heapifyDown(int node) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int smallest = node;
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (node != smallest) {
            heap[node] = heap[node] ^ heap[smallest] ^ (heap[smallest] = heap[node]);
            heapifyDown(smallest);
        }
    }
    private void heapifyUp(int node) {
        if (0 <= node) {
            int parent = (node - 1) / 2;
            if (heap[node] < heap[parent]) {
                heap[node] = heap[node] ^ heap[parent] ^ (heap[parent] = heap[node]);
                heapifyUp(parent);
            }
        }
    }
    public MinHeap(int c) {
        this.heap = new int[c];
        this.size = 0;
        this.capacity = c;
    }
    public void add(int value) {
        if (size >= capacity) {
            this.pop();
        }
        heap[size] = value;
        heapifyUp(size);
        size += 1;
    }
    public void pop() {
        heap[0] = heap[size - 1];
        this.heapifyDown(0);
        size -= 1;
    }
    public int top() {
        return heap[0];
    }
}

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int indexedArray[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            indexedArray[i][0] = i;
            indexedArray[i][1] = nums[i];
        }

        Arrays.sort(indexedArray, (a, b) -> b[1] - a[1]);
        List<Integer> topK = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            topK.add(indexedArray[i][0]);
        }
        Collections.sort(topK);

        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = nums[topK.get(i)];
        }

        return result;


    }
}