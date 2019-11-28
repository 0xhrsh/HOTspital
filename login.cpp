#include <bits/stdc++.h>
#include "pharmacist.cpp"
// #include <windows.h>
//#include "pass.cpp"
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
		
		cout<<"Enter Medicine ID and Quantity: "<<endl;
		cin>>med>>quant;
		for (int i = 0; quant>0 && i<20;){
			fin.open("admin/records/inventory.txt");
			while(fin.read(reinterpret_cast<char*>(&ik), sizeof(inventory)))
				if(ik.medicineId==med)
					break;
			fin.close();
			if(ik.Quantity>=quant){
				p->medicine[i][0]=med;
				p->medicine[i++][1]=quant;
			}
			else
				cout<<med<<" is insufficient"<<endl;
			cin>>med>>quant;
		}
		cout<<endl;
		cout<<"Enter Remarks: "<<endl;
		char dmarks[50];
		char x;
		scanf("%c",&x);
		fgets (dmarks, 55, stdin);
		string temp;
		//scanf ("%[^\n]%*c", dmarks);
		//cin>>dmarks;y
		strcpy(p->dRemarks,dmarks);
		
		temp=(string)p->record+(string)"\n"+(string)dmarks;
		strcpy(p->record,temp.c_str());
		return p;
}
int main(){
	while(true){
	cout<<"\n\n==================================================================\n";
	cout<<"                      WELCOME TO IITJ HC CENTER";
	cout<<"\n==================================================================\n";
	ifstream fin;
	fin.open("admin/records/login.txt");
	char username[20],password[20];
	cout<<endl<<"Enter Login Username : ";
	cin>>username;
	cout<<"Enter Password : ";
	cin>>password;
	// string pass=getpass("Enter Password: ",true);
	// strcpy(password,pass.c_str());
	login l;
	bool flag=true;
	while(true){
		if(fin.read(reinterpret_cast<char*>(&l), sizeof(login))==0){
			flag=false;
			break;
		}
		if(l.role==username[0]&&num(username+1)==l.num){
			if (strcmp(password,l.pass)==0){
				cout<<"\nLogging in....."<<endl;
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
			case 'R': {cout<<"\n===================  WELCOME RECEPTIONIST  ===============\n\n";receptionist* r=new receptionist();receptionistInit(l.num,r);break;}
			case 'D': {cout<<"\n======================  WELCOME DOCTOR  ====================\n\n";doctor* d=new doctor();doctorInit(l.num,d);break;}
			case 'P': {patient* p=new patient();patientInit(l.num,p);break;}
			case 'F': {cout<<"\n=====================  WELCOME PHARMACIST  =================\n\n";pharmacist* f=new pharmacist();pharmacistInit(l.num,f);break;}
			default: cout<<"  Error!!! \nExecutable not found"<<endl;
		}
	}
	else
		cout<<"ERROR!!!  Invalid details"<<endl;	
}
	return 0;
}
