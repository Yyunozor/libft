# **ft_memmove**

### **Purpose**:

The `ft_memmove` function copies `n` bytes from `src` to `dst`, but unlike `ft_memcpy`, it handles overlapping memory areas correctly.

### **Prototype**:

```c
void *ft_memmove(void *dst, const void *src, size_t len);

```

- **Input**:
    - `dst`: Pointer to the destination memory area.
    - `src`: Pointer to the source memory area.
    - `len`: The number of bytes to copy.
- **Output**: A pointer to `dst`.

### **Code Implementation**:

```c
void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (!dst && !src)
        return NULL;

    if (d < s)
    {
        while (len--)
            *d++ = *s++;
    }
    else
    {
        d += len;
        s += len;
        while (len--)
            *(--d) = *(--s);
    }
    return dst;
}

```

### **Explanation**:

- The function handles overlapping memory by checking the relative position of `dst` and `src`.
    - If `dst` is **before** `src` in memory (`d < s`), it copies from the beginning to the end (left to right).
    - If `dst` is **after** `src` in memory, it copies from the end to the beginning (right to left).
- Both `dst` and `src` are cast to `unsigned char *` to manipulate memory byte by byte.
- The function returns `dst`.

---

### **Summary of Memory Functions**:

- **`ft_memset`**: Fills a block of memory with a constant byte.
- **`ft_bzero`**: Sets a block of memory to zero.
- **`ft_memcpy`**: Copies memory from one area to another but does not handle overlapping memory.
- **`ft_memmove`**: Copies memory from one area to another and handles overlapping memory safely.
---