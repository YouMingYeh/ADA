#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

string str;
int K;
string ans;



void printVector(vi v)
{
    for (auto &w : v)
    {
        cout << w << endl;
    }
}
void printMap(map<char, vector<int> > M){
    for (auto &w : M)
    {
        cout << w.first << " ";
        printVector(w.second);
        cout << endl;
    }
}



int findMin(vi& a,int l, int k){
    if( k <= 0 || l >= a.size()-1) return -1;
    
    int MIN = INT64_MAX;
    int min_index = -1;
    
    for(int i = l; i < min( l+k+1 , static_cast<int>(a.size())); i++){
        if(a[i] < MIN){ 
            MIN = a[i];
            min_index = i;
        }
    }

    return min_index;
}

vi Stranger(vi& a, int l, int k){
    if( k <= 0 || l >= a.size()-1) return a;
    
    int min_index = findMin(a, l, k);
    while(min_index == -1 || min_index == l){
        l++;
        min_index = findMin(a, l, k);
        // cout << min_index <<l << k<< endl;
        if(l >= a.size()-1) return a;
    }

    if(min_index < 0 || min_index >= a.size() || l >= a.size()) return a;

    a.insert(a.begin()+l,a[min_index]);
    a.erase(a.begin()+min_index+1);
    k -= min_index - l;
    return Stranger(a, l+1, k);
    
}


void solve(){
    
    vector<int> s;
    for(int i = 0; i <  str.length(); i++){
        s.push_back(static_cast<int>(str[i]));
    }
    
    
    s = Stranger(s,0,K);

    for(int i = 0; i < s.size(); i++){
        cout << static_cast<char>(s[i]);
    }
}

signed main()
{
    cin >> str;
    cin >> K;
    
    // solve();
    
    // // solve2();
    vector<int> move(str.length(), 0);
    // map<char,vi> pos;
    map<char, vi> M;
    vi temp(0);
    M['0'] = temp;
    M['1'] = temp;
    M['2'] = temp;
    M['3'] = temp;
    M['4'] = temp;
    M['5'] = temp;
    M['6'] = temp;
    M['7'] = temp;
    M['8'] = temp;
    M['9'] = temp;
    M['A'] = temp;
    M['B'] = temp;
    M['C'] = temp;
    M['D'] = temp;
    M['E'] = temp;
    M['F'] = temp;
    M['G'] = temp;
    M['H'] = temp;
    M['I'] = temp;
    M['J'] = temp;
    M['K'] = temp;
    M['L'] = temp;
    M['M'] = temp;
    M['N'] = temp;
    M['O'] = temp;
    M['P'] = temp;
    M['Q'] = temp;
    M['R'] = temp;
    M['S'] = temp;
    M['T'] = temp;
    M['U'] = temp;
    M['V'] = temp;
    M['W'] = temp;
    M['X'] = temp;
    M['Y'] = temp;
    M['Z'] = temp;
    M['a'] = temp;
    M['b'] = temp;
    M['c'] = temp;
    M['d'] = temp;
    M['e'] = temp;
    M['f'] = temp;
    M['g'] = temp;
    M['h'] = temp;
    M['i'] = temp;
    M['j'] = temp;
    M['k'] = temp;
    M['l'] = temp;
    M['m'] = temp;
    M['n'] = temp;
    M['o'] = temp;
    M['p'] = temp;
    M['q'] = temp;
    M['r'] = temp;
    M['s'] = temp;
    M['t'] = temp;
    M['u'] = temp;
    M['v'] = temp;
    M['w'] = temp;
    M['x'] = temp;
    M['y'] = temp;
    M['z'] = temp;

    for (int i = 0; i < str.length(); i++)
    {
        M[str[i]].push_back(i);
    }
    for (int i = 0; i < str.length(); i++)
    {
        for(auto &v:M){
            if(v.first > str[i]){
                for(auto &idx: v.second){
                    if(i > idx)
                    {
                        move[i]++;
                    }
                }
            }
        }
    }

    // printVector(move);
    
    map<char, vi> A;


    
    for (int i = 0; i < str.length(); i++)
    {
        A[str[i]].push_back(move[i]);
    }

    // printMap(M);
    char last = '0';
    map<char, int> I;
    for(auto &v:A){
        for(int i = 0; i < v.second.size();i++){
            if(K >= v.second[i] && v.second[i] > 0){
                K -= v.second[i];
                v.second[i] = 0;
                // ans += v.first;
                cout << v.first;
                // pos[v.first].erase(pos[v.first].begin());
                if(I.find(v.first) != I.end())
                    I[v.first]++;
                else
                    I[v.first] = 1;
            }
        }
    }
   
    if(K > 0){
        
        string newStr;
            for(int i = 0; i < str.length(); i++){
                if(I[str[i]] > 0){
                    I[str[i]]--;
                }
                else{
                    newStr+=str[i];
                }   
            }
            str = newStr;
            solve();
    }
    else{
        string newStr;
            for(int i = 0; i < str.length(); i++){
                if(I[str[i]] > 0){
                    I[str[i]]--;
                }
                else{
                    newStr+=str[i];
                }   
            }
            str = newStr;
            cout << str;
    }
    
}





