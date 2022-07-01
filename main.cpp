#include <vector>
#include <iostream>
#include <cmath>
#include <string>

int main(){
    std::vector<int> v1(10); //inicializando un vector de tipo enteros vacio
    int x=15, y=100;
    std::vector<int> v2(x,y); //inicializando un vector de 15 elementos inicializados a 0
    std::vector<std::string> vector_de_cadena; //inicializando un vector de tipo string vacio

    std::cout << "Numero de elementos del vector v1: " << v1.size() << std::endl;
    std::cout << "Numero de elementos del vector v1: " << v2.size() << std::endl;
    for (int i=0;i<v2.size();i++)
        std::cout << "Posicion v["<< i<< "] tiene el valor:" << v2[i] << std::endl;

    std::allocator<int> myAllocator;
    int *arr = myAllocator.allocate(5);
    myAllocator.construct(arr, 100);
    arr[3] = 10;
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;
    myAllocator.deallocate(arr, 5);

    std::allocator<std::string> myAllocator1;
    std::string *str = myAllocator1.allocate(3);
    myAllocator1.construct(str, "Geeks");
    myAllocator1.construct(str+1, "for");
    myAllocator1.construct(str+2, "Gekc");

    std::cout << str[0] << str[1] << str[2] << std::endl;

    myAllocator1.destroy(str);
    myAllocator1.destroy(str+1);
    myAllocator1.destroy(str+2);

    myAllocator1.deallocate(str, 3);


    return 0;
}