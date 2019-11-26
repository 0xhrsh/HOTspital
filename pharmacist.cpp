#include <bits/stdc++.h>
#include "admin/classes/Fclass.cpp"
#include"patient.cpp"
typedef struct Inventory{
	int medicineId;
	int Quantity;
}inventory;
		

class pharmacist: public patient{
	public:
		int LDAP;
		int getPatient(){
			char pat[4];
			cout << "Enter the patient's ID:";
			cin >> pat;
			if(pat[2])
				return (pat[1]-'0');
			return (pat[1]-'0')*10+(pat[2]-'0');
		}
		patient* getPrescription(int pat){
			patient* p1=new patient();
			ifstream fin;
			fin.open("admin/records/records.txt");
			while(fin.read(reinterpret_cast<char*>(p1), sizeof(patient)))
				if(p1->LDAP==LDAP)
					return p1;
		}
		void updateInventory(patient* p){
			ifstream fin;
			ofstream fout;
			inventory* in;
			fin.open("admin/records/inventory.txt");
			fout.open("admin/records/tempFiles/tempInventory.txt");
			while(fin.read(reinterpret_cast<char*>(in), sizeof(inventory))){
				int i=-1;
				while(p->medicine[++i][0])
					if(p->medicine[i][0]==in->medicineId){
						(in->Quantity)-=(p->medicine[i][1]);
						break;
					}
				fout.write(reinterpret_cast<char*>(in), sizeof(inventory));
			}
			fin.close();fout.close();
			fin.open("admin/records/tempFiles/tempInventory.txt");
			fout.open("admin/records/inventory.txt");
			while(fin.read(reinterpret_cast<char*>(in), sizeof(inventory)))
				fout.write(reinterpret_cast<char*>(in), sizeof(inventory));
			fin.close();fout.close();
		}
		void printInventory(){
			ifstream fin;
			inventory in;
			fin.open("admin/records/inventory.txt");
			while(fin.read(reinterpret_cast<char*>(&in), sizeof(inventory)))
				cout<<"Medicine Id: "<<in.medicineId<<" Quantity: "<<in.Quantity<<endl;
		}
		void orderMedicine(){
			inventory in;
			cout<<"Enter Medicine ID and Quantity:"<<endl;
			cin>>in.medicineId>>in.Quantity;
			ofstream fout;
			fout.open("admin/records/orderMedicine.txt",ios_base::app);
			fout.write(reinterpret_cast<char*>(&in), sizeof(inventory));
			fout.close();
		}
};
void pharmacistInit(int num, pharmacist* f){
	cout<<"Press 1 to give medicine"<<endl;
	cout<<"Press 2 to view Inventory"<<endl;
	cout<<"Press 3 to Order Medicines"<<endl;
	char cmd;
	cin>>cmd;
	if(cmd=='1'){
		int pat;
		pat=f->getPatient();
		patient* p=f->getPrescription(pat);
		f->updateInventory(p);
	}
	else if(cmd=='2')
		f->printInventory();
	else if(cmd=='3')
		f->orderMedicine();
	else cout<<"Invalid Input"<<endl;
}