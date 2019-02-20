#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	cout<<"Enter the number of tracks in request queue : ";
	int n, i;
	cin>>n;
	vector<int> t(n);
	int sum;
	cout<<"Enter the track numbers : ";
	for(i = 0; i < n; i++)
		cin>>t[i];
	cout<<"Enter the total tracks in the disk : ";
	int t_no;
	cin>>t_no;
	cout<<"Enter the source track : ";
	int src;
	cin>>src;
	sort(t.begin(), t.end());
	auto a = upper_bound(t.begin(), t.end(), src);
	cout<<*(a-t.begin())<<endl;
	return 0;
}