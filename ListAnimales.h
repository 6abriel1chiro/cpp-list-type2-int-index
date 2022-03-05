
#pragma once
#define TAM 100
#include "Animal.h"
class listAnimales
{
private:
	int len;

	int first, last;
	Animal** animales;


public:


	listAnimales(int len);
	~listAnimales();

	void insertFront(Animal* animal);
	void insertFront2(Animal animal);
	void insertBack(Animal* animal);


	void deleteFront();
	void deleteBack();

	Animal* findRec(Animal* animal);
	Animal* recorrdioRecursivo(int aux, Animal* animal);
	Animal* findNotRec(Animal* animal);

	Animal* mayorLista();

	void mostrar();
		






};