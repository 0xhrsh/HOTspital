#include <bits/stdc++.h>
using namespace std;

typedef struct Inventory{
	int medicineId;
	int Quantity;
}inventory;

int main(){
	inventory inv;
	ifstream fin;
	fin.open("admin/records/inventory.txt");
	for (int i = 0; i < 20; ++i){
		fin.read(reinterpret_cast<char*>(&inv), sizeof(inventory));
		cout<<inv.medicineId<<" "<<inv.Quantity<<endl;
	}

	
}