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
void dfs(ll node){
    for(auto x:v[node]){
        if(vis[x]==0){
            vis[x]=1;
            dfs(x);
        }
    }
}
int main(){
    fast;
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        while(e--){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll c=0;
        for(ll i=1;i<=n;i++){
            if(vis[i]==0){
                vis[i]=1;
                dfs(i);
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}