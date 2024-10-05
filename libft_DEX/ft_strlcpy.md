# **ft_strlcpy**

### **Purpose**:

The `ft_strlcpy` function copies a string from `src` to `dst`, ensuring that no more than `dstsize - 1` characters are copied. It always null-terminates the result, provided `dstsize > 0`.

### **Prototype**:

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

```

- **Input**:
    - `dst`: The destination buffer where the string is copied.
    - `src`: The source string to copy from.
    - `dstsize`: The size of the destination buffer.
- **Output**: The total length of `src` (whether or not it was truncated).

### **Code Implementation**:

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t src_len = 0;

    while (src[src_len])
        src_len++;

    if (dstsize)
    {
        size_t i = 0;
        while (i < dstsize - 1 && src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }

    return src_len;
}

```

### **Explanation**:

- The function first calculates the length of `src` to return at the end.
- If `dstsize > 0`, it copies up to `dstsize - 1` characters from `src` to `dst` and ensures the result is null-terminated.
- It returns the full length of `src` so the caller can detect truncation.
---