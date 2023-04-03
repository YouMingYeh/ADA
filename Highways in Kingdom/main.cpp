#include <bits/stdc++.h>
using namespace std;
#define int long long

using vi = vector<int>;
using pii = pair<int, int>;
using iTuple = tuple<int, int, int>;
using ac = tuple<int, int, int, int>;

int M, N;

vector<vector<iTuple > > adj;
int ans = 0;
vi LP;
signed main()
{
    // cout << Min;
    cin >> N >> M;
    adj.resize(N);

    for (int i = 0; i < M; i++)
    {
        int a, b, c,d;
        cin >> a >> b >> c >> d;
        adj[a].push_back(iTuple(b,c,d));
        adj[b].push_back(iTuple(a,c,d));
    }

    priority_queue<ac, vector<ac>, greater<ac> > pq;
    // vertex, cost, length
    pq.push(ac(0,0,0,0));
    vector<bool> visited(N,false);
    int cnt = 0;
    LP.resize(N,0);
    LP[0] = 0;
    
    while (!pq.empty() && cnt < N)
    {
        
        
        
        int w = get<2>(pq.top());
        
        
        if(visited[w]){
            pq.pop();
            continue;
            
        } 
        
        
        cnt++;
        visited[w] = true;
        
        
        int x_length = get<0>(pq.top());
        int x_cost = get<1>(pq.top());
        int from = get<3>(pq.top());
        pq.pop();
        // cout << "pop" << x_length <<" "<< x_cost <<" "<< w <<endl;
        LP[w] = max(LP[from],x_length);
        ans+=x_cost;
        // cout << w <<" "<< x_cost << endl;
        for (auto &v : adj[w])
        {
            
            int u = get<0>(v); //每個一個相鄰vertices
            int length = get<1>(v); //
            int cost = get<2>(v); //
            
            if(visited[u]) continue;

            if(length < LP[w]){
                // cout<<"!" << LP[w] << w;
                cost = x_cost;
            }
            else if(length == LP[w]){
                cost += x_cost;
            }
            

            
            

            // cout << "push" << length << " " << cost << " "<< u<< endl;
            pq.push(ac(length,cost,u,w));
                
            
        }
    }

    std::cout << ans;
    
    
}
