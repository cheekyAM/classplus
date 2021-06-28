#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mx 1e15 +2
ll ans=mx;

int hidetime(ll cur,vector<int> demons){
    int hi=demons.size()-1, lo=1;
    while(lo < hi){
        int mid=lo + (hi-lo)/2;
        if(demons[mid]==cur){
            int extra=1,x=cur;
            while(1){
                if(demons[++mid]==++x){extra++;}
                else{
                    break;
                }
            }
            return extra;
        }
        else if(demons[mid]>cur){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return 0;
}
void dfs(int src, int dest,vector<pair<int,int>> adj[],ll cur,vector<int> demons[]){
    if(src==dest){
        ans=min(ans,cur);
        return;
    }
    if(cur>ans){
        return;
    }
    if(demons[src][0] !=0){
        ll hid=hidetime(cur+1,demons[src]);
        cur +=hid;
    }
    
    for(pair<int,int> p: adj[src]){
        dfs(p.first,dest,adj,cur+p.second,demons);
    }
}
int main(){
   int n,m;
   cin>>n>>m;
   //n=no. of universes
   //m=no. of portals
   vector<pair<int,int>> adj[n+1];
   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       adj[a].pb({b,c});
   }
   vector<int> demons[n+1];
   for(int i=0;i<n;i++){
       int k;
       cin>>k;
       demons[i+1].pb(k);
       for(int j=0;j<k;j++){
           ll p;
           cin>>p;
           demons[i+1].pb(p);
       }
   }
    //source =1, destination=n
    dfs(1,n, adj,0,demons);
    if(ans==mx){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
    
   return 0;
}