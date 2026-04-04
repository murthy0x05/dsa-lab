class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int N = encodedText.size();

        string result;
        int cols = N / rows;
        for (int k = 0; k < cols; k++) {
            for (int i = 0, j = k; i < rows && j < cols; i++, j++) {
                result.push_back(encodedText[i * cols + j]);
            }
        }
        while (!result.empty() && isspace(result.back())) {
            result.pop_back();
        }

        return result;
    }
};