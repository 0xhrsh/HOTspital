#include <bits/stdc++.h>

#include "Dclass.cpp"
//#include "updateQueue.cpp"
//using namespace std;

// DO NOT TAMPER WITH



void addToQueue(int num,int ind){
	//cout<<"here";
	doctor d;
	ifstream fin;
	ofstream fout;
	fin.open("admin/records/doctors.txt");
	fout.open("admin/records/tempDoctors.txt");
	while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor))){
		if(d.LDAP==ind){
			//cout<<"Here";
			int i=0;
			while(d.patientQ[i]!=0)i++;
			d.patientQ[i]=num;
			if(i==14)
				d.available=false;
		}
		fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
	}
	fin.close();fout.close();
	//ifstream fin;
	//ofstream fout;
	fin.open("admin/records/tempDoctors.txt");
	fout.open("admin/records/doctors.txt");
	while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor)))
		fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
	fin.close();fout.close();
	

	// The code below is to test whether the queue update works 
	// or not
	
	// fin.open("admin/records/doctors.txt");
	// while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor))){
	// 	int i=0;
	// 	while(d.patientQ[i])
	// 		cout<<d.patientQ[i++]<<" "<<d.LDAP;
	// 	cout<<endl;
	// }
	// fin.close();


}


class patient{
protected:
	long ph;
	long emergency;
	char record[100];
	int temp;
	int weight;
	char rRemarks[20];
	char dRemarks[50];
	int medicine[20][2];
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
		fin.close();
	}
	void takeAppointment(int num){
		cout<<"Enter Id to choose doctor"<<endl;
		chooseDoctor();
		int ind;
		cout<<endl;
		cout<<"Enter Id to choose doctor"<<endl;
		cin>>ind;
		doctor d;
		addToQueue(num,ind);
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
