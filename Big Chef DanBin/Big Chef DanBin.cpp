#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pii = pair<int, int>;


int group_num;
vi ppl_num;
vector< vector<pii> > ppl;
vi remaining;
int cnt = 0;

struct Data
{
    pii ac;
    int num;
};
// void print2DArray(vector< vector<pii> > arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = 0; j < arr[i].size(); j++)
//         {
//             cout << arr[i][j].first << " "<<arr[i][j].second <<" ";
//         }
//         cout << endl;
//     }
// }
// //print Array
// void printArray(vector<Data> a)
// {

//     for (int i = 0; i < a.size(); i++){
//         cout << i<<" groupTotal: "<<a[i].ac.first << " eatingTime:" << a[i].ac.second << endl;
//     }
    
// }


//solve
int solve(vector<pii> group)
{
    int eat = 0;
    int cook = 0;
    int num = group.size();
    int total = 0;
    for (int i = 0; i < num; i++)
    {
        total += group[i].first;
        eat = max(eat, total+group[i].second);
    }
    remaining.push_back(eat-total);
    return total;
}
//compare1


bool compare1(const pii& a, const pii& b)
{
    return a.second > b.second;
}

bool compare2(const Data& a, const Data& b ){
    int A;
    int B;
    A = (a.ac.first+a.ac.second)*a.num+(a.ac.first + b.ac.first + b.ac.second)*b.num;
    B = (b.ac.first+b.ac.second)*b.num+(b.ac.first + a.ac.first + a.ac.second)*a.num;
    // cout << A << " " << B << endl;
    return A < B;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(NULL);

    cin >> group_num;
    cnt = group_num;
    for (int i = 0; i < group_num; i++)
    {
        
        int a;
        
        vector<pii> temp;
        cin >> a;
        ppl_num.push_back(a);

        for (int j = 0; j < ppl_num[i]; j++)
        {
            int b,c;
            cin >> b>>c;
            temp.push_back(pii(b,c));
        }
        
        ppl.push_back(temp);
        sort(ppl[i].begin(),ppl[i].end(),compare1);
        
    }

    vector<Data> group_data;

    for(int i = 0; i < group_num; i++){
        Data HI;
        int wa = solve(ppl[i]);
        HI.ac = make_pair(wa,remaining[i]);
        HI.num = ppl_num[i];
        group_data.push_back(HI);
        
    }
    // printArray(group_data);
    sort(group_data.begin(),group_data.end(),compare2);
    
    
    // printArray(group_data);
    
    int ans = 0;
    int start = 0;
    int A = 0;
    // for(int i = 0; i < group_data.size(); i++){
    //     A += group_data[i].ac.first;

    //     ans += (A + group_data[i].ac.second)*group_data[i].num;
    // }
    
    for (auto g : group_data) {
        A += g.ac.first;

        ans += (A + g.ac.second)*g.num;

    }

    
    
    cout << ans;

    // print2DArray(ppl);

        return 0;
}
