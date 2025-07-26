#include "glthread.h"
#include <stdlib.h>
#include <stdio.h>

void glthread_handle_init(glhandle_t *glhandle_ptr){
    glhandle_ptr->head = NULL;
    glhandle_ptr->tail = NULL;
    glhandle_ptr->no_of_nodes = 0;
}

void glthread_add_node(glhandle_t* glhandle_ptr, glnode_t *glnode_ptr){
    if(glhandle_ptr->tail == NULL){
        glnode_ptr->prev = NULL;
        glnode_ptr->next = NULL;
        glhandle_ptr->head = glnode_ptr;
        glhandle_ptr->tail = glnode_ptr;
    }
    else{
        glnode_ptr->prev = glhandle_ptr->tail;
        glnode_ptr->next = NULL;
        glhandle_ptr->tail->next = glnode_ptr;
        glhandle_ptr->tail = glnode_ptr;
    }
    glhandle_ptr->no_of_nodes++;
}

void iterate_over_glthread(glhandle_t* glhandle_ptr, iterate_over_glthread_callback_t fun_callback){
    glnode_t *glnode_ptr = NULL;
    for(glnode_ptr = glhandle_ptr->head; glnode_ptr != NULL; glnode_ptr = glnode_ptr->next){
        fun_callback(glnode_ptr);
    }
}