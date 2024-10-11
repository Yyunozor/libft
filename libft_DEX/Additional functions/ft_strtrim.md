# **ft_strtrim**

---

### **Purpose**:

The `ft_strtrim` function trims characters from the beginning and end of a string. It removes any characters from the specified set found at the start or the end of the string.

### **Prototype**:

```c
char	*ft_strtrim(char const *s1, char const *set)
```

- **Parameters**:
    - `s1`: The input string to be trimmed.
    - `set`: The reference set of characters to trim from `s1`.
- **Return Value**:
    - Returns the trimmed string.
    - Returns `NULL` if the memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);

	// Find the first character not in the set
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;

	// Find the last character not in the set
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;

	// Allocate memory for the trimmed string
	return (ft_substr(s1, start, end - start));
}
```

---

### **Explanation**:

1. **Check for Null Inputs**:
    - The function first checks if `s1` or `set` is `NULL`. If either is `NULL`, it returns `NULL` to prevent dereferencing a null pointer.
2. **Finding the Start Index**:
    - The function determines the first index where a character in `s1` is **not** found in `set`. This marks the beginning of the trimmed string.
3. **Finding the End Index**:
    - The function identifies the last index where a character in `s1` is **not** found in `set`. This marks the end of the trimmed string.
4. **Allocate Memory for the Trimmed String**:
    - It uses `ft_substr` to create a substring from `s1` starting at `start` and of length `end - start`. This ensures the newly allocated string contains only the trimmed portion of the original string.
5. **Return the Result**:
    - The function returns the newly allocated trimmed string, or `NULL` if memory allocation fails.

---

### **Visual Focus**

Let’s use the string `" Hello World! "` and the character set `" "` (space) to illustrate how `ft_strtrim` works.

### **Before Trimming**:

```c
Input String: "  Hello World!  "
Trim Set:     " "

```

### **After Trimming**:

```c
Trimmed String: "Hello World!"

```

- **Start Index Calculation**: The first non-space character is `'H'` at index `2`.
- **End Index Calculation**: The last non-space character is `'!'` at index `12`.

### Visual Representation: