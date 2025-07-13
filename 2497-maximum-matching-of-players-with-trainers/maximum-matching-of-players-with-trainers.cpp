class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int result = 0;
        for (int i = 0, j = 0, ilen = players.size(), jlen = trainers.size(); i < ilen && j < jlen; i++, j++) {
            if (players[i] <= trainers[j]) {
                result++;
            } else if (players[i] > trainers[j]) {
                i--;
            }
        }

        return result;
        
    }
};