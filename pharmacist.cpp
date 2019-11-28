#include <bits/stdc++.h>
#include "admin/classes/Fclass.cpp"
#include"patient.cpp"
typedef struct Inventory{
	int medicineId;
	int Quantity;
}inventory;
	

void updateInventory(patient* p){
	ifstream fin;
	ofstream fout;
	inventory in;
	fin.open("admin/records/inventory.txt");
	fout.open("admin/records/tempFiles/tempInventory.txt");
	//cout<<fin.read(reinterpret_cast<char*>(&in), sizeof(inventory))<<endl;
	while(fin.read(reinterpret_cast<char*>(&in), sizeof(inventory))){
		int i=-1;
		while(p->medicine[++i][0])
			if(p->medicine[i][0]==in.medicineId){
				cout<<"Medicines given by doctor Id and quantity are "<<p->medicine[i][0]<<" "<<p->medicine[i][1]<<endl;
				(in.Quantity)-=p->medicine[i][1];
				break;
			}
		fout.write(reinterpret_cast<char*>(&in), sizeof(inventory));
	}
	fin.close();fout.close();
	fin.open("admin/records/tempFiles/tempInventory.txt");
	fout.open("admin/records/inventory.txt");
	while(fin.read(reinterpret_cast<char*>(&in), sizeof(inventory)))
		fout.write(reinterpret_cast<char*>(&in), sizeof(inventory));
	fin.close();fout.close();
}


class pharmacist: public patient{
	public:
		int LDAP;
		patient* getPrescription(int pat){
			patient* p1=new patient();
			ifstream fin;
			fin.open("admin/records/records.txt");
			while(fin.read(reinterpret_cast<char*>(p1), sizeof(patient))){	
				if(p1->LDAP==pat){
					cout<<"Patient's LDAP is "<<pat<<endl;
					return p1;
				}
		}
	}
	void printInventory(){
		ifstream fin;
		inventory in;
		fin.close();
		fin.open("admin/records/inventory.txt");
		while(fin.read(reinterpret_cast<char*>(&in), sizeof(inventory)))
			cout<<"Medicine Id: "<<in.medicineId<<" Quantity: "<<in.Quantity<<endl;
		fin.close();
	}
	void orderMedicine(){
		inventory in;
		cout<<"Enter Medicine ID and Quantity:"<<endl;
		cin >> in.medicineId >> in.Quantity;
		ofstream fout;
		fout.open("admin/records/orderMedicine.txt",ios_base::app);
		fout.write(reinterpret_cast<char*>(&in), sizeof(inventory));
		fout.close();
	}
};
void pharmacistInit(int num, pharmacist* f){
	while(true){

		cout<<"Press 1 to give medicine"<<endl;
		cout<<"Press 2 to view Inventory"<<endl;
		cout<<"Press 3 to Order Medicines"<<endl;
		cout<<"Press 4 to log out"<<endl;

		char cmd='0';
		cin>>cmd;
		if(cmd=='1'){
			cout<<"Enter the patient's LDAP (example: P10)"<<endl;
			int id;
			char cmd[4];
			cin>>cmd;
			if(cmd[2]=='\0'){
				//cout<<"NotHere";
				id=cmd[1]-'0';
			}
			else{
				//cout<<"Here";
				id=(cmd[1]-'0')*10+cmd[2]-'0';
			}
			patient* p=f->getPrescription(id);
			int i=-1;
			// while(p->medicine[++i][0])
			// 	cout<<p->medicine[i][0]<<" "<<p->medicine[i][1]<<endl;
			updateInventory(p);
			cout << "medicines given to " << id << endl;
		}
		else if(cmd=='2')
			f->printInventory();
		else if(cmd=='3'){
			f->orderMedicine();
			cout << "Order Recieved" << endl ;
		}
		else if(cmd=='4')
			return;
		else cout<<"Invalid Input"<<endl;
	}
}