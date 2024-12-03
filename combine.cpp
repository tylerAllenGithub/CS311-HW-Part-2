// HW 2 Part 2
// Name: Tyler Allen
// Compiler Used: g++
// File Type: .cpp
// Purpose of the program: To complete the combine function of Merge Sort 
// Algorithm: Take two ordered lists and combine them into a larger sorted list with logn comparisons
//

#include <iostream>
#include <vector>
using namespace std;

void Combine(vector<int> L1, vector<int> L2, vector<int> &L3)
{
  int i = 0;//L1 index
  int j = 0;//L2 index
  while(L3.size()<(L1.size()*2))//if L3 is the same size as L1 and L2 combined
    {
      if(i>=L1.size())//if L1 has already been looked through
	{
	  while(j<L2.size())//then add all of L2 to L3
	    {
	      L3.push_back(L2.at(j));
	      j++;
	    }
        }
      else if(j>=L2.size())//if L2 has already been looked through
	{
	  while(i<L1.size())//then add all of L1 to L3
		{
		  L3.push_back(L1.at(i));
		  i++;
		}   
	}
      else if(L1.at(i)==L2.at(j))//if the elements in L1 and L2 are the same
	{
	  cout<<"Comparing "<<L1.at(i)<<" and "<<L2.at(j)<<endl;
	  L3.push_back(L1.at(i));//add L1 element to L3
	  L3.push_back(L2.at(j));//add L2 element to L3
	  i++;//increment L1 index
	  j++;//increment L2 index
	}
      else if(L1.at(i)<L2.at(j))//if L1 element is less than L2 element
	{
	  cout<<"Comparing "<<L1.at(i)<<" and "<<L2.at(j)<<endl;
	  L3.push_back(L1.at(i));//add L1 element to L3
	  i++;
	}
      else //if L2 element is less than L1 Element
	{
	  cout<<"Comparing "<<L1.at(i)<<" and "<<L2.at(j)<<endl;
	  L3.push_back(L2.at(j));//add L2 element to L3
	  j++;
	}
    }
}
//main function
int main()
{
  //declare vectors
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  //declare input variables
  int L1Input=0;
  int L2Input=0;
  //initial output messages for entering L1 values
  cout<<"Press -1 to stop entering values for L1, or -2 to quit"<<endl;
  cout<<"Please enter numbers in increasing order for L1"<<endl;
  cout<<endl;
  
  while(L1Input>=0)
    {
      cout<<"Press -1 to stop entering values for L1, or -2 to quit"<<endl;
      cout<<"Enter a value in in increasing order for L1: "<<endl;
      cin>>L1Input;
      L1.push_back(L1Input);
    }
  if(L1Input==-2)
    {
      cout<<"-2 was entered. Program is ending."<<endl;
      return 0;
    }
  //Inputs for L2 code
  L1.pop_back();//get rid of -1 that was entered

  cout<<"Press -1 to stop entering values for L2, or -2 to quit"<<endl;
  cout<<"Please enter numbers in increasing order for L2"<<endl;
  cout<<endl;

  while(L2Input>=0)
    {
      cout<<"Press -1 to stop entering values for L2, or -2 to quit"<<endl;
      cout<<"Enter a value in in increasing order for L2: "<<endl;
      cin>>L2Input;
      L2.push_back(L2Input);
    }
  if(L2Input==-2)//for exit case: if -2 is entered
    {
      cout<<"-2 was entered. Program is ending."<<endl;
      return 0;
    }
  else if(L2Input==-1&&L2.size()<L1.size())
    {
      cout<<"Error, not enough elements were entered into L2. L2 and L1 must be of same size."<<endl;
      cout<<"Exiting Program..."<<endl;
      return 0;
    }
  L2.pop_back();//gets rid of -1 that was entered

  Combine(L1, L2, L3);//calls Combine function

   for(int i = 0; i<L3.size();i++)
     {
       cout<<L3.at(i)<<" ";
     }
   cout<<endl;
  return 0;
}
