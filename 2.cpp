/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool chet(int x) {
    return x % 2 != 0;
}

int X;
bool kratn(int x) {
    if (X != 0) { return x % X == 0; }
    else return 0;
}


int main()
{
    int n; cin >> n;
    vector<int>vec1;
    vector<int>vec2;
    int ch;
    cout << "First one: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        vec1.push_back(ch);
    }
    cout << "Second one: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        vec2.push_back(ch);
    }


    cout << endl;

    vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), chet);
    vec1.erase(it, vec1.end());

    vector<int> temp(vec2);
    int Max = *max_element(temp.begin(), temp.end());
    cout << "X = "; cin >> X; //здесь не нужно описывать переменную Х, так как мы описали ее в самом начале программы
    replace_if(temp.begin(), temp.end(), kratn, 0); //нули в любом случае кратны любому числу
    replace(temp.begin(), temp.end(), 0, Max);

    cout << "1 answer"<<endl;
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "2 answer" << endl;
    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    sort(vec1.begin(), vec1.end());
    sort(temp.begin(), temp.end());

    cout << "3 answer" << endl;
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "4 answer" << endl;
    vector<int> v(vec1.size() + temp.size());
    merge(vec1.begin(), vec1.end(), temp.begin(), temp.end(), v.begin());
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "5 answer" << endl;
    int g; cout << "G = "; cin >> g;
    vector<int>vec3;
    vec3.push_back(g);
    vector<int>v2(v.size() + vec3.size());
    merge(v.begin(), v.end(), vec3.begin(), vec3.end(), v2.begin());
    for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}




