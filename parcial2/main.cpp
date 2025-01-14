// Sanchez Serantes, Juan Ignacio
// Legajo 86162
// Curso 2R1
// SEGUNDO PARCIAL DE INFORMATICA II 2021
#include <iostream>
#include "franquicia.h"
#include <iomanip>
#define TAM 100
using namespace std;
int main(){
	Franquicia tabla[TAM];
	int lastF = -1;
	int mostSold, index, mostQant;
	int tmpQant, indMost;
	int &refTmp = tmpQant;
	while(1){
		switch(menu()){
			case 1:
				cout << "Ingrese las cantidades pedidas de los 6 menues en orden: ";
				int c1, c2, c3, c4, c5, c6;
				cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6; 
				tabla[++lastF] = Franquicia(c1,c2,c3,c4,c5,c6);
				break;
			case 2:
				cout << setfill(' ') << setw(10) << "Franquicia\tMenu 1\tMenu 2\tMenu 3\tMenu 4\tMenu 5\tMenu 6" << endl;
				for(int i = 0; i <= lastF; i++){
					if(tabla[i].isSet()){
						cout << setw(10) << std::left << i+1 << "\t";
						tabla[i].mostrar();
						cout << endl;
					}
				}	
				
				mostSold = index = mostQant = 0;
				for(int i = 0; i <= lastF; i++){
					indMost = tabla[i].getBest(refTmp);
					if(tmpQant > mostQant){
						mostQant = tmpQant;
						mostSold = indMost;
						index = i + 1;
					}
				}

				cout << "El menu mas pedido es el Menu " << mostSold << " con " << mostQant << " unidades pedidas por la franquicia " << index << endl;
				break;
			
			case 3:
				cout << "Ingrese el indice de la franquicia a dar de baja: ";
				int baja;
				cin >> baja;
				tabla[baja - 1] = Franquicia(-1, -1, -1, -1, -1, -1);
				break;
			case 4:
				return 0;
		}	
	}
}
