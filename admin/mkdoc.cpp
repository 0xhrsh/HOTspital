#include <iostream>  
#include <string> 
#include <bits/stdc++.h>
using namespace std; 
typedef struct doctor
{
	int id;
	string name;
	string speciality;
	queue <int> patient;
	bool available;
}doc;
int main(int argc, char** argv){ 
	doc d;
	ofstream fout;
	fout.open("records/doctors.txt");
	for (int i = 0; i < 10; ++i){
		d.id=i+1;
		d.name="test";
		if(i%3==0)
			d.speciality="Skin";
		else if(i%3==1)
			d.speciality="Bones";
		else
			d.speciality="ENT";
		if(i%2)
			d.available=false;
		else
			d.available=true;
		fout.write(reinterpret_cast<char*>(&d), sizeof(doc));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	// ifstream fin;
	// fin.open("records/doctors.txt");
	// for (int i = 0; i < 10; ++i){
	// 	fin.read(reinterpret_cast<char*>(&d), sizeof(doc));
	// 	cout<<d.name<<" "<<d.id<<" "<<d.available<<endl;
	// }

	
	
	return (0); 
} 
