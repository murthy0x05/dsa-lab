class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String> result = new ArrayList<>();
        int start = 0, n = s.length();
        while (start < n) {
            if (start + k < n) {
                result.add(s.substring(start, start + k));
            } else {
                result.add(String.format("%-" + k + "s", s.substring(start)));
            }
            start += k;
        }
        result.set(result.size() - 1, result.get(result.size() - 1).replace(' ', fill));

        return result.toArray(new String[0]);
    }
}