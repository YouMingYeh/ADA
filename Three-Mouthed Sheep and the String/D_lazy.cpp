

#include <iostream>
using namespace std;

#define max 200000
struct Node
{
    long long val;
    long long tag;
    Node() : val(0), tag(0) {}
};
int input[max + 11];
Node st[4 * max + 11];

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            st[node].val = input[l];
            return;
        }
        build(2 * node, l, (l + r) / 2);
        build(2 * node + 1, (l + r) / 2 + 1, r);
        st[node].val = st[2 * node].val + st[2 * node + 1].val;
    }
long long sum(int node, int l, int r)
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
void add(int node, int l, int r, int ql, int qr, long long u)
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
long long query(int node, int l, int r, int ql, int qr)
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
    long long ret = query(2 * node, l, (l + r) / 2, ql, qr) + query(2 * node + 1, (l + r) / 2 + 1, r, ql, qr);
    pull(node, l, r);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int l, r;
            long long u;
            cin >> l >> r >> u;
            add(1, 1, n, l, r, u);
        }
        else
        {
            int k;
            cin >> k;
            cout << query(1, 1, n, k, k) << '\n';
        }
    }
    return 0;
}