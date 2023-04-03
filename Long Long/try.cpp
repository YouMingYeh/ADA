#include <bits/stdc++.h>
#include <iostream>
#include "ypglpk.hpp"

int N, M;
std::vector<std::tuple<int,int,int> >  edges;

int main() {
    
    std::cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        edges.emplace_back(a-1,b-1,c);
    }
    // ypglpk::set_output(true);

\

    // N 個 u存DFS number=> 1,2,3,...
    // M 個 邊存要不要選這個邊=> 0, 1
    
    // Condition 1: cycle
    // M(i,j) i.e. From i to j => 1u_i - 1u_j * 10000*M(i,j) <= 9999

    // Condition 2: in = out
    // for all i , in M(x,i) - out M(i, x)= 0 except for S, T
    // in M(x,S) - out M(S, x)= -1
    // in M(x,T) - out M(T, x)= 1

    // Condition 3: 
    // for all i M(i, x), sum 1*M(i,x) = 1; except for that of T is 0.

    // maximize: 
    // sum of weight of all edges: sum weight*M(i,j)





    std::vector<double> Objective_Function(N + M);
    for(int i = 0; i < N; ++i) {
        Objective_Function[i] = 0;
    }
    for(int i = 0;i < M;i++) {
        auto [a,b,c] = edges[i];
        Objective_Function[N + i] = c;
    }
    // for(int i = 0; i <N+ M; i++){
    //     std::cout << Objective_Function[i] <<" ";
    // }
    // std::cout << std::endl;

    std::vector<std::vector<double>> Constraint(M+3*N, std::vector<double>(N+M));
    std::vector<double> Inequality(M+3*N);
    //condition 1
    for(int i = 0;i < M; i++){
        auto [a,b,c] = edges[i];
        for(int j = 0; j < N; j++){
            if(j == a){
                Constraint[i][j] = 1; 
            }
            else if(j == b){
                Constraint[i][j] = -1;
            }
            else{
                Constraint[i][j] = 0;
            }
        }
        for(int j = 0; j < M; j++){
            Constraint[i][N+j] = 0;
        }
        Constraint[i][N+i] = 10000;
        Inequality[i] = 9999;
    }

    // condition 2
    for(int i = M;i < M+N; i++){
        for(int j = 0; j < N+M; j++){
            Constraint[i][j] = 0;
        }
        for(int j = 0; j < M ;j ++){
            auto [a,b,c] = edges[j];

            if(a == i-M){ //0 to N
                Constraint[i][N+j] = -1;
            }
            else if(b == i-M){ //0 to N
                Constraint[i][N+j] = 1;
            }
        }
        Inequality[i] = 0;
    }
    Inequality[M] = -1;
    Inequality[M+N-1] = 1;

    for(int i = M+N;i < M+2*N; i++){
        for(int j = 0; j < N+M; j++){
            Constraint[i][j] = 0;
        }
        for(int j = 0; j < M ;j ++){
            auto [a,b,c] = edges[j];

            if(a == i-(M+N)){ //0 to N
                Constraint[i][N+j] = 1;
            }
            else if(b == i-(M+N)){ //0 to N
                Constraint[i][N+j] = -1;
            }
        }
        Inequality[i] = 0;
        
    }
    Inequality[M+N] = 1;
    Inequality[M+2*N-1] = -1;

    //condition 3
    for(int i = M+2*N; i < M+3*N; i++){
        for(int j = 0; j < N+M; j++){
            Constraint[i][j] = 0;
        }
        for(int j = 0; j < M ;j ++){
            auto [a,b,c] = edges[j];

            if(a == i-(M+2*N)){ //0 to N
                Constraint[i][N+j] = 1;
            }
        }
        Inequality[i] = 1;
    }
    Inequality[M+3*N-1] = 0;
    

    for(int i = 0; i < M+3*N; i++){
        for(int j = 0; j < N+M; j++){
            std::cout << Constraint[i][j] << " + ";
        }
        std::cout <<" <= "<< Inequality[i];
        std::cout << std::endl;
    }
    
    // int n = 3, m = 4;
    
    // std::vector<double> Inequity(m), Objective_Function(n);
    // Objective_Function[0] = 1; Objective_Function[1] = 2; Objective_Function[2] = -2.5;
    // Constraint[0][0] = 3; Constraint[0][1] = 2; Constraint[0][2] = 1;     Inequity[0] = 9.9;
    // Constraint[1][0] = -1; Constraint[1][2] = 1;                 Inequity[1] = 8.24; 
    // Constraint[2][1] = 1.5; Constraint[2][2] = -1;               Inequity[2] = 4.3;
    // Constraint[3][0] = 1; Constraint[3][1] = -1.3; Constraint[3][2] = -1; Inequity[3] = 5.3;
    
    std::pair<double, std::vector<double>> res;
    // res = ypglpk::linear_programming(Constraint, Inequity, Objective_Function);
    // std::cout << "\033[1;36m"
    //     << "LP: max=" << res.first;
    // if (res.first == -ypglpk::INF) {
    //     std::cout << " INFEASIBLE OR UNBOUNDED";
    // } else {
    //     std::cout << " with"
    //         << " x=" << res.second[0] << " y=" << res.second[1]
    //         << " z=" << res.second[2];
    // }
    // std::cout << "\033[0m\n";

    std::vector<int> vartype(N+M, GLP_BV);
    for(int i=0; i<N; i++){
        vartype[i] = GLP_CV;
    }
    // vartype[0] = GLP_CV;
    // vartype[1] = GLP_IV;
    // vartype[2] = GLP_IV; // y,z should be integers
    res = ypglpk::mixed_integer_linear_programming(Constraint, Inequality, Objective_Function, vartype);

    
    long long max = (long long)res.first;
    if (res.first == -ypglpk::INF) {
        std::cout << -1;
        return 0;
    }
    std::cout << max << std::endl;
    for(int i = 0; i < M; i++){
        std::cout << res.second[N+i];
    }
    
    // } else {
    //     std::cout << " with"
    //         << " x=" << res.second[0] << " y=" << res.second[1]
    //         << " z=" << res.second[2];
    // }
   
}