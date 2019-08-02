//
// Created by decla on 5/2/2019.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

/*
 * Note: This priority queue uses a binary search tree where the keys
 * are the priorities and the values are the strings.  This is less efficient
 * than using a heap like we discussed in class, but it's quicker to implement.
 * In C++, we can use the multimap class which is just like map except it allows
 * multiple values per key.  (You don't have to worry about any of this code.)
 */

#include <string>
#include <map>
#include <iostream>

using namespace std;

class PriorityQueue
{
public:
    void insert(string s, int priority);    // add a new item into the priority queue
    bool contains(string s);  // check if this string already exists in the priority queue
    void changePriority(string s, int newpriority); // change the priority of an item already in the queue
    string extractMin();    // return the item with the minimum priority
    bool isEmpty() const;   // check if the queue is empty
    void print() const;     // print the elements & their priorities in the queue

private:
    multimap<int, string> pq;
};


#endif
