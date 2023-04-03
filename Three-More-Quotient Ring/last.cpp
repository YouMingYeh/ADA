#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int v[405][405];

int dp1[405][405]; // i to j-1 cut k
int dp2[405][405];

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
            //cin >> v[i][j-1]
        }
    }
    
    // 1 2 3 4

    // 13 1 5 9
    // 10 14 2 6
    // 7 11 15 3
    // 4 8 12 16
    vector<int> ans(N);
    for (int s = 0; s < N; s++) // start point
    {
        for (int i = 0; i < N; i++) // cal base case
        {

            dp1[i][0] = v[(i + s) >= N ? (i + s) - N: (i + s)][(s + N - 1) >= N ? (s + N - 1)- N: (s + N - 1)];
            //1 2 3 4
            // cout << dp1[i][0] << " ";
        }

        //1 2 3 4
        
        for (int k = 1; k < N; k++)
        {
            for (int i = 0; k < N - i - s ; i++)
            {
                for (int j = i + 1; k - 1 < N - j - s ; j++)
                {
                    dp1[i][k] = max(dp1[j][k - 1] + v[(s + i) >= N ? (s + i) - N: (s + i)][(s + j - 1) >= N? (s + j - 1) - N: (s + j - 1)], dp1[i][k]);
                }
            }
        }
        //4 1 2 3
        
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < N; k++)
            {
                
                cout << dp1[i][k] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < N; k++)
            {
                ans[k] = max(dp1[0][k], ans[k]);
                dp1[i][k] = 0;
            }
        }
    }

    // 13 1 5 9
    // 10 14 2 6
    // 7 11 15 3
    // 4 8 12 16

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}