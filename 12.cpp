#include <iostream>
using namespace std;

struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, char x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

char pop(stack*& h) {
	char i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack *&h){
    stack *r = NULL;
    char x;
    while (h){
        x = pop(h);
        push(r, x);
    }
    h = r;
}

stack* result(stack *&h){
    stack *res = NULL;
    int fl = 0;
    while(h){
        char x = pop(h);
        if (x == 'e' || x == 'y' || x == 'u' || x == 'i' || x == 'o' || x == 'a'){
            if (fl == 1){
                push(res, x);
            }
            else{
                push(res, '!');
                push(res, x);
                fl = 1;
            }
        }
        else{
            push(res, x);
        }
    }
    //reverse(res);
    return res;
}

int main(){
    int n; cout<<"n = "; cin >> n;
    char x;
    stack *h = NULL;
    for (int i = 0; i < n; i++){
        cin >> x;
        push (h, x);
    }
    stack* res = result(h);
    while (res){
        cout << pop(res) << " ";
    }
}




