#include <bits/stdc++.h>

using namespace std;

class pharmacist
{

};
void pharmacistInit(int num)
{
	cout << "this is pharmacist" << endl;
}
int main()
{
	ifstream fin;
	string pat;
	cout << "enter the patient's ID:";
	cin >> pat;
	fin.open("admin/records.txt");
	string str;
	do
	{
		
		getline(fin,str);
		if(str[0]==pat[0] && str[1]==pat[1] && str[2]==pat[2])  // !!! patient's id is assumed to be in the first column of record
		{
			// patient's prescription must be at the end and in the format: "pres: ......"	
			size_t pos=str.find("pres:");
			string pres=str.substr(pos);
			break;

		}
	}while(getline(fin,str));



}