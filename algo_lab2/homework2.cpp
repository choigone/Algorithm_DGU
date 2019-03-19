#include <iostream>

using namespace std;

struct treeNode{ char info; struct treeNode *l, *r; };

typedef treeNode* itemType;

// 트리를 만들어줄 스택
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

// 결과를 저장하여 출력할 큐
class Queue{
public:
    Queue(int max =100){
        queue = new itemType[max];
        tail = 0;
        head = 0;
        size = max;
    }
    void put(itemType v){
        queue[tail++] = v;
        if(tail > size) tail = 0;
    }
    itemType get(){
        itemType t = queue[head++];
        if(head > size) head = 0;
        return t;
    }
    int empty(){ return head == tail; }
private:
    itemType *queue;
    int head;
    int tail;
    int size;
};

struct treeNode *x, *z;
void visit(struct treeNode *t);
void traverse(struct treeNode *t);
Queue queue;

int main(){
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
}

void visit(struct treeNode *t){
    cout << t->info << " ";
}

void traverse(treeNode *t){
    queue.put(t);
    while(!queue.empty()){
        t = queue.get(); visit(t);
        if(t->l != z) queue.put(t->l);
        if(t->r != z) queue.put(t->r);
    }
}