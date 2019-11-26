#include<bits/stdc++.h>
using namespace std;

class receptionist
{
private:
	int docSchedule[10];
protected:
	int hospitalInventory;
public:
	int name;
	string LDAP;
	receptionist();
}recp;

string initial_digno();
{
	string a;
	cout<<"Enter the initial diagnosis : ";
	cin>>a;
	return a;
}

int doc_schedule(int arr[10])
{
	//I am assuming that arr[]=1 means doctor schedule is busy 
	for(int i=0;i<10;i++)
	{
		if(arr[i]==0)
		{
			return 0;
			break;
		}
	}
	return 1;
}

int main()
{
	int 
}