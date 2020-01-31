//lang::CwC
#pragma once

#include "object.h"
#include <cstdlib>
#include <cstring>
#include <cstdio> 

/**
 * An immutable String class representing a char*
 * author: chasebish */
class String : public Object {
public:
  size_t size_;
  char* val_;

  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates a String copying s */
  String(const char* s) {
    size_ = strlen(s);                                                           
    val_ = duplicate_(s);
  }

  /** Construct a string copying s. Does not take ownership of s. */
    String(char* s) {
      this->val_ = duplicate_(s);
      this->size = strlen(s);
    };

  /* Copies a String copying the value from s */
  String(String* const s) {
    char* cs = s->val_;
    size_ = strlen(cs);                                                           
    val_ = duplicate_(cs); 
  }

  /* Clears String from memory */
  ~String() {
    delete[] val_;
  }


  /** INHERITED METHODS **/

  /* Inherited from Object, generates a hash for a String */
  size_t hash() {
    return hash_me_();
  }

  size_t hash_me_() {
    size_t hash = 0;                                                             
    for (size_t i = 0; i < size_; ++i)                                           
      hash = val_[i] + (hash << 6) + (hash << 16) - hash;                        
    return hash;    
  }

  /* Inherited from Object, checks equality between an String and an Object */
  bool equals(Object* const obj) {
    if (obj == nullptr) return false;                                          
    String* tgt = dynamic_cast<String*>(obj);                                  
    if (tgt == nullptr) return false;                                            
    return this->hash() == obj->hash();
  }


  /** STRING METHODS **/
  
  /** Compares strings based on alphabetical order
   * < 0 -> this String is less than String s
   * = 0 -> this String is equal to String s
   * > 0 -> this String is greater than String s
   */
  int cmp(String* const s) {
    return strcmp(val_, s->val_);
  }

  /* Creates a new String by combining two existing Strings */
  String* concat(String* const s) {
    char* res = new char[size_ + s->size() + 1];                             
    for (size_t i = 0; i < size_; i++)                                           
      res[i] = val_[i];                                                          
    for (size_t i = size_, j = 0; i < size_ + s->size(); i++, j++)           
      res[i] = val_[j];                                                          
    res[size_] = '\0';                                                           
    return new String(res);
  }

  /* Returns the current length of the String */
  size_t size() {
    return size_;
  }
};
