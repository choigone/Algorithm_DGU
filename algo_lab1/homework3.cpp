#include <iostream>
using namespace std;
typedef int itemType;

class Stack2
{
public:
    Stack2()
    {
        //initialize stack
        z = new node;
        head = new node;
        head->next = z;
    }

    ~Stack2()
    {
        delete head;
        delete z;
    }

    void push(itemType v)
    {
        struct node *ptr = new node;
        ptr->key = v;
        ptr->next = head->next;
        head->next = ptr;
    }

    itemType pop()
    {
        itemType data = head->next->key;
        head->next = head->next->next;
        return data;
    }

    int empty()
    {
        if(head->next == z){
            return 1;
        }
        else{
            return 0;
        }
    }

private:
    struct node
        { itemType key; struct node *next; };
    struct node *head, *z;
};

int main()
{
    char c; Stack2 acc; itemType x;
    itemType num1, num2;
    while((c = cin.get()) != '\n')
    {
        x = 0;
        while(c == ' ') cin.get(c);
        if(c == '+') x = acc.pop() + acc.pop();
        if(c == '-')
        {
            num2 = acc.pop();
            num1 = acc.pop();
            x = num1 - num2;
        }
        if(c == '*') x = acc.pop() * acc.pop();
        if(c == '/')
        {
            num2 = acc.pop();
            num1 = acc.pop();
            x = num1 / num2;
        }

        while (c >= '0' && c <= '9')
        { x = 10 * x + ( c - '0'); cin.get(c); }
        acc.push(x);
    }

    cout << acc.pop() << '\n';
    return 0;
}
