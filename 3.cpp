/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    for (int i = 2; i < n; i++){
        v.push_back(accumulate(v.begin() + i - 2, v.end(), 0));
    }
    
    for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++){
        cout << *iter << " ";
    }
    return 0;
}

