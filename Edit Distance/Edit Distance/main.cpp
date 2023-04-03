#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;
int n , m;
int dp[3001][3001] = {0};

int editDistance(int i, int j) {
    if(dp[i][j] != 0) return dp[i][j];
    
	if (i == 0) return j; //i==0 str1 convert to str2 takes j steps



	if (j == 0) return i; //j==0 str1 convert to str2 takes i steps

	int ans = 1 + min({
		editDistance(i, j - 1), // insertions
		editDistance(i - 1, j), // deletions
		editDistance(i - 1, j - 1) //substitution
	});
    
    
	if (str1[i - 1] == str2[j - 1]) {
		ans = min(ans, editDistance(i - 1, j - 1)); //if the last index is equal
	}
    
    dp[i][j] = ans;
	return ans;
}

int _editDistance(){

    
	int ans = editDistance(n,m);

	return ans;
}

int main() {
    
	cin>>str1>>str2;
    n = str1.size();
    m = str2.size();
	cout<<_editDistance();

}
