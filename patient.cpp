#include <bits/stdc++.h>
#include <sqlite3.h>
using namespace std;


sqlite3* doctors;
typedef struct Prescription{
	int medicineID[10];
	int quantity[10];
}prescription;

static int callback(void* data, int argc, char** argv, char** azColName){ 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 
  	

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
		int doc=0;
		doc = sqlite3_open("/admin/doctors.db", &doctors);
		string data("CALLBACK FUNCTION");
		string sql("SELECT * FROM PERSON;");
		if(doc){
			std::cerr<<"Error in Opening Doctor's database"<<endl;
			return -1;
		}
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