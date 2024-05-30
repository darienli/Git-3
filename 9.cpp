#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in("1.txt");
ofstream out("2.txt");

vector<vector<int>> create(int n){
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            in >> a[i][j];
    }
    return a;
}

void counting_sort(vector<int>& x){
    int min1 = x[0];
    int max1 = x[0];
    for (int i = 0; i < x.size(); ++i) {
        if (min1 > x[i]) min1 = x[i];
        if (max1 < x[i]) max1 = x[i];
    }
    int k = abs(min1 - max1) + 1;
    vector<vector<int>> a(k);
    for (int i = 0; i < x.size(); ++i) {
        a[x[i] - min1].push_back(x[i]);
    }
    x.clear();
    for (const auto& vec : a) x.insert(x.end(), vec.begin(), vec.end());
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    a = create(n);
    for (int i = 0; i < n; ++i)
        counting_sort(a[i]);
    for (int i = 0; i < n; ++i, out << endl){
        for (int j = 0; j < n; ++j)
            out << a[i][j] << " ";
    }
}
