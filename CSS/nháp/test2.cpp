#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int e;
    map<string,map<string,int>> ke;
    unordered_map<string,int> names;
    vector<string> vt;
public:
    void nhap(int e)
    {
        this->e = e;
        for(int i=0;i<e;i++)
        {
            string x,y;
            int k;
            cin >> x >> y >> k;
            ke[x].insert({y,k});
        }
    }
    void xuly(int n)
    {
        while(n--)
        {
            
        }
        string s;
        while(cin >> s && s!=".")
        {
            vt.push_back(s);
        }
        if(*vt.begin() != *vt.rbegin()) 
        {
            cout << "FALSE";
            return;
        }
        for(auto it=vt.begin()+1;it!=vt.end();it++)
        {
            if(ke[*it].find(*it)) 
        }
    }
    
};

int main(){
    Graph G;
    int e,n; cin >> e>>n;
    G.nhap(e);
    G.xuly(n);
    return 0;
}