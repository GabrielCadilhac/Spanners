#include <iostream>
#include <vector>

class Node {
    public :
        int id;
        int level; // The level where is this
        Node* parent;
        std::vector<int> neighbors;

        //Constructor for the root
        Node ()
        {
            id = 0;
        }

        Node(int nodeId, Node p, int lvl)
        {
            id = nodeId;
            parent = &p;
            level = lvl;
            neighbors = {};
        }

        //At the end the vector neighbors will be private to prevent adding without the addNeighbour method
        std::vector<int> getNeighbors(){
            return neighbors;
        }

        void addNeighbor(Node neighbor)
        {
            (*parent).printNeighbors();
            std::cout << "Current node : " << id << std::endl;
            if (level != neighbor.level){ // If neighbor and this are not on the same levels, they can't be neighbor
                return;
            }

            for ( unsigned int i = 0; i < (*neighbor.parent).getNeighbors().size(); i++){
                std::cout << "i = " << i << std::endl;
                int n1 = (*neighbor.parent).getNeighbors()[i];
                for ( unsigned int j=0; j < (*parent).getNeighbors().size(); j++){
                    int n2 = (*parent).getNeighbors()[j];
                    if (n1 == n2){ 
                        // We found a common neighbor from the parents
                        neighbors.push_back(neighbor.id);
                        neighbor.neighbors.push_back(this->id);
                    }
                }
            }
        }

        void printNeighbors()
        {
            std::cout << "Neighbor of " << id << " with size : " << neighbors.size() << " -> ";
             for (int n : neighbors){
                std::cout << n << " ";
            }
            std::cout << std::endl;
        }
};