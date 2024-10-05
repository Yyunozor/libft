# **ft_strnstr**

### **Purpose**:

The `ft_strnstr` function locates the **first occurrence** of the null-terminated string `needle` within the string `haystack`, searching up to `len` characters in `haystack`.

### **Prototype**:

```c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

```

- **Input**:
    - `haystack`: The string to search in.
    - `needle`: The substring to search for.
    - `len`: The maximum number of characters to search.
- **Output**: Returns a pointer to the first occurrence of `needle` in `haystack`, or `NULL` if `needle` is not found within the first `len` characters.

---

### **Code Implementation**:

```c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len;

	if (!*needle)  // If needle is empty, return haystack
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

- The function searches for the substring `needle` within the first `len` characters of `haystack`.
- If `needle` is found, the function returns a pointer to the first occurrence within `haystack`.
- If `needle` is an empty string, the function returns `haystack`.
- If `needle` is not found within the first `len` characters, the function returns `NULL`.

---

### **Visual Focus**

Let’s walk through an example where we are searching for the substring `"World"` in the string `"Hello World!"`, with a maximum search length of `12`.

### **Before `ft_strnstr` Execution**

- **String (`haystack`)**: `"Hello World!"`
- **Substring (`needle`)**: `"World"`
- **Max search length (`len`)**: `12`

Here’s the layout before the function runs:

```jsx
Haystack:    [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Needle:      [ W | o | r | l | d ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]

```

---

### **After `ft_strnstr` Execution**

The function finds the substring `"World"` starting at index `6` within the bounds of `len`.

```jsx
Haystack:    [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Needle:      [ W | o | r | l | d ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                                       ^
                          Substring found at index 6

```

---

### **Step-by-Step Breakdown**:

1. **Step 1**: Compare `haystack[0]` to `haystack[6]` with `needle` (no match).
2. **Step 2**: Slide over to `haystack[6]` and compare with `needle`.
3. **Step 3**: **Match found** at `haystack[6]`, so the function returns a pointer to `haystack[6]`.

---

### **Final State**:

- The function returns a pointer to the substring `"World"` starting at index `6` in `haystack`.
- If no match were found, or if `needle` were longer than the remaining `len` characters, it would return `NULL`.

---

### **Conclusion**

This optimized version of `ft_strnstr`:

- **Efficiently searches** for a substring within a limited length.
- **Returns a pointer** to the substring or `NULL` if not found.
- Ensures safe searching within a limited number of characters, making it ideal for partial string searches.

---
