#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	cout<<"Enter the number of tracks in request queue : ";
	int n, i, j;
	cin>>n;
	vector<int> t(n);
	cout<<"Enter the track numbers : ";
	for(i = 0; i < n; i++)
		cin>>t[i];
	cout<<"Enter the source track : ";
	int src;
	cin>>src;
	map<int, int> m;
	int sum = 0;
	for(j = 0; j < n; j++)
	{
		vector<int>:: iterator position = find(t.begin(), t.end(), src);
		if(position != t.end())
			t.erase(position);
		m.clear();
		for(i = 0; i < t.size(); i++)
		{
			if(src - t[i] < 0)
				m[-(src - t[i])] = t[i];
			else
				m[(src - t[i])] = t[i];
		}
		map<int, int>::iterator it;
		it = m.begin();
		/*cout<<"The current request queue : "<<endl;*/
		/*for(int k = 0; k < t.size(); k++)
			cout<<t[k]<<endl;*/
		if(src - it->second < 0)
			sum = sum - (src - it->second);
		else
			sum = sum + (src - it->second);
		/*cout<<"source : "<<src<<endl;*/
		src = it->second;
		/*cout<<"new source : "<<src<<endl;*/
	}
	cout<<"The seek time is "<<sum<<endl;
	return 0;
}
