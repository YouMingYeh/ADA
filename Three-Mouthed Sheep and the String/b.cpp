//prefixSum
#include <bits/stdc++.h>
using namespace std;

//prefixSum
int prefixSum(int arr[], int n)
{
    int prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix = prefix + arr[i];
    }
    return prefix;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << prefixSum(arr, n);
    return 0;
}