#include <bits/stdc++.h>
#include "Pclass.cpp"
using namespace std;

class doctor:virtual public patient{
private:
	//removeFromQueue(LDAP);
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
	doctor(int x){
		LDAP=x;
		for (int i = 0; i < 15; ++i)
			patientQ[i]=0;	
	}
	void onlineDiscussion(int p){
		cout<<"Online Discussion"<<endl;
		return;
	}	
	friend patient* writePrescription(patient* p);   //  IN LOGIN.CPP
	friend patient* nextPatient(doctor* d,patient* p);
	
};
