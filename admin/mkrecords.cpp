#include <bits/stdc++.h>
using namespace std;
typedef struct patient{
	long long ph;
	long long emergency;
	string record;
	string prescription;
	char role;
	int num;
	string fname;
	string lname;	
}pat;
int main(){
	ofstream fout;
	pat p;
	fout.open("records/records.txt",ios::app);
	for (int i = 0; i < 20; ++i){
		p.ph=10*i+5;   //  Anything Random
		p.emergency=i*100;  //  Random
		p.fname="abc";
		p.lname="xyz";
		p.role='P';  // Patient
		p.num =i+1;
		fout.write(reinterpret_cast<char*>(&p), sizeof(pat));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	// ifstream fin;
	// fin.open("records.txt");
	// for (int i = 0; i < 20; ++i){
	// 	fin.read(reinterpret_cast<char*>(&p), sizeof(pat));
	// 	cout<<p.ph<<" "<<p.emergency<<" "<<p.num<<endl;
	// }

	
	return 0;
}