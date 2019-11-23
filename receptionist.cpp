#include <bits/stdc++.h>
using namespace std;

void addToQueue(int num,int ind){
	//cout<<"here";
	doctor d;
	ifstream fin;
	ofstream fout;
	fin.open("admin/records/doctors.txt");
	fout.open("admin/records/tempFiles/tempDoctors.txt");
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
	fin.open("admin/records/tempFiles/tempDoctors.txt");
	fout.open("admin/records/doctors.txt");
	while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor)))
		fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
	fin.close();fout.close();
	

	// The code below is to test whether the queue update works 
	// or not
	
	fin.open("admin/records/doctors.txt");
	while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor))){
		int i=0;
		if(ind==d.LDAP){
			cout<<"Name added to queue"<<endl<<"Current Queue: ";
			while(d.patientQ[i])
				cout<<'P'<<d.patientQ[i++]<<" ";
		}
	}
	cout<<endl;
	fin.close();
}