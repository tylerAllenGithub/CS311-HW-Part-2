//INSTRUCTION
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Tyler Allen
//Compiler:  g++
//File type: stack implementation file
//=========================================================
#ifndef VSTACK_CPP
#define VSTACK_CPP//include guards

using namespace std;  
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  To utilize stack functions with a vector data type
//Algorithm: Implements stack with a vector which includes updating
//previous stack functions built for use by array. Elements will be added and removed from the stack.

vstack::vstack()
{ 
  //nothing to do
}  
//PURPOSE:  Destructor clears leftover elements in stack
vstack::~vstack()
  {
    clearIt();//calls clearIt function
  }
//PURPOSE: checks size and returns true if empty, false otherwise.
//the stack is empty when size is less than or equal to 0
bool vstack::isEmpty()
{ if (el.size() <= 0)//check size
      return true; 
  else 
      return false;
}    
//PURPOSE: Tells you when stack is full
//It is never full though.
bool vstack::isFull()
{ 
    return false;
}
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el
//PARAMETER: pass the element (elem) to be pushed 
 void vstack::push(el_t elem)
{ 
  if (isFull())
     throw vstack::Overflow();
  else 
  { 
    el.push_back(elem); //push element onto the back of the stack
  }
}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, store value about to be popped in elem  
 //PARAMETER: provide a holder (elem) for the element about to be popped (pass by ref)
//then remove element at back of stack
 void vstack::pop(el_t& elem)
{ 
   if (isEmpty()) throw vstack::Underflow();
   else 
     { 
       elem = el.back();
       el.pop_back();
     }
 }
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from stack to elem
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void vstack::topElem(el_t& elem)
{ if (isEmpty())
    throw vstack::Underflow();
  else 
    {
      elem = el.back();
    } 
 }
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void vstack::displayAll()
 {
   if (isEmpty()) 
     cout << "[ empty ]" << endl;//outputs empty 
   else 
     for (int i=el.size()-1; i>=0; i--)//start from top, goes down to zero
     { 
       cout << el.at(i) << endl; 
     }
       cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void vstack::clearIt()
 {// local variable for storage from pass by reference
   int local;
   //while the stack is not empty
   while(!vstack::isEmpty())
     {
       pop(local);//pops local variable for pass by reference call to pop
     }
 }
 
#endif
