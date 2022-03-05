#include "ListAnimales.h"





listAnimales::listAnimales(int len)
{
	first = -1;
	last = -1;
	animales = new Animal* [len];
	this->len = len;

	for (int i = 0; i < len; i++)
	{
		animales[i] = new Animal;
	}

}

listAnimales::~listAnimales()
{
	for (int i = 0; i < len; i++)
	{
		delete animales[i];
	}
	delete[] animales;
}

void listAnimales::insertBack(Animal* animal)
{
	if (first == -1 && last == -1)
	{
		first = len / 2;
		last = first;
		animales[first] = animal;
	}
	else
	{
		if (first - 1 == last || (first == 0 && last == len - 1))
		{
			cout<<"lista llena"; 
		}
		else
		{
			if (last < len - 1)
			{
				last++;
			}
			else
			{
				last = 0;
			}
			animales[last] = animal;
		}
	}
}

void listAnimales::insertFront(Animal* animal)
{
	if (first == -1 && last == -1)
	{
		first = len / 2;
		last = first;
		animales[first] = animal;
	}
	else
	{
		if (first - 1 == last || (first == 0 && last == len - 1))
		{
			cout << "llena" << endl;  //con lista llena
		}
		else
		{
			if (first > 0)
			{
				first--;
			}
			else
			{
				first = len - 1;
			}
			animales[first] = animal;
		}
	}

}

void listAnimales::insertFront2(Animal animal)
{

	
		if (first == -1 && last == -1)
		{
			first = len / 2;
			last = first;
			*animales[first] = animal;
		}
		else
		{
			if (first - 1 == last || (first == 0 && last == len - 1))
			{
				cout << "llena" << endl;  //con lista llena
			}
			else
			{
				if (first > 0)
				{
					first--;
				}
				else
				{
					first = len - 1;
				}
				*animales[first] = animal;
			}
		}

	
}

void listAnimales::deleteFront()
{

	if (first == -1 && last == -1)
	{
		cout << "lista vacia" << endl;//lista vacia
	}
	else
	{
		if (first == last)
		{
			first = -1;
			last = -1;
		}
		else
		{
			if (first < len - 1)
			{
				first++;
			}
			else
			{
				first = 0;
			}
		}
	}
}

void listAnimales::deleteBack()
{
	if (first == -1 && last == -1)
	{
		cout << "lista vacia" << endl;//lista vacia
	}
	else
	{
		if (first == last)
		{
			first = -1;
			last = -1;
		}
		else
		{
			if (last > 0)
			{
				last--;
			}
			else
			{
				last = len - 1;
			}
		}
	}

}

Animal* listAnimales::recorrdioRecursivo( int aux, Animal* animal)
{
	if (aux == last + 1)
	{
		return NULL;
	}
	else
	{
		if ((*animales[aux]).getNombre() == animal->getNombre())
		{
			return animales[aux];
		}
		else
		{
			if (aux < len - 1)
			{
				return recorrdioRecursivo(aux + 1, animal);
			}
			else
			{
				return recorrdioRecursivo(0, animal);
			}
		}
	}
	
}
Animal* listAnimales::findRec(Animal* animal)
{
	return recorrdioRecursivo(first, animal);
}

Animal* listAnimales::findNotRec(Animal* animal)
{
	int aux = first;
	while (aux != last)
	{
		if (animal->getNombre() == animales[aux]->getNombre())
		{
			return animales[aux];
		}
		if(aux==len-1)
		{
			aux = 0;
		}
		else
		{
			aux++;
		}
	}
	return nullptr;

}

void listAnimales::mostrar()
{
	int aux = first;
	while (aux != last)
	{
		animales[aux]->mostrar();
		if (aux==len-1)
		{
			aux = 0;
		}
		else
		{
			aux++;
		}
	}
}



Animal* listAnimales::mayorLista()
{
	Animal* mayor = animales[first];
	int i = first;
	while (i != last)
	{
		if (animales[i]->getNum()>mayor->getNum())
		{
			mayor = animales[i];
		}

		if (i == len - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return mayor;
}