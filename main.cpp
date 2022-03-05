

#include "ListAnimales.h"
#include <fstream>




void insertFromFile()
{


	//Animal *animal = new Animal("Animal", 1);

	string filename("10000_Numero.txt");
	int number;
	listAnimales listaAnimalesConNum(10002);
	ifstream file;
	file.open(filename);
	while (!file.eof())
	{
		file >> number;
		listaAnimalesConNum.insertFront(new Animal("Animal", number));

	}

	listaAnimalesConNum.mostrar();
	cout << "mayor"<<endl;
	cout<<listaAnimalesConNum.mayorLista()->getNum();





}

void insertFromFile2()
{


	Animal animal ("Animal", 1);

	string filename("10000_Numero.txt");
	int number;
	listAnimales listaAnimalesConNum(15000);
	ifstream file;
	file.open(filename);
	while (!file.eof())
	{
		file >> number; 
		
		animal.setPeso(number);
		listaAnimalesConNum.insertFront2(animal);

	} 

	listaAnimalesConNum.mostrar();
	cout << "mayor" << endl;
	cout << listaAnimalesConNum.mayorLista()->getNum();


}

void test2()
{
	
	listAnimales lista(50);
	Animal* perro;
	Animal* gato;
	Animal* tortuga;
	Animal* pez;
	perro = new Animal("perro",3);

	gato = new Animal("gato",2);

	tortuga = new Animal("tortuga",1);

	pez = new Animal("pez",5);
	lista.insertFront(perro);
	lista.insertFront(gato);
	lista.insertBack(tortuga);
	lista.insertBack(pez);

	lista.mostrar();

	lista.deleteFront();
	lista.deleteBack();
	cout << "despues de eliminar" << endl;
	lista.mostrar();


	cout << "buscamos perro" << endl;

	lista.findNotRec(new Animal("perro"))->mostrar();
	cout << "buscamos perro recursivamete" << endl;

	lista.findRec(new Animal("perro"))->mostrar();




}
int main()
{
	insertFromFile2();
}





