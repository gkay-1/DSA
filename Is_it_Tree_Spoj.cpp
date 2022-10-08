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
vector<ll> g[100005];
ll vis[100005]={};
void dfs(ll node){
    vis[node]=1;
    for(auto child:g[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main(){
    fast;
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        ll c=0;
        for(ll i=1;i<=n;i++){
            if(vis[i]==0){
                c++;
                dfs(i);
            }
        }
        if(c==1 && m==n-1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}