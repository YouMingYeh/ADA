#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pii = pair<int, int>;

void print2DArray(vector<vector<pair<int, int> > > &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j].first << " " << array[i][j].second << " ";
        }
        cout << endl;
    }
}

int M, N;
int Min = INT64_MAX;

vector<vector<pair<int, int> > > adj;
signed main()
{
    // cout << Min;
    cin >> N >> M;
    adj.resize(N);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(pair<int, int>(b - 1, c));
    }

    for (int i = 1; i < N; i++)
    {

         bool flag = false;
        int changed = 0;
        for(auto &v: adj[0]){
            if(v.first == i){
                changed = v.second;
                v.second = 0;
                flag = true;
                
            }
        }
        if(!flag){
           adj[0].push_back(pair<int,int>(i,0)); 
        }


        priority_queue<pii, vector<pii>, greater<pii> > pq;
        vi SP(N, INT64_MAX);
        pq.push(make_pair(0, 0));
        SP[0] = 0;

        while (!pq.empty())
        {
            int w = pq.top().second;
            pq.pop();
            for (auto &v : adj[w])
            {
                int u = v.first;
                int weight = v.second;

                if (SP[w] + weight < SP[u])
                {

                    SP[u] = SP[w] + weight;
                    pq.push(make_pair(SP[u], u));
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < SP.size(); i++)
        {
            sum += SP[i];
        }
        Min = min(sum, Min);
        if(!flag) adj[0].pop_back();
        else{
            for(auto &v: adj[0]){
            if(v.first == i){
                v.second = changed;
                
            }
        }
        }
    }
    cout << Min;

    //

    // BFS
    // for (int i = 1; i < N; i++)
    // {

    //     adj[0].push_back(pair<int,int>(i,0));

    //     // print2DArray(adj);

    //     vector<bool> mark(N,false);
    //     vector<int> SP(N, INT64_MAX);
    //     queue<int> Q;
    //     SP[0] = 0;
    //     Q.push(0);
    //     while (Q.size() > 0)
    //     {
    //         int w = Q.front();
    //         Q.pop();
    //         // cout << w;
    //         mark[w] = true;
    //         for (auto &v : adj[w])
    //         {
    //             // cout << '!';
    //             if(!mark[v.first]){
    //                 // cout << v.first;
    //                 if(w == 0 && v.first == i && v.second > 0) continue;
    //                 Q.push(v.first);
    //                 if(SP[w] + v.second < SP[v.first]){
    //                     SP[v.first] = SP[w] + v.second;
    //                 }
    //             }
    //         }

    //     }
    //     int sum = 0;
    //     for(int j = 0; j < N; j++)
    //     {
    //         // cout << SP[j] << " ";
    //         sum += SP[j];
    //     }
    //     // cout << sum << endl;
    //     Min = min(sum,Min);
    //     // cout << endl;
    //     adj[0].pop_back();
    // }
    // cout << Min;

    // // print2DArray(adj);
    // // for(int i = 0; i < N; i++){
    // //     cout << SP[i] << " ";
    // // }
    // // for (int i = 0; i < N; i++)
    // // {
    // // }
}