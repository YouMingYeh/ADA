#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using vi = std::vector<int>;
using mi = std::map<int,vi>;
void Cal(int l, int r ,mi::iterator );

int rbound = 0;
int count(int ,int ,int num);
int find(int i, int r, int m);

int n = 0;
vi loc;
int curr = 0;
mi rec;
int max_diff = 0;
int cnt = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> n;
    loc.resize(n);
    
    for(int i = 0 ; i < n; i ++)
    {
        std::cin >> loc[i];
        
        rec[loc[i]].push_back(i);
//        std::sort(rec[loc[i]].begin(),rec[loc[i]].end());
        
    }
    max_diff= ((rec.rbegin()++)->first-rec.begin()->first);
    mi::iterator it = rec.begin(); //紀錄 it for map
    
    int l = 0; //
    
    Cal(l,n, it);
    std::cout << cnt;
}

void Cal(int l, int r ,mi::iterator it)
{
   
    if(l >= r) return;
    int min = it->first;
    if(min > max_diff) return;
    
    
    
//    std::cout <<"l:"<< l << " r:"<< r <<" min:"<<min<<"\n";
    while(find(l,r,min) == -1)
    {
        if(it == rec.end()) return;
        it++;
        min = it->first;
    }
    
    std::map<int,int> done;
    int m = find(l,r,min);
    for(int i = l; i < r ; i ++ )
    {
        if(i > m )
        {
            done.clear();
            m = find(i,r,min);
        }
        if(m == -1) {
            break;
        }
        
        if(done.find(loc[i]) != done.end() )
        {
            cnt+=done.at(loc[i]);
            continue;
        }
        
        int res = 0;
        
        res = count(m , r , loc[i] + min);
        cnt+=res;
        done[loc[i]]+=res;
        done[loc[i]+2*min] += res;
        
        res = count(m , r , loc[i] - min);
        cnt+= res;
        done[loc[i]] += res;
        done[loc[i]-2*min] += res;
        
    }
    
    if(std::next(it) == rec.end()) return;
    
    while(true)
    {
        int m = find(l,r,min);
        if(m == -1) break;
        
        Cal(l, m, std::next(it));
        l = m +1;
    }
    
    Cal(l,r, std::next(it));
//    l+=1;
//    while(true)
//    {
//        int m = find(l,r,min);
//        if(m == -1) break;
//
//        Cal(l, m, std::next(it));
//        l = m +1;
//    }
//
//    Cal(l,r, std::next(it));
}

int find(int l, int r, int num)
{
    
    if(l > r) return -1;
    for(int i = 0; i < rec[num].size();i++)
    {
        if(rec[num][i] >= l && rec[num][i] < r)
        {
            
            return rec[num][i];
        }
    }
    return -1;
}

int count(int l, int r, int num)
{
    if(rec.count(num) == 0) return 0;
    
    int c = 0;
    for(int i = 0;i < rec[num].size(); i++)
    {
        if(rec[num][i] < l) continue;
        if(rec[num][i] >= r) break;
        c++;
    }
    return c;
}
