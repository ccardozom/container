#include <vector>
#include "../Stack/stack.hpp"
#include <iostream>
#include <typeinfo>

template<class Container = std::vector<int> >
class test{
    public:
        Container vector1;
        void set_vector(){vector1.push("carlos"); }
        void print_vector_size(){std::cout << vector1.size() << std::endl;}
        void print_vector_top_element(){std::cout << vector1.top() << std::endl;}
};

int main(){
    test<ft::stack<std::string> > uno;
    int hola;
    uno.print_vector_size();
    uno.set_vector();
    uno.print_vector_size();
    uno.print_vector_top_element();
    uno.vector1.empty();
    std::cout << typeid(uno).name() << std::endl;
    std::cout << typeid(hola).name() << std::endl;
}