#include <iostream>
#include <cstring>
using namespace std;
int dp[1002][1002];
void timxauchungdainhat(string a,string b)
{
	int n = a.size();
	int m = b.size();
	dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(a[i-1]==b[j-1]) dp[i][j] = max(dp[i-1][j] , dp[i][j-1]+1);
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	string a;
	string b;
	cin>>a;
	cin>>b;
	timxauchungdainhat(a,b);
	
	return 0;
}

