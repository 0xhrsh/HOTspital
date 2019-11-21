#include <bits/stdc++.h>
//#include "Pclass.cpp"
#include"Dclass.cpp"
using namespace std;

// class doctor{
// public:
// 	int LDAP;
// 	char name[15];
// 	char speciality[15];
// 	bool available;
// 	int patientQ[15];
// 	doctor(){};		
// };




void addToQueue(int num,int ind){
	doctor d;
	ifstream fin;
	ofstream fout;
	fin.open("records/doctors.txt");
	fout.open("records/tempDoctors.txt");
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
	//ifstream fin;
	//ofstream fout;
	fin.open("records/tempDoctors.txt");
	fout.open("records/doctors.txt");
	while(fin.read(reinterpret_cast<char*>(&d), sizeof(doctor)))
		fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
}
void removeFromQueue(int num, int ind){

}
