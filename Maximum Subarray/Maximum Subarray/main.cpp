//
//  main.cpp
//  Maximum Subarray
//
//  Created by 葉又銘 on 2022/9/12.
//

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int gay = 0;
    std::cin >> gay;
    std::vector<long long int> arr(gay);
    
    
    for(auto &v:arr)
    {
        std::cin >> v;
        
    }
    
    long long int curr_sum = 0;
    long long int max = LONG_LONG_MIN;
    for(int i = 0; i < gay; i++)
    {
        curr_sum += arr[i];
        max = std::max(curr_sum, max);
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
        
            
        
    }
    std::cout << max;
    
}
