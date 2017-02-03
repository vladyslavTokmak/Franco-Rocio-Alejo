/*
  Id.Programa: Crear archivo binario
  Autor......: Vladyslav Tokmak
  Fecha......: Febrero-2017
  Comentario.: Creacion de archivo de Datos.bin
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<iomanip>
#include <iostream>

using namespace std;

struct StructDatos {
	int c1,
        c2,
    	c3;
};

void ObtDatos(StructDatos &);

int main() {
	FILE *Datos = fopen("Datos.bin","wb+");;
	StructDatos sDatos;

	ObtDatos(sDatos);
	
	while(sDatos.c1) {
		fwrite(&sDatos,sizeof(sDatos),1,Datos);
		ObtDatos(sDatos);
	}
	
	
	fseek(Datos,0,SEEK_SET);
	cout<< endl << setw(9) << "c1" << setw(10) << "c2" << setw(10) << "c3" <<endl<<endl;
	while(fread(&sDatos,sizeof(sDatos),1,Datos)){
		cout<< setw(9) << sDatos.c1 << " " << setw(9) << sDatos.c2 << " " << setw(9) << sDatos.c3 << endl;	
	}
	fclose(Datos);
}

void ObtDatos(StructDatos &rDatos) {

	cout << "Introduzca el c1: ";
	cin >> rDatos.c1;
	if (rDatos.c1) {
		do {
			cout << "c2: ";
			cin >> rDatos.c2;
		}
		while (rDatos.c2 == 0);
		do {
			cout << "c3: ";
			cin >> rDatos.c3;
		}
		while (rDatos.c3 == 0);
	}
} 

