#pragma once

#include "object.h"
#include <cassert>

/** represents an Object that points at its two neighbors */
class Node: public Object {
    public:
        Node* prev_;        //the node closer to the tail that is a neighbour
        Object* val_;       //the value of the node (the Object* stored inside)
        Node* next_;        //the node closer to the head that is a neighbour

        /**
         * the primary constructor for a Node
         * @param prev: the neighbouring node closer to the tail
         * @param val: the Object* stored in the node
         * @param next: the next Node in the linked list - closer to the head */
        Node(Node* prev, Object* val, Node* next) {
            this->prev_ = prev;
            this->val_ = val;
            this->next_ = next;
        }  

        /**
         * the method to get the neighbouring Node closer to the tail
         * @param prev: the previous Node in the linked list */
        void set_prev(Node* prev) {
            this->prev_ = prev;
        }

        /**
         * sets the next variable to a Node that will be closer to the head of the linked list
         * @param next: the neighbour closer to the head */
        void set_next(Node* next) {
            this->next_ = next;
        }
        
        /**
         * sets the value for this Node to the given Object*
         * @param val: the Object* that will be the value of this Node */
        void set_val(Object* val) {
            this->val_ = val;
        }
        
        // returns the Node* that is the neighbour of this node closer to the tail
        Node* prev() {
            return this->prev_;
        }
        
        // returns the Node* that the next_ val points to - the neighbour closer to the head of the LL
        Node* next() {
            return this->next_;
        }

        // returns the Object* value stored in this
        Object* get() {
            return this->val_;
        }
};


class Queue : public Object {
    public:
        Node* list_head_;
        Node* list_tail_;
        size_t size_;

        Queue() {
            this->list_head_ = NULL;
            this->list_tail_ = NULL;
            this->size_ = 0;
        }

        // copy constructor
        Queue(Queue* e) {
            this->list_head_ = NULL;
            this->list_tail_ = NULL;
            Queue* temp_queue = new Queue();
            size_t count = 0;

            while(e->peek() != NULL) {
                Object* tmp_obj = e->dequeue();
                temp_queue->enqueue(tmp_obj);
                String* s = dynamic_cast<String*>(tmp_obj);
                if (s != NULL) {
                    this->enqueue(new String(s->val_));
                } else {
                    this->enqueue(new Object(tmp_obj));
                }
                count += 1;
            }
            while(temp_queue->peek()) {
                e->enqueue(temp_queue->dequeue());
            }
        }

        ~Queue() {
            while(list_head_) {
                delete this->dequeue();
            }
        }

        // adds e to the back of the queue, returns this queue for chaining
        Queue* enqueue(Object* e) {
            if (this->size() == 0) {
                list_head_ = new Node(NULL, e, NULL);
                list_tail_ = list_head_;
            } else {
                list_tail_->set_prev(new Node(NULL, e, list_tail_));
                list_tail_ = list_tail_->prev();
            }
            this->size_ += 1;
            return this;
        }

        // removes the head of the queue and returns it
        Object* dequeue() {
            if (this->size() <= 0)
                return NULL;
            Object* e = list_head_->get();
            String * s = dynamic_cast<String*>(e);
            if (list_head_->prev() != NULL) {
                list_head_->prev()->set_next(NULL);
                list_head_ = list_head_->prev();
            } else {
                list_head_ = NULL;
                list_tail_ = NULL;
            }
            this->size_ -= 1;
            return e;
        }

        // returns the head of the queue without removing it
        Object* peek() {
            if (!list_head_) {
                return NULL;
            }
            return list_head_->get();
        }

        // returns the number of elements in queue
        size_t size() {
            return this->size_;
        }

        bool equals(Object* e) {
            Queue* q = dynamic_cast<Queue*>(e);
            if (q==NULL)
                return false;
            if (q->size() != this->size())
                return false;

            Node* list_head = NULL;
            Node* list_tail = NULL;

            Queue* temp_queue = new Queue();
            Queue* temp_queue_2 = new Queue();

            bool rv = true;
            while(q->peek() != NULL) {
                if (temp_queue->peek() == NULL) {
                    Object* tmp_obj = q->dequeue();
                    Object* tmp_obj2 = this->dequeue();
                    String* s1 = dynamic_cast<String*>(tmp_obj);
                    String* s2 = dynamic_cast<String*>(tmp_obj2);
                    if(rv && (s1 == NULL || s2 == NULL)) {
                        //puts("gets here :(");
                        rv = tmp_obj->equals(tmp_obj2);
                    } else if (rv /*&& s1!= NULL && s2!= NULL*/) {
                        rv = s1->equals(s2);
                    } else {}
                    temp_queue->enqueue(tmp_obj);
                    temp_queue_2->enqueue(tmp_obj2);
                } else {
                    Object* tmp_obj = q->dequeue();
                    Object* tmp_obj2 = this->dequeue();
                    String* s1 = dynamic_cast<String*>(tmp_obj);
                    String* s2 = dynamic_cast<String*>(tmp_obj2);
                    if(rv && (s1 == NULL || s2 == NULL)) {
                        rv = tmp_obj->equals(tmp_obj2);
                    } else if (rv) {
                        rv = s1->equals(s2);
                    } else {}
                    temp_queue->enqueue(tmp_obj);
                    temp_queue_2->enqueue(tmp_obj2);
                }
            }
            while(temp_queue->peek()) {
                q->enqueue(temp_queue->dequeue());
                this->enqueue(temp_queue_2->dequeue());
            }
            return rv;         
        }

        size_t hash() {
            return reinterpret_cast<size_t>(this);
        }
};