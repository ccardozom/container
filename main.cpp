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
  std::cout << "*******  PRUEBAS PARA EL CONTENEDOR STACK  *******" << std::endl;
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
  ft::stack<int> mystack_empty;
  int sum(0);
  for (int i(0); i < 10; i++)
    mystack_empty.push(i);
  while(!mystack_empty.empty()){
    sum += mystack_empty.top();
    mystack_empty.pop();
  }
  std::cout << "Total: " << sum << std::endl;

  std::cout << "\n========= size =============" << std::endl; //prueba del metodo SIZE
  std::cout << "El Objeto pila2 tiene " << pila2.size() << " elementos" << std::endl;
  std::cout << "El Objeto pila1 tiene " << pila1.size() << " elementos" << std::endl;
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<5; i++) 
    myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  std::cout << "\n========= pop =============" << std::endl; //prueba del metodo POP
  std::cout << "Quitamos el ultimo elemento a pila1 con el metodo pop de esta forma --> pila1.pop();" << std::endl;
  pila1.pop();
  std::cout << "El Objeto pila1 tiene " << pila1.size() << " elementos" << std::endl;
  ft::stack<int> mystack_pop;
  for (int i=0; i<5; ++i) 
    mystack_pop.push(i);
  std::cout << "El tamaño de mystack_pop es: " << mystack_pop.size() << std::endl;
  std::cout << "mystack_pop contiene: ";
  while (!mystack_pop.empty())
  {
    std::cout << ' ' << mystack_pop.top();
    mystack_pop.pop();
  }
  std::cout << '\n';
  std::cout << "Despues de vaciar con pop el tamaño de mystack_pop es: " << mystack_pop.size() << std::endl;
  std::cout << '\n';


  // ----------  SOBRECARGA DE OPERADORES  ----------
  std::cout << "\n===== SOBRECARGA DE OPERADORES =====" << std::endl;
  bool test = (pila2 == pila1); //prueba del operador ==
  if (test == 1)
    std::cout << "Los objetos pila2 y pila1 son iguales" << std::endl;
  else
    std::cout << "Los objetos pila2 y pila1 son diferentes" << std::endl;
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
  test = (pila2 <= pila1); //prueba del operador <=
  if (test == 1)
    std::cout << "pila2 es menor o igual a pila1" <<std::endl;
  else
    std::cout << "pila2 es mayor a pila1" <<std::endl;
  test = (pila2 >= pila1); //prueba del operador >=
  if (test == 1)
    std::cout << "pila2 es mayor o igual a pila1" <<std::endl;
  else
    std::cout << "pila2 es menor a pila1" <<std::endl;
  test = (pila2 != pila1); //prueba del operador !=
  if (test == 1)
    std::cout << "pila2 es distinto a pila1" <<std::endl;
  else
    std::cout << "pila2 es igual a pila1" <<std::endl;

  std::cout << "*******  PRUEBAS PARA EL CONTENEDOR VECTOR  *******" << std::endl;

  


  return 0;
}