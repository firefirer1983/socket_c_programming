cmake_minimum_required(VERSION 3.10)
project(socket_programming C)

set(CMAKE_C_STANDARD 99)

include_directories(
        uv/include
        uv/src
)

add_library(
        uv STATIC
        uv/src/unix/async.c
        uv/src/unix/atomic-ops.h
        uv/src/unix/core.c
        uv/src/unix/dl.c
        uv/src/unix/fs.c
        uv/src/unix/fsevents.c
        uv/src/unix/getaddrinfo.c
        uv/src/unix/getnameinfo.c
        uv/src/unix/internal.h
        uv/src/unix/linux-core.c
        uv/src/unix/linux-inotify.c
        uv/src/unix/linux-syscalls.c
        uv/src/unix/linux-syscalls.h
        uv/src/unix/loop.c
        uv/src/unix/loop-watcher.c
        uv/src/unix/no-fsevents.c
        uv/src/unix/no-proctitle.c
        uv/src/unix/pipe.c
        uv/src/unix/poll.c
        uv/src/unix/process.c
        uv/src/unix/procfs-exepath.c
        uv/src/unix/proctitle.c
        uv/src/unix/pthread-fixes.c
        uv/src/unix/signal.c
        uv/src/unix/spinlock.h
        uv/src/unix/stream.c
        uv/src/unix/sysinfo-loadavg.c
        uv/src/unix/sysinfo-memory.c
        uv/src/unix/tcp.c
        uv/src/unix/thread.c
        uv/src/unix/tty.c
        uv/src/unix/udp.c
        uv/src/fs-poll.c
        uv/src/heap-inl.h
        uv/src/idna.c
        uv/src/idna.h
        uv/src/inet.c
        uv/src/queue.h
        uv/src/strscpy.c
        uv/src/strscpy.h
        uv/src/threadpool.c
        uv/src/timer.c
        uv/src/uv-common.c
        uv/src/uv-common.h
        uv/src/uv-data-getter-setters.c
        uv/src/version.c
)


find_package (Threads)

add_executable(test_uv test.c)
target_link_libraries(test_uv PRIVATE uv)

add_executable(systeminfo learnuv/systeminfo.c)
target_link_libraries(systeminfo PRIVATE uv ${CMAKE_THREAD_LIBS_INIT})

add_executable(idle_func learnuv/idle_func.c)
target_link_libraries(idle_func PRIVATE uv ${CMAKE_THREAD_LIBS_INIT})

add_executable(fs_readsync learnuv/fs_readsync.c)
target_link_libraries(fs_readsync PRIVATE uv ${CMAKE_THREAD_LIBS_INIT})
