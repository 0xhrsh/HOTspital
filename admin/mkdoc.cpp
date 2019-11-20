#include <iostream>  
#include <string> 
#include <bits/stdc++.h>
using namespace std; 
typedef struct doctor
{
	int id;
	char name[15];
	char speciality[15];
	//deque <int> patient;
	bool available;
}doc;
int main(int argc, char** argv){ 
	doc d;
	ofstream fout;
	fout.open("records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		d.id=i+1;
		d.patient.push_back(i+1);
		string temp="test";
		strcpy(d.name,temp.c_str());
		//d.name[4]='\0';
		string speciality;
		if(i%3==0)
			speciality="Bones";
		else if(i%3==1)
			speciality="Skin";
		else
			speciality="ENT";
		strcpy(d.speciality,speciality.c_str());
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
