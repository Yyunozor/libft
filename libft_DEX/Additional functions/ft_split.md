# **ft_split**

### **Purpose**:

The `ft_split` function splits a string into an array of substrings based on a specified delimiter character. It allocates memory for each substring and returns an array of these substrings.

### **Prototype**:

```c
char **ft_split(char const *s, char c);

```

- **Parameters**:
    - `s`: The input string to be split.
    - `c`: The delimiter character used to split the string.
- **Return Value**:
    - Returns a dynamically allocated array of substrings obtained by splitting `s` using `c`.
    - The array ends with a `NULL` pointer.
    - Returns `NULL` if memory allocation fails or if the input string is `NULL`.

---

### **Code Implementation**:

```c
#include "libft.h"

static void	free_all(char **arr, char **ptr)
{
	while (ptr-- > arr)
		free(*ptr);
	free(arr);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			count++;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_substr(start, 0, *s - start));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (words--)
	{
		*ptr = get_next_word(&s, c);
		if (!*ptr++)
			return (free_all(res, ptr - 1), NULL);
	}
	*ptr = NULL;
	return (res);
}

```

---

### **Explanation**:

1. **`free_all` Function**:
    - Frees all allocated memory if an allocation fails. It starts from the last allocated memory slot and moves backward, freeing each element.
2. **`word_count` Function**:
    - Counts the number of words (substrings) in the input string `s`, using `c` as the delimiter.
    - It increments the count when a non-delimiter character is followed by a delimiter or the end of the string.
3. **`get_next_word` Function**:
    - Finds the next word in the input string `s`, skipping leading delimiters.
    - Returns a substring using `ft_substr` that contains the word, which is created from the portion of the string from the start to the next delimiter.
4. **`ft_split` Function**:
    - The main function that performs the splitting.
    - It first checks if the input string `s` is `NULL`, returning `NULL` if true.
    - It allocates memory for an array of strings (`res`), with space for the `words + 1` to accommodate the terminating `NULL`.
    - It then iterates through the words, using the `get_next_word` function to populate the `res` array.
    - If any memory allocation fails, `free_all` is called to release allocated resources.
    - The array is terminated with a `NULL` pointer.

---

### **Visual Focus**

Let’s use the string `"Hello 42 Network"` with the space character `' '` as the delimiter.

### **Original String**:

```mathematica
Input String: "Hello  42 Network"
Delimiter: ' '

```

### **Steps for Splitting**:

1. **Count the Words**:
    - The function counts three words: `"Hello"`, `"42"`, and `"Network"`.
2. **Extract the Words Using `get_next_word`**:
    - The function finds `"Hello"` as the first word.
    - It skips consecutive spaces, then finds `"42"` as the second word.
    - Finally, it extracts `"Network"` as the third word.

### **Visual Representation of Memory Allocation**:

```jsx
Original String:   "Hello  42 Network"
Splitting on:      ' '
Result Array:      [ "Hello" | "42" | "Network" | NULL ]

```

### **Edge Cases**:

- **Empty String**: Returns an array with a single `NULL` element.
- **Consecutive Delimiters**: Skips over consecutive delimiters and does not create empty strings in the array.
- **Memory Allocation Failure**: Frees any previously allocated memory and returns `NULL`.
- **NULL Input String**: If the input string is `NULL`, returns `NULL`.

---

### **Conclusion**:

This optimized version of `ft_split` uses pointer arithmetic and helper functions to achieve a clean, efficient implementation while adhering to the 42 Norm. The code avoids using explicit indexing, making it concise and leveraging C's capabilities for efficient memory handling.

---