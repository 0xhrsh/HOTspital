#include <bits/stdc++.h>

#include "admin/Dclass.cpp"

/*void error(int num){
	num++;
	cout<<"Invalid Input"<<endl;
}*/


void doctorInit(int num,doctor* d){
	while(true){
	char x;
	cout<<"Press 1 to Treat patients"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to logout"<<endl;
     
	cin>>x;
	
	int cmd=x-'0';
	
	switch(cmd){
		case 1:{d->treatPatients();break;}
		case 2:{d->onlineDiscussion(num);break;}
		case 3:{cout<<"Logged Out"<<endl;return;}
		default: cout<<"Invalid Value"<<endl;
	}
}
}