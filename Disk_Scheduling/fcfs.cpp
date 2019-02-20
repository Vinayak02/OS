#include<iostream>
#include<vector>
using namespace std;
int main()
{
	cout<<"Enter the number of tracks in request queue : ";
	int n, i;
	cin>>n;
	vector<int> t(n);
	cout<<"Enter the tracker numbers : "<<endl;
	for(i = 0; i < n; i++)
		cin>>t[i];
	cout<<"Enter the source track : ";
	int source;
	cin>>source;
	int sum = 0;
	for(i = 0; i < n; i++)
	{
		if(source - t[i] < 0)
			sum = sum - (source - t[i]);
		else
			sum = sum + (source - t[i]);
		source = t[i];
	}
	cout<<"The seek time is "<<sum<<endl;
	return 0;
}
	
