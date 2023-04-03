#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using vii = vector<vi>;

stack<int> S;
vii adj;
int n; //#vertices
int m; //#edges
vii adj_T;
int ans = 0;
int cnt = 0;


void DFS(int v, vector<bool>& visited){
    // cout << v <<"DFS" << endl;
    visited[v] = true;
    for(int i = 0;i < adj[v].size();i++){
        if(!visited[adj[v][i]]){
            DFS(adj[v][i],visited);
        }
    }

    S.push(v);
    // cout << v << " pushed to S" << endl;
};

void DFS2(int v, vector<bool>& visited){
    cnt++;
    visited[v] = true;
    for(int i = 0;i < adj_T[v].size();i++){
        if(!visited[adj_T[v][i]]){
            DFS2(adj_T[v][i],visited);
        }
    }
    
}


signed main(){
    cin >> n >> m;
    adj.resize(n);
    adj_T.resize(n);

    int U = 0, V = 0;
    for(int i = 0; i < m; i++){
        cin >> U >> V;
        // cout << U << ' ' << V << endl;
        // cout << "cin complete"<<endl;
        adj_T[V-1].push_back(U-1);
        adj[U-1].push_back(V-1); // 1 = 0, 2 =1 ...
    }
    // cout << "init completed" << std::fflush;

    vector<bool> visited(n,false);
    for(int i = 0;i < n;i++){
        if(!visited[i]) DFS(i,visited);
    }
    // cout << "DFS completed"<< std::fflush;;
    vector<bool> visited2(n,false);
    
    while(!S.empty()){
        int v = S.top();
        S.pop();
        cnt = 0;
        if(!visited2[v]){
            DFS2(v,visited2);
            // cout << cnt << endl;
        }
        
        ans += cnt*(cnt-1)/2;
    }
    // cout << "DFS2 completed";
    cout<<ans;
}
