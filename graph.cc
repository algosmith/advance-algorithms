#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack> 
#include <vector>
using namespace std;
struct nodeT {
  vector  <nodeT *> connect  ;
  int color ;
  int wt ;
};


/*class Graph {
  vector <struct node *> vertices ;
  int vn ;
  char color ;
 public: 
   Graph() {
     vn = 0 ; 

   }
   void addnode () ;
   void addedge(int ver1, int ver2) ;
   void traverse_node () ;
} ;
*/

int vn ;

void addNode (vector <nodeT *> &vertices) 
{
  struct nodeT * temp ;
  temp = new nodeT ;
  vertices[vn] = temp ;
  vertices[vn]->wt = vn ;
  vertices[vn]->color = 0 ;
  vn++ ;

 // cout << "Node added to the list, Node number is: " << vn-1 <<endl;
 // cout << "Color of the node is: "<< vertices[vn-1]->color << endl ;

}

void addEdge(int ver1, int ver2, vector <nodeT *> &vertex) {
  cout << "Color: "<< vertex[0]->color << endl ;
  cout << "Size: "<<vertex[0]->connect.size()<<endl;
  vertex[ver1]->connect.push_back(vertex[ver2]) ;
//  cout <<"Hello\n" ;
  vertex[ver2]->connect.push_back(vertex[ver1]) ;
  cout << "Size: "<<vertex[0]->connect.size()<<endl;

}
void visitvertex(struct nodeT *vert) 
{
  vert->color = 1;
  cout << "In Visit Vertex\n" ;
  cout <<"Connect SIze: "<< vert->connect.size() << endl ;
  cout << "Visited Vertex is: " << vert->wt << endl ;
  for (int j = 0; j < vert->connect.size() ; j++) 
  {
    if ( vert->connect[j]->color == 0) {
      visitvertex(vert->connect[j]) ;
    }
  }
}

void DFS (vector <nodeT *> &vertices) 
{
  int i = 0 ;
  cout << "Size: " << vertices.size() <<endl ;

  for (i=0; i<vn; i++) 
  {
   // cout << "Hello\n" ;
    vertices[i]->color = 0 ;
  }

  //cout << "Size: " << vertices.size() <<endl ;
  for (i = 0; i<vn; i++) 
  {
    if (vertices[i]->color == 0) {
      cout << "Hello\n" ;
      visitvertex(vertices[i]) ;
    }
  }
}



main()
{
   int ch ;
   int v1, v2 ;
   vector <nodeT *> vertices(5) ;
   for(;;) {
   printf("To add node in the list enter 1, Add edge in the list: 2, Implement DFS: 3\n") ;
   cin >> ch ;
   switch(ch) {
     case 1: addNode(vertices) ;
              break ;
     case 2:  cout << "Enter the vertex between which edge to be added\n";
              cin >> v1 >> v2 ;
	      
	      addEdge(v1, v2, vertices) ;
              break ;
     case 3: DFS(vertices) ;
              break ;
     case 4: exit(0) ;
    }
   }
}








