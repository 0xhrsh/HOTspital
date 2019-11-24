#include <bits/stdc++.h>
#include "admin/classes/Fclass.cpp"
#include"patient.cpp"
#include"admin/mkrecords/mkInventory.cpp"
// using namespace std;

patient* findPrescription(int LDAP)
	{
		int prescription[20][2];
		patient* p=new patient();   // !!!!
		ifstream fin;
		fin.open("admin/records/records.txt", ios::in);
		for (int i = 0; i < 20; ++i)
		{
			fin.read(reinterpret_cast<char*>(p), sizeof(patient));
			if(p->LDAP==LDAP)
				return p;
		}
		//return prescription;	
	
	}
void maintainInventory(patient* p)
	{
		ifstream fin;
		inventory* in;
		fin.open("admin/records/inventory.txt", ios::in);
		int i;
		while(1)
		{
			fin.read(reinterpret_cast<char*>(in), sizeof(inventory));
			if(p->medicine[i][0]!=0 && in->medicineId==p->medicine[i][0])
			{
				in->Quantity--;
				i++;
			}
			if(p->medicine[i][0]==0) break;
		}

	}



class pharmacist
{
	friend patient* findPrescription(int LDAP);
	
	friend void maintainInventory(patient* p);

	public:
		int getPatient()
		{
			int pat;  //ldap of the patient
			cout << "enter the patient's ID:";
			cin >> pat;	
			return pat;
		}
		patient* getPrescription(int pat)
		{

			return findPrescription(pat);
		}
		void updateInventory(patient* p)
		{
			maintainInventory(p);
		}

};
void pharmacistInit(int num, pharmacist* f)
{
	int pat=f->getPatient();
	patient* p=f->getPrescription(pat);
	f->updateInventory(p);

}