#include <bits/stdc++.h>
using namespace std;
int num(char* n){
	if(*(n+1))
		return (*n-'0')*10 + *(n+1)-'0';
	else
		return *n-'0';
}

typedef struct login{
	char role;
	char pass[20];
	int num;
}login;
int main(){
	ifstream fin;
	fin.open("admin/login.txt");
	char username[20],password[20];
	cout<<"Enter login username"<<endl;
	cin>>username;
	cout<<"Enter Password"<<endl;
	cin>>password;
	login l;
	bool flag=true;
	while(true){
		if(fin.read(reinterpret_cast<char*>(&l), sizeof(login))==0){
			flag=false;
			break;
		}
		if(l.role==username[0]&&num(username+1)==l.num){
			if (strcmp(password,l.pass)==0){
				cout<<"Logging in..";
				break;
			}
			else{
				flag=false;
				break;
			}
		}
	}
	if(flag)
		cout<<endl;
		// do something;
	else
		cout<<"Invalid details"<<endl;	
	return 0;
}