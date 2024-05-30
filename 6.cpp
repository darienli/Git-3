#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<string.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

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

bool operator < (const people& a, const people& b) {//переопределяем оператор < в соотвествии с условием
    if (a.Surname < b.Surname) return true;
    if (a.Surname == b.Surname && a.timeofwork < b.timeofwork) return true;
    if (a.Surname == b.Surname && a.timeofwork == b.timeofwork && a.Salary < b.Salary) return true;
    return false;
}

void chet_nechet(vector<people>& x) {// сортировка
    for (int i = 0; i < x.size() - 1;i++){
        if (i % 2 == 0) {
            for (int j = 2; j < x.size() - 1; j += 2) {
                if (x[j] < x[j - 1])
                    swap(x[j], x[j - 1]);//поменяли
                
            }
        }
        else{
            for (int j = 1; j < x.size() - 1; j += 2) {
                if (x[j] < x[j - 1]) 
                    swap(x[j], x[j - 1]);//поменяли
                
            }
        }
    }    
}

int main() {
    vector<people> x;
     x = inFile();
    chet_nechet(x);
    for (int i = 0; i < x.size(); i++)
         print(x[i]);
    return 0;
}

