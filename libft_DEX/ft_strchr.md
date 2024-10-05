# **ft_strchr**

### **Purpose**:

The `ft_strchr` function locates the first occurrence of the character `c` in the string `s`.

### **Prototype**:

```c
char *ft_strchr(const char *s, int c);

```

- **Input**:
    - `s`: The string to search.
    - `c`: The character to find (converted to `char`).
- **Output**: A pointer to the first occurrence of `c` in `s`, or `NULL` if `c` is not found.

### **Code Implementation**:

```c
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (*s == (char)c)
        return (char *)s;
    return NULL;
}

```

### **Explanation**:

- The function loops through the string `s`, looking for the first occurrence of the character `c`.
- If `c` is found, it returns a pointer to that location in the string. If `c` is not found, it returns `NULL`.

---

### **Purpose**:

The `ft_strchr` function locates the first occurrence of the character `c` in the string `s`.

### **Prototype**:

```c
char *ft_strchr(const char *s, int c);

```

- **Input**:
    - `s`: The string to search.
    - `c`: The character to find (converted to `char`).
- **Output**: A pointer to the first occurrence of `c` in `s`, or `NULL` if `c` is not found.

### **Code Implementation**:

```c
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (*s == (char)c)
        return (char *)s;
    return NULL;
}

```

### **Explanation**:

- The function loops through the string `s`, looking for the first occurrence of the character `c`.
- If `c` is found, it returns a pointer to that location in the string. If `c` is not found, it returns `NULL`.