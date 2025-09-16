class Solution {
    private long __gcd(long a, long b) {
        while (b != 0) {
            long rem = a % b;
            a = b;
            b = rem;
        }

        return a;
    }
    private long __lcm(long a, long b) {
        return (a * b) / __gcd(a, b);
    }
    public List<Integer> replaceNonCoprimes(int[] nums) {
        int n = nums.length;

        Deque<Integer> dq = new LinkedList<>();
        dq.addFirst(nums[0]);
        for (int i = 1; i < n; i++) {
            if (__gcd(Long.valueOf(dq.getLast()), nums[i]) != 1L) {
                long last = dq.removeLast();
                long lcm = __lcm(last, nums[i]);
                while (!dq.isEmpty()) {
                    if (__gcd(Long.valueOf(dq.getLast()), lcm) != 1L) {
                        lcm = __lcm(Long.valueOf(dq.removeLast()), lcm);
                    } else {
                        break;
                    }
                }
                dq.addLast((int)lcm);
            } else {
                dq.addLast(nums[i]);
            }
            // for (Integer ele: dq) {
            //     System.out.print(ele + " ");
            // }
            // System.out.println();
        }


        return new ArrayList<Integer>(dq);
    }
}