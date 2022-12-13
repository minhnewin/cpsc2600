//Name: Minh Nguyen
//Date: Friday March 4, 2022
//schedule.h

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
using namespace std;

class Schedule
{
private:
  int** courses;  //two-dimensional array for storing the graph
  int size;   //the number of courses (i.e. verticies)
  int* colors;    //an array to store the "color" of each course. For convenience, we will be representing a color by an integer (ex. 0 representing "red", 1 representing "blue", ect.)
  int maxColor;
  
public:
  Schedule(const Schedule&);//impllement copy constructor
  Schedule(int n);    //a constructor that creates the graph consisting of n verticies and no edges.
  ~Schedule();    //an appropriate deconstructor
  void addEdge(int a, int b); //adds the edge {a,b} to the graph. remember this is an undirected graph.
  void display() const;   //displays the graph's adjacency matrix to the screen using this format
  //single space between digits
  //first row (top) and first column (left) is vertex 0, second row and column is vertex 1, ... last row (bottom) and last column (right) is vertex n - 1
  bool isAdjacent(int a, int b);  //returns whether verticies a and b are adjacent
  void colorGraph();  //uses greedy coloring algorithm to figure out a valid coloring of the graph. Sets colors[i] to an integer corresponding to the iths course color. Prints the colors array after assigning each course to a color. Colors can be printed as c0, c1, c2, ect.
  void printSchedule();   //displays a schedule where no adjacent courses have an exam at the same time
  int degree(int i) const;    //returns the degree of vertex i
};

#endif
