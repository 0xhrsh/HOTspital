#include <bits/stdc++.h>
#include "Pclass.cpp"
using namespace std;

class pharmacist{
	int prescription[20][2];
	string findPrescription(int LDAP){
	patient* p=new patient();
	ifstream fin;
	fin.open("records/records.txt", ios::in);
	for (int i = 0; i < 20; ++i){
		fin.read(reinterpret_cast<char*>(p), sizeof(patient));
		if(p->LDAP==LDAP){
			for(int i=0;i<20;i++){
				prescription[i][0]=p->medicine[i][0];
				prescription[i][1]=p->medicine[i][1];
			}

		}
	}	
	
	}
public:
	string getPatient()
	{
		string pat;
		cout << "enter the patient's ID:";
		cin >> pat;	
		return pat;
	}
	string getPrescription(string pat)
	{
		return findPrescription(pat);
	}

};
void pharmacistInit(int num, pharmacist* f)
{
	int patient=f->getPatient();
	string pres=f->getPrescription(patient);

}