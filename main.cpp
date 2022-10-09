#include <iostream>
#include <map>
#include <vector>
#include "node.cpp"

int main(int argc, char const *argv[])
{
    Node r; // Tree's root
    Node n1(1,r,1);
    Node n2(2,r,1);
    Node n3(3,r,1);

    //Adding manually some neighbors for nodes, just to try, at the end this can't will be done
    n1.neighbors.push_back(n2.id);
    n1.neighbors.push_back(n3.id);
    n2.neighbors.push_back(n1.id);

    //Creating children 
    Node n4(4,n1,2);
    Node n5(5,n1,2);
    Node n6(6,n2,2);
    
    //Try adding with the good method -> the parents of n5 and n6 must be neighbors
    n5.addNeighbor(n6);

    //Print the results
    n5.printNeighbors();
    n6.printNeighbors();

    std::cout << "Done !" << std::endl;
    return 0;
}
