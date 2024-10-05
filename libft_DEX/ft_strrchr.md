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

### **Visual Representation of the Search**

Think of the process as scanning through the string, and every time you hit `'o'`, you mark that position. Here’s a simplified look:

[ H | e | l | l | o |   | W | o | r | l | d | ! ]
                  ^            ^
            First 'o'          Last occurrence of 'o'

---

### **Explanation of the Visual Approach**:

- **String Representation**:
   - The string is displayed in **plaintext** using a consistent format `[ H | e | l | l | o | ... ]`, which mimics the way you'd see characters in memory.
   - This format allows you to **see** where each character is located, making it easy to visually trace the process.

- **Highlighting the First and Last Occurrences**:
   - **Arrows (`^`)** are used to point out specific positions in the string.
   - The **first occurrence** of `'o'` is highlighted first, followed by the **last occurrence** of `'o'`.

- **Step-by-Step Visualization**:
   - The string is displayed multiple times, with **different highlights** in each step.
   - This shows a clear progression from the initial string layout to the final identification of the **last occurrence**.

---

### **Why This is Better**:

1. **Clear Visual Representation**: 
   - By displaying the string in a memory-like format with arrows pointing to the characters, it’s much easier to follow than textual explanations alone.
   
2. **Simple Layout for `.md` Files**: 
   - Markdown handles plaintext blocks well, and the layout is easy to implement across any Markdown viewer.
   
3. **Graphical Appeal**: 
   - The use of **arrows** gives the impression of step-by-step traversal through the string.

---

### **Next Steps**:

If this approach works, you can extend the visual representation technique to other functions. This will provide consistency in visually explaining string manipulations and other processes in a clear, step-by-step way.

Let me know if this version is what you were looking for!
