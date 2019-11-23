#include <bits/stdc++.h>
#include "Pclass.cpp"
#include "../mkrecords/mkinventory.cpp"
using namespace std;




class doctor: virtual public patient{
public:
	int LDAP;
	char name[15];
	char speciality[15];
	bool available;
	int patientQ[15];
	doctor(){};

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
		if(pLDAP==0)
			return;
		patient p(pLDAP);
		writePrescription(p);
		cout<<"Medical Leave Required"<<endl;
		bool leave;
		cin>>leave;
		if(leave)
			//notifyAdmin();
		//updateRecords();
		return;
	}

	void writePrescription(patient p){
		int med,quant;
		inventory ik;
		ifstream fin;
		fin.open("../records/inventory.txt");
		cin>>med>>quant;
		for (int i = 0; quant>0 && i<20;){
			fin.read(reinterpret_cast<char*>(&ik), sizeof(Inventory));
			if(ik.Quantity>0){
				i++;
				p.medicine[med][0]=med;
				p.medicine[med][1]=quant;	
			}
			cin>>med>>quant;
	}

	

	
};
