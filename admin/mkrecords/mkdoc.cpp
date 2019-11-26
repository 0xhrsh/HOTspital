#include <bits/stdc++.h>
#include "../classes/Dclass.cpp"
using namespace std; 

int main(int argc, char** argv){ 
	doctor d;
	ofstream fout;
	fout.open("../records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		d.LDAP=i+1;
		string temp="test";
		strcpy(d.name,temp.c_str());
		string speciality;
		if(i%3==0)
			speciality="Bones";
		else if(i%3==1)
			speciality="Skin";
		else
			speciality="ENT";
		strcpy(d.speciality,speciality.c_str());
		if(i%2)
			d.available=false;
		else
			d.available=true;
		fout.write(reinterpret_cast<char*>(&d), sizeof(doctor));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	ifstream fin;
	fin.open("../records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(&d), sizeof(doctor));
		if(d.available){
		//int x=d.patient.back();
		cout<<d.name<<" "<<d.LDAP<<" "<<d.speciality<<" "<<d.patientQ[0]<<"here"<<endl;
		}
	}
	fin.close();

	
	
	return (0); 
} 
