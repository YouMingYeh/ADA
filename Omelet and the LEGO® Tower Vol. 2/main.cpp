#include <bits/stdc++.h>
using namespace std;
#define int long long
#define print(x) cout << x << endl;
#define vi vector<int>

int N , K , M;
int dp1[301][301]={0};
int dp2[301][301]={0};

int Sum1(int n, int a, int b);
int Sum2(int n, int a, int b);

void PrintDP(int type){
    int x = max(N-2,0ll);
    if(type== 1){
        for(int i= x; i<=N; i++){
            for(int j= x; j<=N; j++){
                cout << dp1[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        for(int i= x; i<=N; i++){
            for(int j= x; j<=N; j++){
                cout << dp2[i][j] << " ";
            }
            cout << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K >> M;

    for(int k = 1; k <= N+1; k++){ //跑 N+1次
        for(int i=0; i<=K; i++){
            for(int j=0; j<=i; j++){
                if(k%2 == 0)
                    Sum1(k,i,j); // N 是偶數 會使用dp2 會得到dp1
                else
                    Sum2(k,i,j); // N 是奇數 會使用dp1 會得到dp2
            }
        }
    }
    // PrintDP(1);
    // PrintDP(2);
    int ans = (N%2 == 0) ? (dp2[K][K]) : (dp1[K][K]);
    cout << ans; //印出答案

}




int Sum1(int n, int a, int b){
    if(n == 1) {
        dp1[a][b] = 1;
        return 1;
    }
    int total = 0;
    for(int i = 0; i <= b; i++){
        total+= dp2[a][i];
        total = total >= M ? total-M : total;
    }
    if(a != b){
        for(int i = b; i <= a-1; i++){
            total+= dp2[i][b];
            total = total >= M ? total-M : total;
        }
    }
    dp1[a][b] = total;
    return dp1[a][b];
}
int Sum2(int n, int a, int b){
    if(n == 1) {
        dp2[a][b] = 1;
        return 1;
    }

    int total = 0;
    
    for(int i = 0; i <= b; i++){
        total+= dp1[a][i];
        total = total >= M ? total-M : total;
    }
    
    if(a != b){
        for(int i = b; i <= a-1; i++){
            total+= dp1[i][b];
            total = total >= M ? total-M : total;
        }
    }
    dp2[a][b] = total;
    return dp2[a][b];
}