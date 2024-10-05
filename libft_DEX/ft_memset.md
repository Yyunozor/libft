# **ft_memset**

### **Purpose**:

The `ft_memset` function fills the first `n` bytes of the memory area pointed to by `b` with the constant byte `c`.

### **Prototype**:

```c
void *ft_memset(void *b, int c, size_t len);

```

- **Input**:
    - `b`: A pointer to the memory area to be filled.
    - `c`: The value to set (converted to `unsigned char`).
    - `len`: The number of bytes to fill.
- **Output**: A pointer to the memory area `b`.

### **Code Implementation**:

```c
void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr = (unsigned char *)b;

    while (len--)
    {
        *ptr++ = (unsigned char)c;
    }
    return b;
}

```

### **Explanation**:

- We cast `b` to `unsigned char *` to work byte by byte.
- The loop fills each byte of the memory block with the value `c` until `len` bytes are set.
- The function returns the original pointer `b`.
---