#include <bits/stdc++.h>
#include "Dclass.cpp"
//using namespace std;

// DO NOT TAMPER WITH

class patient{
protected:
	long ph;
	long emergency;
	char record[100];
	int temp;
	int weight;
	char rRemarks[10];
	char prescription[10];
public:
	int LDAP;
	char fname[10];
	char lname[10];
	patient(){};
	patient(int x){
		LDAP=x;
	}
	patient(string fx,string lx,int x){
		LDAP=x; strcpy(fname,fx.c_str()); strcpy(lname,lx.c_str());
	}
	int chooseDoctor(){
		doctor d;
		ifstream fin;
		fin.open("admin/records/doctors.txt");
		for (int i = 0; i < 10; ++i){
			fin.read(reinterpret_cast<char*>(&d), sizeof(doctor));
			if(d.available)
				cout<<d.LDAP<<" "<<d.name<<" "<<d.speciality<<endl;
		}
	}
	void takeAppointment(int num){
		cout<<"Enter Id to choose doctor"<<endl;
		chooseDoctor();
		int ind;
		cout<<endl;
		cout<<"Enter Id to choose doctor"<<endl;
		cin>>ind;
		doctor d;
		ifstream fout;
		fout.open("admin/records/doctors.txt");
		//addToQueue(num,ind);
		//d.patientQ.back();
		return;
	}
	void onlineDiscussion(int p){
		cout<<"OnlineDiscussion"<<endl;
		return;
	}
	void setPh(long x){
		ph=x;
	}
	void setEm(long x){
		emergency=x;
	}
	//~patient();
	
};