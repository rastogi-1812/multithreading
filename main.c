#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#include "nfc.h"


// typedef void* thread_fn_arg_t;
// typedef void* thread_fn_ret_t;

// typedef thread_fn_ret_t (*thread_fn_callback_t)(thread_fn_arg_t);

// void
// thread_create(pthread_t *pthread_handle, thread_fn_callback_t callback_fn, thread_fn_arg_t args){
//     pthread_attr_t attr;
//     pthread_attr_setdetachstate(&attr,
//             PTHREAD_CREATE_JOINABLE);
//     pthread_create(pthread_handle,
//                     &attr,
//                     callback_fn,
//                     args);
// }



// thread_fn_ret_t
// task(thread_fn_arg_t args){
//     int id = *(int *)args;
//     while(1){
//         printf("Hello from thread %d\n",id);
//         sleep(1);
//     }
// }




void fun0(){
    printf("Hello World from fun0\n");
}

void fun1(){
    printf("Hello World from fun1\n");
}

void fun2(){
    printf("Hello World from fun2\n");
}

void fun3(){
    printf("Hello World from fun3\n");
}

void fun4(){
    printf("Hello World from fun4\n");
}

void fun5(){
    printf("Hello World from fun5\n");
}

void fun6(){
    printf("Hello World from fun6\n");
}

void fun7(){
    printf("Hello World from fun7\n");
}

int main(){
    // pthread_t th0,th1;
    // int t0=0;
    // int t1=1;

    // thread_create(&th0, task, (thread_fn_arg_t)&t0);
    // thread_create(&th1, task, (thread_fn_arg_t)&t1);

    // pthread_join(th0,NULL);
    // pthread_join(th1,NULL);

    nfc_handle_t nfc;
    nfc_handle_init(&nfc);

    nfc_add(&nfc, fun0);
    nfc_add(&nfc, fun1);
    nfc_add(&nfc, fun2);
    nfc_add(&nfc, fun3);
    nfc_add(&nfc, fun4);
    nfc_add(&nfc, fun5);
    nfc_add(&nfc, fun6);
    nfc_add(&nfc, fun7);

    nfc_iterate(&nfc);
    return 0;
}