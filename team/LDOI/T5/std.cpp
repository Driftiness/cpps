#include<bits/stdc++.h>
using namespace std;
int sum[200007],ans,n,q;
string a,b;
vector<int>v[57];
int t[500007];
inline int lowbit(int x){return x&-x;}
inline void add(int idx,int k)
    {while(idx<=n)t[idx]+=k,idx+=lowbit(idx);}
inline int getsum(int x)
    {int ans=0;while(x>0)ans+=t[x],x-=lowbit(x);return ans;}
inline int getsum(int l,int r)
    {return getsum(r)-getsum(l-1);}

inline int convert(char c)
{
    return isalpha(c)?c-95:(isdigit(c+27-48));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>q>>b>>a;
    for(int i=0;i<n;i++)
        v[convert(a[i])+convert(b[i])].push_back(max(a[i],b[i]));
    for(int i=0;i<n;i++)add(i+1,a[i]==b[i]);
    for(int i=1;i<=q;i++)
    {
        int x;char c;
        cin>>x>>c;x--;
        if((a[x]==b[x])^(b[x]==c))
            if(a[x]==b[x])
                if(!(b[x]==c))add(i+1,-1);
            else
                if(b[x]==c)add(i,1);
        b[x]=c;
        for(int i=1;i<=27+9;i++)
        {
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size();j++)
                ans=max(ans,j+1+getsum(i-v[i][j]-1)-getsum(v[i][j]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}