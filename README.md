Object:  
- we included a copy constructor  
  
String:
- initialize a string by passing a string literal
- copy constructor included
- length does not include the null terminator
- compare returns values in the same manner that cstring.strcmp would
- equals compares more than their memory addresses  
  
Queue:  
- copy constructor included
- enqueue adds to the end of the queue
- dequeue removes from the head of the queue and returns it
- peek returns the head of the queue, but does not remove it
- size returns the number of elements in the queue
- equals compares the elements and order in the queue

NOTE: 
  - our Object and String classes were taken from a public repo another student (Chase Bishop) posted on piazza
  - repo link: https://github.com/chasebish/cwc_object_string/blob/master/string.h
