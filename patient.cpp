#include <bits/stdc++.h>
//#include "admin/updateQueue.cpp"
#include "admin/classes/Pclass.cpp"
void error(int num){
	num++;
	cout<<endl<<"Invalid Input"<<endl;
}
void patientInit(int num,patient* p){
	//patient p;
	p->LDAP=num;
	while(true){
	char x;
	cout<<endl<<"Press 1 to Take appointment"<<endl;
	cout<<"Press 2 for online discussion"<<endl;
	cout<<"Press 3 to logout"<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	cin>>x;
	//cout<<cmd<<endl;
	int cmd=x-'0';
	//patient p;
	switch(cmd){
		case 1:{p->takeAppointment(num);break;}
		case 2:{p->onlineDiscussion(num);break;}
		case 3:{cout<<"Logged Out"<<endl;return;}
		default: cout<<"Invalid Value"<<endl;
	}
}
}

