#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

int N, M;
// vector<bool> mark;
vector<vi> adj;
vi pos;
vector<pair<int,int> > ac;
vector<pair<int, int> > start_time;
vi end_time;
int cnt = 0;
int dp[3001][3001]= {0};
vi nextChild;
vi nextTree;
vi total;
int MAX = 0;
int DFS(vector<bool>& visited, int v){
    visited[v] = true;
    cnt++;
    start_time[v].first = cnt;
    start_time[v].second = v;
    total[v] = ac[v].first;
    // cout << v << std::flush;
    if(adj[v].size() > 0){
        for(int i = 0; i < adj[v].size() - 1 ; i++){
            
            nextTree[adj[v][i]] = adj[v][i+1];
            
        }
            nextTree[adj[v].back()] = nextTree[v];
    }

    for(auto &u: adj[v]){
        if(!visited[u]){
            total[v]+=DFS(visited, u);
        }

    }
    return total[v];
}

int S(int k, int v){
    if(v == -1 || k <= 0) return INT64_MIN;

    if(dp[k][v] != 0) return dp[k][v];
    
    int sum = 0;
    sum = max(sum, S(k, nextChild[v]));
    sum = max(S(k-ac[v].first,nextChild[v] + ac[v].first), sum);
    sum = max(sum, S(k-ac[v].second, nextTree[v]) + total[v]);
    
    dp[k][v] = sum;
    return sum;
}


signed main(){
    cin >> N >> M;
    adj.resize(N);
    pos.resize(N);
    start_time.resize(N);
    end_time.resize(N);
    nextTree.resize(N, -1);
    nextChild.resize(N, - 1);
    total.resize(N);
    int c = 0;
    
    // cout << '!';
    for(int i = 0; i < N; i++){
        cin >> pos[i];
        // cout << i << std::flush;
        if(pos[i] == -1 && i != 0) {
            nextTree[c] = i;
            c = i;
        }
        if(pos[i] == -1){
            
        }else 
            adj[pos[i]].push_back(i);
        
    }

    ac.resize(N);
    for(int i = 0; i < N; i++){
        cin >> ac[i].first >> ac[i].second;
    }
    vector<bool> visited(N);
    for(int i = 0; i < N; i++){
        if(!visited[i]) DFS(visited, i);
    }

    for(int i = 0; i< N; i++){
        cout << nextTree[i]<< " ";
    }
    
    sort(start_time.begin(), start_time.end());
    for(int i = 0; i < start_time.size() - 1; i++){
        nextChild[start_time[i].second] = start_time[i+1].second;
    }
    for(int i = 0; i < nextChild.size();i++){
        cout << nextChild[i]<< " ";
    }
    

    cout << S(M,0);
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}