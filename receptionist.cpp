#include <bits/stdc++.h>
#include "doctor.cpp"
//using namespace std;

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
	// Prints queue of the doctor selected
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