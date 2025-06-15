struct node
{
    int info;
    node *next;
    node(int x)
    {
        info = x;
        next = NULL;
    }
};

struct List
{
    node *head,*tail;
};

void Init(List &l)
{
    l.head = l.tail = NULL;
}

void addTail(List &l,int x)
{
    node *p = new node(x);
    if(!l.head)
    {
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
}

void inputList(List &l,int n)
{
    for(int i=0;i<n;i++)
    {
        int x; cin >> x;
        addTail(l,x);
    }
}

void outputList(List l)
{
    node *p = l.head;
    if(!p)
    {
        cout << "List is empty";
        return;
    }
    while(p)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

node* findElementFromEnd(List l,int i)
{
    int n;
    node *p = l.head;
    if(!p) 
    {
        cout << "List is empty";
        return NULL;
    }
    while(p)
    {
        n++;
        p = p->next;
    }
    int idx = n-i;
    p = l.head;
    while(p)
    {
        if(idx==0) return p;
        idx--;
        p = p->next;
    }
    cout << "The index is invalid";
    return NULL;
}