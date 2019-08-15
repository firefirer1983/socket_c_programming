//
// Created by xy on 8/15/19.
//
#include "uv.h"

int main(int argc, char **argv)
{
    int err;
    double uptime;
    size_t memory_usage = 0;
    err = uv_uptime(&uptime);
    if(err != 0) {
        printf("shit happen");
    }
    printf("%d\n", err);
    printf("%f\n", uptime);
    err = uv_resident_set_memory(&memory_usage);
    if(err != 0) {
        printf("shit happen");
    }
    printf("%lu\n", memory_usage);
}