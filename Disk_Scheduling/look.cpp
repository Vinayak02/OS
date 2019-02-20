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
	cout<<"Enter the source track : ";
	int src;
	cin>>src;
	auto min = min_element(t.begin(), t.end());
	auto max = max_element(t.begin(), t.end());
	sum = (*max - src) + (*max - *min);
	cout<<"The seek time is "<<sum<<endl;
	return 0;
}
