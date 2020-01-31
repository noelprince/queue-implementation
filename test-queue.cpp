#include "object.h"
#include "string.h"
#include "queue.h"

// testing output functions taken from starter tests of warmup 2
void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */}
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

int main(int argc, char** argv) {
    // Object tests
    Object* a = new Object();
    Object* b = new Object();
    Object* c = new Object(a);
    //t_true(a->equals(c));

    // String tests
    String* p = new String("hello");
    String* q = new String("world");
    String* r = new String(p);
    t_true(p->length() == 5);
    t_false(p->equals(q));
    t_true(p->equals(r));
    t_true(p->compare(q) < 0);
    t_true(p->compare(r) == 0);

    // Queue tests
    Queue* x = new Queue();
    Queue* y = new Queue();
    t_true(x->peek() == nullptr);
    t_true(x->dequeue() == nullptr);
    x->enqueue(p)->enqueue(q);
    Queue* z = new Queue(x);
    t_false(x->equals(y));
    t_true(x->equals(z));
    t_true(x->size() == 2);
    t_true(x->dequeue()->equals(p));
    y->enqueue(q);
    x->enqueue(p);
    y->enqueue(p);
    t_true(x->equals(y));
    t_true(x->peek()->equals(q));
    
    Queue* w = new Queue();
    w->enqueue(a)->enqueue(b);
    t_true(w->size() == 2);
    t_true(w->dequeue()->equals(a));
    t_true(w->peek()->equals(b));

    return 0;
}