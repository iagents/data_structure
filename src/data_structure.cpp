#include "data_structure.h"

namespace data_structure
{
  Graph::Graph(int num_vertices)
  {
    num_vertices_ = num_vertices;
    // \todo{Need to check whether num_vertices_ is greater than zero
    node_ = new std::list<int>[num_vertices_];
  }

  void Graph::add_edge(int v, int w)
  {
    node_[v].push_back(w);
  }

  void Graph::BFS(int s)
  {
    if (s < 0 || s > num_vertices_) 
    {
      std::cerr << "[Error] the input index, " << s << ", is out of index!!!" << std::endl;
      return;
    }

    // Mark all the vertices not visited 
    bool *visited = new bool[num_vertices_];
    for (int i=0; i < num_vertices_; i++) 
    {
      visited[i] = false;
    }

    // Create a queue for BFS
    // \todo{Do you really need this?
    std::list<int> queue;

    // Mark the current node as visited and enqueue it.
    visited[s] = true;
    queue.push_back(s);

    std::list<int>::iterator itr;

    while(!queue.empty()) 
    {
      // Dequeue a vertex from the queue and print it.
      s = queue.front();
      std::cout << s << " ";
      queue.pop_front();

      // Get all adjacent vertices of the (just) dequeued vertex, s.
      // If an adjacent has not been visited, then mark it visited and enqueue it.
      for(itr = node_[s].begin(); itr != node_[s].end(); ++itr)
      {
	if(!visited[*itr])
	{
	  visited[*itr] = true;
	  queue.push_back(*itr);
	}
      }
    }
  }

  void Graph::DFS(int s)
  {
    bool *visited = new bool[num_vertices_];
    for (int i=0; i < num_vertices_; i++)
    {
      visited[i] = false;
    }

    recursive_DFS(s, visited);
  }

  void Graph::recursive_DFS(int s, bool visited[])
  {
    visited[s] = true;
    std::cout << s << " ";

    std::list<int>::iterator itr;
    for (itr = node_[s].begin(); itr != node_[s].end(); ++itr)
    {
      if(!visited[*itr])
      {
	recursive_DFS(*itr, visited);
      }
    }
  }
}
