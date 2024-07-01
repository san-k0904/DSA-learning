class Solution {
public:
    long long MOD=1000000007;
    // long long power(long long x,long long n){
    //     long long ans=1;
    //     while(n>0){
    //         if(n&1){
    //             ans=(ans*x)%MOD;
    //         }
    //         x=(x*x)%MOD;
    //         n=n>>1;
    //     }
    //     return ans;
    // }
    long long power(long long x, long long n){
        if(n==0){
            return 1;
        }
        long long halfpow= power(x,n/2);
        if(n&1){//odd power
            return (x*((halfpow*halfpow)%MOD))%MOD;
        }
        return (halfpow*halfpow)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long even;
        long long odd;
        if(n&1){
            odd=n/2;
            even=n/2+1;
        }
        else{
            odd=n/2;
            even=n/2;
        }
        return ((power(5,even)%MOD)*(power(4,odd)%MOD))%MOD;
    }
};
