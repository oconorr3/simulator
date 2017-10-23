#ifndef NODE_H
#define NODE_H

#include <list>

#include "Event.h"

// Defines the Node class
class Node {
public:
    Node(int size, int id);

    /**
    Determines if the event is a disk read or write, and calls the appropriate
    private methods to handle that type. 

    NOTE: this could be changed to a bool to handle requests bigger than total disk size
    **/
    void processEvent(Event event);


private:
    /* PRIVATE VARIABLE DECLARATIONS */
    int diskSize;                   // The total disk space available
    int diskUsed;                   // The bytes used on the disk
    int nodeID;                     // ID of the node
    std::list<int> filesOnDisk;     // List of previous write sizes still stored on the disk

    /* PRIVATE FUNCTION DECLARATIONS */
    void runLRU();                  // Clears space on the disk using LRU
    void processDiskRead();         // Not sure what we want to do for reads yet.
    void processDiskWrite(int size);// Increment counter of disk space, update filesOnDisk, call LRU if not enough space


};

#endif
