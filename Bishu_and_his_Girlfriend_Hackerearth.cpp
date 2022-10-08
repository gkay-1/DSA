#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod=1000000007;
vector<ll> v[100005];
ll vis[100005]={};
ll dis[100005]={};
void dfs(ll node,ll d){
    vis[node]=1;
    for(auto x:v[node]){
        if(vis[x]==0){
            dis[x]=d+1;
            dfs(x,dis[x]);
        }
    }
}
int main(){
    fast;
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,q;
        cin>>n;
        for(ll i=1;i<n;i++){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1,0);
        cin>>q;
        ll mn=1e9,mid=-1;
        while(q--){
            ll x;
            cin>>x;
            if(mn>dis[x]){
                mn=dis[x];
                mid=x;
            }
            else if(mn==dis[x]){
                mid=min(mid,x);
            }
        }
        cout<<mid<<endl;
    }
    return 0;
}