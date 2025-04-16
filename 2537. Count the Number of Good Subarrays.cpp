#define ll long long
class Solution {
public:
    long long countGood(vector<int>& v, int k) {
        ll n = v.size();
       
        unordered_map<ll,ll> m;
        ll p=0,ans=0;
        for(ll i=0,j=0;i<n;i++){
            m[v[i]]++;
            p+=m[v[i]]-1;
          
            while(p>=k){
                ans+=n-i;
                m[v[j]]--;
                p-=m[v[j]];
                j++;
            }

        }
        return ans;
    }
};