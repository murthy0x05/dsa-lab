const int mod=1e9+7;
class Solution {
public:
    int N;
    int L, R;

    int dp[2001][2001][2];
    
    int bottom_optmised(){
        if(N==1) return (R-L+1)%mod;

        int range=R-L+1;

        for(int val=0; val<range; val++){
            dp[N-1][val][0]=1;
            dp[N-1][val][1]=1;
        }

        for(int indx=N-2; indx>=0; indx--){

            long long suffixSum=0;
            for(int val=range-1; val>=0; val--){
                dp[indx][val][0]=suffixSum;

                suffixSum=(suffixSum+dp[indx+1][val][1]%mod)%mod;
            }

            long long prefixSum=0;
            for(int val=0; val<range; val++){
                dp[indx][val][1]=prefixSum;

                prefixSum=(prefixSum+dp[indx+1][val][0]%mod)%mod;
            }
        }

        long long ans=0;
        for(int val=0; val<range; val++){
            ans=(ans+dp[0][val][0])%mod;
            ans=(ans+dp[0][val][1])%mod;
        }

        return ans;

    }

    int zigZagArrays(int n, int l, int r) {
        long long ans=0;
        N=n;
        L=l, R=r;

        ans=bottom_optmised();

        return ans;
    }
};