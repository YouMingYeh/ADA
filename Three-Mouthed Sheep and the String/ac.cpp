//credit to 許文鑫's segment tree and lazy propagation code
//感謝資管系同學們的各種debug方式

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 500000
struct Node
{
    int val;
    int tag;
    Node() : val(0), tag(0) {}
};

string str;
int K;
Node st[4 * MAX + 1];
map<char, vector<int>> M;
int pushed = 0;

bool flag = false;

// lazy propagation
int sum(int node, int l, int r)
{
    return st[node].val + st[node].tag * (r - l + 1);
}

void push(int node)
{
    st[2 * node].tag += st[node].tag;
    st[2 * node + 1].tag += st[node].tag;
    st[node].tag = 0;
}

void pull(int node, int l, int r)
{
    st[node].val = sum(2 * node, l, (l + r) / 2) + sum(2 * node + 1, (l + r) / 2 + 1, r);
}

void add(int node, int l, int r, int ql, int qr, int u)
{
    if (ql <= l && r <= qr)
    {
        st[node].tag += u;
        return;
    }
    else if (ql > r || qr < l)
    {
        return;
    }
    push(node);
    add(2 * node, l, (l + r) / 2, ql, qr, u);
    add(2 * node + 1, (l + r) / 2 + 1, r, ql, qr, u);
    pull(node, l, r);
}
int query(int node, int l, int r, int ql, int qr)
{

    if (ql <= l && r <= qr)
    {
        return sum(node, l, r);
    }
    else if (ql > r || qr < l)
    {
        return 0;
    }
    push(node);
    int ret = query(2 * node, l, (l + r) / 2, ql, qr) + query(2 * node + 1, (l + r) / 2 + 1, r, ql, qr);
    pull(node, l, r);
    return ret;
}

int findTrueIndex(int i)
{
    return i + query(1, 0, str.length() - 1, i, i);
}
int findMin()
{
    if (pushed >= str.length())
        return -1;

    int min_index = -1;
    int y = str.length();
    for (auto &w : M)
    {
        if (w.second.size() == 0)
            continue;
        if (w.second.back() > y)
            continue;
        else
            y = w.second.back();

        int x = findTrueIndex(w.second.back());
        
        if (pushed <= x && x <= pushed + K)
        {
            // cout  << pushed << " " << x << " " << pushed+K <<endl;
            K -= x - pushed;
            min_index = w.second.back();
            w.second.pop_back();

            if (w.second.size() == 0)
                M.erase(w.first);
            
            if(K == 0) flag = true;
            return min_index;
        }
    }

    return min_index;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    cin >> str;
    cin >> K;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        M[str[i]].push_back(i);
    }



    for (int i = 0; i < str.length(); i++)
    {
        int min_index = findMin();
        if (min_index == -1)
            break;
        cout << str[min_index];
        str[min_index] = '/';
        if(flag) break;
        add(1, 0, str.length() - 1, 0, min_index - 1, 1);
        pushed++;
        
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '/'){
            cout << str[i];
        }
    }
}
