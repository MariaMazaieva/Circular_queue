 #include "queue.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>


 queue_t* create_queue(int capacity){
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->q_array = (void**)malloc(sizeof(void*) * capacity);

    q->capacity = capacity;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
    for (int i = 0; i < capacity; i++) {
     q->q_array[i] = NULL;
    }

    return q;

 }

 /* deletes the queue and all allocated memory */
 void delete_queue(queue_t *queue) {
   free(queue-> q_array);
   free(queue);
 }

 /*
  * inserts a reference to the element into the queue
  * returns: true on success; false otherwise
  */
 bool push_to_queue(queue_t *queue, void *data){
  if (queue->count == queue->capacity)
    return false;

  queue->q_array[queue->tail] = data;
  queue->tail = (queue->tail + 1) % queue->capacity;
  queue->count++;

  return true;
 }

 /*
  * gets the first element from the queue and removes it from the queue
  * returns: the first element on success; NULL otherwise
  */
 void* pop_from_queue(queue_t *queue){
  if (queue->count == 0) {
   return NULL;
  }
  void *element = queue->q_array[queue->head];
  queue->head = (queue->head + 1) % queue->capacity;
  queue->count--;


  return element; // Return the retrieved data

 }

 /*
  * gets idx-th element from the queue, i.e., it returns the element that
  * would be popped after idx calls of the pop_from_queue()
  * returns: the idx-th element on success; NULL otherwise
  */
 void* get_from_queue(queue_t *queue, int idx){
  if (idx < 0 || idx >= queue->count) {
   return NULL; // Invalid index
  }
  int position = (queue->head + idx) % queue->capacity;
  void* element = queue->q_array[position];
  return element
      ;
 }

 /* gets number of stored elements */
 int get_queue_size(queue_t *queue){
 return queue -> count ;
 }
