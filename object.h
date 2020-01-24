#pragma once

class Object {
    public:
        Object() {}

        // copy constructor
        Object(Object* e) {}

        ~Object() {}

        // compares hashes to check for equality
        bool equals(Object* e) {}

        size_t hash() {}
};