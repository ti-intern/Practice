#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a,int s,int e,int x)
{
	int mid;
	//cout<<s<<" "<<e<<" ";
	while(s<=e)
	{
		mid = (s+e)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			e = mid-1;
		else
			s = mid+1;
	}
	return -1;
}

int findPivot(vector<int> &a,int l,int h)
{
	if(h<l) return -1;
	if(h==l) return l;
	int mid = (l+h)/2;
	if(mid<h && a[mid]>a[mid+1])
		return mid;
	if(mid>l && a[mid]<a[mid-1])
		return mid-1;
	if(a[l]>=a[mid])
		return findPivot(a,l,mid-1);
	return findPivot(a,mid+1,h);
}

int search(vector<int> &a,int x)
{
	/*int i;
	for(i=0;i<a.size();i++)
	{
		if(a[i+1]<a[i])
			break;
	}*/
	//cout<<i<<endl;
	int i = findPivot(a,0,a.size()-1);
	if(x>a[0])
		return binarySearch(a,0,i,x);
	else
		return binarySearch(a,i+1,a.size()-1,x);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> a;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	cin>>x;
	int index = search(a,x);
	cout<<index<<endl;
	return 0;
}