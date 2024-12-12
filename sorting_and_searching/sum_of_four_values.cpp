#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;
    vector<int>a(n);
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i)
    {
    	ll xx;
    	cin>>xx;
    	a[i]=xx;
    	v[i]={xx,i};
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			int low=j+1,high=n-1;
			while(low<high)
			{
				int p=v[i].first,q=v[j].first,r=v[low].first,s=v[high].first;
				if(p+q+r+s==x)
				{
					cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[low].second+1<<" "<<v[high].second+1<<endl;
					return 0;
				}
				else if(p+q+r+s<x)low++;
				else high--;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	
	return 0;
}