#include "choose.h"
#include "bits/stdc++.h"
/*
Feel free to use global variables.
However, if you want to write your code more "correctly",
you can search for the keyword "anonymous namespace", a helpful tool in C++.
*/

// this is an example usage
bool compare(const int & a, const int & b) {
    return compare_task(a, b) == 1;
}

void schedule(int N) {
    int endtime[3];
    std::vector<int> tasks(N);
    for(int i = 0; i < N; i++){
        tasks[i]=i+1;
    }
    std::sort(tasks.begin(), tasks.end(), compare);

    endtime[1] = 0;
    endtime[2] = 0;
    for(int i = 0; i < N; i++){
        if(endtime[1] <= endtime[2]){
            endtime[1] = assign_task(1,tasks[i]);
        }else{
            endtime[2] = assign_task(2,tasks[i]);
        }
    }
}


