#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int v[405][405];

int dp[405][405][405]; // i to j-1 cut k

int S(int i, int j, int K)
{
    // S(i to j -1)
    if (dp[i][j][K] != 0)
        return dp[i][j][K];

    
    if(i <= j && j - i < K){
        dp[i][j][K] = INT32_MIN;
        return INT32_MIN;
    }

    if (i < j)
    {
        for (int m = i; m < j ; m++)
        {
            int sum = 0;
            // sum = S(i,m, K -1) + dp[m+1][j][0];
            sum = dp[i][m][K-1]+dp[m+1][j][0];
            dp[i][j][K] = max(dp[i][j][K], sum);
        }
    }

    return dp[i][j][K];
}

void printDP()
{

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int K = (j + N - 1) >= N ? (j + N - 1) - N : (j + N - 1);
            cin >> v[i][K];
            // value from i to (j-1+N)%N
        }
    }

    // 13 1 5 9
    // 10 14 2 6
    // 7 11 15 3
    // 4 8 12 16

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j][0] = v[i][j];
        }
    }

    
    vector<int> ans(N);
    
    for(int k = 1; k < N; k++){
        for(int i = 0; N-i > k; i++){
            dp[i][(i-1+N)%N][k] = 
                max(S(i,N-1,k-1) , dp[i][(i-1+N)%N][k]);
        }
    }
    
    printDP();
    for (int k = N-1; k >=0; k--){
        for (int s = 0; s < N; s++)
        {
            int r = (s + N - 1) >= N ? (s + N - 1) - N : (s + N - 1);
            // ans[k] = max(ans[k], S(s, r, k));
            if(k == 0) ans[k] = max(ans[k], dp[s][r][k]);
            else ans[k] = max(ans[k], dp[s][N-1][k-1] + dp[0][s-1][0]);
        }
    }
    for (int k = 0; k < N; k++)
    {
        cout << ans[k] << " ";
    }
}