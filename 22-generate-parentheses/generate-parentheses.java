class Solution {
    private final void backtrack(List<String> validParens, StringBuilder paren, int n, int open, int close) {
        if (open == n && close == n) {
            validParens.add(paren.toString());
            return ;
        }

        if (open < n) {
            paren.append('(');
            backtrack(validParens, paren, n, open + 1, close);
            paren.delete(paren.length() - 1, paren.length());
        }

        if (close < open) {
            paren.append(')');
            backtrack(validParens, paren, n, open, close + 1);
            paren.delete(paren.length() - 1, paren.length());
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> validParens = new ArrayList<>();
        StringBuilder paren = new StringBuilder();
        backtrack(validParens, paren, n, 0, 0);
        return validParens;
    }
}