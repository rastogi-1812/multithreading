#ifndef __NFC_H__
#define __NFC_H__

#include "glthread.h"

typedef glhandle_t nfc_handle_t;

typedef void (*nfc_iter_cb_t)(void);

void
nfc_handle_init(nfc_handle_t *handle_ptr);

void nfc_add(nfc_handle_t *handle_ptr,
    nfc_iter_cb_t callback_func);

void nfc_iterate(nfc_handle_t *handle_ptr);

#endif /*__NFC_H__*/