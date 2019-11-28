#include <bits/stdc++.h>
#include <string>
#include "admin/classes/Dclass.cpp"
string to_string(int x){
	char* ret=new char[4];
	ret[0]=' ';
	ret[1]=x/10+'0';
	ret[2]=x%10+'0';
	ret[3]='\0';
	return (string)ret;
}
string to_strng(int x){
	char* ret=new char[3];
	ret[0]=x/10+'0';
	ret[1]=x%10+'0';
	ret[2]='\0';
	return (string)ret;
}
void displayMedicalRecord(patient* p){
	cout<<"Receptionist Remarks : ";
	cout<<p->rRemarks;
	cout<<endl;
	cout<<"Temperature : ";
	cout<<p->temp<<endl;
	cout<<"Weight : ";
	cout<<p->weight<<endl;
	//cout<<p->rRemarks;
	cout<<endl;
}

void notifyAdmin(int pldap){
	typedef struct leave{
		int LDAP,startingMonth,startingDate,endMonth,endDate;
	}leave;
	ofstream fout;
	leave s;
	s.LDAP=pldap;
	fout.open("admin/records/leave.txt",ios_base::app);
	cout<<"Enter Starting Date followed by starting Month"<<endl;
	cin>>s.startingDate>>s.startingMonth;
	cout<<"Enter Ending Date followed by Ending Month"<<endl;
	cin>>s.endDate>>s.endMonth;
	fout.write(reinterpret_cast<char*>(&s), sizeof(leave));
	string send=(string)"notifyAdmin.py P"+to_strng(pldap)+to_string(s.startingDate)+to_string(s.startingMonth)+to_string(s.endDate)+to_string(s.endMonth);
	cout<<endl;
	system(send.c_str());
	fout.close();

	//ifstream fin;
	//leave s1;
	// fin.open("admin/records/leave.txt");
	// while(fin.read(reinterpret_cast<char*>(&s1), sizeof(leave)))
	// 	cout<<s1.LDAP<<" "<<s1.endMonth<<" "<<endl;
	// cout<<endl; 
	//fin.close();

}

patient* nextPatient(doctor* d,patient*p){
		int next=d->patientQ[0];
		if(next==0)
			return NULL;
		ifstream fin;
		fin.close();
		fin.open("admin/records/records.txt");
		patient* p1=new patient();
		//cout<<"-->"<<fin.read(reinterpret_cast<char*>(p1), sizeof(patient));
		while(fin.read(reinterpret_cast<char*>(p1), sizeof(patient)))
			if(p1->LDAP==next)
				return p1;
		cout<<endl;
}

void treatPatients(int num,doctor* d){
	ifstream fin;
	fin.open("admin/records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(d), sizeof(doctor));
		if(d->LDAP==num)
			break;
	}
	fin.close();



	patient* p=new patient();
	p=nextPatient(d,p);
	if(p==NULL){
		cout<<"No patients in the queue..  "<<endl;
		return;
	}
	cout<<endl<<" Next Patient: "<<'P'<<p->LDAP<<endl;
	displayMedicalRecord(p);
	p=writePrescription(p);
	cout<<"Medical Leave Required?\n(Press 1 for Yes)\n(Press 0 for No)"<<endl;
	bool leave;
	cin>>leave;
	if(leave)
		notifyAdmin(p->LDAP);
	updateRecords(p);
	return;
}

void updateRecords(patient* p){
	ifstream fin;
	ofstream fout;
	patient* p1=new patient();
	fin.open("admin/records/records.txt");
	fout.open("admin/records/tempFiles/tempRecords.txt");
	while(fin.read(reinterpret_cast<char*>(p1), sizeof(patient)))
		if(p1->LDAP==p->LDAP)
			fout.write(reinterpret_cast<char*>(p), sizeof(patient));
		else
			fout.write(reinterpret_cast<char*>(p1), sizeof(patient));
	fin.close();fout.close();
	patient* p2=new patient();
	fin.open("admin/records/tempFiles/tempRecords.txt");
	fout.open("admin/records/records.txt");
	while(fin.read(reinterpret_cast<char*>(p2), sizeof(patient)))
		fout.write(reinterpret_cast<char*>(p2), sizeof(patient));
	fin.close();fout.close();
	cout<<"==Records Updated=="<<endl;
	return;				
	}



void doctorInit(int num,doctor* d){
	ifstream fin;
	ofstream fout;
	while(true){	
	char x;
	cout<<"Press 1 to Treat patients"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to logout"<<endl;
	cin>>x;
	int cmd=x-'0';
	switch(cmd){
		case 1:{treatPatients(num,d);/*pushQ();*/break;}
		case 2:{d->onlineDiscussion(num);break;}
		case 3:{cout<<"Logged Out.."<<endl;return;}
		default: cout<<"Invalid Value"<<endl;
	}
	doctor* d1=new doctor();
	fin.open("admin/records/doctors.txt");
	fout.open("admin/records/tempFiles/tempDoctors.txt");
	int i=0;
	while (i++<10){		
		fin.read(reinterpret_cast<char*>(d1), sizeof(doctor));
		//cout<<"Updating records";
		if(d1->LDAP==num){
			for(int i=0;i<=13;i++)
				d1->patientQ[i]=d1->patientQ[i+1];
			d1->patientQ[14]=0;
			//cout<<"pQ 14: "<<d1->patientQ[14]<<endl;
			d1->available=1;
			}
		fout.write(reinterpret_cast<char*>(d1), sizeof(doctor));
	}
	fin.close();fout.close();
	fin.open("admin/records/tempFiles/tempDoctors.txt");
	fout.open("admin/records/doctors.txt");
	while(fin.read(reinterpret_cast<char*>(d1), sizeof(doctor)))
		fout.write(reinterpret_cast<char*>(d1), sizeof(doctor));
	fin.close();fout.close();
}
}

