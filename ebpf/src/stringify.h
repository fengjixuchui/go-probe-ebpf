#ifndef GO_PROBE_EBPF_STRINGIFY_H
#define GO_PROBE_EBPF_STRINGIFY_H

#include "type.h"
#include "event.h"
#include "macro.h"
#include <bpf/bpf_helpers.h>
#include <sys/param.h>

#define SLICE_MAX_COUNT 10

static int stringify_string(string *str, char *buffer, size_t size) {
    if (!str->data || str->length <= 0)
        return 0;

    __u32 remain = size - 1;
    __u32 length = MIN(str->length, remain);

    length = MAX_LENGTH(length, ARG_LENGTH);

    if (bpf_probe_read_user(buffer, length, str->data) < 0)
        return -1;

    return (int) length;
}

static int stringify_string_slice(slice *s, char *buffer, size_t size) {
    if (!s->data || !s->count)
        return 0;

    size_t length = 0;

#pragma unroll
    for (int i = 0; i < SLICE_MAX_COUNT * 2 - 1; i++) {
        if (i >= s->count * 2 - 1 || length >= size - 1)
            break;

        if (i % 2) {
            buffer[length++] = ' ';
            continue;
        }

        string str;

        if (bpf_probe_read_user(&str, sizeof(string), (string *) s->data + i/2) < 0)
            return -1;

        int n = stringify_string(&str, buffer + length, size - length);

        if (n < 0)
            break;

        length += n;
    }

    return (int) length;
}

static int stringify_os_exec_cmd(os_exec_cmd *cmd, char *buffer, size_t size) {
    size_t length = 0;

    {
        int n = stringify_string(&cmd->path, buffer, size);

        if (n < 0)
            return -1;

        length += n;
    }

    {
        int n = stringify_string_slice(&cmd->args, buffer + length, size - length);

        if (n < 0)
            return -1;

        length += n;
    }

    return (int) length;
}

#endif //GO_PROBE_EBPF_STRINGIFY_H
