#include "data_structure.h"

using namespace data_structure;

int main()
{
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  std::cout << "following is an example of Breadth-First Traversal (starting from the vertex 2)" 
	    << std::endl;
  g.BFS(2);
  std::cout << std::endl;

  std::cout << "follosing is an example of Depth-First Traversal (starting from the vertex 2)"
	    << std::endl;
  g.DFS(2);
  std::cout << std::endl;

  return 0;
}
  
