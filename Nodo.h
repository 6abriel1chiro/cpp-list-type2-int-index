#include <iostream> 
using namespace std;

template <typename T>
class Nodo{

    public :
    T dato;
    Nodo *first;
    Nodo *last;
    Nodo(T dato)
    {
        this->dato=dato;
    }

};

