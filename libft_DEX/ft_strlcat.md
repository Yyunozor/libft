# **ft_strlcat**

### **Purpose**:

The `ft_strlcat` function appends the `src` string to the `dst` string, ensuring that the total length of the destination buffer is no more than `dstsize - 1`, and it is null-terminated.

### **Prototype**:

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

```

- **Input**:
    - `dst`: The destination string.
    - `src`: The source string to append to `dst`.
    - `dstsize`: The total size of the destination buffer.
- **Output**: The total length of the string that was attempted to be created (`dst` + `src`).

### **Code Implementation**:

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dst_len = 0;
    size_t src_len = 0;

    while (dst[dst_len] && dst_len < dstsize)
        dst_len++;

    while (src[src_len])
        src_len++;

    if (dstsize == 0 || dst_len >= dstsize)
        return dstsize + src_len;

    size_t i = 0;
    while (src[i] && (dst_len + i) < dstsize - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }

    dst[dst_len + i] = '\0';

    return dst_len + src_len;
}

```

### **Explanation**:

- The function first calculates the lengths of `dst` and `src`.
- If `dstsize == 0` or `dst` is already full, it returns the total length of the strings (`dstsize + src_len`).
- Otherwise, it appends `src` to `dst`, ensuring that no more than `dstsize - 1` characters are written and null-terminating the result.
---