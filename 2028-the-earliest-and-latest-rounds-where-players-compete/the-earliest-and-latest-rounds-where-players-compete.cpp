// //Recursion: CPP Code
// class Solution {
//     int n;
//     int min_rounds = INT_MAX;
//     int max_rounds = INT_MIN;
    
//     void allPossibleMatchups(int mask,int left,int right,int& p1,int& p2,int rounds){
//         if(left>=right){
//             //We are done with current round. Goto next round.
//             allPossibleMatchups(mask,0,n-1,p1,p2,rounds+1);
//         }else if((mask & (1<<left)) == 0){
//             //Skip the defeated left player
//             allPossibleMatchups(mask,left+1,right,p1,p2,rounds);
//         }else if((mask & (1<<right)) == 0){
//             //Skip the defeated right player
//             allPossibleMatchups(mask,left,right-1,p1,p2,rounds);
//         }else if(left==p1 and right==p2){
//             min_rounds = min(min_rounds,rounds);
//             max_rounds = max(max_rounds,rounds);
//         }else{
//             if(left!=p1 and left!=p2)//Make right win
//                 allPossibleMatchups(mask^(1<<left),left+1,right-1,p1,p2,rounds);
            
//             if(right!=p1 and right!=p2)//Make left win
//                 allPossibleMatchups(mask^(1<<right),left+1,right-1,p1,p2,rounds);
//         }
//     }
// public:
//     vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
//         /*
//             Set all player states to 1 initially, meaning they can play.
//             Ex. For N=6
//             mask = 111111
//             This means, all the players are ready to play {1,2,3,4,5,6}

//             mask = 011101 means 1,5 can't play. They are out of the tournament.
//             Only {2,3,4,6} can still play.
//         */ 
//         this->n = n;
//         int mask = (1<<n)-1;
//         firstPlayer-=1;
//         secondPlayer-=1;
//         allPossibleMatchups(mask,0,n-1,firstPlayer,secondPlayer,1);
//         return {min_rounds,max_rounds};
//     }
// };

// //Memoization DP: CPP Code
class Solution {
    bool seen[28][28][28];
    int n;
    int min_rounds = INT_MAX;
    int max_rounds = INT_MIN;
    
    void allPossibleMatchups(int mask, int left, int right, int p1, int p2, int rounds, int l, int m, int r) {
        /*
            Check every possible match between left and right.
            Try both outcomes of every match, that is make left win and then right win.
            When 2 and 4 fight, we stop. So to reach that state, we must try out every possibility
        */

        if (left >= right) {
            // We are done with current round. Goto next round.
            allPossibleMatchups(mask, 0, n - 1, p1, p2, rounds + 1, l, m, r);
        } else if ((mask & (1 << left)) == 0) {
            // Skip the defeated left player
            allPossibleMatchups(mask, left + 1, right, p1, p2, rounds, l, m, r);
        } else if ((mask & (1 << right)) == 0) {
            // Skip the defeated right player
            allPossibleMatchups(mask, left, right - 1, p1, p2, rounds, l, m, r);
        } else if (left == p1 and right == p2) {
            //Stop match after p1 Vs p2
            min_rounds = min(min_rounds, rounds);
            max_rounds = max(max_rounds, rounds);
        } else if (!seen[l][m][r]) {
            seen[l][m][r] = true;

            if (left != p1 and left != p2) // Make right win
                allPossibleMatchups(mask ^ (1 << left), left + 1, right - 1, p1, p2, rounds,
                    l - (left < p1), 
                    m - (left > p1 && left < p2), 
                    r - (left > p2));

            if (right != p1 and right != p2) // Make left win
                allPossibleMatchups(mask ^ (1 << right), left + 1, right - 1, p1, p2, rounds,
                    l - (right < p1), 
                    m - (right > p1 && right < p2), 
                    r - (right > p2));
        }
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        /*
            Set all player states to 1 initially, meaning they can play.
            Ex. For N=6
            mask = 111111
            This means, all the players are ready to play {1,2,3,4,5,6}

            mask = 011101 means 1,5 can't play. They are out of the tournament.
            Only {2,3,4,6} can still play.
        */ 
        int mask = (1 << n) - 1;
        firstPlayer -= 1;
        secondPlayer -= 1;
        memset(seen, false, sizeof(seen));
        this->n = n;

        allPossibleMatchups(mask, 0, n - 1, firstPlayer, secondPlayer, 1,
            firstPlayer, secondPlayer - firstPlayer - 1, n - 1 - secondPlayer);

        return {min_rounds, max_rounds};
    }
};