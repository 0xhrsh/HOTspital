#include <bits/stdc++.h>
#include "pharmacist.cpp"
int num(char* n){
	if(*(n+1))
		return (*n-'0')*10 + *(n+1)-'0';
	else
		return *n-'0';
}
typedef struct login{
	char role;
	char pass[20];
	int num;
}login;
patient* writePrescription(patient* p){
		int med,quant;
		inventory ik;
		ifstream fin;
		fin.open("admin/records/inventory.txt");
		cout<<"Enter Medicine ID and Quantity: "<<endl;
		cin>>med>>quant;
		for (int i = 0; quant>0 && i<20;){
			fin.read(reinterpret_cast<char*>(&ik), sizeof(inventory));
			if(ik.Quantity>=quant){
				p->medicine[i][0]=med;
				p->medicine[i++][1]=quant;
			}
			cin>>med>>quant;
		return p;
	}
}
int main(){
	while(true){
	ifstream fin;
	fin.open("admin/records/login.txt");
	char username[20],password[20];
	cout<<endl<<"Enter Login Username"<<endl;
	cin>>username;
	cout<<"Enter Password"<<endl;
	cin>>password;
	login l;
	bool flag=true;
	while(true){
		if(fin.read(reinterpret_cast<char*>(&l), sizeof(login))==0){
			flag=false;
			break;
		}
		if(l.role==username[0]&&num(username+1)==l.num){
			if (strcmp(password,l.pass)==0){
				cout<<"Logging in..";
				break;
			}
			else{
				flag=false;
				break;
			}
		}
	}
	if(flag){
		cout<<endl;
		switch(l.role){
			case 'D': {doctor* d=new doctor();doctorInit(l.num,d);break;}
			case 'P': {patient* p=new patient();patientInit(l.num,p);break;}
			case 'F': {pharmacist* f=new pharmacist();pharmacistInit(l.num,f);break;}
			//case 'R': {receptionistInit(num);break;}
			default: cout<<"Error: Executable not found"<<endl;
		}
	}
	else
		cout<<"Invalid details"<<endl;	
}
	return 0;
}
