//參考ada戰友區與資管系邱一新同學的算法


#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define int long long
using vi = std::vector<int>;
int right[100001] = {0};
int left[100001] = {0};
int cnt = 0;
int test = 0;
void solve(vi& loc,int l, int r){
    
    if(r - l <= 1) return ;
    int m = (l+r)/2;
    solve(loc, l , m);//divide
    solve(loc, m , r);
    //solve
    
    
    int l_curr = m - 1;
    int r_curr = m;
    int l_bound = m-1;
    int r_bound = m;
    
    
    int min;
    int mode;
    int temp = 0;
    
    if(loc[l_bound] <= loc[r_bound]){
        min = loc[l_bound];
        mode = 0;
    }
    else{
        min = loc[r_bound];
        mode = 1;
    }
    
    
    do{
//        std::cout << static_cast<int>(mode);
//        std::cout << l <<m<< r << std::endl;
        
//        std::cout << right[4];
        if(mode == 0){
            if(l_bound >= l){
                while(loc[l_bound] >= min){
                    
                    left[loc[l_bound]]++;
                    if(l_bound == l) {
                        l_bound--;
                        break;
                    }else{
                        l_bound--;
                    }
    //                std::cout << 'a';
                }
            }
            
    //        std::cout << right[1];
            if(r_bound <= r-1){
                while(loc[r_bound] >= min){
                    right[loc[r_bound]]++;
                    if(r_bound == r-1) {
                        r_bound++;
                        break;
                    }
                    else{
                        r_bound++;
                    }
    //                std::cout << 'b';
                }
            }
            while(l_curr > l_bound){
                if(loc[l_curr]+min <= 100000)
                    temp += right[loc[l_curr]+min];
                if(loc[l_curr]-min >= 0)
                temp += right[loc[l_curr]-min];
                l_curr--;
//                std::cout << 'c';
            }
        }else if(mode == 1){
            if(l_bound >= l){
                while(loc[l_bound] >= min){
                    left[loc[l_bound]]++;
                    if(l_bound == l) {
                        l_bound--;
                        break;
                    }else{
                        l_bound--;
                    }
    //                std::cout << 'a';
                }
            }
            
    //        std::cout << right[1];
            if(r_bound <= r-1){
                while(loc[r_bound] >= min){
                    right[loc[r_bound]]++;
                    if(r_bound == r-1) {
                        r_bound++;
                        break;
                    }
                    else{
                        r_bound++;
                    }
    //                std::cout << 'b';
                }
            }
            while(r_curr < r_bound){
                if(loc[r_curr]+min <= 100000)
                    temp += left[loc[r_curr]+min];
                if(loc[r_curr]-min >= 0)
                    temp += left[loc[r_curr]-min];
                r_curr++;
//                std::cout << 'd';
            
            }
        }
        else if (mode == 2){
            if(l_bound >= l){
                while(loc[l_bound] >= min){
                    left[loc[l_bound]]++;
                    if(l_bound == l) {
                        l_bound--;
                        break;
                    }else{
                        l_bound--;
                    }
    //                std::cout << 'a';
                }
            }
            while(l_curr > l_bound){
                if(loc[l_curr]+min <= 100000)
                temp += right[loc[l_curr]+min];
                if(loc[l_curr]-min >= 0)
                temp += right[loc[l_curr]-min];
                l_curr--;
//                std::cout << 'c';
            }
            
    //        std::cout << right[1];
            if(r_bound <= r-1){
                while(loc[r_bound] >= min){
                    right[loc[r_bound]]++;
                    if(r_bound == r-1) {
                        r_bound++;
                        break;
                    }
                    else{
                        r_bound++;
                    }
    //                std::cout << 'b';
                }
            }
            while(r_curr < r_bound){
                if(loc[r_curr]+min <= 100000)
                temp += left[loc[r_curr]+min];
                if(loc[r_curr]-min >= 0)
                temp += left[loc[r_curr]-min];
                r_curr++;
//                std::cout << 'd';
            
            }
        }
        if(l_bound < l && r_bound > r-1) break;
        if(l_bound < l){
            min = loc[r_bound];
            mode = 1;
            r_curr = r_bound;
            continue;
        }
        else if(r_bound > r-1){
            min = loc[l_bound];
            mode = 0;
            l_curr = l_bound;
            continue;
        }
        
        if(loc[l_bound] == loc[r_bound])
        {
            min = loc[l_bound];
            mode =  2;
            l_curr = l_bound;
            r_curr = r_bound;
        }
        else if(loc[l_bound] > loc[r_bound]){
            min = loc[l_bound];
            mode = 0;
            l_curr = l_bound;
        }
        else{
            min = loc[r_bound];
            mode = 1;
            r_curr = r_bound;
        }
        
    }while(true);
    
    cnt+= temp;
    for(int i = l;i <r;i++){
        right[loc[i]] = 0;
        left[loc[i]] = 0;
    }
//    std::cout << "l: "<<l<<"  r: "<<r<<"  cnt: "<<temp<<std::endl;
    return;
    
}

signed main()
{
    int n = 0;
    std::cin >> n;
    vi loc(n);
//    int max = 0;
    for(auto &v : loc)
    {
        std::cin >> v;
//        max = std::max(v, max);
    }
    
    solve(loc,0,n);
    std::cout << cnt;
    
    
    
}
