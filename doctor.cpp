#include <bits/stdc++.h>
#include "admin/classes/Dclass.cpp"

void displayMedicalRecord(patient* p){
	ifstream fin;
	inventory in;
			fin.open("admin/records/inventory.txt");
			while(fin.read(reinterpret_cast<char*>(&in), sizeof(inventory)))
				cout<<"Medicine Id: "<<in.medicineId<<" Quantity: "<<in.Quantity<<endl;

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
	fout.close();
	
	//ifstream fin;
	//leave s1;
	// fin.open("admin/records/leave.txt");
	// while(fin.read(reinterpret_cast<char*>(&s1), sizeof(leave)))
	// 	cout<<s1.LDAP<<" "<<s1.endMonth<<" "<<endl;
	// cout<<endl;
	fin.close();

}



patient* nextPatient(doctor* d,patient*p){
		int next=d->patientQ[0];
		if(next==0)
			return NULL;
		ifstream fin;
		fin.close();
		fin.open("admin/records/records.txt");
		patient* p1=new patient();
		while(fin.read(reinterpret_cast<char*>(p1), sizeof(patient)))
			if(p1->LDAP==next)
				return p1;
		cout<<endl;
	}

void treatPatients(doctor* d){
	patient* p=new patient();
	p=nextPatient(d,p);
	if(p==NULL){
		cout<<"No patients in the queue"<<endl;
		return;
	}
	cout<<endl<<"Next Patient: "<<'P'<<p->LDAP<<endl;
	p=writePrescription(p);
	displayMedicalRecord(p);
	cout<<"Medical Leave Required?"<<endl;
	bool leave;
	cin>>leave;
	if(leave)
		notifyAdmin(p->LDAP);
		d->updateRecords(p);
		return;
}

void doctorInit(int num,doctor* d){
	ifstream fin;
	ofstream fout;
	while(true){	
	fin.open("admin/records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(d), sizeof(doctor));
		if(d->LDAP==num)
			break;
	}
	fin.close();
	char x;
	cout<<"Press 1 to Treat patients"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to logout"<<endl;
	cin>>x;
	int cmd=x-'0';
	switch(cmd){
		case 1:{treatPatients(d);/*pushQ();*/break;}
		case 2:{d->onlineDiscussion(num);break;}
		case 3:{cout<<"Logged Out"<<endl;return;}
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

