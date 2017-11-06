#ifndef CONTROLLER_H
#define CONTROLLER_H

// Header for the Controller. This class will be in charge of creating threads and assigning
// loads to the threads

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "event.h"
#include "node.h"
#include <string>

// Definition of the Controller Class
class Controller {    
    public:
        /* CONSTRUCTORS */
        Controller(int numThreads, int numNodes, int nodeSize);

        /* PUBLIC FUNCTION DECLARATIONS */
        void addEvent(Event event);     // Adds an event to the taskQueue for the controller
        int getNumNodes();              // Returns the number of nodes 

        /**
        *   Joins all manager threads once their work is completed.
        *
        *   PRECONDITION: All work that will be assigned to the controller has been assigned
        *                 before shutdownController() is called.
        **/
        void shutdownController(); 


        void printNodeValues(char * filename);         // Prints the values of nodes in nodeID order


    private:
        bool shutdown;
        int numNodes;                   // Number of nodes to be simulated by the controller
        int numThreads;                 // Number of threads to be used by the controller
        int nodeSize;                   // The size (in bytes) of th disk capacity for a node
        Node * nodeList;                // Pointer to array of nodes tracked by the controller. Populated by spawnNodes()
        std::vector<std::thread> tpool; // Tracks the threads used by the Controller to track nodes
        std::condition_variable cv;     // Condition variable used to synchronise and signal task queue availability

        // Thread work distribution/synchronization variables
        std::queue<Event> *queueList;   // List of work queues. Each thread has one of these queues assigned to it
        std::mutex *queueLock;          // List of locks for the work queues
        int *threadBoundries;           // End markers for the manager threads partitions of nodeList (used for assigning work to the proper thread)
        std::condition_variable *cvList;// Condition variables for the work queues
        

        /* PRIVATE FUNCTION DECLARATIONS */
        void spawnThreads();            // spawns the threads that manage the nodes
        void spawnNodes();              // creates all nodes that are tracked by the controller

        void managerThread(int nodeRangeStart, int nodeRangeEnd, int id);
};

#endif
