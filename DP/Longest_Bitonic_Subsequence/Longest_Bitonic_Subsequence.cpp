

// Longest Bitonic Subsequence
// O(n*n)
// Tested on SPOJ CODERE3

#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long int LL;

const int N=1003;
int a[N],dpl[N],dpr[N];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);

  //freopen("input.in","r",stdin);
     
     int t;cin>>t;while(t--) // Number of testcases
     {
     	 int n; cin>>n;

     	 for(int i=1;i<=n;i++)cin>>a[i];

     	 for(int i=1;i<=n;i++)
     	 {
     	 	dpl[i]=1;
     	 	for(int j=1;j<=i-1;j++)
     	 	{
                 if(a[j]<a[i])dpl[i]=max(dpl[i],1+dpl[j]);
     	 	}
     	 }
         
         for(int i=n;i>=1;i--)
         {
         	dpr[i]=1;
         	for(int j=i+1;j<=n;j++)
         	{
                  if(a[j]<a[i])dpr[i]=max(dpr[i],1+dpr[j]);
         	}
         }

         int res=0;
         
         for(int i=1;i<=n;i++)
         {
         	int tmp=max(dpl[i],dpr[i]);
         	tmp=max(tmp,dpl[i]+dpr[i]-1);
         	res=max(res,tmp);
         }

         cout<<res<<endl;
     }
  
  return 0;
}
