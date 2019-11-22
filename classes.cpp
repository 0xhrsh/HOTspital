#include <bits/stdc++.h>
using namespace std;


// typedef struct Doctor{
	
// }doctor;

class doctor{
public:
	int id;
	char name[15];
	char speciality[15];
	bool available;
	vector<int> patientQ();
	Doctor();		
};

class patient{
protected:
	int PhNum[10];
	int emergency[10];
	//prescription p;
public:
	int name;
	string LDAP;
	patient(){};
	int chooseDoctor(){
		doctor d;
		ifstream fin;
		fin.open("admin/records/doctors.txt");
		for (int i = 0; i < 10; ++i){
			fin.read(reinterpret_cast<char*>(&d), sizeof(doctor));
			if(d.available)
				cout<<d.id<<" "<<d.name<<" "<<d.speciality<<endl;
		}
	}
	void takeAppointment(int num){
		cout<<"Enter Id to choose doctor"<<endl;
		chooseDoctor();
		int ind;
		cin>>ind;
		doctor d;
		ifstream fout;
		fout.open("admin/records/doctors.txt");
		//addToQueue(num,ind);
		//d.patientQ.back();
		return;
	}
	void onlineDiscussion(int p){
		cout<<"OnlineDiscussion"<<endl;
		return;
	}
	//~patient();
	
};