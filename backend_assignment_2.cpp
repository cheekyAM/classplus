#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void dfs(int u,vector<int> &dist,vector<int> adj[],vector<bool> &vis){
    vis[u]=true;
    for(int v:adj[u]){
        if(!vis[v]){
            dist[v]=dist[u]+1;
            dfs(v,dist,adj,vis);
        }
    }
    
}
int main(){
    int n,h,x;
    //n=number of cities, 
    // h=the number of hotspots 
    //x= the distance that the virus can travel from the epicentre.
    cin>>n>>h>>x;
    vector<int> hotspot(h);
    for(int i=0;i<h;i++){
        cin>>hotspot[i];
    }
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // solution should mean that i have to find a cities(epicentre) from which every hotspot should be at most x distance from epicentre
    // and also i should include all cities (infected + not infected) which comes in the distance from epicentre to epicentre+x distance.
    //beacuse there may be other cities which are also infected but not given.
    vector<int> dist(n+1);
    vector<vector<int>> dd(n+1,vector<int>(n+1,0));
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[j]=0;
            vis[j]=false;
        }
        dfs(i,dist,adj,vis);
        for(int j=1;j<=n;j++){
            dd[i][j]=dist[j];
        }
    }
    vector<int> epicentre;
    for(int i=1;i<=n;i++){
        int j;
        for(j=0;j<h;j++){
            if(dd[i][hotspot[j]] > x){
                break;
            }
        }
        if(j==h){
            epicentre.pb(i);
        }
    }
    cout<<epicentre.size()<<"\n";
    return 0;
}