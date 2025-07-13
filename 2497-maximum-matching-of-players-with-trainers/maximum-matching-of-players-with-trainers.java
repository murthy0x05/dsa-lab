class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);

        int i = 0, j = 0, result = 0;
        int ilen = players.length;
        int jlen = trainers.length;
        for (; i < ilen && j < jlen; i++, j++) {
            if (players[i] <= trainers[j])
                result++;
            else 
                i--;
        }

        return result;
    }
}