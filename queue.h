#pragma once

#include "object.h"

class Queue : public Object {
    public:
        Queue() {}

        // copy constructor
        Queue(Queue* e) {}

        ~Queue() {}

        // adds e to the back of the queue, returns this queue for chaining
        Queue* enqueue(Object* e) {}

        // removes the head of the queue and returns it
        Object* dequeue() {}

        // returns the head of the queue without removing it
        Object* peek() {}

        // returns the number of elements in queue
        size_t size() {}

        bool equals(Object* e) {}

        size_t hash() {}
};