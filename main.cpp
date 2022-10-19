#include <vector>
#include "Vector/vector.hpp"
#include "Stack/stack.hpp"
#include <iostream>
#include <cmath>
#include <string>


void reportStackSize(ft::stack<int>& s){
    std::cout << "El tamaño de la pila es: " << s.size() << std::endl;
}

void reportStackTop(ft::stack<int>& s){
  std::cout << "El elemento de la pila es: " << s.top() << std::endl;
}

int main(){

  //Pruebas con el contenedor stack
  ft::stack<int> pila1;
  ft::stack<int> pila2;
  ft::stack<int> pila3;

// ***********  PRUEBAS PARA EL CONTENEDOR STACK  ***********

  std::cout << "\n========= push =============" << std::endl; //prueba del metodo PUSH
  std::cout << "Añadimos un elemento a pila1 con el metodo push de esta forma --> pila1.push(5);" << std::endl;
  pila1.push(5);
  std::cout << "Creamos un objeto mystack vacio y agremos elementos con el metodo push" << std::endl;
  ft::stack<int> mystack;
  std::cout << "mystack: ";
  if (mystack.empty())
    std::cout << "está vacio" << std::endl;
  for (int i=0; i<5; ++i) 
    mystack.push(i);
  std::cout << "Después de añadir elementos" << std::endl;
  std::cout << "mystack contiene: ";
  while (!mystack.empty())
  {
    std::cout << ' ' << mystack.top();
    mystack.pop();
  }
  std::cout << '\n';
  

  std::cout << "\n========= top =============" << std::endl; //prueba del metodo TOP
  int value1 = pila1.top();
  std::cout << "El elemento de la pila1 es: " << value1 << std::endl;
  ft::stack<int> s;
  s.push(2);
  s.push(6);
  s.push(51);
  reportStackSize(s);
  reportStackTop(s);
  s.pop();
  reportStackSize(s);
  reportStackTop(s);

  std::cout << "\n========= empty =============" << std::endl; //prueba del metodo EMPTY
  std::string ret = pila1.empty() ? "True" : "False";
  std::cout << "El Objeto pila1 esta vacio: " << ret << std::endl;
  ret = pila2.empty() ? "True" : "False";
  std::cout << "El Objeto pila2 esta vacio: " << ret << std::endl;

  std::cout << "\n========= size =============" << std::endl; //prueba del metodo SIZE
  std::cout << "El Objeto pila2 tiene " << pila2.size() << " elementos" << std::endl;
  std::cout << "El Objeto pila1 tiene " << pila1.size() << " elementos" << std::endl;

  std::cout << "\n========= pop =============" << std::endl; //prueba del metodo POP
  std::cout << "Quitamos el ultimo elemento a pila1 con el metodo pop de esta forma --> pila1.pop();" << std::endl;
  pila1.pop();
  std::cout << "El Objeto pila1 tiene " << pila1.size() << " elementos" << std::endl;

// ----------  SOBRECARGA DE OPERADORES  ----------
  bool test = (pila2 == pila1); //prueba del operador ==
  std::cout << test << " son iguales" <<std::endl;
  pila1.push(10);
  test = (pila2 < pila1); //prueba del operador <
  if (test == 1)
    std::cout << "pila2 es menor que pila1" <<std::endl;
  else
    std::cout << "pila2 es mayor que pila1" <<std::endl;
  test = (pila2 > pila1); //prueba del operador >
  if (test == 1)
    std::cout << "pila2 es mayor que pila1" <<std::endl;
  else
    std::cout << "pila2 es menor que pila1" <<std::endl;

  return 0;
}