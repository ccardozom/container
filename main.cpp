#include "Vector/vector.hpp"
#include "Stack/stack.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>
//#include <cmath>
#include <string>

int main(){
/*
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

  ft::vector<int> vector1(10, 10);
  ft::vector<int> vector2;
                
  vector2 = vector1;

  ft::vector<int>::iterator p;

  p = vector1.begin();
  std::cout << "Valor de p: " << *p << std::endl;
  //std::cout << "Valor de *p: " << *p << std::endl;
  for(int i = 0; i != (int)vector1.size() ; i++){
    std::cout << "Vector1: " << vector1[i] << "  Vector2: " << vector2[i] << std::endl;
  }
  std::cout << "Size de vector1: " << vector1.size() << std::endl;
  std::cout << "Size de vector1: " << vector1.max_size() << std::endl;
  for(int i = 0; i != (int)vector1.size() ; i++){
    vector1[i] = i*2;
  }
  std::cout << "Opteniendo el valor de vector1["<< 3 << "]: " << vector1.at(3) << std::endl;
  for(int i = 0; i != (int)vector1.size() ; i++){
    std::cout << "Vector1: " << vector1[i] << "  Vector2: " << vector2[i] << std::endl;
  }
  std::cout << vector1.capacity() << std::endl;
  
  std::vector<int> v2(2);
  std::vector<int> v1(5);

  if(v1>v2)
    std::cout << "1" << std::endl;
  else if (v1<v2)
    std::cout << "2" << std::endl;
*/
  /* ///////////////  STACK   \\\\\\\\\\\\\\\ */
  {
	  std::cout << "\n\n\n*************************************************************************" << std::endl;
	  std::cout << "**************************    STACK    **********************************" << std::endl;
	  std::cout << "*************************************************************************" << std::endl;
	
	  // ------ CONSTRUCTORS ------
    {
      std::cout << "\n------------- FT Stack (Constructor)-------------" << std::endl;
      ft::vector<int> myvector(2,200);
      ft::stack<int> first;
      ft::stack<int, ft::vector<int> > second;
      ft::stack<int, ft::vector<int> > third(myvector);

      std::cout << "size of first:  " << first.size() << std::endl;
      std::cout << "size of second: " << second.size() << std::endl;
      std::cout << "size of third   " << third.size() << std::endl;
      std::cout << std::endl;
      std::cout << "third.top() is: " << third.top() << std::endl;
    }
	  // ------ EMPTY ------
    {
      std::cout << "\n------------- FT Stack (empty)-------------" << std::endl;
      ft::stack<std::string> mystack;
      std::cout << "Is mysyack empty?:            " << mystack.empty() << std::endl;
      mystack.push("hola");
      mystack.push("hi");
      mystack.push("hello");
      mystack.push("salut");
      mystack.push("hallo");
      mystack.push("ciao");
      std::cout << "mystack size is now: " << mystack.size() << std::endl;
      std::cout << "Is mystack empty?:            " << mystack.empty() << std::endl;
      while (!mystack.empty())
        mystack.pop();
      std::cout << "mystack size is now: " << mystack.size() << std::endl;
      std::cout << "Is mystack empty?:            " << mystack.empty() << std::endl;
    }
    // ------ SIZE ------
    {
      std::cout << "\n------------- FT Stack (Size)-------------" << std::endl;
      ft::stack<int> myints;
      std::cout << "mystack size is: " << myints.size() << std::endl;
      for (int i = 0; i < 5; i++)
        myints.push(i);
      std::cout << "mystack size is: " << myints.size() << std::endl;
      myints.pop();
      std::cout << "mystack size is: " << myints.size() << std::endl;
    }
    // ------ TOP ------
    {
      std::cout << "\n------------- FT Stack (Top)-------------" << std::endl;
      ft::stack<int> mystack;
      mystack.push(10);
      mystack.push(20);
      mystack.top() -= 5;
      std::cout << "mystack.top() is now:      " << mystack.top() << std::endl;
      const ft::stack<int> const_stack(mystack);
      std::cout << "const_stack.top() is also: " << const_stack.top() << std::endl;
    }
    // ------ PUSH / POP ------
    {
      std::cout << "\n------------- FT Stack (Push/Pop)-------------" << std::endl;
      ft::stack<int> mystack;
      for (int i = 0; i < 5; ++i)
        mystack.push(i);
      std::cout << "size is now: " << mystack.size() << std::endl;
      std::cout << "Popping out elements...";
      while (!mystack.empty())
      {
        std::cout << ' ' << mystack.top();
        mystack.pop();
      }
      std::cout << " ...size is now: " << mystack.size() << std::endl;
      std::cout << std::endl;
    }
	  //  RELATIONAL OPERATORS:
	  {
      // ------ == / != ------
      {
        std::cout << "\n------------- FT Stack (operator== / operator!=)-------------" << std::endl;
        ft::stack<int, ft::vector<int> > s1, s2, s3;
        s1.push(1);
        s1.push(2);

        s2.push(1);
        s2.push(2);

        s3.push(1);
        s3.push(2);
        s3.push(3);

        if (s1 == s2)
          std::cout << "The stacks s1 and s2 are equal." << std::endl;
        if (s1 != s2)
          std::cout << "The stacks s1 and s2 are not equal." << std::endl;

        if (s1 == s3)
          std::cout << "The stacks s1 and s3 are equal." << std::endl;
        if (s1 != s3)
          std::cout << "The stacks s1 and s3 are not equal." << std::endl;
      }
      // ------ >= / < ------
      {
        std::cout << "\n------------- FT Stack (operator>= / operator<)-------------" << std::endl;
        ft::stack<int, ft::vector<int> > s1, s2, s3;
        s1.push(2);
        s1.push(4);
        s1.push(6);
        s1.push(8);

        s2.push(5);
        s2.push(10);

        s3.push(2);
        s3.push(4);
        s3.push(6);
        s3.push(8);

        if (s1 < s2)
          std::cout << "The stack s1 is less than the stack s2." << std::endl;
        if (s1 >= s2)
          std::cout << "The stack s1 is greater than or equal to the stack s2." << std::endl;
        if (s1 < s3)
          std::cout << "The stack s1 is less than the stack s3." << std::endl;
        if (s1 >= s3)
          std::cout << "The stack s1 is greater than or equal to the stack s3." << std::endl;
      }
      // ------ <= / > ------
      {
        std::cout << "\n------------- FT Stack (operator<= / operator>)-------------" << std::endl;
        ft::stack<int> s1, s2, s3;
        s1.push(5);
        s1.push(10);

        s2.push(1);
        s2.push(2);

        s3.push(5);
        s3.push(10);

        if (s1 <= s2)
          std::cout << "The stack s1 is less than or equal to the stack s2." << std::endl;
        if (s1 > s2)
          std::cout << "The stack s1 is greater than the stack s2." << std::endl;
        if (s1 <= s3)
          std::cout << "The stack s1 is less than or equal to the stack s3." << std::endl;
        if (s1 > s3)
          std::cout << "The stack s1 is greater than the stack s3." << std::endl;
      }
	  }
    // ------ OTHER CONTAINERS COMPATIBILITY ------
    {
      std::cout << "\n------------- FT Stack (deque compatibility)-------------" << std::endl;
      ft::stack<int, std::deque<int> > deque_stack;
      std::cout << "myints size: " << deque_stack.size() << std::endl;
      for (int i = 0; i < 5; i++)
        deque_stack.push(i);
      std::cout << "myints size: " << deque_stack.size() << std::endl;
      deque_stack.pop();
      std::cout << "myints size: " << deque_stack.size() << std::endl;

      std::cout << "\n------------- FT Stack (list compatibility)-------------" << std::endl;
      ft::stack<int, std::list<int> > list_stack;
      std::cout << "myints size: " << list_stack.size() << std::endl;
      for (int i = 0; i < 5; i++)
        list_stack.push(i);
      std::cout << "myints size: " << list_stack.size() << std::endl;
      list_stack.pop();
      std::cout << "myints size: " << list_stack.size() << std::endl;
    }
  }


  /* ///////////////  VECTOR  \\\\\\\\\\\\\\\ */
  {
	std::cout << "\n\n\n*************************************************************************" << std::endl;
	std::cout << "**************************   VECTOR   ***********************************" << std::endl;
	std::cout << "*************************************************************************" << std::endl;

	// ------ CONSTRUCTORS ------
	{
		std::cout << "\n---------- FT Vector (Constructors and iterator) ----------" << std::endl;
		
		ft::vector<int> empty_vec;
		std::cout << "Empty vector:";
		for (ft::vector<int>::iterator it = empty_vec.begin(); it != empty_vec.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		ft::vector<int> fill_vec(5, 10);
		std::cout << "Fill vector:";
		for (ft::vector<int>::iterator it = fill_vec.begin(); it != fill_vec.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		empty_vec.push_back(2);
		empty_vec.push_back(4);
		empty_vec.push_back(6);
		ft::vector<int> range_vec(empty_vec.begin(), empty_vec.end());
		std::cout << "Range vector:";
		for (ft::vector<int>::iterator it = range_vec.begin(); it != range_vec.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		ft::vector<int> copy_vec(fill_vec);
		std::cout << "Copy vector:";
		for (ft::vector<int>::iterator it = copy_vec.begin(); it != copy_vec.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		copy_vec.push_back(33);
		copy_vec.push_back(66);
		copy_vec.push_back(99);

		ft::vector<int> deep_copy_vec(copy_vec);
		copy_vec.clear();
		std::cout << "Deep copy vector:";
		for (ft::vector<int>::iterator it = deep_copy_vec.begin(); it != deep_copy_vec.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		int myints[] = {16, 2, 77, 29};
		ft::vector<int> extra(myints, myints + sizeof(myints) / sizeof(int));
		std::cout << "Extra vector:";
		for (ft::vector<int>::iterator it = extra.begin(); it != extra.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
	// ------ OPERATOR = ------
	{
		std::cout << "\n------------- FT Vector (operator=)-------------" << std::endl;
		ft::vector<int> foo(3, 100);
		ft::vector<int> bar(5, 200);
		bar = foo;
		foo = ft::vector<int>();
		std::cout << "Size of foo: " << int(foo.size()) << std::endl;
		std::cout << "Size of bar: " << int(bar.size()) << std::endl;
		std::cout << "The contents of bar vector are:";
		for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
	// ------ DIFERENT ITERATORS ------
	{
		std::cout << "\n---- FT Vector (iterator walk & comparison diferent iterators) ----" << std::endl;
		ft::vector<int> myvector;
		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);
		std::cout << "myvector contains:";
		ft::vector<int>::iterator it = myvector.begin();
		ft::vector<int>::const_iterator cit = myvector.end();
		for (; it != cit; ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		std::cout << "\n------------- FT Vector (reverse iterator walk)-------------" << std::endl;
		std::cout << "myvector contaift:";
		for (ft::vector<int>::reverse_iterator it1 = myvector.rbegin(); it1 != myvector.rend(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << std::endl;
	}
	// CAPACITY:
	{
		// ------ SIZE ------
			{
				std::cout << "\n------------- FT Vector (size)-------------" << std::endl;
				ft::vector<int> myvector;
				std::cout << "size (should be 0):  " << myvector.size() << std::endl;
				for (int i = 0; i < 10; i++)
					myvector.push_back(i);
				std::cout << "size (should be 10): " << myvector.size() << std::endl;
				myvector.insert(myvector.end(), 10, 100);
				std::cout << "size (should be 20): " << myvector.size() << std::endl;
				myvector.pop_back();
				std::cout << "size (should be 19): " << myvector.size() << std::endl;

				std::cout << "\n------------- FT Vector (max_size)-------------" << std::endl;
				std::cout << "max_size: " << myvector.max_size() << std::endl;

				std::cout << "\n------------- FT Vector (resize)-------------" << std::endl;
				ft::vector<int> myvector1;
				for (int i = 0; i < 10; i++)
					myvector1.push_back(i);
				std::cout << "myvector contains 10 elements:                           ";
				for (size_t i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1[i];
				std::cout << std::endl;

				myvector1.resize(5);
				std::cout << "myvector contains 5 elements:                            ";
				for (size_t i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1[i];
				std::cout << std::endl;

				myvector1.resize(8);
				std::cout << "myvector contains 8 elements, filled up with value 0:    ";
				for (size_t i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1[i];
				std::cout << std::endl;

				myvector1.resize(11, 100);
				std::cout << "myvector contains 11 elements, filled up with value 100: ";
				for (size_t i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1[i];
				std::cout << std::endl;
			}
		// ------ CAPACITY ------
			{
				std::cout << "\n------------- FT Vector (capacity)-------------" << std::endl;
				ft::vector<int> myvector;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(1);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(2);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(3);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(4);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(5);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(6);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(7);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(8);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
				std::cout << std::endl;

				myvector.push_back(9);
				std::cout << "myvector contains: ";
				for (size_t i = 0; i < myvector.size(); i++)
					std::cout << ' ' << myvector[i];
				std::cout << std::endl;
				std::cout << "capacity: " << myvector.capacity() << std::endl;
				std::cout << "size: " << myvector.size() << std::endl;
			}
		// ------ EMPTY ------
			{
				std::cout << "\n------------- FT Vector (empty)-------------" << std::endl;
				ft::vector<int> myvector;
				std::cout << "Is my vector empty?: " << myvector.empty() << std::endl;
				for (int i = 1; i < 10; i++)
					myvector.push_back(i);
				std::cout << "size after pushing values 1 to 9 included: " << myvector.size() << std::endl;
				std::cout << "Is my vector empty?: " << myvector.empty() << std::endl;
				while (!myvector.empty())
					myvector.pop_back();
				std::cout << "size after pop back until empty:           " << myvector.size() << std::endl;
				std::cout << "Is my vector empty?: " << myvector.empty() << std::endl;
			}
		// ------ RESERVE ------
			{
			std::cout << "\n--------- FT Vector (reserve) ---------" << std::endl;
			ft::vector<int> myvector;
			for (int i = 1; i < 10; i++)
				myvector.push_back(i);
			std::cout << "Initial capacity: " << myvector.capacity() << std::endl;

			myvector.reserve(5);
			std::cout << "Capacity should be the same: " << myvector.capacity() << std::endl;

			myvector.reserve(20);
			std::cout << "Capacity should be 20: " << myvector.capacity() << std::endl;
		}
	}
	// ELEMENT ACCESS:
	{}
	{
		// ------ OPERATOR [] ------
			{
				std::cout << "\n------------- FT Vector (operator[])-------------" << std::endl;
				ft::vector<int> myvector1(10);
				for (unsigned i = 0; i < myvector1.size(); i++)
					myvector1[i] = i;
				std::cout << "myvector contains:";
				for (unsigned i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1[i];
				std::cout << std::endl;
			}
		// ------ AT ------
			{
				std::cout << "\n------------- FT Vector (at)-------------" << std::endl;
				ft::vector<int> myvector1(10);
				for (unsigned i = 0; i < myvector1.size(); i++)
					myvector1.at(i) = i;
				std::cout << "myvector contains:";
				for (unsigned i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1.at(i);

				myvector1.at(5) = 28;

				std::cout << "\nmyvector contains:";
				for (unsigned i = 0; i < myvector1.size(); i++)
					std::cout << ' ' << myvector1.at(i);

				try
				{
					std::cout << myvector1.at(45);
				}
				catch(const std::exception& e)
				{
					std::cout << "\nlooking out of bounds";
				}
				std::cout << std::endl;
			}
		// ------ FRONT / BACK ------
			{
				std::cout << "\n------------- FT Vector (front/back)-------------" << std::endl;
				ft::vector<int> myvector1;
				myvector1.push_back(78);
				myvector1.push_back(42);
				myvector1.push_back(16);

				std::cout << "myvector.front() (should be 78):   " << myvector1.front() << std::endl;
				std::cout << "myvector.back()  (should be 16):   " << myvector1.back() << std::endl;

				myvector1.front() -= myvector1.back();
				std::cout << "myvector.front() (should be 62):   " << myvector1.front() << std::endl;
			}
	}
	// MODIFIERS:
	{
		// ------ ASSIGN ------
		{
			std::cout << "\n------------- FT Vector (assign)-------------" << std::endl;
			ft::vector<int> first;

			first.assign(3, 100);
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < first.size(); i++)
				std::cout << ' ' << first[i];
			std::cout << std::endl;
			std::cout << "Size of first: " << int(first.size()) << std::endl;
			std::cout << std::endl;

			first.assign(6, 200);
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < first.size(); i++)
				std::cout << ' ' << first[i];
			std::cout << std::endl;
			std::cout << "Size of first: " << int(first.size()) << std::endl;
			std::cout << std::endl;

			ft::vector<int> second;
			ft::vector<int>::iterator it1;
			it1 = first.begin() + 1;
			second.assign(it1, first.end() - 1);
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < second.size(); i++)
				std::cout << ' ' << second[i];
			std::cout << std::endl;
			std::cout << "Size of second: " << int(second.size()) << std::endl;
			std::cout << std::endl;

			int myints1[] = {1776, 7, 4};
			first.assign(myints1, myints1 + 3);
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < first.size(); i++)
				std::cout << ' ' << first[i];
			std::cout << std::endl;
			std::cout << "Size of first: " << int(first.size()) << std::endl;
		}
		// ------ PUSH/POP BACK ------
		{
			std::cout << "\n---------- FT Vector (push_back / pop_back) ----------" << std::endl;
			ft::vector<int> myvector1;
			int ints[] = {15, 78, 99, 45, 78, 99, 65, 0, 44};
			for (int i = 0; ints[i]; i++)
				myvector1.push_back(ints[i]);
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < myvector1.size(); i++)
				std::cout << ' ' << myvector1[i];
			std::cout << std::endl;
			std::cout << "Size of myvector1:     " << int(myvector1.size()) << std::endl;
			std::cout << std::endl;

			myvector1.pop_back();
			myvector1.pop_back();
			std::cout << "myvector contains: ";
			for (size_t i = 0; i < myvector1.size(); i++)
				std::cout << ' ' << myvector1[i];
			std::cout << std::endl;
			std::cout << "Size of myvector1:     " << int(myvector1.size()) << std::endl;
			std::cout << std::endl;
		}
		// ------ INSERT ------
		{
			std::cout << "\n------------- FT Vector (insert)-------------" << std::endl;

			ft::vector<int>::iterator it1;

			ft::vector<int> myvector1(3, 100);
			std::cout << "\nmyvector contains:";
			for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << std::endl;
			std::cout << "Its size is of     " << myvector1.size() << std::endl;

			it1 = myvector1.begin();
			it1 = myvector1.insert(it1, 200);
			myvector1.insert(it1, 2, 300);
			std::cout << "\nmyvector contains:";
			for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << "\nIts size is of     " << myvector1.size() << std::endl;

			ft::vector<int> anothervector1(2, 400);
			it1 = myvector1.begin();
			myvector1.insert(it1 + 2, anothervector1.begin(), anothervector1.end());
			std::cout << "\nmyvector contains:";
			for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << "\nIts size is of     " << myvector1.size() << std::endl;

			int myarray1[] = {501, 502, 503};
			myvector1.insert(myvector1.begin(), myarray1, myarray1 + 3);
			std::cout << "\nmyvector contains:";
			for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << "\nIts size is of     " << myvector1.size() << std::endl;
		}
		// ------ ERASE ------
		{
			std::cout << "\n------------- FT Vector (erase)-------------" << std::endl;
			ft::vector<int> myvector;
			ft::vector<int>::iterator index;
			ft::vector<int>::iterator it1;
			ft::vector<int>::iterator it2;

			for (int i = 1; i <= 10; i++)
				myvector.push_back(i);
			index = myvector.begin();
			std::cout << "myvector contains:";
			for (; index != myvector.end(); index++)
				std::cout << ' ' << *index;

			myvector.erase(myvector.begin() + 5);
			std::cout << "\nmyvector contains:";
			for (unsigned i = 0; i < myvector.size(); ++i)
				std::cout << ' ' << myvector[i];

			myvector.erase(myvector.begin(), myvector.begin() + 3);
			std::cout << "\nmyvector contains:";
			for (unsigned i = 0; i < myvector.size(); ++i)
				std::cout << ' ' << myvector[i];
			std::cout << std::endl;
		}
		// ------ SWAP ------
		{
			std::cout << "\n------------- FT Vector (swap)-------------" << std::endl;
			ft::vector<int> foo(3, 100);
			ft::vector<int> bar(5, 200);

			ft::vector<int>::iterator it1 = foo.begin();
			ft::vector<int>::iterator it2 = bar.begin();

			std::cout << "foo contains:";
			for (; it1 != foo.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << std::endl;
			std::cout << "Size of foo before     " << foo.size() << std::endl;
			std::cout << "Capacity of foo before " << foo.capacity() << std::endl << std::endl;

			std::cout << "bar contains:";
			for (; it2 != bar.end(); it2++)
				std::cout << ' ' << *it2;
			std::cout << std::endl;
			std::cout << "Size of bar before     " << bar.size() << std::endl;
			std::cout << "Capacity of bar before " << bar.capacity() << std::endl << std::endl;
			
			it1 = foo.begin();
			it2 = bar.begin();

			foo.swap(bar);
			std::cout << "SWAP!" << std::endl << std::endl;

			std::cout << "foo contains:";
			for (; it2 != foo.end(); it2++)
				std::cout << ' ' << *it2;
			std::cout << std::endl;
			std::cout << "Size of foo     " << foo.size() << std::endl;
			std::cout << "Capacity of foo " << foo.capacity() << std::endl << std::endl;

			std::cout << "bar contains:";
			for (; it1 != bar.end(); it1++)
				std::cout << ' ' << *it1;
			std::cout << std::endl;
			std::cout << "Size of bar     " << bar.size() << std::endl;
			std::cout << "Capacity of bar " << bar.capacity() << std::endl;
		}
		// ------ CLEAR ------
		{
			std::cout << "\n------------- FT Vector (clear)-------------" << std::endl;
			ft::vector<std::string> myvector1;
			myvector1.push_back("hola");
			myvector1.push_back("hi");
			myvector1.push_back("hello");
			std::cout << "myvector contains:";
			for (unsigned i = 0; i < myvector1.size(); i++)
				std::cout << ' ' << myvector1[i];
			std::cout << std::endl;
			std::cout << "myvector1 size:       " << myvector1.size() << std::endl;
			myvector1.clear();
			std::cout << "CLEAR!" << std::endl;
			std::cout << "size after clear:     " << myvector1.size() << std::endl;
			myvector1.push_back("adios");
			myvector1.push_back("bye");
			std::cout << "myvector contains:";
			for (unsigned i = 0; i < myvector1.size(); i++)
				std::cout << ' ' << myvector1[i];
			std::cout << std::endl;
		}
	}
	// ------ GET_ALLOCATOR ------
	{}
	{
		std::cout << "\n------------- FT Vector (get_allocator)-------------" << std::endl;
		ft::vector<int> myvector;
		int             *p;
		unsigned int    i;

		p = myvector.get_allocator().allocate(5);
		for (i = 0; i < 5; i++)
			myvector.get_allocator().construct(&p[i], i);
		std::cout << "The manually allocated array contaift:";
		for (i = 0; i < 5; i++)
			std::cout << ' ' << p[i];
		std::cout << std::endl;
		for (i = 0; i < 5; i++)
			myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p, 5);
	}
	// ------ RELATIONAL OPERATORS ------
	{
		std::cout << "\n------------- FT Vector (Relational operators)-------------" << std::endl;
		ft::vector<int> foo(2, 200);
		ft::vector<int> bar(foo);
		if (foo == bar)
			std::cout << "foo and bar are equal" << std::endl;
		if (foo != bar)
			std::cout << "foo and bar are not equal" << std::endl;
		if (foo < bar)
			std::cout << "foo is less than bar" << std::endl;
		if (foo > bar)
			std::cout << "foo is greater than bar" << std::endl;
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar" << std::endl;
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar" << std::endl;
		std::cout << std::endl;
		ft::vector<int> baz;
		baz.push_back(200);
		baz.push_back(200);
		baz.push_back(300);
		baz.push_back(400);
		if (foo == baz)
			std::cout << "foo and baz are equal" << std::endl;
		if (foo != baz)
			std::cout << "foo and baz are not equal" << std::endl;
		if (foo < baz)
			std::cout << "foo is less than baz" << std::endl;
		if (foo > baz)
			std::cout << "foo is greater than baz" << std::endl;
		if (foo <= baz)
			std::cout << "foo is less than or equal to baz" << std::endl;
		if (foo >= baz)
			std::cout << "foo is greater than or equal to baz" << std::endl;
	}
  }
    

  
  return 0;
}