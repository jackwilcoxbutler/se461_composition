// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
#include "Base_Array.h"
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
//#include "Queue.h"

#include <iostream>
#include<string>
#include <stdexcept>
#include <cstdlib>

//
// main
////
//
int main (int argc, char * argv [])
{
    Base_Array<int> b = Base_Array<int>();
    Base_Array<int> c = Base_Array<int>(10,4);
    std :: cout << c.size() << std :: endl;
    for(int i = 0;i  < c.size(); i++){
        std :: cout << c[i] << std :: endl;
    }

    Array<int> a = Array<int>(14,6);
    std :: cout << a.size() << std :: endl;
    for(int i = 0;i  < a.size(); i++){
        std :: cout << a[i] << std :: endl;
    }
    a.resize(5);
    std :: cout << "Size : " << a.size() << std :: endl;
    std :: cout << "Max Size : " << a.max_size() << std :: endl;

    
    for(int i = 0;i  < a.size(); i++){
        std :: cout << a[i] << std :: endl;
    }

    Stack<int> stack = Stack<int>();
    stack.push(4);stack.push(4);stack.push(4);stack.push(4);stack.push(4);
    std :: cout << stack.top() << std :: endl;

    Queue<int> queue = Queue<int>();
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    std :: cout << queue.head() << std :: endl;
    std :: cout << queue.tail() << std :: endl;
    std :: cout << queue.dequeue() << std :: endl;

    queue.clear();
    std :: cout << queue.size() << std :: endl;

    ////


}
//