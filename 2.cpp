#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &a,int s,int e)
{
	int n = (e+s)/2;
	for(int j=0;j<=n-s;j++)
	{
		swap(a[s+j],a[e-j]);
	}
}

void print(vector<int> &a)
{
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void rotate(vector<int> &a,int d)
{
	reverse(a,0,d-1);
	print(a);
	reverse(a,d,a.size()-1);
	print(a);
	reverse(a,0,a.size()-1);
	print(a);
}

int main(int argc, char const *argv[])
{
	int n,d,x;
	cin>>n>>d;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	d = d%n;
	rotate(a,d);
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}