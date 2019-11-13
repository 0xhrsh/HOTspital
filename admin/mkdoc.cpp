#include <iostream> 
#include "sqlite3.h" 
#include <string> 

using namespace std; 

static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
	int i; 
	fprintf(stderr, "%s: ", (const char*)data); 

	for (i = 0; i < argc; i++) { 
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
	} 

	printf("\n"); 
	return 0; 
} 


int main(int argc, char** argv) 
{ 
    sqlite3* DB; 
    std::string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "Specialization char(10)     NOT NULL, "; 
    int exit = 0; 
    exit = sqlite3_open("doctors.db", &DB); 
    char* messaggeError; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
  
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Create Table" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Table created Successfully" << std::endl; 
    sqlite3_close(DB); 
	//sqlite3* DB; 
	//char* messaggeError; 
	exit = sqlite3_open("doctors.db", &DB); 
	string query = "SELECT * FROM PERSON;"; 

	cout << "STATE OF TABLE BEFORE INSERT" << endl; 

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 

	string sql1("INSERT INTO PERSON VALUES(1, 'doc1', 'Heart');"
			"INSERT INTO PERSON VALUES(2, 'doc2', 'Skin');"
			"INSERT INTO PERSON VALUES(3, 'doc3', 'Sex');"); 

	exit = sqlite3_exec(DB, sql1.c_str(), NULL, 0, &messaggeError); 
	if (exit != SQLITE_OK) { 
		std::cerr << "Error Insert" << std::endl; 
		sqlite3_free(messaggeError); 
	} 
	else
		std::cout << "Records created Successfully!" << std::endl; 

	cout << "STATE OF TABLE AFTER INSERT" << endl; 

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 

	// sql = "DELETE FROM PERSON WHERE ID = 2;"; 
	// exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
	// if (exit != SQLITE_OK) { 
	// 	std::cerr << "Error DELETE" << std::endl; 
	// 	sqlite3_free(messaggeError); 
	// } 
	// else
	// 	std::cout << "Record deleted Successfully!" << std::endl; 

	// cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl; 
	// sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 

	sqlite3_close(DB); 
	return (0); 
} 
