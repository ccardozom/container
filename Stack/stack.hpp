#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> > 
    class stack{
        public:
            //como sabemos que Container es equivalente a decir vector<T> donde T es el tipo de dato
            //la siguiente linea genera un alias a Container que a partir de ahora será container_type
            typedef Container   container_type;
            //aqui creamos un alias para Container::value_type que es el tipo de dato o tambien T en este caso
            //a partir de ahora T sera value_type
            typedef typename Container::value_type  value_type;
            //es lo mismo que size_t y sirve para representar el tamaño del objeto en forma de un entero positivo 
            //con valor de 0 a 4.000.000.000 aproximadamente
            typedef typename Container::size_type   size_type;

        protected:
            //instanciamos un objeto c de tipo vector<T> especificando el acceso como protegido
            //para que asi los miembros de la clase puedan acceder a el pero no se podrá acceder
            //desde otra clase
            container_type c;

        public:
            //Constructores
            // este constructor es para instanciar un objeto vacio
            // Ejemplo: stack(int) pila; --> donde vector<T> &ctnr = vector<T>()
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