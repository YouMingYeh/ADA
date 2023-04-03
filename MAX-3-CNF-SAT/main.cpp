#include <bits/stdc++.h>
using namespace std;
using iTuple = tuple<int, int, int>;

int n , m;
vector<iTuple> clauses;
int main(){
    cin >> n >> m;
     
    
    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        clauses.emplace_back(a,b,c);
    }

    vector<int> x(n);
    bool flag = false;
    while(!flag){
        for(int i = 0; i < n; i++){
            int randomNumber = rand(); 
            if(randomNumber % 2 == 1){
                x[i] = 1;
            }else{
                x[i] = -1;
            }
        }
        int cnt = 0;
        for(auto clause: clauses){
            auto [p, q, r] = clause;
            
            if(p*x[abs(p) - 1] > 0 || q*x[abs(q) - 1] > 0 || r*x[abs(r) - 1] > 0){
                cnt++;
            }
        }
        if(cnt*8 >= 7*m){
            flag = true;
        }
    }
    
    for(int i =0 ;i < n; i++){
        if(i != n-1) cout<<x[i]<<" ";
        else cout <<x[i];
    }

}  