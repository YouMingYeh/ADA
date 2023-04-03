#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;



vi str;
int K;

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
// bool isStranger(vi a, vi b){

//     for(int i = 0; i < a.size(); i++){
//         if(a[i]!= b[i]){
//             return a[i] < b[i];
//         }
//     }
//     return false;
// }

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
    // for(int i = min_index; i > l; i--){
    //     int temp = a[i];
    //     a[i] = a[i-1];
    //     a[i-1] = temp;
    //     // swap(a[i],a[i-1]);
    // }
    // cout << min_index<<l << k << endl;
    k -= min_index - l;

    return Stranger(a, l+1, k);
    
}


//swap index
// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

signed main(){
    string s;
    cin >> s;
    for(int i = 0; i <  s.length(); i++){
        str.push_back(static_cast<int>(s[i]));
    }
    cin >> K;
    
    str = Stranger(str,0,K);

    for(int i = 0; i < str.size(); i++){
        cout << static_cast<char>(str[i]);
    }
}