# **ft_strrchr**

### **Purpose**:

The `ft_strrchr` function locates the last occurrence of the character `c` in the string `s`.

### **Prototype**:

```c
char *ft_strrchr(const char *s, int c);

```

- **Input**:
    - `s`: The string to search.
    - `c`: The character to find (converted to `char`).
- **Output**: A pointer to the last occurrence of `c` in `s`, or `NULL` if `c` is not found.

### **Code Implementation**:

```c
char *ft_strrchr(const char *s, int c)
{
    const char *last = NULL;

    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    if (*s == (char)c)
        return (char *)s;
    return (char *)last;
}

```

### **Explanation**:

- The function loops through the string `s`, tracking the last occurrence of the character `c`.
- It returns a pointer to the last occurrence of `c`, or `NULL` if `c` is not found.

---

### **Visual Focus**

Let's use the string **`"Hello World!"`** and the character **`'o'`** as the target to find the last occurrence.

### **String Representation:**

| H | e | l | l | o |  | W | o | r | l | d | ! |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

We start at index `0` and iterate over the string:

1. **Index 0**: `'H'` does not match `'o'`.
2. **Index 1**: `'e'` does not match `'o'`.
3. **Index 2**: `'l'` does not match `'o'`.
4. **Index 3**: `'l'` does not match `'o'`.
5. **Index 4**: **`'o'` matches!** We store this index in `last` (currently `last = 4`).
6. **Index 5**: Space `' '` does not match `'o'`.
7. **Index 6**: `'W'` does not match `'o'`.
8. **Index 7**: **`'o'` matches again!** We update `last = 7`.
9. **Index 8**: `'r'` does not match `'o'`.
10. **Index 9**: `'l'` does not match `'o'`.
11. **Index 10**: `'d'` does not match `'o'`.
12. **Index 11**: `'!'` does not match `'o'`.

After looping through the string, the **last occurrence** of `'o'` was at **Index 7**.

### Visual Representation

Here’s a visual representation showing both the **first** and **last occurrence** of `'o'`:

```jsx
String:  [ H | e | l | l | o |   | W | o | r | l | d | ! ]
Index :  [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11]
                   ^                   ^
            First 'o'                  Last occurrence of 'o'

```

- The first match happens at index 4 (`'o'`), but the final match occurs at index 7, which is the result of the function.

### **Explanation of the Final Result**:

- **What the function returns**: The function will return a pointer (or address) to the last `'o'` in the string, which is located at **index 7**.

---