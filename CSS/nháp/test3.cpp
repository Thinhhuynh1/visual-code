#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)a;i>=(int)b;i--)

#define ll long long
#define db double

#define pi M_PI
#define MAX 1000

void dichmangtrc(char *s,int k,int &n){
    s[k-1]=s[k];
    s[k]= s[k+1];
    n--;
}


int main(){
    char s1[MAX];
    cin.getline(s1,1000);

    int n=strlen(s1);
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='.'){
            while(s1[i-1] == ' '){
                dichmangtrc(s1,i,n);
            }

        }
    }
    cout << n << endl;
    cout << s1;

}