//lang::CwC
#pragma once

#include <cstdlib>

/**
 * A class that represents the top of the object hierarchy.
 * author: chasebish */
class Object {
public:
  size_t hash_;

  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Default Object constructor */
  Object() {
    hash_ = hash();
  }

  /* Default Object destructor, to be overriden by subclasses */
  virtual ~Object() {}


  /** VIRTUAL METHODS **/

  /* Returns whether two objects are equal, to be overriden by subclasses */
  virtual bool equals(Object* const obj) { return this == obj; }

  size_t hash_me_() {
    return reinterpret_cast<size_t>(this);
  }

  /* Returns an object's hash value. Identical objects should have identical hashes */
  virtual size_t hash() {return  hash_ ? hash_ :  hash_ = hash_me_();}

  char* duplicate_(const char* s) {                                               
    char* res = new char[strlen(s) + 1];                                         
    strcpy(res, s);                                                              
    return res;                                                                  
  }                                                                              
  char* duplicate_(char* s) {                                                     
    char* res = new char[strlen(s) + 1];                                         
    strcpy(res, s);                                                              
    return res;                                                                  
  }
};
