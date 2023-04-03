#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;

vi rod;
vi prefix_sum;
int M;
vi ans;

bool bySec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void print(vi a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
}


signed main(){
    cin >> M;
    for(int i = 0;i < M;i++){
        string str;
        cin >> str;
        // cout << i;
        if(str == "PUT"){
            int weight = 0;
            cin >> weight;
            rod.push_back(weight);
            if(prefix_sum.size() == 0){
                prefix_sum.push_back(weight);
            }else{
                prefix_sum.push_back(weight+prefix_sum.back());
            }
        }else if(str == "TAKE"){
            ans.push_back(rod.back());

            prefix_sum.pop_back();
            rod.pop_back();
            
        }else if(str == "CC"){
            int x, k;
            cin >> x >> k;
            int X = ceil(static_cast<double>(x)/static_cast<double>(k));
            vector<pair<int,int> > temp;
            int a = rod.size() ;
            for(int j = 0;j < x;j++){
                temp.push_back(pair<int,int>(rod[a-1-j],x-j -1));
                // rod.pop_back();
                // prefix_sum.pop_back();
            }
            rod.erase(rod.end() - x, rod.end());
            prefix_sum.erase(prefix_sum.end() - x, prefix_sum.end());
        
            std::sort(temp.begin(), temp.end());
            int sum = 0;
            for(int j = 0;j < X;j++){
                sum += temp[x-1-j].first;
                // temp.pop_back();
            }
            temp.erase(temp.end() - X, temp.end());

            std::sort(temp.begin(), temp.end(),bySec);
            for(int j = 0;j < temp.size();j++){
                rod.push_back(temp[j].first);
                if(prefix_sum.size() == 0){
                    prefix_sum.push_back(temp[j].first);
                }else{
                    prefix_sum.push_back(temp[j].first+prefix_sum.back());
                }
            }

            ans.push_back(sum);

        }else if(str == "DD"){
            // print(rod);
            // print(prefix_sum);
            int x; cin >> x;
            if(prefix_sum.size() == x){
                ans.push_back(prefix_sum.back());
                // cout << prefix_sum.back() << endl;
            } else{

                ans.push_back(prefix_sum.back() - prefix_sum[prefix_sum.size() - x - 1]);
            
            }

            

            // rod.resize(rod.size() - x);
            // prefix_sum.resize(prefix_sum.size() - x);
            
            
        }
    }
    print(ans);
}