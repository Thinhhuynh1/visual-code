/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct List
{
    node *head, *tail;
};

void Init(List &l)
{
    l.head = l.tail = NULL;
}

void addTail(List &l,int x)
{
    node *p= new node(x);
    if(!l.head) 
    {
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
}

void addHead(List &l,int x)
{
    node *p = new node(x);
    if(!l.head)
    {
        l.head = l.tail = p;
        return;
    }
    p->next = l.head;
    l.head = p;
}

void addAfter(List &l, int a, int x)
{
    node *p = l.head;
    node *q = new node(x);
    if(!l.head)
    {
        l.head = l.tail = q;
        return;
    }
    while(p)
    {
        if(p->data == a)
        {
            if(l.head == p)
            {
                addHead(l,x);
                return;
            }
            else if(l.tail == p)
            {
                addTail(l,x);
                return;
            }
            q->next = p->next;
            p->next = q;
            return;
        }
        p = p->next;
    }
    addHead(l,x);
}


void deleHead(List &l)
{
    node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    delete p;
}

void deleTail(List &l)
{
    node *p = l.head;
    while(p->next)
    {
        p = p->next;
    }
    l.tail = p;
    p = p->next;
    l.tail->next = NULL;
    delete p;
}

void deleNode1(List &l,int x)
{
    if(!l.head)
    {
        return;
    }
    node *p = l.head;
    node *parent = NULL;
    while(p)
    {
        if(p->data == x)
        {
            if(l.head == p)
            {
                deleHead(l);
                return;
            }
            else if(l.tail == p)
            {
                deleTail(l);
                return;
            }
            parent->next = p->next;
            p->next = NULL;
            delete p;
            return;

        }
        parent = p;
        p = p->next;
    }
}

void deleNodeN(List &l,int x)
{
    if(!l.head) return;
    node *p = l.head;
    node *parent = NULL;
    while(p)
    {
        if(p->data == x)
        {
            if(l.head == p)
            {
                deleHead(l);

            }
            else if(l.tail == p)
            {
                deleTail(l);
                return;
            }
            parent->next = p->next;
            p->next = NULL;
        }
        parent = p;
        p = p->next;
    }
}

void outputList(List l)
{
    if(!l.head)
    {
        cout << "blank";
        return;
    }
    node *p = l.head;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    List l;
    Init(l);
    int tmp;
    while(cin >> tmp)
    {
        if(tmp == 6)
        {
            break;
        }
        if(tmp==0)
        {
            int x; cin >> x;
            addHead(l,x);
        }
        else if(tmp == 1)
        {
            int x ; cin >> x;
            addTail(l,x);
        }
        else if(tmp == 2)
        {
            int a,b; cin >> a >> b;
            addAfter(l,a,b);
        }
        else if(tmp == 3)
        {
            int x; cin >> x;
            deleNode1(l,x);
        }
        else if(tmp == 4)
        {
            int x; cin >> x;
            deleNodeN(l,x);
        }
        else if(tmp == 5)
        {
            deleHead(l);
        }
    }

    outputList(l);
}