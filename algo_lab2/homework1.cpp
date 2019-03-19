#include <iostream>

using namespace std;

struct treeNode{ char info; struct treeNode *l, *r; };

typedef treeNode* itemType;

struct treeNode *x, *z;
void visit(struct treeNode *t);
void traverse(struct treeNode *t);

class Stack
{
public:
    Stack(int max = 100){ stack = new itemType[max]; p = 0;};
    ~Stack(){ delete stack;}
    inline void push(itemType v){ stack[p++] = v; }
    inline itemType pop(){ return stack[--p]; }
    inline int empty(){ return !p; }
private:
    itemType *stack;
    int p;
};

int main() {
    char c; Stack stack(50);
    z = new treeNode; z->l = z; z->r = z;

    while((c = cin.get())!='\n'){
        while(c == ' ') cin.get(c);
        x = new treeNode;
        x->info = c; x->l = z; x->r = z;
        if(c=='+' || c=='*' || c=='-'){ x->r = stack.pop(); x->l = stack.pop(); }
        stack.push(x);
    }
    traverse(stack.pop());
    cout << endl;

    return 0;
}

void visit(struct treeNode *t){
    cout << t->info << " ";
}

void traverse(struct treeNode *t){
    if(t != z){
        traverse(t->l);
        visit(t);
        traverse(t->r);
    }
}