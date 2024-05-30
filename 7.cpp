#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in("1.txt");
ofstream out("2.txt");

struct date {
    int dd, mm, yy;

};
struct people {
    string Surname;
    string Post;
    date DateOfBirth;
    int timeofwork;
    int Salary;
};
date Str_to_Date(string str) {
    date x;
    string temp = str.substr(0, 2);
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile() {
    vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname;
        in >> temp.Post;
        string tmp;
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.timeofwork;
        in >> temp.Salary;
        x.push_back(temp);
    }
    return x;
}


void print(people x) {
    out << setw(20) << left << x.Surname;
    out << setw(20) << left << x.Post;
    if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';
    else out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
    else out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;
    out << left << setw(10) << x.timeofwork;
    out << left << setw(10) << x.Salary << endl;
}

bool operator < (const people& a, const people& b) {
    return a.Salary < b.Salary;
}

bool operator > (people& a, people& b) {
    if (a.Salary > b.Salary) return true;
    if (a.Salary == b.Salary && a.Surname > b.Surname) return true;

    return false;
}


void sort(vector<people>& x, int n) {
    int d = n;
    int  step = d / 3;
    while (step > 1) {
        for (int i = 0; i < d - step;i++) {
            int j = i;
            while (j >= 0 and x[j] > x[j + step]) {
                swap(x[j], x[j + step]);
                j--;
            }
        }
        step = step / 3;
    }
}


int main() {
    vector<people> x;
    x = inFile();
    sort(x, x.size());
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;

}