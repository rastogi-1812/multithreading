#include "nfc.h"
#include "glthread.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NFC_KEY_SIZE 64

typedef struct nfc_element_{
    glnode_t glnode;
    nfc_iter_cb_t nfc_callback;
}nfc_element_t;


void
nfc_handle_init(nfc_handle_t *handle_ptr){
    glthread_handle_init((glhandle_t*)handle_ptr);
}

void
nfc_add(nfc_handle_t *handle_ptr, 
    nfc_iter_cb_t callback_func){
    nfc_element_t *nfc_element = (nfc_element_t *) calloc( 1, sizeof(nfc_element_t));
    nfc_element->nfc_callback = callback_func;
    glthread_add_node(handle_ptr, &nfc_element->glnode);
}

static void 
nfc_iter_handler(glnode_t *glnode_ptr){
    nfc_element_t *nfc_node = (nfc_element_t *) glnode_ptr;
    nfc_node->nfc_callback();
}

void
nfc_iterate(nfc_handle_t *handle_ptr){
    iterate_over_glthread(handle_ptr, nfc_iter_handler);
}