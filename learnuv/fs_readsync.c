//
// Created by xy on 8/16/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include "uv.h"
void read_cb(uv_fs_t* req)
{
    uv_fs_req_cleanup(req);
    if (req->result == 0) {
        uv_fs_close(uv_default_loop(), req, req->file, NULL);
        printf("read done");
    }
    printf(req->data);
}
#define BUF_SIZE 256


int main(int argc, char **argv)
{
    printf("start synchronous reading\n");
    uv_loop_t *loop;
    char read_buf[BUF_SIZE + 1];
    memset(read_buf, 0, sizeof(read_buf));
    uv_buf_t buf = uv_buf_init(read_buf, BUF_SIZE);
    uv_fs_t open_req;
    loop = uv_default_loop();
    int err = uv_fs_open(loop, &open_req, "/home/xy/repo/c/socket_c_programming/file.txt", O_RDONLY, S_IREAD, NULL);

    if(err < 0) {
        printf("shit happen when open file : %s\n", uv_strerror(err));
        exit(1);
    }
    uv_fs_t read_req;
    int r_err = uv_fs_read(loop, &read_req, open_req.result, &buf, 1, 0, NULL);
    if(err < 0) {
        printf("shit happen when read file: %s\n", uv_strerror(r_err));
        exit(1);
    }
    printf("read:%s\n", read_buf);
    printf("%ld", read_req.result);
    uv_fs_t close_req;
    int c_err = uv_fs_close(loop, &close_req, open_req.result, NULL);

    uv_fs_req_cleanup(&open_req);
    uv_fs_req_cleanup(&read_req);
    uv_fs_req_cleanup(&close_req);
    uv_run(loop, UV_RUN_DEFAULT);
}

