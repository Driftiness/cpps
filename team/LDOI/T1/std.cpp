#include<bits/stdc++.h>
using namespace std;
double m1,m2,v1,v2,x1,x2,v3,v4,v5;
inline bool impossible() 
{
	if((x1<x2&&v1<=v2)||(x1>x2&&v1>=v2))return true;
	return false;
}
int main() 
{
	int N=0;
	cin>>N;
	while(N--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&m1,&v1,&x1,&m2,&v2,&x2);
		if(x1==x2)
			printf("Already together\n");
		else if(impossible()) 
			printf("No Collision\n");
        else
        {
            v3=v1-v2;
            v4=(m1-m2)/(m1+m2)*v3;
            v5=2*m1/(m1+m2)*v3;
            v4+=v2,v5+=v2;
            printf("%.3f %.3f\n",v4,v5);
        }
	}
	return 0;
}