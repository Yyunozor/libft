# **ft_memcpy**

### **Purpose**:

The `ft_memcpy` function copies `n` bytes from the memory area `src` to the memory area `dst`. This function does **not** handle overlapping memory areas.

### **Prototype**:

```c
void *ft_memcpy(void *dst, const void *src, size_t n);

```

- **Input**:
    - `dst`: Pointer to the destination memory area.
    - `src`: Pointer to the source memory area.
    - `n`: The number of bytes to copy.
- **Output**: A pointer to `dst`.

### **Code Implementation**:

```c
void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (!dst && !src)
        return NULL;

    while (n--)
    {
        *d++ = *s++;
    }
    return dst;
}

```

### **Explanation**:

- Both `dst` and `src` are cast to `unsigned char *` to work byte by byte.
- A check is done to return `NULL` if both `dst` and `src` are `NULL` (to prevent undefined behavior).
- The loop copies `n` bytes from `src` to `dst` byte by byte.
- The function returns `dst`.
---