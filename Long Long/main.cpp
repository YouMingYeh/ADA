// In this problem, we want you to find the longest simple path from S to T. You are given an unidirected graph with N vertices and M edges. 
//There are non-negative integer weights on each edges.
//Please output the maximum weight among all simple path from S to T, where S, T are the starting and ending vertices. 
//You should also provide the actual path with that maximum weight.

// The weight of a simple path is defined as the sum of the weight of each edge on the path.

// A path is called simple if it does not have any repeated vertices.

/*
To find the longest simple path in a DAG, you can first topologically sort the vertices of the DAG. 
This will put the vertices in a linear order such that if there is a directed edge from vertex A to vertex B, then vertex A will come before vertex B in the linear order
Once the vertices are topologically sorted, you can start at the first vertex in the order and move along the edges of the DAG, keeping track of the longest simple path that you have found so far.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl "\n"
using vi = vector<int>;
using iPair = pair<int, int>;
using iTuple = tuple<int, int, int>;

int N, M;
int MAX = 0;
vector<iPair> PATH;


bool bySec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

iPair EdgeIndex[95][95];

class Graph {
public:
	vector<bool> visited;
	vector<vector<iPair > > adj;
    vector<int> dist;
	void addEdge(int v, int w, int weight);

	void DFS(int v, int from, int T);

};

void Graph::addEdge(int v, int w, int weight)
{
	adj[v].emplace_back(w, weight); 
}

vector<iPair>  CurrentPath;
int CurrentTotal = 0;
pair<vector<iPair>,int>  SimplePath;

void Graph::DFS(int v, int from, int T)
{
    if(visited[v]) return;
	visited[v] = true;
    if(from != v){
        CurrentPath.push_back(iPair(from, v));
        CurrentTotal += EdgeIndex[from][v].second;
    }
	if(v == T)
    {
        if(SimplePath.second < CurrentTotal){
            SimplePath = (make_pair(CurrentPath, CurrentTotal));
        }
        visited[v] = false;
        CurrentPath.pop_back();
        CurrentTotal-= EdgeIndex[from][v].second;
        return;
    }

    for(auto &edge: adj[v]){
            auto [w, weight] = edge;
            DFS(w, v, T);
    }
    CurrentPath.pop_back();
    CurrentTotal-=EdgeIndex[from][v].second;
    visited[v] = false;

}  

        






signed main(){
    cin >> N >> M;
    Graph g;
    Graph g_T;
    g.visited.resize(N);
    g.adj.resize(N);
    g.dist.resize(N, -1);
    
    for(int i = 0; i < M; i ++){
        int from, to, weight;
        cin >> from >> to >> weight;
        
        g.addEdge(from -1 , to-1, weight);
        
        if(weight > EdgeIndex[from -1][to -1].second){
            EdgeIndex[from -1][to -1] = make_pair(i+1, weight);
        }
    }

    for(int i = 0; i < N; i ++){
        sort(g.adj[i].begin(), g.adj[i].end(), bySec);
    }
    

    string chosen_edge(M, '0');
    vector<iPair> temp;
    SimplePath = make_pair(temp, -1);
    g.DFS(0, 0, N-1);
    if(SimplePath.second == -1){
        cout<< -1;
        return 0;
    }  
    
    

    auto path = SimplePath.first;
    vi Choosing;
    for(int i = 0;i < path.size();i++){
        auto [from, to] = path[i];
        if(from != to)
            Choosing.push_back(EdgeIndex[from][to].first - 1);
    }
    cout << SimplePath.second << '\n';
    for(auto choice: Choosing){
        // cout << choice;
        chosen_edge[choice] = '1';
    }
    cout << chosen_edge;




    return 0;
}