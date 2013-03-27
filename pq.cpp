//
// pq.cpp
//
// Decide how you want to implement this: linked list? heap? array?
// magic pixie dust? The choice is yours.
//
// NOTE: You will need to edit pq_struct.h as appropriate, depending
// on your implementation strategy. You will turn in this file (your
// implementation of everything) and pq_struct.h (your definition of
// the pq structure and any helper functions you might create).

// Your Name: Adam Sunshine

#include <queue>
#include <string>
#include "pq.h"
#include "pq_struct.h"

/**
 * Initialize an empty priority queue.
 *
 * This is needed for unit testing. I'll do something like this:
 *
 *   pq* queue = init_priority_queue();
 *   string text = "Speaker of the House";
 *   insert(queue,  text, 7.9);
 *   text = "President";
 *   insert(queue, text, 10.0);
 *   text = "Congressional Staffer";
 *   insert(queue, text, 2.0);
 *   cout << remove(queue) << endl; // President
 *   cout << remove(queue) << endl; // Speaker of the House
 *   cout << remove(queue) << endl; // Congressional Staffer
 *
 **/
pq* init_priority_queue() {
	pq* queue = new pq;
	queue->priority = 0;
	queue->text = " ";
	queue->next = NULL;
	return queue;
  
}

/**
 * Insert the given text information into the queue with the specified
 * priority.
 *
 * Larger priority values have precedence. So if I add "foo" at
 * priority 5.0 and "bar" at priority 5.1, "bar" will be removed
 * before "foo".
 *
 * Priority values may be negative, zero, or positive.
 **/
void insert(pq* &queue, string &text, float priority) 
{
	pq* cursor = queue;
	pq* new_pq = init_priority_queue();
	new_pq->text = text;
	new_pq->priority = priority;
	if (queue->next==NULL && queue->priority==0)
	{
		new_pq->next = NULL;
		queue = new_pq;
	}
	else
	{
		if ( cursor->priority < priority)
		{
			new_pq->next = cursor;
			queue = new_pq;
		}
		else
		{
			while ( cursor->next)
			{
				if (priority > cursor->next->priority)
				{
					new_pq->next = cursor->next;
					cursor->next = new_pq;
					break;
				}
				cursor = cursor->next;
			}
			cursor->next = new_pq;
		}
	}	
		
			
  
}

/**
 * Remove the highest priority element from the queue and return it.
 **/
string remove(pq* &queue) 
{
	pq* temp = queue;
	queue = queue->next;
	temp->next = NULL;
	return temp->text;
}

/**
 * Return the highest priority element in the queue but do not alter
 * the queue's membership.
 **/
string peek(pq* &queue) 
{
	return queue->text;
}

bool contains (pq* &queue, string &text)
{
	pq* cursor = queue;
	if (queue == NULL)
		return false;
	else
	{
		while (cursor->next)
		{
			if ( cursor->text == text)
				return true;
			else
				cursor = cursor->next;
		}
	}
	if (cursor -> text == text )
		return true;
	else
		return false;
}
		
