#include <iostream>

//Declaración de la plantilla Pila

template <class T, int nE1 = 100>
class Pila{
    private:
        T datos[nE1];
        int nElementos;
        int totalElementos;
    public:
        // Constructor
        Pila():nElementos(0){};
        Pila(T nelem):totalElementos(nelem), nElementos(0)
            {
                for (T i=0;i < totalElementos; i++)
                    Poner(5);
            }

        //añade un elemento a la pila
        void Poner(T elem);

        //obtener y borrar un elemento de la pila
        T Quitar();

        //obtener un numero de elementos
        int num_elementos();

        //está la pila vacia?? booleano para verificar
        bool Vacia();

        //está la pila llena?? booleano para verificar
        bool Llena();

        //muestra el elemento
        T getElem(int index);
};

//Implementación de la plantilla Pila
template <class T, int nE1>
void Pila <T, nE1> :: Poner(T elem){
    if (nElementos < nE1){
        datos[nElementos] = elem;
        nElementos++;
    }
    else
        std::cout << "Pila llena" << std::endl;
}

template <class T, int nE1>
T Pila<T, nE1>::Quitar(){
    if (nElementos > 0){
        nElementos--;
        return datos[nElementos];
    }
    else
        std::cout << "la pila esta vacia" << std::endl;
    return 0;
}

template <class T, int nE1>
int Pila<T, nE1>::num_elementos(){
    return nElementos;
}

template <class T, int nE1>
bool Pila<T, nE1>::Vacia(){
    return (nElementos == 0); 
}

template <class T, int nE1>
bool Pila<T, nE1>::Llena(){
    return (nElementos == nE1);
}

template <class T, int nE1>
T Pila<T, nE1>::getElem(int index){
    return datos[index];
}

int main(){
    //pila de enteros
    Pila<int, 6> p1;
    p1.Poner(6);
    p1.Poner(12);
    p1.Poner(18);

    std::cout << "Número de elementos : " << p1.num_elementos() << std::endl;
    std::cout << "Quitar 1 : " << p1.Quitar() << std::endl;
    std::cout << "Quitar 2 : " << p1.Quitar() << std::endl;
    std::cout << "Quitar 3 : " << p1.Quitar() << std::endl;
    std::cout << "Número de elementos : " << p1.num_elementos() << std::endl;

 // Pila de enteros largos
 Pila <long,6> p2;
 p2.Poner(60000L);
 p2.Poner(1000000L);
 p2.Poner(2000000L);
 std::cout << "Número de elementos :" << p2.num_elementos() << std::endl;
 std::cout << "Quitar 1 :" << p2.Quitar() << std::endl;
 std::cout << "Quitar 2 :" << p2.Quitar() << std::endl;
 std::cout << "Quitar 3 :" << p2.Quitar() << std::endl;
 std::cout << "Número de elementos :" << p2.num_elementos() << std::endl;
 Pila <double,6> p3;
 p3.Poner(6.6);
 p3.Poner(12.12);
 p3.Poner(18.18);
 std::cout << "Número de elementos :" << p3.num_elementos() << std::endl;
 std::cout << "Quitar 1 :" << p3.Quitar() << std::endl;
 std::cout << "Quitar 2 :" << p3.Quitar() << std::endl;
 std::cout << "Quitar 3 :" << p3.Quitar() << std::endl;
 std::cout << "Número de elementos :" << p3.num_elementos()<< std::endl;

    return 0;
}