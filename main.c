#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

#define MAX_EVENTS 30
#define BUFFER_SIZE 1024


int main() {
    int running = 1, event_count;
    struct epoll_event event, events[MAX_EVENTS];
    char buffer_read[BUFFER_SIZE];
    ssize_t bytes_read = 0;
    int epoll_fd = epoll_create1(0);
    if(epoll_fd == -1) {
        fprintf(stderr, "create epoll fd fail!");
        return 1;
    }

    event.events = EPOLLIN;
    event.data.fd = 0;
    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0 , &event)){
        fprintf(stderr, "epoll ctl fail!");
        close(epoll_fd);
        return 1;
    }

    while (running == 1) {
        event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, 30000);
        for(int i=0; i<event_count; i++) {
            int fd = events[i].data.fd;
            printf("reading from fd %d\n", fd);
            bytes_read = read(fd, buffer_read, 10);
            buffer_read[bytes_read+1] = '\0';
            printf("read: %s\n", buffer_read);
            memset(&buffer_read, '\0', sizeof(buffer_read));
            if(!strncmp(buffer_read, "stop", 5)) {
                running = 0;
            }
        }
    }

    if(close(epoll_fd)) {
        fprintf(stderr, "close epoll fd fail!");
        return 1;
    }
    return 0;
}