# **ft_strchr**

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
- **Output**: Returns a pointer to the first occurrence of `c` in `s`, or `NULL` if `c` is not found.

---

### **Code Implementation**:

```c
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	return (NULL);
}

```

---

### **Visual Focus**

We are searching for the character `'o'` in the string `"Hello World!"`.

### **String Representation**:

| H | e | l | l | o |  | W | o | r | l | d | ! |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

We start scanning from index `0`.

### **Steps**:

1. **Index 0**: `'H'` does not match `'o'`.
2. **Index 1**: `'e'` does not match `'o'`.
3. **Index 2**: `'l'` does not match `'o'`.
4. **Index 3**: `'l'` does not match `'o'`.
5. **Index 4**: **`'o'` matches!** → Return pointer to index `4`.

---

### **Visual Representation with Arrows**:

```jsx
String:  [ H | e | l | l | o |   | W | o | r | l | d | ! ]
Index :  [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11]
                           ^
      First occurrence of 'o' at index 4

```

---