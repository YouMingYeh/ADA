#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define vi std::vector<int>

int subOptimal(vi&, int W);
int Optimal(vi&, int W, int);
std::map<int,int> foundedSum;

int main()
{
    int N, W;
    std::cin >> N >> W;
    vi price(N);
    for(auto &v: price)
    {
        std::cin >> v;
    }
    
    int st = 0;
    
    std::sort(price.begin(),price.end());
    
    for(int i = 1; i <= W; i ++)
    {
        std::cout << subOptimal(price, i) - Optimal(price, i, st)<<'\n';
        
    }
    
    
}

int subOptimal(vi& price,int W){
    for(int i = 0; i < price.size();i++)
    {
        
        W = W % price[price.size()-1-i];
        if(W == 0) return 0;
        
    }
    return W;
}




int Optimal(vi& price , int remaining, int st){
    if(st >= price.size()) return remaining;
    if(foundedSum.find(remaining) != foundedSum.end()) return foundedSum[remaining];
    
    if(remaining >= price[st])
    {
        if(remaining % price[st] == 0) return 0;
        int ans = std::min(Optimal(price, remaining - price[st], st), Optimal(price, remaining, st+1));
        foundedSum[remaining] = ans;
        return ans;
    }
    else
    {
        foundedSum[remaining] = remaining;
        return remaining;
    }
}

