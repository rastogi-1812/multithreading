#ifndef __GLTHREAD_H__
#define __GLTHREAD_H__


typedef struct glnode_{
    struct glnode_ *prev;
    struct glnode_ *next;
}glnode_t;

typedef struct glhandle_{
    glnode_t *head;
    glnode_t *tail;
    unsigned int no_of_nodes;
}glhandle_t;


typedef void (*iterate_over_glthread_callback_t)(glnode_t *glnode_ptr);


void glthread_handle_init(glhandle_t *handle);

void glthread_add_node(glhandle_t* glhandle_ptr, glnode_t *glnode_ptr);

void iterate_over_glthread(glhandle_t* glhandle_ptr, iterate_over_glthread_callback_t fun_callback);

#endif /*__GLTHREAD_H__*/