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

void shell_step_3_nch(vector<int>& x, int n, int k){ //для четных строк (вводим вектор, размер, максимальный шаг)
    int step = pow(3, k), d = n;
    while (step >= 1){
        for (int i = 0; i < d - step;i++) {
            int j = i;
            while (j >= 0 and x[j] > x[j + step]) {
                swap(x[j], x[j + step]);
                j--;
            }
        }
        k -= 1;
        step = pow(3,k);
    }
}

void shell_step_3_ch(vector<int>& x, int n, int k){ //для четных строк (вводим вектор, размер, максимальный шаг)
    int step = pow(3, k), d = n;
    while (step >= 1){
        for (int i = 0; i < d - step;i++) {
            int j = i;
            while (j >= 0 and x[j] < x[j + step]) {
                swap(x[j], x[j + step]);
                j--;
            }
        }
        k -= 1;
        step = pow(3,k);
    }
}



int main (){
    int n; cin >> n;
    vector <vector<int>> a(n, vector<int> (n));
    a = create(n);
    //определим максимальный шаг для Шелла с шагом 3 в степени i
    int k = 0;
    while (pow(3, k) < n) {
        k += 1;

    }
    k -= 1;
    
    for(int i = 0; i < n; i++){
        if (i % 2 == 0) shell_step_3_ch(a[i], n, k);
        else shell_step_3_nch(a[i], n, k);
    }
    for (int i = 0; i < n; ++i, out << endl){
        for (int j = 0; j < n; ++j)
            out << a[i][j] << " ";
    }
    
}