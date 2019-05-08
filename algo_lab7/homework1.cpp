#include <iostream>
#include <vector>

#define infoNIL 0
#define itemMIN -1
#define black 0
#define red 1

typedef int itemType;
typedef int infoType;

using namespace std;

class BST{
private:
    struct node{
        itemType key; infoType info;
        struct node *l, *r;
        node(itemType k, infoType i, struct node *ll, struct node *rr)
        { key = k; info = i; l = ll; r = rr; };
    };
    struct node *head, *z;
public:
    itemType *result;
    int index;
    BST(int max){
        z = new node(0,infoNIL,0,0);
        head = new node(itemMIN,infoNIL,z,z);
        result = new itemType[max];
        index = 0;
    }
    ~BST(){};
    infoType BSTsearch(itemType v);
    void BSTinsert(itemType v, infoType info);
    void BSTdelete(itemType v);
    void inorderTraverse(node *node1);
    void visit(node *node1);
    node* getHead(){
        return head;
    }
};

infoType BST::BSTsearch(itemType v) {
    struct node *x = head->r;
    z->key = v;
    while(v != x->key) x = (v < x->key) ? x->l:x->r;
    return x->info;
}

void BST::BSTinsert(itemType v, infoType info) {
    struct node *p, *x;
    p = head; x = head->r;
    while(x!=z){
        p = x;
        x = (v<x->key) ? x->l : x->r;
        info++;
    }
    x = new node(v,info,z,z);
    x->info++;
    if(v<p->key) p->l = x; else p->r = x;
}

void BST::inorderTraverse(node *node1) {
    if(node1 != z){
        inorderTraverse(node1->l);
        visit(node1);
        inorderTraverse(node1->r);
    }
}

void BST::visit(node *node1) {
    result[index] = node1->key;
    index++;
}

struct node {
    itemType key, tag;
    infoType Info;
    struct node *l, *r;

    node(itemType k, infoType i, itemType t, struct node *ll, struct node *rr) {
        key = k;
        Info = i;
        tag = t;
        l = ll;
        r = rr;
    }
};

struct node *head, *tail, *x, *p, *g, *gg, *z;

void RBtree(int max) {
    z = new node(0, infoNIL, black, 0, 0);
    z->l = z;
    z->r = z;
    head = new node(itemMIN, infoNIL, black, z, z);
}

struct node *rotate(itemType k, struct node *y) {
    struct node *high, *low;
    high = (k < y->key) ? y->l : y->r;
    if (k < high->key) {
        low = high->l;
        high->l = low->r;
        low->r = high;
    }
    else {
        low = high->r;
        high->r = low->l;
        low->l = high;
    }
    if (k < y->key) y->l = low; else y->r = low;
    return low;
}

void split(itemType k) {
    x->tag = red;
    x->l->tag = black;
    x->r->tag = black;
    if (p->tag) {
        g->tag = red;
        if (k < g->key != k < p->key) p = rotate(k, g);
        x = rotate(k, gg);
        x->tag = black;
    }
}

void insert(itemType k, infoType info) {
    x = head;
    p = head;
    g = head;
    while (x != z) {
        gg = g;
        g = p;
        p = x;
        x = (k < x->key) ? x->l : x->r;
        if (x->l->tag && x->r->tag) split(k);
    }
    x = new node(k, info, red, z, z);
    if (k < p->key) p->l = x; else p->r = x;
    split(k);
    head->r->tag = black;
}

infoType search(itemType k) {
    struct node *x = T->r;

    int count = 0;

    while (k != x->key)  {
        x = (k < x->key) ? x->l : x->r;
        count++;
    }

    x->info = count;
    return x->info;
}


int main() {
    int size;
    cin >> size;
    int *a = new int[size];

    srand((unsigned) time(NULL));
    vector<pair<int, int>> v;
    for (int i = 0; i < size; i++) {
        v.push_back(pair<int, int>(rand() % size + 1, i + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < size; i++) a[i] = v[i].second;

    BST T1 = BST(size);
    for(int i=0;i<size;i++) T1.BSTinsert(a[i],infoNIL);
    T1.inorderTraverse(T1.getHead()->r);

    BST T2 = BST(size);
    for(int i=0;i<size;i++) T2.BSTinsert(T1.result[i],0);




    return 0;
}
