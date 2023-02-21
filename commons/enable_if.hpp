#ifndef ENABLE_IF
#define ENABLE_IF

namespace ft{
    template<bool Cond, class T = void>
    class enable_if {};

    template<class T>
    class enable_if<true, T>{
        public:
            typedef T   type;
    };
}
#endif
