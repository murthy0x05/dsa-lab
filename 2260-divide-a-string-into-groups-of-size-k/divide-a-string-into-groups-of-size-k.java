class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length(), size = (int)Math.ceil(n / (float)k);
        String[] result = new String[size];

        for (int i = 0; i < size; i++) {
            result[i] = s.substring(i * k, Math.min(i * k + k, n));
        }
        if (result[size-1].length() < k) {
            result[size-1] += String.valueOf(fill).repeat(k - result[size - 1].length());
        }

        return result;
    }
}

/* 1ms Solution */
// class Solution {
//     public String[] divideString(String s, int k, char fill) {
//         int n = s.length(), size = n / k;
//         List<String> result = new ArrayList<>();

//         for (int i = 0; i < size; i++) {
//             StringBuilder group = new StringBuilder();
//             for (int j = 0; j < k; j++) {
//                 group.append(s.charAt(k*i + j));
//             }
//             result.add(group.toString());
//         }

//         if (size * k < n) {
//             StringBuilder lastGroup = new StringBuilder(s.substring(size * k));
//             lastGroup.append(String.valueOf(fill).repeat(k - n + size * k));
//             result.add(lastGroup.toString());

//         }

//         return result.toArray(new String[0]);
//     }
// }

/* 8ms Solution */
// class Solution {
//     public String[] divideString(String s, int k, char fill) {
//         List<String> result = new ArrayList<>();
//         int start = 0, n = s.length();
//         while (start < n) {
//             if (start + k < n) {
//                 result.add(s.substring(start, start + k));
//             } else {
//                 result.add(String.format("%-" + k + "s", s.substring(start)));
//             }
//             start += k;
//         }
//         result.set(result.size() - 1, result.get(result.size() - 1).replace(' ', fill));

//         return result.toArray(new String[0]);
//     }
// }