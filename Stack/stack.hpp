#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> > 
    class stack{
        public:
            typedef Container   container_type;
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;

        protected:
            container_type c;

        public:
            //Constructores
            explicit stack (const container_type& ctnr = container_type()){
                c = ctnr;  
            }

            //Destructor
             ~stack(){
             }
           //Funciones miebros
            bool empty() const{
                return c.empty();
            }

            void push(const value_type& value){
                c.push_back(value);
            }
   
            value_type& top(){
                return c.back();
            }
/* 
            void pop(){

            }


            size_type size(){

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

            }*/
    };
}

#endif