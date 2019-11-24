#include <bits/stdc++.h>
#include "Pclass.cpp"
using namespace std;

class doctor: virtual public patient{
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

	void updateRecords(patient p){
		
	}





	void notifyAdmin(int x){
		struct leave{
			int patientLDAP,startingDate,startingMonth,endDate,endMonth;
		}s;
		s.patientLDAP=x;
		cout<<"Starting date (DD,MM): "<<endl;
		cin>>s.startingDate>>s.startingMonth;
		cout<<"End date (DD,MM): "<<endl;
		cin>>s.endDate>>s.endMonth;
		ofstream fout;
		fout.open("admin/records/leave.txt",ios_base::app);
		fout.write(reinterpret_cast<char*>(&s), sizeof(leave));
		fout.close();
	}

	int nextPatient(){

		int next=patientQ[0];
		for(int i=0;i<13;i++)
			patientQ[i]=patientQ[i+1];
		patientQ[14]=0;
		available=1;
		return next;
	}

	void onlineDiscussion(int p){
		cout<<"OnlineDiscussion"<<endl;
		return;
	}	
	void treatPatients(){
		int pLDAP=nextPatient();
		cout<<pLDAP<<endl;
		if(pLDAP==0){
			cout<<"No patients in the queue"<<endl;
			return;
		}
		patient* p=new patient(pLDAP);
		p=writePrescription(p);
		cout<<"Medical Leave Required?"<<endl;
		bool leave;
		cin>>leave;
		if(leave)
			notifyAdmin(pLDAP);
		updateRecords(p);
		return;
	}

	friend patient* writePrescription(patient* p);   //  IN LOGIN.CPP
	
};
