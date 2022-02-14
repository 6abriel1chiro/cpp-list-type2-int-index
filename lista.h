#include "Nodo.h"

template<class T>
class Lista
{
private:
	Nodo<T>* primer;
	Nodo<T>* ultimo;
public:
	Lista();
	~Lista();
	void addFront(T* dato);
	void addBack(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	void deleteBack();
	T* busquedaSecuencialNoRecursiva(T* dato);
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Nodo<T>* aux);
	T* menorLista(bool(*funcComp)(T*, T*));;
	T* buscarIesimaPosicion(int pos);
	void invertirSobreSiMisma();
	void invertirOtraLista();
};

template<class T>
Lista<T>::Lista()
{
	primer = NULL;
	ultimo = NULL;
}

template<class T>
Lista<T>::~Lista()
{
	Nodo<T>* segundo;
	while (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete primer;
			ultimo = NULL;
			primer = NULL;
		}
		else
		{
			segundo = primer->getSiguiente();
			delete primer;
			primer = segundo;
			//primer->anterior=NULL;
			primer->crearAnterior(NULL);
		}
	}
}

//primera manera
template<class T>
void Lista<T>::addBack(T* dato)
{
	
	if (primer == NULL && ultimo == NULL)
	{
		primer = new Nodo<T>(dato);
		ultimo = primer;
	}
	else
	{
		Nodo<T>* aux = primer;
		primer = new Nodo<T>(dato);
		primer->crearSiguiente(aux);
		aux->crearAnterior(primer);
	}
}


//segunda manera
template<class T>
void Lista<T>::addFront(T* dato)
{
	if (primer == NULL)
	{
		primer = new Nodo<T>(dato);
		ultimo = primer;
	}
	else
	{
		Nodo<T>* aux = ultimo;
		ultimo = new Nodo<T>(dato);
		ultimo->crearAnterior(aux);
		aux->crearSiguiente(ultimo);
	}
}

template<class T>
void Lista<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Nodo<T>* aux = primer;
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			aux = aux->getSiguiente();
		}
	}
}

template<class T>
void Lista<T>::deleteBack()
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Nodo<T>* aux = primer->getSiguiente();
		delete primer;
		primer = aux;
		primer->crearAnterior(NULL);
	}
}

template<class T>
void Lista<T>::deleteFront()
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Nodo<T>* aux = ultimo->getAnterior();
		delete ultimo;
		ultimo = aux;
		ultimo->crearSiguiente(NULL);
	}
}

template<class T>
T* Lista<T>::busquedaSecuencialNoRecursiva(T* dato)
{
	Nodo<T>* aux = primer;
	T* datoEncontrado = NULL;
	while (aux != NULL)
	{
		if (*aux->getDato() == dato)
		{
			datoEncontrado=aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}


template<class T>
T* Lista<T>::busquedaSecuencialRecursiva(T* dato)
{
	Nodo<T>* aux = primer;
	return buscarRecursivamente(dato, aux);
}

template<class T>
T* Lista<T>::buscarRecursivamente(T* dato, Nodo<T>* aux)
{
	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getDato() == dato)
		{
			return aux->getDato();
		}
		else
		{
			return buscarRecursivamente(dato, aux->getSiguiente());
		}
	}
}

template<class T>
T* Lista<T>::menorLista(bool (*funcComp)(T*, T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	T* menor = primer->getDato();
	Nodo<T>* aux = primer->getSiguiente();

	while (aux == NULL)
	{
		if ((*funcComp)(aux->getDato(), menor) == false)
		{
			menor = aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return menor;
}


template<class T>
T* Lista<T>::buscarIesimaPosicion(int pos)
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	Nodo<T>* aux = primer;
	T* datoEncontrado = NULL;
	int cont = 0;
	while (aux != NULL)
	{
		if (pos == cont)
		{
			datoEncontrado = aux->getDato();
		}
		cont++;
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}

template<class T>
void intercambiar(Nodo<T>* a, Nodo<T>* b)
{
	T* aux = a->getDato();
	a->setDato(b->getDato());
	b->setDato(aux);
}

template <class T>
void Lista<T>::invertirSobreSiMisma()
{
	Nodo<T>* i = primer;
	Nodo<T>* j = ultimo;

	int tam=0;
	Nodo<T>* aux = primer;
	while (aux != NULL)
	{
		aux = aux->getSiguiente();
		tam += 1;
	}

	int cont = 0;
	while (i != j)
	{
		intercambiar((i), (j));
		i=	i->getSiguiente();
		j = j->getAnterior();
		cont += 1;
	}
}
