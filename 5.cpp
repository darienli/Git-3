#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct tree {
    int inf;
    tree* right;
    tree* left;
};

tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}
void create(tree*& tr, int n) {
    int x;
    if (n > 0) {
        cin >> x;
        tr = node(x);
        int nl = n / 2;
        int nr = n - nl - 1;
        create(tr-> left, nl);
        create(tr-> right, nr);
    }
}
void preorder(tree* tr) { //прямой обход (К_Л_П)
        if (tr) {
        cout << tr-> inf << " ";
        preorder(tr-> left);
        preorder(tr-> right);
    }

}

int height(tree* tr) {
    if (!tr)
        return -1;
    else {
        int left_height = height(tr->left);
        int right_height = height(tr->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void printLeaves(tree* tr, int& k) {
    if (tr) {
        if (!tr->left && !tr->right) { // Проверяем, является ли текущий узел листом
            k++; // Подсчитываем количество листьев
        }
        printLeaves(tr->left, k);
        printLeaves(tr->right, k);
    }
    
}


int main() {
    setlocale(LC_ALL, "Ru");
    tree* tr = NULL;
    int n, x;
    cin >> n;
    create(tr, n);
    preorder(tr); cout << endl;
    cout << "Высота дерева: " << height(tr) << endl;
    int amount = 0;
    cout << "Количество листьев: ";
    printLeaves(tr, amount);
    cout << amount;
    cout << endl;
    
    return 0;
}

