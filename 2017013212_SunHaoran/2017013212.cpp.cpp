
#include<iostream>
using namespace std;
 const int size=100;
int p[size];
int m[size][size],s[size][size];
int n;
void matrixchain()
{
    int i,r,j,k;
	memset(m,0,sizeof(m));
	memset(s,0,sizeof(s));
	for(r=2;r<=n;r++)
	{
	for(i=1;i<=n-r+1;i++)
	{
		j=i+r-1;
		m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
		s[i][j]=i;
		for(k=i+1;k<j;k++)
		{
			int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			if(t < m[i][j])
			{
				m[i][j]=t;
				s[i] [j]=k;
			}
		}
	}
}}
 void print(int i,int j)
{
	if(i == j)
	{
		cout<<"A["<<i<<"]";
		return;
	}
	cout<<"(";
	print(i,s[i][j]);
	print(s[i][j]+1,j);
	cout<<")";
}
 
int main()
{
	cin>>n;
	int i,j;
	for(i=0;i<=n;i++)
		cin>>p[i];
	matrixchain(); 
	print(1,n);
	cout<<endl;
	cout<<m[1][n]<<endl;
	return 0;
}