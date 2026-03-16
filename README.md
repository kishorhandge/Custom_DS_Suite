# Custom_DS_Suite

CustomDSSuite is a template-based Data Structure library in C++ built completely without using STL. 
It contains 279 manually implemented functions and provides common linear data structures like arrays, linked lists, stack, and queue.
The project focuses on understanding memory management, pointer manipulation, and generic programming by implementing everything from scratch.

Features:

Template-based generic design
279 manually implemented functions
Dynamic Array
Singly & Doubly Linked Lists (Linear & Circular)
Stack and Queue
No STL dependency
Header-only modular library
Namespace encapsulation (dslib)

Use Case :

#include "CustomDSSuite.hpp"
using namespace dslib;

Array<int> obj;
obj.InsertLast(10);
obj.InsertLast(20);
obj.Display();

