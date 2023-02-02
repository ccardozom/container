#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "vector_iterator.hpp"
#include "../commons/reverse_iterator.hpp"
#include "../commons/enable_if.hpp"
#include "../commons/is_integral.hpp"
#include <iostream>

namespace ft {
   template < class T, class Alloc = std::allocator<T> >
   class vector{
        public:
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef vector_iterator<pointer>                    iterator;
            typedef vector_iterator<const_pointer>              const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
            typedef std::ptrdiff_t                              diference_type;
            typedef size_t                                      size_type;
        private:
            size_t _size;
            size_t _capacity;
            Alloc _alloc;
            T*  _array;
        public:
            //-------------- CONSTRUCTORS ----------------
            explicit vector(const allocator_type& alloc = allocator_type()) { 
            _array = NULL;
            _size = 0;
            _capacity = 0; 
            _alloc = alloc;
            }

            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                //_array = NULL;
                _size = n;
                _capacity = n;
                _alloc = alloc;

                _array = _alloc.allocate(n);
                for(size_t i = 0; i < n; i++)
                    _alloc.construct(_array + i, val);
            }

            template<class InputIterator>
            vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()){
                _array = NULL;
                _size = 0;
                _capacity = 0;
                _alloc = alloc;

                for( ; first != last; first++)
                    push_back(*first);
            }

            vector(const vector& x){
                _array = NULL;
                _size = 0;
                _capacity = 0;

                *this = x;
            }

            // ---------- DESTRUCTOR --------------

            ~vector(){
                if(_capacity){
                    for(size_t i = 0; i < _size; i++)
                        _alloc.destroy(_array + 1);
                    _alloc.deallocate(_array, _capacity);
                }
            }

            // ------------ SOBRECARGA DE OPERADOR -----------

            vector& operator= (const vector &x){
                if(this != &x){
                    this->~vector();
                    _size = x._size;
                    _capacity = x._capacity;
                    _alloc = x._alloc;
                    if(_capacity != 0)
                        _array = _alloc.allocate(_capacity);
                    for(size_t i = 0; i < _size; i++)
                        _alloc.construct(_array + i, x._array[i]);
                }
                return *this;
            }

            // ------------- ITERADORES ------------------

            iterator begin(){
                return iterator(this->_array);
            }
            
            const iterator begin() const{
                return const_iterator(this->_array);
            }

            iterator end(){
                return iterator(this->_array + this->_size);
            }

            const iterator end() const{
                return const_iterator(this->_array + this->_size);
            }

            // ----------- CAPACIDAD -----------------

            size_type size() const {
                return this->_size;
            }

            // ----------- ACCESO DE ELEMENTOS -----------
            reference operator[] (size_type n){
                return this->_array[n];
            }
   };
}

#endif