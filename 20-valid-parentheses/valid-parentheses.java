class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        HashMap<Character, Character> map = new HashMap<>();
        Deque<Character> stk = new ArrayDeque<>();
        map.put(')', '(');
        map.put('}', '{');
        map.put(']', '[');

        for (char bracket: s.toCharArray()) {
            if (map.containsKey(bracket)) {
                if (map.get(bracket) == stk.peek()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(bracket);
            }
        }

        if (stk.size() != 0) {
            return false;
        }
        return true;
    }
}