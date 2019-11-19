#include <iostream>  
#include <string> 
#include <bits/stdc++.h>
using namespace std; 
typedef struct doctor
{
	int id;
	char name[15];
	char speciality[5];
	//queue <int> patient;
	bool available;
}doc;
int main(int argc, char** argv){ 
	doc d;
	ofstream fout;
	fout.open("records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		d.id=i+1;
		string temp="test";
		strcpy(d.name,temp.c_str());
		d.name[4]='\0';
		if(i%3==0){
			d.speciality[0]='S';
			d.speciality[1]='k';
			d.speciality[2]='i';
			d.speciality[3]='n';
		}

		else if(i%3==1){
			d.speciality[0]='B';
			d.speciality[1]='o';
			d.speciality[2]='n';
			d.speciality[3]='e';
		}
		else{
			d.speciality[0]='E';
			d.speciality[1]='n';
			d.speciality[2]='t';
			d.speciality[3]='s';
		}
		d.speciality[4]='\0';
		if(i%2)
			d.available=false;
		else
			d.available=true;
		fout.write(reinterpret_cast<char*>(&d), sizeof(doc));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	ifstream fin;
	fin.open("records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		fin.read(reinterpret_cast<char*>(&d), sizeof(doc));
		if(d.available)
		cout<<d.name<<" "<<d.id<<" "<<d.speciality<<endl;
	}

	
	
	return (0); 
} 
