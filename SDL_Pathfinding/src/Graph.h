#pragma once
#include "Connection.h"
#include <vector>
class Graph
{
private:
	// Returns an array of connections outgoing from the given node
	std::vector<Connection> GetConnections(Node* fromNode);

	bool EqualNode(Node a, Node b) {
		return (a.GetCoords() == b.GetCoords());
	}
public:
	std::vector<Connection> connections;

};
