#include <bits/stdc++.h>
#include "doctor.cpp"
//using namespace std;

class receptionist
{
	public:
	int LDAP;
	void addToQueue(int num,int ind)
	{
		cout<<"Adding to queue"<<endl;
		doctor d;
		ifstream fin;
		ofstream fout;
		fin.open("admin/records/doctors.txt");
		fout.open("admin/records/tempFiles/tempDoctors.txt");
		while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor))){
			if(d.LDAP==ind){
				int i=0;
				while(d.patientQ[i]!=0)i++;
				d.patientQ[i]=num;
				if(i==14)
					d.available=false;
			}
			fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
		}
		fin.close();fout.close();
		fin.open("admin/records/tempFiles/tempDoctors.txt");
		fout.open("admin/records/doctors.txt");
		while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor)))
			fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
		fin.close();fout.close();

		fin.open("admin/records/doctors.txt");
		while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor))){
			int i=0;
			// // uncomment this to check all queues
	
			// while(d.patientQ[i]){
			// 	cout<<'P'<<d.patientQ[i]<<" ";
			// 	i++;
			// }
			// cout<<endl;
			if(ind==d.LDAP){
				cout<<"Name added to queue"<<endl<<"Current Queue for doctor "<<d.LDAP<<": ";
				while(d.patientQ[i])
					cout<<'P'<<d.patientQ[i++]<<" ";
			}
		}
		cout<<endl;
		fin.close();
	}
	void initial_diagnosis(int ldapID)
	{
		float temp;
		float weight;
		string remarks;
		char remrk[20];
		cout<<"Enter the body tempearture in Fahrenheit : ";
		cin>>temp;
		cout<<"\nEnter the weight in kgs : ";
		cin>>weight;
		cout<<"\nEnter the remarks if any : ";
		cin>>remarks;
		patient p;
		ofstream fout;			
		fout.open("records/records.txt", ios::out);
		ifstream fin;
		fin.open("records/records.txt", ios::in);
		fin.read(reinterpret_cast<char*>(&p), sizeof(patient));
		if(p.LDAP==ldapID)
		{
			p.temp=temp;
			p.weight=weight;
			strcpy(remrk,remarks.c_str());
			fout.write(reinterpret_cast<char*>(&p), sizeof(patient));
		}
		fin.close();
		fout.close();
	}
	int update_hospital_inventory()
	{
	}
	int student_id()
	{
		int ldapID;
		cout<<"\n Enter patient ID";
		cin>>ldapID;
		return ldapID;
	}
	receptionist(){};

};

/*int main()
{
	receptionist r;
	int ldapID;
	ldapID=r.student_id();
	r.initial_diagnosis(ldapID);
	return 0;

}*/