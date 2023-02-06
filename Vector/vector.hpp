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
            //-------------- CONSTRUCTORES ----------------
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

            reverse_iterator rbegin(){
                return reverse_iterator(end());
            }

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(end());
            }

            reverse_iterator rend(){
                return reverse_iterator(begin());
            }

            const_reverse_iterator rend() const{
                return const_reverse_iterator(begin());
            }

            // ----------- CAPACIDAD -----------------

            size_type size() const {
                return _size;
            }

            size_type max_size() const{
                return _alloc.max_size();
            }

            void resize(size_type n, value_type val = value_type()){
                if (n > this->_capacity)
                    this->reallocation(n);
                for (size_t i = this->_sizej - n; i > 0; i++)
                    this->push_back(val);
            }

            // ----------- ACCESO DE ELEMENTOS -----------
            reference operator[] (size_type n){
                return this->_array[n];
            }

            // ----------- MODIFICADORES ------------------

            void push_back(const value_type& val){
                if (this->_size < this->_capacity)
                    this->_alloc.construct(this->_array + this->_size, val);
                else{
                    if (this->_capacity)
                        this->reallocation(this->_capacity * 2);
                    else{
                        this->_array = this->_alloc.allocate(1);
                        this->_capacity++;
                    }
                    this->_alloc.construct(this->_array + this->_size, val);
                }
                this->_size++;
            }

            void pop_back(){
                if(!this->empty()){
                    this->_alloc.destroy(this->_array + (this->_size - 1));
                    this->_size--;
                }
            }

            iterator insert(iterator position, const value_type& val){
                if(this->_capacity == this->max_size())
                    return NULL;
                if(this->_capacity == 0){
                    this->push_back(val);
                    return this->begin();
                }
                if(this->_capacity == this->_size){
                    std::ptrdiff_t pos = position - this->begin();
                    this->reallocation(2 * this->_capacity);
                    position = this->begin() + pos;
                }
                vector tmp(position, this->end());
            }

            // ------------ ALOCADORES DE MEMORIA ------------

            allocator_type get_allocator() const{
                return this->_alloc;
            }

        private:
            void reallocation(size_t n){
                pointer new_array = this->_alloc.allocate(n);
                for(size_t i = 0; i < this->_size; i++){
                    this->_alloc.construct(new_array + i, this->_array[i]);
                    this->_alloc.destroy(this->_array + i);
                }
                this->_alloc.deallocate(this->_array, this->_capacity);
                this->_array = new_array;
                this->_capacity = n;
            }
   };
}

#endif