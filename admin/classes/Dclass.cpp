#include <bits/stdc++.h>
#include "Pclass.cpp"
using namespace std;

class doctor: virtual public patient{
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
		pLDAP=nextPatient();
		if(patient==0)
			return;
		patient p(pLDAP);
		writePrescription(patient p);
		cout<<"Medical Leave Required"<<endl;
		bool leave;
		cin>>leave;
		if(leave)
			notifyAdmin();
		updateRecords();
		return;
	}

	void writePrescription(patient p){
		
	}

	int nextPatient(){
		int next=patientQ[0];
		for(int i=0;i<13;i++)
			patientQ[i]=patientQ[i+1];
		patientQ[14]=0;
		available=1;
		return next;
	}
};
