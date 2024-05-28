/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale (LC_ALL, "russian");
    int n;
    cout << "n = "; cin >> n;
    vector<int> vec;
    int ch;
    for (int i; i < n; i++){ //создание вектора
        cin >> ch;
        vec.push_back(ch);
    }
    int y = 0; //для замены
    int Min = *min_element(vec.begin(), vec.end());
    replace(vec.begin(), vec.end(), Min, y); //заменяем все минимумы на 0
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter << " ";
    }

    return 0;
}

