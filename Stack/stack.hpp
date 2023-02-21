#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft {
    template <class T, class Container = vector<T> > 
    class stack{
        public:
            typedef Container   container_type;
            //sabemos que Container es equivalente a decir vector<T> donde T es el tipo de dato
            //asignamos un alias a Container que a partir de ahora será container_type
            typedef T value_type;
            //aqui creamos un alias para Container::value_type que es el tipo de dato
            //a partir de ahora T sera value_type
            //Si necesitamos hacer uso de un tipo proporcionado por la clase/estructura utilizada para especializar el template tendremos 
            //que redeclarar el tipo en nuestro template. En este caso tendremos que usar obligatoriamente typename
            // aqui esta un comentario que puede ayudar a entender mejor esta definicion https://es.stackoverflow.com/questions/540/son-iguales-class-y-typename-en-el-contexto-de-template
            typedef size_t   size_type;
            //es lo mismo que size_t y sirve para representar el tamaño del objeto en forma de un entero positivo 
            //con valor de 0 a 4.000.000.000 aproximadamente

            //Constructores
            // este constructor es para instanciar un objeto vacio
            //la palabra reservada explicit cumple la funcion de avisar al compilar que la llamada a este constructor tiene que ser explicita y no implicita
            //en este enlace puedes encontrar un ejemplo claro del porque y para que se utiliza la palabra reservada http://ambar.com.ve/saphire/?p=505
            // Ejemplo: stack(int) pila; -->esto llama al constructor donde vemos que al cambiar los alias quedaria de esta forma vector<T> &ctnr = vector<T>()
            explicit stack (const container_type& ctnr = container_type()){
                _c = ctnr;  
            }

            stack(const stack<T, Container>& src){
                this->_c = src._c;
                *this = src;
            }

            //Destructor
             ~stack(){
             }
           //Funciones miembro
            bool empty() const{
                return this->_c.empty();
            }

            size_type size() const{
                return this->_c.size();
            }
   
            value_type& top(){
                return this->_c.back();
            }

            const value_type& top() const{
                return this->_c.back();
            }

            void push(const value_type& value){
                this->_c.push_back(value);
            }

            void pop(){
                this->_c.pop_back();
            }

            stack& operator= (const stack& other){
                _c = other._c;
                return *this;
            }


			template<class U, class Cont>
			friend bool	operator==(const stack<U, Cont>& lhs, const stack<U, Cont>& rhs);
            
            template <class U, class Cont>
            friend bool operator<(const stack<U, Cont>& lhs, const stack<U, Cont>& rhs);

            template <class U, class Cont>
            friend bool operator!=(const stack<U, Cont>& lhs, const stack<U, Cont>& rhs);

            template <class Type, class C>
            friend bool operator<= (const stack<Type, C>& lhs, const stack<Type, C>& rhs);

            template <class Type, class C>
            friend bool operator>  (const stack<Type, C>& lhs, const stack<Type, C>& rhs);

            template <class Type, class C>
            friend bool operator>= (const stack<Type, C>& lhs, const stack<Type, C>& rhs);
    
        protected:
            //instanciamos un objeto c de tipo vector<T> especificando el acceso como protegido
            //para que asi los miembros de la clase puedan acceder a el pero no se podrá acceder
            //desde otra clase
            container_type _c;
    };

    
    template<class Type, class Container>
	bool operator== ( const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
        return lhs._c == rhs._c;
    }


	template<class Type, class Container> 
    bool operator< (const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
			return lhs._c < rhs._c;
		}

	template<class Type, class Container>
	bool operator!= (const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
            return lhs._c != rhs._c;
        }
    
    template <class Type, class Container>
    bool operator<= (const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
        return lhs._c <= rhs._c;
    }

    template <class Type, class Container>
    bool operator>  (const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
        return lhs._c > rhs._c;
    }

    template <class Type, class Container>
    bool operator>= (const stack<Type, Container>& lhs, const stack<Type, Container>& rhs){
        return lhs._c >= rhs._c;
    }	
}

#endif