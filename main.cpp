#include <vector>
#include "Vector/vector.hpp"
#include "Stack/stack.hpp"
#include <iostream>
#include <cmath>
#include <string>

int main(){

  //Pruebas con el contenedor stack
  //ft::stack<int> pila1;
  ft::stack<int> pila2;
  ft::stack<int> pila1 = ft::stack<int>();

  std::cout << "\n========= push =============" << std::endl;
  std::cout << "Añadimos un elemento a pila1 con el metodo push de esta forma -->g@ pila1.push(5);" << std::endl;
  pila1.push(5);

  std::cout << "\n========= top =============" << std::endl;
  int value1 = pila1.top();
  std::cout << "El elemento de la pila1 es: " << value1 << std::endl;

  std::cout << "\n========= empty =============" << std::endl;
  std::string ret = pila1.empty() ? "True" : "False";
  std::cout << "El Objeto pila1 esta vacio: " << ret << std::endl;
  ret = pila2.empty() ? "True" : "False";
  std::cout << "El Objeto pila2 esta vacio: " << ret << std::endl;



    //ft::vector<int> v0; //inicializando un vector de tipo enteros vacio
    std::vector<int> v1(10); //inicializando un vector de tipo enteros vacio
    int x=15, y=100;
    std::vector<int> v2(x,y); //inicializando un vector de 15 elementos inicializados a 0
    std::vector<std::string> vector_de_cadena; //inicializando un vector de tipo string vacio

    std::cout << "\nNumero de elementos del vector v1: " << v1.size() << std::endl;
    std::cout << "Numero de elementos del vector v1: " << v2.size() << std::endl;
//    for (int i=0;i<v2.size();i++)
  //      std::cout << "Posicion v["<< i<< "] tiene el valor:" << v2[i] << std::endl;

    std::allocator<int> myAllocator;
    int *arr = myAllocator.allocate(5);
    myAllocator.construct(arr, 100);
    arr[3] = 10;
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;
    myAllocator.deallocate(arr, 5);

    std::allocator<std::string> myAllocator1;
    std::string *str = myAllocator1.allocate(3);
    myAllocator1.construct(str, "Geeks");
    myAllocator1.construct(str+1, "for");
    myAllocator1.construct(str+2, "Gekc");

    std::cout << str[0] << str[1] << str[2] << std::endl;

    myAllocator1.destroy(str);
    myAllocator1.destroy(str+1);
    myAllocator1.destroy(str+2);

    myAllocator1.deallocate(str, 3);


    return 0;
}