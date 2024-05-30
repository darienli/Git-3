#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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

void chet_nechet(vector<int>& x) {
    for (int i = 0; i < x.size(); i++) {
        if (i % 2 == 0) {
            for (int j = 2; j < x.size(); j += 2) {
                if (x[j] < x[j - 1]) swap(x[j], x[j - 1]);//поменяли
            }
        }
        else {
            for (int j = 1; j < x.size(); j += 2) {
                if (x[j] < x[j - 1]) swap(x[j], x[j - 1]);//поменяли
            }
        }
    }
}

void sortDiagonals(vector<vector<int>>& a, int N) {
    for (int k = 0; k < N - 1; ++k) {
        vector<int> diagonalElements;
        for (int i = 0; i < N; ++i) { //добавляет диагональ выше главной в вектор
            if (k + i < N) {
                diagonalElements.push_back(a[i][k + i]);
            }
        }
        chet_nechet(diagonalElements); //сортировка диагонали
        int L = 0;
        for (int i = 0; i < N; ++i) {  //переприсваивание отсортированой диагонали
            if (k + i < N) {
                a[i][k + i] = diagonalElements[L];
                ++L;
            }
        }
        diagonalElements.clear(); //удаляет отсортированную диагональ

        for (int j = 0; j < N; ++j) {
            if (k + j < N) {
                diagonalElements.push_back(a[k + j][j]);
            }
        }
        chet_nechet(diagonalElements);
        L = 0;
        for (int j = 0; j < N; ++j) {
            if (k + j < N) {
                a[k + j][j] = diagonalElements[L];
                ++L;
            }
        }
        diagonalElements.clear();
    }
}

int main() {
    int N;
    cout << "Enter the size of the square matrix: ";
    cin >> N;

    vector <vector<int>> a(N, vector<int> (N));
    a = create(N);
    sortDiagonals(a, N);

    cout << "Sorted matrix:" << std::endl;
    for (int i = 0; i < N; ++i, out << endl){
        for (int j = 0; j < N; ++j)
            out << a[i][j] << " ";
    }

    return 0;
}

