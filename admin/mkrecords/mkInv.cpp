#include <bits/stdc++.h>
using namespace std;
typedef struct Inventory{
	int medicineId;
	int Quantity;
}inventory;
int main(){
	ofstream fout;
	inventory inv;
	fout.open("../records/inventory.txt");
	for (int i = 0; i < 20; ++i){
		inv.medicineId=i+1;   //  Anything Random
		inv.Quantity=(i+1)*100;  //  Random
		fout.write(reinterpret_cast<char*>(&inv), sizeof(inventory));
	}
	fout.close();

	// The code below is to read the info (I made this to verify
	// 	whether the above code works fine or not)

	ifstream fin;
	fin.open("../records/inventory.txt");
	for (int i = 0; i < 20; ++i){
		fin.read(reinterpret_cast<char*>(&inv), sizeof(inventory));
		cout<<inv.medicineId<<" "<<inv.Quantity<<endl;
	}

	
	return 0;
}