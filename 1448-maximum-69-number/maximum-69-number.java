class Solution {
    public int maximum69Number (int num) {
        StringBuilder temp = new StringBuilder(String.valueOf(num));

        for (int i = 0, n = temp.length(); i < n; i++)  {
            if (temp.charAt(i) == '6') {
                temp.setCharAt(i, '9');
                return Integer.valueOf(temp.toString());
            }
        }

        return num;
    }
}