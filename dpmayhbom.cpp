#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cout<<"Nhap May Bom && So Giay: ";cin>>n>>k;
	int dp[n+1][k+1];
	//set gia tri
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<k+1;j++)
		{
			dp[i][j]=0;
		}
	}
	int mb[n+1];mb[0]=0;
	int d ;
	cout<<"Nhap Khoi Luong Nuoc!:";
	cin>>d;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap May["<<i<<"] :";cin>>mb[i];
	}
	//printf matrix
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	//dynamic programs
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<k+1;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(dp[i-1][j]+mb[i]<=d)
			{
				dp[i][j]=dp[i-1][j]+mb[i];
			}else
			{
				if(dp[i-2][j] + mb[i]<=d )
				{
					dp[i-1][j]= dp[i-2][j];
					dp[i][j]=dp[i-1][j]+mb[i]; 
				}	
			}
			
			cout<<"vi tri i,j: "<<i<<j<<" value:"<<dp[i][j]<<endl;
			cin.get();
		}
	}
	//xuat
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<k+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	//truy vet
	cout<<"Can Bat Tat "<<k<<"s"<<" cua cac may de dat duoc lhuong nuoc toi da="<<d<<endl;
	int j=1;
	for(int i=n;i>0;i--)
	{
		if(dp[i][k] == d || dp[i][k]!=dp[i-1][k])
		{
			cout<<"Turn on may: "<<i<<"("<<j<<")s"<<endl;
			j+=1;
		}
	}
	return 0;
}
//bo test 3 3
//6
//1 2 3 dang fix
//bo test 3 2
//6
//2 3 4 true
