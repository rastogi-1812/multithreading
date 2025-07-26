#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#include "glthread.h"


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


typedef struct student_{
    glnode_t glue;
    char name[100];
}student_t;

void print_student_names(glnode_t *glue){
    student_t *student = (student_t*)glue;
    printf("%s\n", student->name);
}

int main(){
    // pthread_t th0,th1;
    // int t0=0;
    // int t1=1;

    // thread_create(&th0, task, (thread_fn_arg_t)&t0);
    // thread_create(&th1, task, (thread_fn_arg_t)&t1);

    // pthread_join(th0,NULL);
    // pthread_join(th1,NULL);

    glhandle_t glhandle;
    student_t s0={ .name = "szero"}, s1={ .name = "sone"}, s2={ .name = "stwo"}, s3={ .name = "sthree" }, s4={ .name = "sfour" }, s5={ .name = "sfive" };
    glthread_handle_init(&glhandle);
    glthread_add_node(&glhandle, &s0.glue);
    glthread_add_node(&glhandle, &s1.glue);
    glthread_add_node(&glhandle, &s2.glue);
    glthread_add_node(&glhandle, &s3.glue);
    glthread_add_node(&glhandle, &s4.glue);
    glthread_add_node(&glhandle, &s5.glue);
    iterate_over_glthread(&glhandle, print_student_names);
    return 0;
}