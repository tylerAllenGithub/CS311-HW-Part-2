//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Tyler Allen
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <ctype.h>
#include "vstack.h"

//Purpose of the program: Utilize the stack to create a postfix calculator
//Algorithm: If element added to stack is number change to int and add to stack. 
//If element entered is operator, pop last 2 operands on stack and perform specified operation
//Display result

int main()
{
  vstack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  el_t result; //stores result of calculation to be pushed onto the stack  

  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), convert to integer 
	  if(isdigit(item))
	    {
	      int a =(item)-48;
	      postfixstack.push(a); //push integer onto the stack (Beware of Overflow)
	      postfixstack.displayAll();//display the newly updated stack
	    }

	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
		result = box2-box1;//store answer into result
	      //do the + and * cases
	      else if(item=='+')
		result = box1+box2;//store answer into result
	      else if(item=='*')
		result = box1*box2;//store answer into result
	      postfixstack.push(result); 
	      //  Finally push the result onto the stack
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (vstack::Overflow) 
	{ cerr<<"Expression is too long."<<endl;//expression is too long
	  return 0;
        }
      catch (vstack::Underflow) // for too few operands
	{
	  cerr<<"Too few operands(numbers)."<<endl;
	  return 0;
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr<<"There was an invalid entry."<<endl;
	  return 0;
	}
      // go back to the loop after incrementing i
      i++;
    }// end of while
  postfixstack.displayAll();//display final stack elements

  // After the loop successfully completes:
  // The result will be at the top of the stack. Pops it and show it.

  postfixstack.pop(result);//pop top element into result
  // If anything is left on the stack, an incomplete expression was found.
  if(!postfixstack.isEmpty())//Stack should be empty here, if not displays error
      {
	cerr<<"An incomplete expression was found. (The Numbers and signs don't match)"<<endl;// Inform the user.
	return 0;
      }
  cout<<"Result: "<<result<<endl;//displays result for clarity  

}// end of the program
