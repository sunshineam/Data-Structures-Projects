// 
// pq_struct.h
// 
// Edit this to flesh out the pq structure as appropriate. You may
// also add the function prototypes for anything else, and implement
// them in pq.cpp.
//
// You will turn in this file and pq.cpp to retrograde.
//
// Your Name: Adam Sunshine
#include <string>
#ifndef pq_struct_h
#define pq_struct_h

struct pq {
	pq* queue;
	float priority;
	std::string text;
	pq* next;
  // implement me
};

#endif
