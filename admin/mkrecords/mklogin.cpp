#include <bits/stdc++.h>
using namespace std;
typedef struct login{
	char role;
	char pass[20];
	int num;
	
}login;
int main(){
	ofstream fout;
	login l;
	fout.open("../records/login.txt");
	for (int i = 0; i < 20; ++i){
		l.role='P';
		l.pass[0]=l.role;
		l.pass[1]=(i+1)/10+'0';
		l.pass[2]=(i+1)%10+'0';
		l.pass[3]='\0';
		l.num=i+1;
		fout.write(reinterpret_cast<char*>(&l), sizeof(login));
	}
	for (int i = 0; i < 20; ++i){
		l.role='D';
		l.pass[0]=l.role;
		l.pass[1]=(i+1)/10+'0';
		l.pass[2]=(i+1)%10+'0';
		l.pass[3]='\0';
		l.num=i+1;
		fout.write(reinterpret_cast<char*>(&l), sizeof(login));
	}
	for (int i = 0; i < 10; ++i){
		l.role='F';
		l.pass[0]=l.role;
		l.pass[1]=(i+1)/10+'0';
		l.pass[2]=(i+1)%10+'0';
		l.pass[3]='\0';
		l.num=i+1;
		fout.write(reinterpret_cast<char*>(&l), sizeof(login));
	}

	for (int i = 0; i < 10; ++i){
		l.role='R';
		l.pass[0]=l.role;
		l.pass[1]=(i+1)/10+'0';
		l.pass[2]=(i+1)%10+'0';
		l.pass[3]='\0';
		l.num=i+1;
		fout.write(reinterpret_cast<char*>(&l), sizeof(login));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)


	ifstream fin;
	fin.open("../records/login.txt");
	for (int i = 0; i < 60; ++i){
		fin.read(reinterpret_cast<char*>(&l), sizeof(login));
		cout<<l.role<<l.num<<" "<<l.pass<<endl;
	}

	
	return 0;
}