#include <bits/stdc++.h>
#include "receptionist.cpp"

void error(int num){
	num++;
	cout<<endl<<"Invalid Input"<<endl;
}


void readRecords(int num){
	ifstream fin;
	patient* prr=new patient();
	fin.open("admin/records/records.txt");
	while(fin.read(reinterpret_cast<char*>(prr), sizeof(patient))){
		if(prr->LDAP==num)
			break;
	}
	fin.close();
	cout<<"Last Remarks: "<<prr->dRemarks<<endl;
	cout<<"Full Records: "<<prr->record<<endl;

	return;
}


int chooseDoctor(){
	doctor d;
	ifstream fin;
	fin.open("admin/records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(&d), sizeof(doctor));
		if(d.available){
		cout<<d.name<<" "<<d.LDAP<<" "<<d.speciality<<" "<<endl;
		}
	}
}
void takeAppointment(int num){
	cout<<endl<<"===Doctors Available==="<<endl;
	chooseDoctor();
	int ind;
	cout<<endl;
	cout<<"Enter Id to choose doctor"<<endl;
	cin>>ind;
	receptionist r;
	r.addToQueue(num,ind);
	
	return;
	}


void patientInit(int num,patient* p){
	p->LDAP=num;
	while(true){
	char x;
	cout<<"Press 1 to Take appointment"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to View Medical Report"<<endl;
	cout<<"Press 4 to logout"<<endl;
	cin>>x;
	int cmd=x-'0';
	switch(cmd){
		case 1:{takeAppointment(num);break;}
		case 2:{p->onlineDiscussion(num);break;}
		case 3:{readRecords(num);break;}
		case 4:{cout<<"Logged Out"<<endl;return;}
		default: cout<<"Invalid Value"<<endl;
	}
}
}

