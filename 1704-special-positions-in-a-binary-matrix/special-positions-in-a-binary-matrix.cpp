class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int M = mat.size(),
                  N = mat[0].size();
        vector<int> rOnes(M, 0);
        vector<int> cOnes(N, 0);
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 1){
                    rOnes[i]++;
                    cOnes[j]++;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 1 && rOnes[i] == 1 && cOnes[j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};