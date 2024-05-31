#include<iostream>

using namespace std;

struct stack {
    char letter;
    stack* next;
};

void push(stack*& h, char x) {
    stack* r = new stack;
    r->letter = x;
    r->next = h;
    h = r;
}

char pop(stack*& h) {
    char i = h->letter;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) {
    stack* head1 = NULL;
    while (h)
        push(head1, pop(h));
    h = head1;
}

stack* result(stack*& h) {
    stack* res = NULL;
    stack* h1 = NULL;
    char lastVowel = ' ';
    while (h) {
        char x = pop(h);
        push(res, x);
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            lastVowel = x;
        while (h) {
            char y = pop(h);
            if (x != y)
                push(h1, y);
        }
        reverse(h1);
        h = h1;
        h1 = NULL;
    }
    if (lastVowel != ' ')
        push(res, '!');
    reverse(res);
    return res;
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    stack* head = NULL;
    char x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }
    reverse(head);
    stack* res = result(head);
    while (res)
        cout << pop(res) << " ";

    cout << endl;
    return 0;
}

