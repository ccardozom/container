#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream>

namespace ft {
    template <class T, class Container = std::vector<T> > 
    class stack{
        public:
            typedef Container   container_type;
            //sabemos que Container es equivalente a decir vector<T> donde T es el tipo de dato
            //asignamos un alias a Container que a partir de ahora será container_type
            typedef typename Container::value_type value_type;
            //aqui creamos un alias para Container::value_type que es el tipo de dato
            //a partir de ahora T sera value_type
            //Si necesitamos hacer uso de un tipo proporcionado por la clase/estructura utilizada para especializar el template tendremos 
            //que redeclarar el tipo en nuestro template. En este caso tendremos que usar obligatoriamente typename
            // aqui esta un comentario que puede ayudar a entender mejor esta definicion https://es.stackoverflow.com/questions/540/son-iguales-class-y-typename-en-el-contexto-de-template
            typedef typename Container::size_type   size_type;
            //es lo mismo que size_t y sirve para representar el tamaño del objeto en forma de un entero positivo 
            //con valor de 0 a 4.000.000.000 aproximadamente

        protected:
            //instanciamos un objeto c de tipo vector<T> especificando el acceso como protegido
            //para que asi los miembros de la clase puedan acceder a el pero no se podrá acceder
            //desde otra clase
            container_type _c;

        public:
            //Constructores
            // este constructor es para instanciar un objeto vacio
            //la palabra reservada explicit cumple la funcion de avisar al compilar que la llamada a este constructor tiene que ser explicita y no implicita
            //en este enlace puedes encontrar un ejemplo claro del porque y para que se utiliza la palabra reservada http://ambar.com.ve/saphire/?p=505
            // Ejemplo: stack(int) pila; -->esto llama al constructor donde vemos que al cambiar los alias quedaria de esta forma vector<T> &ctnr = vector<T>()
            explicit stack (const container_type& ctnr = container_type()){
                _c = ctnr;  
            }

            //Destructor
             ~stack(){
             }
           //Funciones miebro
            bool empty() const{
                return _c.empty();
            }

            size_type size(){
                return _c.size();
            }
   
            value_type& top(){
                return _c.back();
            }

            void push(const value_type& value){
                _c.push_back(value);
            }

            void pop(){
                _c.pop_back();
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