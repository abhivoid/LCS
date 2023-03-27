#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,n1,n2,j;
	string s1,s2;
	vector<char> s;
	cout<<"Enter first String\n";
	cin>>s1;
	cout<<"Enter second string\n";
	cin>>s2;
	cout<<endl;
	n1=s1.size();
	n2=s2.size();
	int l[n1+1][n2+1];
	for(i=0;i<n1;i++)
	l[i][0]=0;
	for(i=0;i<n2;i++)
	l[0][i]=0;
	
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
			l[i][j]=l[i-1][j-1]+1;
			else
			l[i][j]=max(l[i-1][j],l[i][j-1]);
		}
	}
	i=n1;
	j=n2;
	while(l[i][j]!=0)
	{
		if(l[i][j]!=l[i-1][j]&&l[i][j]!=l[i][j-1])
		{
			s.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(l[i][j]==l[i-1][j])
		i--;
		else
		j--;
	}
	for(i=s.size()-1;i>=0;i--)
	cout<<s[i];
}
