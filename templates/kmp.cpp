#include<bits/stdc++.h>
using namespace std;
void kmp(string a,string b)
{
    int l=a.size(),m=b.size();
    cout<<l<<' '<<m<<'\n';
    vector<int>nxt(l+5);
    vector<int>f(l+5);
    for(int i=2,j=0;i<=l;i++)
    {
        while(j>0&&(a[i-1]!=a[j]))j=nxt[j];
        if(a[i-1]==a[j])j++;
        nxt[i]=j;
    }
    for(int i=2,j=0;i<=m;i++)
    {
        while(j>0&&(j==l||b[i-1]!=a[j]))j=nxt[j];
        if(b[i-1]==a[j])j++;
        f[i]=j;
        if(f[i]==l)cout<<i<<'\n';//此时就是一次出现。
    }
    for(int i=1;i<=m;i++)cout<<nxt[i]<<' ';
}
int main()
{
    string a,b;
    cin>>a>>b;
    kmp(a,b);
}