#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {
   template < class T, class Alloc = std::allocator<T> >
   class vector{
       typedef T value_type;
       typedef Alloc allocator_type;
       typedef allocator_type::reference reference;
       typedef allocator_type::const_reference const_reference;
       typedef allocator_type::pointer pointer;
       typedef allocator_type::const_pointer const_pointer;
       typedef value_type iterator;
       
   };
}

#endif