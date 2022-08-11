#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream>

namespace ft {
    template <class T, class Container = std::vector<T> > 
    class stack{
        public:
            //sabemos que Container es equivalente a decir vector<T> donde T es el tipo de dato
            //la siguiente linea genera un alias a Container que a partir de ahora será container_type
            typedef Container   container_type;
            //aqui creamos un alias para Container::value_type que es el tipo de dato
            //a partir de ahora T sera value_type
            //Si necesitamos hacer uso de un tipo proporcionado por la clase/estructura utilizada para especializar el template tendremos 
            //que redeclarar el tipo en nuestro template. En este caso tendremos que usar obligatoriamente typename
            // aqui esta un comentario que puede ayudar a entender mejor esta definicion https://es.stackoverflow.com/questions/540/son-iguales-class-y-typename-en-el-contexto-de-template
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
            //la palabra reservada explicit cumple la funcion de avisar al compilar que la llamada a este constructor tiene que ser explicita y no implicita
            //en este enlace puedes encontrar un ejemplo claro del porque y para que se utiliza la palabra reservada http://ambar.com.ve/saphire/?p=505
            // Ejemplo: stack(int) pila; -->esto llama al constructor donde vemos que al cambiar los alias quedaria de esta forma vector<T> &ctnr = vector<T>()
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

            size_type size(){
                return c.size();
            }
   
            value_type& top(){
                return c.back();
            }

            void push(const value_type& value){
                c.push_back(value);
            }

            void pop(){
                c.pop_back();
            }
 

			template< typename Type, typename C>
			friend bool	operator==( const stack<Type, C>& lhs,	const stack<Type, C>& rhs );
            
            //sobrecarga de operadores
            //template <class T, class Container>
            //bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){

           // }
/*
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

    
    template< typename Type, typename Container >
		inline bool	operator==( const stack<Type, Container>& lhs, const stack<Type, Container>& rhs )
		{
			return lhs.c == rhs.c;
		}
/*
	template< typename Type, typename Container >
		inline bool
		operator!=( const stack<Type, Container>& lhs,
					const stack<Type, Container>& rhs )
		{
			return !(lhs == rhs);
		}

	template< typename Type, typename Container >
		inline bool
		operator<( const stack<Type, Container>& lhs,
					const stack<Type, Container>& rhs )
		{
			return lhs.c < rhs.c;
		}

	template< typename Type, typename Container >
		inline bool
		operator<=( const stack<Type, Container>& lhs,
					const stack<Type, Container>& rhs )
		{
			return !(rhs < lhs);
		}

	template< typename Type, typename Container >
		inline bool
		operator>( const stack<Type, Container>& lhs,
					const stack<Type, Container>& rhs )
		{
			return rhs < lhs;
		}

	template< typename Type, typename Container >
		inline bool
		operator>=( const stack<Type, Container>& lhs,
					const stack<Type, Container>& rhs )
		{
			return !(lhs < rhs);
		}
    */
}

#endif