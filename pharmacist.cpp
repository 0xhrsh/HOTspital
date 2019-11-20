#include <bits/stdc++.h>

using namespace std;

class pharmacist
{
	string pres(string pat)
	{	
		ifstream fin;
		fin.open("admin/records.txt");
		string str,pre;
		do
		{
			
			// getline(fin,str);
			if(str[0]==pat[0] && str[1]==pat[1] && str[2]==pat[2])  // !!! patient's id is assumed to be in the first column of record
			{
				// patient's prescription must be at the end and in the format: "pres: ......"	
				size_t pos=str.find("pres:");
				pre=str.substr(pos);
				break;

			}
		}while(getline(fin,str));
		return pre;

	}
	public:
	string getPatient()
	{
		string pat;
		cout << "enter the patient's ID:";
		cin >> pat;	
		return pat;
	}
	string getPrescription(string pat)
	{
		return pres(pat);
	}

};
void pharmacistInit(int num)
{
	cout << "this is pharmacist" << endl;
}
int main()
{
	pharmacist ph;
	string patient=ph.getPatient();
	string pres=ph.getPrescription(patient);
	

}