#include <bits/stdc++.h>
#include "doctor.cpp"
//using namespace std;


void initial_diagnosis(int ldapID){
	float temp;
	float weight;
	char remarks[20];
	char remrk[20];
	cout<<"Enter the body tempearture in Fahrenheit : ";
	cin>>temp;
	cout<<"\nEnter the weight in KGs : ";
	cin>>weight;
	cout<<"\nEnter the remarks if any : ";
	char x;
	scanf("%c",&x);
	fgets (remarks, 25, stdin);
	patient p;
	ofstream fout;			
	fout.open("admin/records/tempFiles/tempRecords.txt");
	ifstream fin;
	fin.open("admin/records/records.txt");

	while(fin.read(reinterpret_cast<char*>(&p), sizeof(patient))){
		if(p.LDAP==ldapID){
			p.temp=temp;
			p.weight=weight;
		strcpy(p.rRemarks,remarks);
		}
		fout.write(reinterpret_cast<char*>(&p), sizeof(patient));
	}
	fin.close();fout.close();
	fin.open("admin/records/tempFiles/tempRecords.txt");
	fout.open("admin/records/records.txt");
	while(fin.read(reinterpret_cast<char*>(&p), sizeof(patient)))
		fout.write(reinterpret_cast<char*>(&p), sizeof(patient));
	fin.close();fout.close();
}


class receptionist
{
	public:
	int LDAP;
	void addToQueue(int num,int ind){
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

	void receptionistInit(int num,receptionist* r){
		r->LDAP=num;
		int cmd;
		while(true){
			cout<<"Press 1 to perform initial diagnosis"<<endl;
			cout<<"Press 2 to logout"<<endl;
			cin>>cmd;
			if(cmd==2){
				cout<<"Logging out..."<<endl; 
				return ;
			} 
			cout<<"Enter the patient's LDAP Id (example: P10)"<<endl;
			char cmd[3];
			cin>>cmd;
			int num;
			if(cmd[2])
				num=(cmd[1]-'0')*10 + cmd[2]-'0';
			else
				num=cmd[1]-'0';
			initial_diagnosis(num);
		}
	}


/*int main()
{
	receptionist r;
	int ldapID;
	ldapID=r.student_id();
	r.initial_diagnosis(ldapID);
	return 0;

}*/