#include <bits/stdc++.h>
#include "admin/classes/Dclass.cpp"


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
		case 1:{d->treatPatients();/*pushQ();*/break;}
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
			for(int i=0;i<13;i++)
				d1->patientQ[i]=d1->patientQ[i+1];
				d1->patientQ[14]=0;
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