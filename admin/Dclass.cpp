#include <bits/stdc++.h>
using namespace std;

class doctor{
public:
	int LDAP;
	char name[15];
	char speciality[15];
	bool available;
	int patientQ[15];
	doctor(){
		for (int i = 0; i < 15; ++i)
			patientQ[i]=0;
	};

	void onlineDiscussion(int p){
		cout<<"OnlineDiscussion"<<endl;
		return;
	}	
	void treatPatients(){
		if(patientQ[0]==0) return ;
		else {
			for(int i=0;i<14;i++)
			{
				patientQ[i]=patientQ[i+1];
			}
			patientQ[14]=0;
		}
				
	}
};
