#include <bits/stdc++.h>
#include "../classes/Pclass.cpp"
using namespace std;
int main(){
	ofstream fout;
	patient* p=new patient();
	fout.open("../records/records.txt");
	for (int i = 0; i < 20; ++i){
		p->setPh(10*i+5);   //  Anything Random
		p->setEm(i*100);  //  Random
		string fname="abc";
		string lname="xyz";
		strcpy(p->fname,fname.c_str());
		strcpy(p->lname,lname.c_str());
		p->record[0]='\0';
		//p->lname="xyz";
		p->LDAP =i+1;
		//cout<<p->fname<<" "<<p->LDAP<<endl;
		fout.write(reinterpret_cast<char*>(p), sizeof(patient));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	patient* p1=new patient();
	ifstream fin;
	fin.open("../records/records.txt", ios::in);
	for (int i = 0; i < 20; ++i){
		fin.read(reinterpret_cast<char*>(p1), sizeof(patient));
		cout<<p1->fname<<" "<<p1->LDAP<<endl;
	}	
	
	return 0;
}