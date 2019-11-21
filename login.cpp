#include <bits/stdc++.h>
#include "patient.cpp"
//#include "doctor.cpp"
//#include "pharmacist.cpp"
using namespace std;
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
int main(){
	
	// if(){
	// 	cout<<"Database does not exist"<<endl;
	// 	return -1;
	// }
	while(true){
	ifstream fin;
	fin.open("admin/records/login.txt");
	char username[20],password[20];
	cout<<"Enter Login Username"<<endl;
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
		//cout<<"You are a "<<l.role<<endl;
		switch(l.role){
			case 'D': {doctor* d=new doctor();doctorInit(l.num,d);break;}
			case 'P': {patient* p=new patient();patientInit(l.num,p);break;}
			
			//case 'F': {pharmacistInit(num);break;}
			//case 'R': {receptionistInit(num);break;}
			default: cout<<"Error: Executable not found"<<endl;
		}
	}
	else
		cout<<"Invalid details"<<endl;	
}
	return 0;
}