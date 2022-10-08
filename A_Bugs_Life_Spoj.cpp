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
ll vis[100005];
ll color[100005];
bool dfs(ll node,ll c){
    vis[node]=1;
    color[node]=c;
    for(auto child:g[node]){
        if(!vis[child]){
            if(dfs(child,!c)==false) return false;
        }
        else if(color[node]==color[child]) return false;
    }
    return true;
}
int main(){
    fast;
    ll t=1,s=1;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            color[i]=0;
            vis[i]=0;
            g[i].clear();
        }
        for(ll i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        ll f=1;
        for(ll i=1;i<=n;i++){
            if(vis[i]==0){
                if(dfs(i,0)==false){
                    f=0;
                    break;
                }
            }
        }
        cout<<"Scenario #"<<s<<":\n";
        if(!f){
            cout<<"Suspicious bugs found!\n";
        }
        else{
            cout<<"No suspicious bugs found!\n";
        }
        s++;
    }
    return 0;
}