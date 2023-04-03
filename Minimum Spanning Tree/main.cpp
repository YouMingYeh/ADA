#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pair<int, int> >;

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vii> adj(n);
    for(int i = 0; i < m; i++){
        int a, b, c;

        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    
    priority_queue<pii, vii, greater<pii>  > pq;

    pq.push(make_pair(0,0));
    vector<bool> visited(n,false);
    int ans = 0;
    while(!pq.empty()){
        int len = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        
        if(visited[w]) continue;
        visited[w] = true;
        ans += len;

        for(auto &v : adj[w]){
            if(visited[v.first]) continue;
            else{
                pq.push(make_pair(v.second,v.first));
            }
        }
    }
    cout << ans;

}