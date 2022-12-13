// NAME: Minh Nguyen 
// DATE: 02/09/2022
// FILE: intFunc.h
// DESCRIPTION: Definition of the IntFunc class.

#ifndef INTFUNC_H
#define INTFUNC_H

#include <iostream>
#include <string>
using namespace std;

class IntFunc
{
private:
  //Complete the private section of the class
  int *inputs;
  int *outputs;
  int *range;
  int *sortInput;
  int size;
  int count;
  int maxX, maxY;
  
  // Add additional data members as needed.
  
  
public: 
  // Constructor: the maximum values in the domain and the codomain 
  //              are passed in as arguments.
  IntFunc(int x, int y);

  // Deconstructor
  ~IntFunc();
  
  // Adds (x,y) to the function.
  // Prints a warning if the input already exists.
  void addPair(int x, int y);
  
  // Displays the function to the screen.
  void printFx() const;
  
  // Displays the range of the function.
  void printRange() const;
  
  // Determines if the function is onto, returns true or false
  bool onto() const;
  
  // Determines if the function is one to one, returns true or false
  bool oneToOne() const;
  
  // displays the inverse function if it exists
  IntFunc inverse() const;
};

#endif
