#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T>> 
    class stack{
        public:
            typedef Container   container_type;
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;

            //Constructores
            stack(){
            }
            
            explicit stack (const container_type& ctnr = container_type()){
                
            }

            //Destructor
             ~stack(){
             }
            //Funciones miebros
            bool empty() const{

            }

            void pop(){

            }

            void push(){

            }

            size_type size(){

            }

            value_type& top(){

            }

            const value_type& top() const{

            }

            //sobrecarga de operadores
            template <class T, class Container>
            bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }

            template <class T, class Container>
            bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }

            template <class T, class Container>
            bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }

            template <class T, class Container>
            bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }

            template <class T, class Container>
            bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }

            template <class T, class Container>
            bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

            }
    };
}

#endif