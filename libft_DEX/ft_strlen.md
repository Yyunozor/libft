# **6. ft_strlen**

### **Purpose**:

The `ft_strlen` function calculates the **length of a string** (number of characters before the null-terminator `'\0'`).

### **Prototype**:

```c
size_t ft_strlen(const char *s);

```

- **Input**: A pointer to a null-terminated string `s`.
- **Output**:
    - Returns the number of characters in the string, excluding the null-terminator.

### **How it works**:

- It iterates through the string until it finds the null-terminator (`'\0'`), counting the characters along the way.

### **Code Implementation**:

```c
size_t ft_strlen(const char *s)
{
    size_t len = 0;

    while (s[len])
        len++;
    return len;
}

```

### **Explanation**:

- The function loops through the string until it reaches the null-terminator.
- It counts each character and returns the total count.