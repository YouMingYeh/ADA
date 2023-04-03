#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int v[405][405];

int dp[405][405][405]; // i to j-1 cut k

int S(int i, int j, int K)
{
    if (dp[i][j][K] != 0)
        return dp[i][j][K];
    
    for(int len = K ; len < j ; len++){
        
        // int sum = dp[i][len][K-1] + dp[(i+len)][j-len][0];
        int sum = S(i, len, K-1) + dp[(i+len)][j-len][0];
        
        dp[i][j][K] = max(dp[i][j][K], sum);
    }

    return dp[i][j][K];
}

void printDP()
{

    for (int k = 0; k < N+1; k++)
    {
        for (int i = 0; i < N+1; i++)
        {
            for (int j = 0; j < N+1; j++)
            {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int K = (j + N - 1) >= N ? (j + N - 1) - N : (j + N - 1);
            cin >> v[i][K];
            
        }
    }

    // 13 1 5 9
    // 10 14 2 6
    // 7 11 15 3
    // 4 8 12 16

    vector<int> ans(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if( i <= j)
                dp[i][j-i+1][0] = v[i][j];
            else 
                dp[i][j-i+N+1][0] = v[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        ans[0] = max(dp[i][N][0],ans[0]);
    }

    // for(int i=0; i<N; i++){
    //     for(int j=1; i + j < N; j++){
    //         for(int k=j-1; k < N; k++){
    //             S(i, j, k);
    //         }
    //     }
    // }
            
    
    // printDP();

    for(int i=0; i<N; i++){
        for(int j=1; i + j <N; j++){
            for(int k=j; k > 0; k--){
                // int sum = dp[i][j][k-1] + dp[i+j][N-j][0];
                int sum = S(i, j, k-1) + dp[i+j][N-j][0];
                dp[i][N][k] = max(sum, dp[i][N][k]);
                ans[k] = max(dp[i][N][k], ans[k]);
            }
        }
    }

    

    
    for (int k = 0; k < N; k++)
    {
        cout << ans[k] << " ";
    }
}