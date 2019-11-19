#include <bits/stdc++.h>
using namespace std;

// typedef struct Doctor{
// 	int medicineID[10];
// 	int quantity[10];
// }doctor;


typedef struct Doctor{
	int id;
	char name[15];
	char speciality[5];
	//queue <int> patient;
	bool available;
}doctor;



class patient{
protected:
	int PhNum[10];
	int emergency[10];
	//prescription p;
	//sqlite3* records;
public:
	int name;
	string LDAP;
	patient();
	//~patient();
	
};
//patient p;
int chooseDoctor(){
	doctor d;
	ifstream fin;
	fin.open("admin/records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(&d), sizeof(doctor));
		if(d.available)
			cout<<d.name<<" "<<d.id<<" "<<endl;
	}
}
void error(int num){
	num++;
	cout<<"Invalid Input"<<endl;
}
void takeAppointment(int num){
	chooseDoctor();
	return;
}
void onlineDiscussion(int num){
	cout<<"onlineDiscussion"<<endl;
	return;
}

void patientInit(int num){
	// cout<<"Hello from the patient"<<endl;
	//p.LDAP=num;
	while(true){
	char x;
	cout<<"Press 1 to Take appointment"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to logout"<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	cin>>x;
	//cout<<cmd<<endl;
	int cmd=x-'0';
	switch(cmd){
		case 1:{takeAppointment(num);patientInit(num);break;}
		case 2:{onlineDiscussion(num);patientInit(num);break;}
		case 3:{cout<<"Logged Out"<<endl;return;}
		default: cout<<"Invalid Value"<<endl;
	}
}
}

