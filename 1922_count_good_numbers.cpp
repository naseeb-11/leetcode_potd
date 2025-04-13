#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    ll power(ll a,ll b){
       
       ll ans = 1 , ntp = a;
       while(b>0){
          if(b&1){
            ans = (ans * ntp)%mod; 
          }
          ntp = (ntp * ntp)%mod;
          b=b>>1;
       }
       return ans;
    }
    int countGoodNumbers(long long n) {

      ll odp = n/2 , ep = (n+1)/2;

      ll ans = 1;
      ans = (ans * power(4,odp)) %mod;  
      ans = (ans * power(5,ep)) %mod;

      return ans;
    }

};