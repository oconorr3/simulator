// Author: Justin Finger
// Last Update: 10/19/2017

#include "event.h"

/**
    Constructor for an Event object. Event objects define a disk read or write
    that a node must process.

    PARAMETERS:
        size_b    - The size of the disk request in bytes
        nodeID    - The numerical ID of the node to which this event is assigned
        type      - The type of the event (DISKREAD or DISKWRITE)
**/
Event::Event(int size_b, int nodeID, EventType type) {
    this->size_b = size_b;
    this->nodeID = nodeID;
    this->type   = type; 
    this->timestamp = 0;  
}

Event::Event(int size_b, int nodeID, EventType type, int timestamp) {
    this->size_b = size_b;
    this->nodeID = nodeID;
    this->type   = type; 
    this->timestamp = timestamp;    
}

Event::Event() {
    this->size_b = 0;
    this->nodeID = 0;
    this->type   = DISKREAD;   
}

/**
    Returns the size in bytes of the disk read/write request
**/
int Event::getEventSize() {
    return size_b;
}

/**
    Returns the type of the event (DISKREAD or DISKWRITE)
**/
EventType Event::getEventType() {
    return type;
}

int Event::getNodeID() {
    return nodeID;
}

int Event::getTimestamp() {
    return timestamp;
}

void Event::copyValues(Event e) {
    size_b = e.getEventSize();
    nodeID = e.getNodeID();
    type = e.getEventType();
    timestamp = e.getTimestamp();
}