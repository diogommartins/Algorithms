//
//  main.cpp
//  Fibonacci
//
//  Created by Diogo Magalhães Martins on 12/21/15.
//  Copyright © 2015 Diogo Magalhães Martins. All rights reserved.
//

#include <iostream>
#include <unordered_map>


u_int fibonacci_map(u_int n, std::unordered_map<u_int, u_int> &hash_map)
{
    if (n <= 2)
        return 1;               // 1. Recursion stop condition
    auto v = hash_map[n];
    if (v)                      // 2. Check if f(n) was already calculated
        return v;               // return if so
    else
    {
        v = fibonacci_map(n-1, hash_map) + fibonacci_map(n-2, hash_map);    // Same structure as the purely recursive solution
        hash_map[n] = v;        // Store the value when calculated
        return v;
    }
}

u_int fibonacci_dp_array(u_int n)
{
    u_int f[n+1];     // The aux scruture to store previous subproblems

    f[1] = 1;       // The first two numbers of the sequence are 1 and 1
    f[2] = 1;

    for (u_int i=3; i<=n; i++)
        f[i] = f[i-1] + f[i-2];

    return f[n];
}

u_int fibonacci_memory_efficient(u_int n)
{
    u_int i_minus_1 = 1;
    u_int i_minus_2 = 1;
    u_int fn = 0;

    for (u_int i=3; i<=n; i++)
    {
        fn = i_minus_1 + i_minus_2;
        i_minus_2 = i_minus_1;
        i_minus_1 = fn;
    }
    return fn;
}

int main(int argc, const char * argv[]) {
    std::unordered_map<u_int, u_int> hash_map;

    for (u_int i=3; i<10; i++)
    {
        std::cout << "map #" << i << ": " << fibonacci_map(i, hash_map) << '\n';
        std::cout << "array #" << i << ": " << fibonacci_dp_array(i) << '\n';
        std::cout << "memory efficient #" << i << ": " << fibonacci_memory_efficient(i) << '\n';
    }
    
    return 0;
}
