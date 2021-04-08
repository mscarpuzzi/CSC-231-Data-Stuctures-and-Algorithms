// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>
#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().

using namespace std;

const int VERTICES = 9; //max number of vertices
 
int minDistance(int distance[], bool shortestPathFoundSet[]); //function declarations
void printSolution(int distance[], int n);

void pressAnyKey();

int minDistance(int distance[], bool shortestPathFoundSet[])  //finding the vertex with the minimum distance value from
                                                             // the set of vertices not within the path tree 
{

   int min = INT_MAX, minIndex;
 
 //this is the check for vertices in the path tree set
   for (int v = 0; v < VERTICES; v++)
   {
      //if this vertex is not in the tree, set that value  
     if ( (shortestPathFoundSet[v] == false) && (distance[v] <= min) )
	 {
         min = distance[v], minIndex = v;
	 }
   }
   return minIndex;
}
 
void printSolution(int distance[], int n)   //print the distance array  
{	
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < VERTICES; i++)
	{
		cout << i << "\t" << distance[i] << endl;
	}
}
 
void dijkstra(int graph[VERTICES][VERTICES], int src) //a function using an adjacency matrix representation of Dijkstra's Algorithm
{
     int distance[VERTICES]; //Output for our printSolution function    
     bool shortestPathFoundSet[VERTICES]; //for our shortest path; set true when we find it; source -> i  
     
     for (int i = 0; i < VERTICES; i++)
	 {
        //set all vertex-to-vertex unreachable
        distance[i] = INT_MAX;
		shortestPathFoundSet[i] = false;
	 }
	      
     distance[src] = 0; // source -> source = 0
     
     //find shortest path
     for (int count = 0; count < VERTICES-1; count++)
     {     
       int u = minDistance(distance, shortestPathFoundSet); //u is the vertex v-1 -> u - (v-1) = 0 = distance[src]      
       shortestPathFoundSet[u] = true; //flag u as processed; 
       
       for (int v = 0; v < VERTICES; v++)
	   {
         if (!shortestPathFoundSet[v] && graph[u][v] && distance[u] != INT_MAX 
                                       && distance[u] + graph[u][v] < distance[v]) //edge weights from u to v are checked to see if it is the shortest path  
		 {
            distance[v] = distance[u] + graph[u][v]; //distance[v] is updated if it is not in shortestPathFoundSet   
		 }
	   }
     } 
     
     printSolution(distance, VERTICES); //print the results
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
			{0,  0,  0,  9,  0, 10,  0,  0,  0},	// 4     \\The graph          
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