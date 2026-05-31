class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        final int N = asteroids.length;

        Arrays.sort(asteroids);
        long planetMass = Long.valueOf(mass);
        for (int i = 0; i < N; i++) {
            if (planetMass >= asteroids[i]) {
                planetMass += asteroids[i];
            } else {
                return false;
            }
        }

        return true;
    }
}