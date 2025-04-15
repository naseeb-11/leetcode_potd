#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

       ll n = nums1.size();

       vector<ll> pos(n);
       for(ll i=0;i<n;i++) pos[nums2[i]]=i;

       vector<ll> mainn(n);
       for(ll i=0;i<n;i++){
          mainn[i]=pos[nums1[i]];
       }

       ordered_set<ll> st;
       vector<ll> lf(n,0),rt(n,0);

       for(ll i=0;i<n;i++){
          lf[i]= st.order_of_key(mainn[i]);
          st.insert(mainn[i]);
       }
       st.clear();
       for(ll i=n-1;i>=0;i--){
        rt[i] = st.size() - st.order_of_key(mainn[i]+1);
        st.insert(mainn[i]);
       }
       ll ans=0;

       for(ll i=0;i<n;i++)
        ans+=lf[i]*rt[i];
       return ans; 
    }
};