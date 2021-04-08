// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>
#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().

using namespace std;

const int VERTICES = 9;
 
int minDistance(int distance[], bool shortestPathFoundSet[]);
void printSolution(int distance[], int n);

void pressAnyKey();

int minDistance(int distance[], bool shortestPathFoundSet[])
{
   int min = INT_MAX, minIndex;
 
   for (int v = 0; v < VERTICES; v++)
   {
     if ( (shortestPathFoundSet[v] == false) && (distance[v] <= min) )
	 {
         min = distance[v], minIndex = v;
	 }
   }
   return minIndex;
}
 
void printSolution(int distance[], int n)
{	
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < VERTICES; i++)
	{
		cout << i << "\t" << distance[i] << endl;
	}
}
 
void dijkstra(int graph[VERTICES][VERTICES], int src)
{
     int distance[VERTICES];     
     bool shortestPathFoundSet[VERTICES];  
     
     for (int i = 0; i < VERTICES; i++)
	 {
        distance[i] = INT_MAX;
		shortestPathFoundSet[i] = false;
	 }
	      
     distance[src] = 0; 
     
     for (int count = 0; count < VERTICES-1; count++)
     {     
       int u = minDistance(distance, shortestPathFoundSet);       
       shortestPathFoundSet[u] = true; 
       
       for (int v = 0; v < VERTICES; v++)
	   {
         if (!shortestPathFoundSet[v] && graph[u][v] && distance[u] != INT_MAX 
                                       && distance[u] + graph[u][v] < distance[v])
		 {
            distance[v] = distance[u] + graph[u][v];
		 }
	   }
     } 
     
     printSolution(distance, VERTICES);
}
 
int main()
{
	// Adjacency matrix.
	int graph[VERTICES][VERTICES] = 
		{		
		//	 0   1   2   3   4   5   6   7   8
			{0,  4,  0,  0,  0,  0,  0,  9,  0},	// 0                       
			{4,  0, 10,  0,  0,  0,  0, 13,  0},	// 1               
			{0, 10,  0,  8,  0,  4,  0,  0,  2},    // 2               
			{0,  0,  8,  0,  9, 15,  0,  0,  0},	// 3               
			{0,  0,  0,  9,  0, 10,  0,  0,  0},	// 4               
			{0,  0,  4, 15, 10,  0,  2,  0,  0},	// 5               
			{0,  0,  0,  0,  0,  2,  0,  1,  6},	// 6               
			{9, 13,  0,  0,  0,  0,  1,  0,  8},	// 7               
			{0,  0,  2,  0,  0,  0,  6,  8,  0}		// 8
		};
 
    dijkstra(graph, 0);
 
	pressAnyKey();

    return 0;
}

void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					
}