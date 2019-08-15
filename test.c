//
// Created by xy on 8/15/19.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "uv/src/queue.h"
#include "uv/include/uv.h"

typedef struct address_book {
    char *address;
    QUEUE book_link;
} address_book_t;


int main(int argc, char** argv) {
    QUEUE queue;
    QUEUE_INIT(&queue);
    printf("queue:%p queue.0: %p\n", &queue, queue[0]);
    printf("queue:%p queue.1: %p\n", &queue, queue[1]);
    address_book_t sunset;
    sunset.address = malloc(256);
    strncpy(sunset.address, "Sunset Avenue", strlen("Sunset Avenue"));
    QUEUE_INIT(&sunset.book_link);
    QUEUE_INSERT_TAIL(&queue, &sunset.book_link);
    printf("\t1 inserted\n");
    printf("queue:%p queue.0: %p\n", &queue, queue[0]);
    printf("queue:%p queue.1: %p\n", &queue, queue[1]);
    printf("sunset:%p sunset.0: %p\n", &sunset.book_link, sunset.book_link[0]);
    printf("sunset:%p sunset.1: %p\n", &sunset.book_link, sunset.book_link[1]);

    struct address_book greatwall;
    QUEUE_INIT(&greatwall.book_link);
    greatwall.address = malloc(256);
    strncpy(greatwall.address, "Great Wall", strlen("Great Wall"));
    QUEUE_INSERT_TAIL(&queue, &greatwall.book_link);
    printf("\t2 inserted\n");
    printf("queue:%p queue.0: %p\n", &queue, queue[0]);
    printf("queue:%p queue.1: %p\n", &queue, queue[1]);
    printf("sunset:%p sunset.0: %p\n", &sunset.book_link, sunset.book_link[0]);
    printf("sunset:%p sunset.1: %p\n", &sunset.book_link, sunset.book_link[1]);
    printf("greatwall:%p greatwall.0: %p\n", &greatwall.book_link, greatwall.book_link[0]);
    printf("greatwall:%p greatwall.1: %p\n", &greatwall.book_link, greatwall.book_link[1]);

    QUEUE* q;
    QUEUE_FOREACH(q, &queue) {
        address_book_t *page = QUEUE_DATA(q, address_book_t, book_link);
        printf("%s\n", page->address);
    }
    return 0;
}
