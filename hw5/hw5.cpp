//Name: Minh Nguyen
//Date: Friday March 4, 2022
//HW5.cpp

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "schedule.h"

void readFile(string filename);

int main()
{
  readFile("courses-sample.csv");
  readFile("courses.csv");

  cout << "This is the end of the program. Goodbye!" << endl << endl;
}


void readFile(string filename)
{
  int count = 0, vertex = 0, tc1 = 0, tc2 = 0, value, num = 0, array = 100;
  string word, line;
  int* temp1;
  int* temp2;
  
  
  ifstream file;
  
  file.open(filename);
  if(!file){ 
    cout << "File problem... exiting program..." << endl;
    return;
  }
  
  while(getline(file, line)){
    stringstream s(line);
    while(getline(s, word, ',')){
      if(count == 0){
        vertex = stoi(word);
        temp1 = new int[array];
        temp2 = new int[array];
        count = 1;
      }else if(count == 1){
        count = 2;
      }else if(count == 2){
        value = stoi(word);
        temp1[tc1] = value;
        tc1++;
        count = 3;
      }else if(count == 3){
        value = stoi(word);
        temp2[tc2] = value;
        tc2++;
        count = 1;
        num++;
      }
    }
  }
  file.close();

  //testing from
  cout << endl << "TESTING FROM " << filename << endl << endl;
  
  //constructor
  Schedule s(vertex);
  
  //add edges
  for(int i = 0; i < num; i++){
    s.addEdge(temp1[i], temp2[i]);
  }
  
  delete [] temp1;
  delete [] temp2;

  //display the adjacency matrix
  s.display();

  //which are not adjacent
  int tempCount = 1;
  for(int i = 0; i < vertex; i++){
    for(int j = 0; j < tempCount; j++){
      if(i == j){
        count++;
        count--;
      }else if(s.isAdjacent(i,j)){
        count++;
        count--;
      }else
        cout << endl << i << " and " << j << " are not adjacent." << endl;
    }
    tempCount++;
  }
  
  //display the in-degree of all verticies
  int degree;
  for(int i = 0; i < vertex; i++){
    degree = s.degree(i);
    cout << endl << "deg(" << i << ") = " << degree << endl;
  }
  
  //color the verticies
  s.colorGraph();
  
  //display a valid schedule
  s.printSchedule();
  
}
