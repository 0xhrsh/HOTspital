#include <bits/stdc++.h>
using namespace std;

typedef struct Doctor{
	int medicineID[10];
	int quantity[10];
}doctor;


class patient{
protected:
	int PhNum[10];
	int emergency[10];
	prescription p;
	sqlite3* records;
public:
	int name;
	string LDAP;
	patient();
	int chooseDoctor(){
		ifstream fin;
		fin.open("admin/doctors.txt");
		
		int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
    	if (rc != SQLITE_OK) 
        	cerr << "Error SELECT" << endl; 
    	else{ 
        	cout << "Operation OK!" << endl; 
    	} 

	}
	//~patient();
	
};



int main(){
	patient harsh;
	harsh.chooseDoctor()

    	
	return 0;
}