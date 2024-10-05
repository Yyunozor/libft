# **ft_strnstr**

---

### **Purpose**:

The `ft_strnstr` function locates the first occurrence of the null-terminated string `needle` within the string `haystack`, searching at most `len` characters.

### **Prototype**:

```c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
```

- **Input**:
    - `haystack`: The string to search in.
    - `needle`: The substring to search for.
    - `len`: The maximum number of characters to search.
- **Output**: Returns a pointer to the first occurrence of `needle` in `haystack`, or `NULL` if `needle` is not found.

---

### **Code Implementation**:

```c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len-- >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
```

---

### **Explanation**:

- The function searches for the substring `needle` in `haystack`, but only searches up to `len` characters.
- If `needle` is found, it returns a pointer to the first occurrence in `haystack`.
- If `needle` is not found, it returns `NULL`.

---

### **Visual Focus**

We are searching for the substring `"World"` in the string `"Hello World!"`, with a maximum search length of `12`characters.

### **Before `ft_strnstr` Execution**

- **String (`haystack`)**: `"Hello World!"`
- **Substring (`needle`)**: `"World"`

Here’s the layout before the function runs:

```jsx
Haystack:    [ H | e | l | l | o |   | W | o | r | l | d | ! ]
Needle:      [ W | o | r | l | d ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
```

---

### **After `ft_strnstr` Execution**

The function finds the substring `"World"` starting at index `6`.

```jsx
Haystack:    [ H | e | l | l | o |   | W | o | r | l | d | ! ]
Needle:      [ W | o | r | l | d ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                                       ^
                           Substring found at index 6
```

---