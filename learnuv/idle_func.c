//
// Created by xy on 8/15/19.
//

#include <zconf.h>
#include "uv.h"

void my_idle(uv_idle_t *handler) {
    printf("idle running\n");
    static int cnt = 0;
    usleep(1*1000*1000);
    printf("%d\n", cnt);
    if(cnt >= 5) {
        printf("stop it!\n");
        uv_idle_stop(handler);
    }
    cnt ++;
}

int main(int argc, char **argv)
{
    int err;
    uv_idle_t idle_handler;
    uv_loop_t *loop = uv_default_loop();
    uv_idle_init(loop, &idle_handler);
    uv_idle_start(&idle_handler, my_idle);
    uv_run(loop, UV_RUN_DEFAULT);
}
