#include <iostream>
#include <stack>
#include <string>

void PLACE(int);
void PHOTO();
void POP();
void solver(int l,int r);
void swapper(int,int,int );
int times = 0;

int cnt = 1, total = 0;
std::string ans;

int main() {
    int n;
    std::cin >> n;
    total = n;
    
    
    
    for(int i = 0;i < n; i++)
    {
        PLACE(n-i);
        
    }
    int l=0;
    int r=n;
        
    solver(l,r);
    
    ans.pop_back();
    std::cout <<times << "\n"<<ans;
    
}
void swapper(int l,int m, int r)
{
    if(r-l == 1) return;
    for(int i =0 ;i < r-l;i++)
    {
        POP();
    }
    for(int i = l ;i < m; i++)
    {
        
        PLACE(i+1);
    }
    for(int i = 0; i < r - m; i++)
    {
        PLACE(r-i);
    }
}

void solver(int l, int r)
{
    int m=(l+r)/2;
    if(m - l > 1)
    {
        solver(l, m);
    }
    else
    {
        if(m==l);
        else{
            PHOTO();
        }
    }
    swapper(l,m,r);
    if(r - m > 1)
    {
        solver(m, r);
    }
    else{
        if(m==r);
        else{
            PHOTO();
        }
    }
}

void PLACE(int num)
{
    ans += "PLACE ";
    ans += std::to_string(num);
    ans += "\n";
    
    times++;
    
}

void PHOTO()
{
    ans += "PHOTO";
    ans += "\n";
    
    cnt++;
    times++;
}

void POP()
{
    ans += "POP ";
    ans += "\n";
    times++;
}
