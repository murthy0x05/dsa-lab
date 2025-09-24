class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        
        StringBuilder result = new StringBuilder();
        if (numerator < 0 ^ denominator < 0)
            result.append("-");        

        long n = Math.abs(Long.valueOf(numerator));
        long d = Math.abs(Long.valueOf(denominator));
        result.append(n / d);
        long rem = n % d;
        if (rem == 0) {
            return result.toString();
        }

        result.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (rem != 0) {
            if (map.containsKey(rem)) {
                result.insert(map.get(rem), "(");
                result.append(")");
                break;
            }
            
            map.put(rem, result.length());
            rem *= 10;
            result.append(rem / d);
            rem %= d;
        }

        return result.toString();
    }
}
