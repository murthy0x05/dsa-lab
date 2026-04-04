class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        final int N = encodedText.length();

        int cols = N / rows;
        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < cols; k++) {
            for (int i = 0, j = k; i < rows && j < cols; i++, j++) {
                sb.append(encodedText.charAt(i * cols + j));
            }
        }
        while (!sb.isEmpty() && sb.charAt(sb.length() - 1) == ' ') {
            sb.deleteCharAt(sb.length() - 1);
        }

        return sb.toString();
    }
}