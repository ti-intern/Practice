#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &a,int d)
{
	vector<int> temp;
	int n = a.size();
	int i;
	for(i=0;i<d;i++)
	{
		temp.push_back(a[i]);
	}
	for(i=0;i<n-d;i++)
	{
		a[i] = a[i+d];
	}
	int j = 0;
	for(;i<a.size();i++,j++)
	{
		a[i] = temp[j];
	}
}

int main(int argc, char const *argv[])
{
	int n,x,d;
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