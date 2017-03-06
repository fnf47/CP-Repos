

// Google Kickstart 2017 Round A
// Problem B (PatternsOverlap)

#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long int LL;

string make(string a)
{
	string res="a";

	for(int i=0;i<a.size();i++){
		res.push_back(a[i]);
		if(a[i]=='*')res=res+"***";
	}
	return res;
}

const int N=8005;
bool dp[N][N];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);

  //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

  dp[0][0]=true;

  int tc;cin>>tc;for(int t=1;t<=tc;t++)
  {    
     cout<<"Case #"<<t<<": ";
     

     string a,b;
     cin>>a>>b;

     a=make(a);
     b=make(b);

     
     bool fnf=true;
     for(int i=1;i<a.size();i++)
     {
     	if(a[i]!='*')fnf=false;
     	dp[i][0]=fnf;
     }
     fnf=true;
     for(int i=1;i<b.size();i++)
     {
     	if(b[i]!='*')fnf=false;
     	dp[0][i]=fnf;
     }
     
     for(int i=1;i<a.size();i++)
     {
     	for(int j=1;j<b.size();j++)
     	{
          if((a[i]!='*')&&(b[j]!='*')){
          	dp[i][j]=((a[i]==b[j])&&(dp[i-1][j-1]));
          }
          else if((a[i]=='*')&&(b[j]!='*')){
          	dp[i][j]=(dp[i-1][j-1]||dp[i-1][j]);
          }
          else if((a[i]!='*')&&(b[j]=='*')){
            dp[i][j]=(dp[i-1][j-1]||dp[i][j-1]);
          }
          else{
          	dp[i][j]=((dp[i-1][j-1])||(dp[i-1][j])||(dp[i][j-1]));
          }
     	}
     }
     string res = (dp[a.size()-1][b.size()-1]) ? "TRUE" : "FALSE";
     cout<<res<<endl;
  }
          
  return 0;
}
