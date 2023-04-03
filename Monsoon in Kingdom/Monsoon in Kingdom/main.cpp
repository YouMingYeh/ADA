// merge sort credit to https://www.geeksforgeeks.org/counting-inversions/
// 資管系顧寬証同學提供inversion counting想法

#include <functional>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <map>

using vd = std::vector<double>;
using pii = std::pair<int,int>;
std::pair<double,double> range;
#define int long long
int l_1, l_2, r_1,r_2;
int n = 0;
//bool in_range(double slo);
//
//double sloper(std::pair<double,double>,std::pair<double,double>);
bool compare_1(std::pair<int, int> l,std::pair<int,int> r)
{
    int deltaX = r.first- l.first;
    int deltaY = r.second - l.second;
    
//    if(done.find(static_cast<double>(deltaY)/static_cast<double>(deltaX)) != done.end())
//        return done[static_cast<double>(deltaY)/static_cast<double>(deltaX)];
    
    
    return r_1*deltaX >= r_2*deltaY;
    
//    done[static_cast<double>(deltaY)/static_cast<double>(deltaX)] = true;
    
//    r_2 * deltaY > r_1 * deltaX
    
}
bool compare_2(std::pair<int, int> l,std::pair<int,int> r)
{
    int deltaX = r.first- l.first;
    int deltaY = r.second - l.second;
    
//    if(done.find(static_cast<double>(deltaY)/static_cast<double>(deltaX)) != done.end())
//        return done[static_cast<double>(deltaY)/static_cast<double>(deltaX)];
    
    
    return l_1*deltaX <= l_2*deltaY;
    
    
//    done[static_cast<double>(deltaY)/static_cast<double>(deltaX)] = true;
    
//    r_2 * deltaY > r_1 * deltaX
    
    
    
    

    
}
using namespace std;

int _mergeSort(std::vector<std::pair<int,int>>& arr, std::vector<std::pair<int,int>>& temp, int left, int right, function<int(pii, pii)>);
int merge(std::vector<std::pair<int,int>>& arr, std::vector<std::pair<int,int>>& temp, int left, int mid,
        int right, function<int(pii, pii)>);


int mergeSort(std::vector<std::pair<int,int>>& arr, int array_size, function<int(pii, pii)> f)
{
    std::vector<std::pair<int,int>> temp(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1, f);
}

int _mergeSort(std::vector<std::pair<int,int>>& arr, std::vector<std::pair<int,int>>& temp, int left, int right,function<int(pii, pii)> f)
{
    int mid, inv_count = 0;
    if (right > left) {
        
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid, f);
        inv_count += _mergeSort(arr, temp, mid + 1, right, f);

        inv_count += merge(arr, temp, left, mid + 1, right, f);
    }
    return inv_count;
}

int merge(std::vector<std::pair<int,int>>& arr, std::vector<std::pair<int,int>>& temp, int left, int mid,
        int right, function<int(pii, pii)> f)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (f(arr[i],arr[j])) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }


    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];


    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    
//    for(auto v:temp)
//    {
//        std::cout << "(" <<v.first << ","<<v.second<< ")"<< " ";
//    }
//    std::cout << std::endl;
    return inv_count;
}



//int sort_and_count_1(std::vector<std::pair<int,int>> a, int l, int r) {
//  if (l == r) {
//    return 0;
//  } else {
//    int mid = (l+r)/2;
//    int first = sort_and_count_1(a, l, mid);
//    int second = sort_and_count_1(a, mid+1, r);
//
//    int i=l;
//    int j=mid+1;
//    int k=0;
//    std::vector<std::pair<int,int>> output(r-l+1);
//    int inversion=0;
//
//    while (i <= mid && j <= r) {
//       if (compare_1(a[i], a[j])) {
//
//         output[k++] = a[i++];
//       } else {
//         output[k++] = a[j++];
//         inversion += (mid-i)+1;
//       }
//    }
//    while (i <= mid) {
//       output[k++] = a[i++];
//    }
//    while (j <= r) {
//       output[k++] = a[j++];
//    }
//
//    k=0;
//    for (int i = l; i <= r; i++) {
//      a[i] = output[k++];
//    }
//      for(int index = 0; index < r-l+1;index ++)
//      {
//          std::cout << output[index].first<<output[index].second << " ";
//      }
//      std::cout << std::endl;
//    return inversion + first + second;
//  }
//}
//
//int sort_and_count_2(std::vector<std::pair<int,int>> a, int l, int r) {
//  if (l == r) {
//    return 0;
//  } else {
//    int mid = (l+r)/2;
//    int first = sort_and_count_2(a, l, mid);
//    int second = sort_and_count_2(a, mid+1, r);
//
//    int i=l;
//    int j=mid+1;
//    int k=0;
//    std::vector<std::pair<int,int>> output(r-l+1);
//    int inversion=0;
//
//    while (i <= mid && j <= r) {
//       if (compare_2(a[i], a[j])) {
//         output[k++] = a[i++];
//       } else {
//         output[k++] = a[j++];
//         inversion += (mid-i)+1;
//       }
//    }
//    while (i <= mid) {
//       output[k++] = a[i++];
//    }
//    while (j <= r) {
//       output[k++] = a[j++];
//    }
//
//    k=0;
//    for (int i = l; i <= r; i++) {
//      a[i] = output[k++];
//    }
////      for(int index = 0; index < r-l+1;index ++)
////      {
////          std::cout << output[index].first<<output[index].second << " ";
////      }
////      std::cout << std::endl;
//
//    return inversion + first + second;
//  }
//}

signed main()
{
    std::cin >> n>>l_1>>l_2>>r_1>>r_2;

    
    std::vector<std::pair<int,int>> pos(n);
    for(auto &v: pos)
    {
        std::cin>> v.first >> v.second;
    }
    std::sort(pos.begin(),pos.end());
    
//    for(auto &v: pos)
//    {
//        std::cout<< v.first << " "<<v.second << std::endl;
//    }
    
    
    
//    std::cout << n*(n-1)/2-sort_and_count(pos, 0, n);
//    std::cout <<sort_and_count_1(pos, 0, n-1) << " " <<sort_and_count_2(pos, 0, n-1) << std::endl;
    int inv = 0;
    inv += mergeSort(pos, n, compare_1);
    std::sort(pos.begin(),pos.end());
    inv += mergeSort(pos, n, compare_2);
    std::cout << n*(n-1)/2-inv;
}






//double sloper(std::pair<double,double> l, std::pair<double,double> r)
//{
//    if(r.first == l.first) return 0;
//    if(r.second == l.second) return 999999999;
//    return (r.first - l.first)/(r.second - l.second);
//}
//
//bool in_range(double slo)
//{
//    if(slo >= range.first && slo <= range.second)
//    {
//        return true;
//    }
//
//    else return false;
//}
