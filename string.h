#pragma once

#include "object.h"

class String : public Object {
    public:
        String(const char* s) {}

        String(String* e) {}

        ~String() {}

        // returns the length of the string (in characters)
        size_t length() {}

        // compares strings (in the same manner as strcmp)
        int compare(String* e) {}

        bool equals(Object* e) {}

        size_t hash() {}
}