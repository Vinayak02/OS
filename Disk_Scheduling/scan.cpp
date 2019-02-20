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
	auto a = min_element(t.begin(), t.end());
	if(a != t.end())
		sum = (t_no - 1 - src) + (t_no - 1 - *a);
	cout<<"The seek time is "<<sum<<endl;
	return 0;
}