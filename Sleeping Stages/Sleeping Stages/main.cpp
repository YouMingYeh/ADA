#include <bits/stdc++.h>

using namespace std;
#define int long long
#define vi vector<int>

int N, K;
int dp_calculate[1001][501] = {0};
int dp_max_subarray[1001][1001] = {0};


int max_subarray(int l, int r, vi& val){
    if(dp_max_subarray[l][r] != 0) return dp_max_subarray[l][r];
    int curr_sum = 0;
    int max = LONG_LONG_MIN;
    for(int i = l; i <= r; i++)
    {
        curr_sum += val[i];
        max = std::max(curr_sum, max);
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    dp_max_subarray[l][r] = max;
    
    return max;
}

int Calculate(int l, vi& val, int k){
    if(dp_calculate[l][k] != 0) return dp_calculate[l][k];
    
    int ans = LONG_LONG_MAX;
    if(k == 1){
        
        ans = (N-l)*max_subarray(l,N-1,val);
        dp_calculate[l][k] = ans;
//        cout << l  << ans << endl;
        return ans;
    }
    
    
    if(l == N-1 && k > 1){
        ans = LONG_LONG_MAX;
        dp_calculate[l][k] = ans;
        return ans;
    }
    
    int MIN = LONG_LONG_MAX;
    for(int i = 0;i < N-l-k+1 ; i++){
        
        MIN = min(max_subarray(l,l+i, val)*(i+1) + Calculate(l+i+1, val, k-1),MIN);
        ans = min(MIN,ans);
    }
    
    dp_calculate[l][k] = ans;
//    std::cout << ans;
    return ans;
    
}
void print2D(int arr[][1001], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j]*(j-i+1) << " ";
        }
        cout<<endl;
    }
}


signed main() {
    cin >> N >> K;
    vi val(N);
    for(int i = 0;i < N; i++){
        cin >> val[i];
    }
    
    
    
    cout<< Calculate(0, val,K);
    print2D(dp_max_subarray, N);
}



