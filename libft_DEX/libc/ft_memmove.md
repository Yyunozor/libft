# **ft_memmove**

---

### **Purpose**:

The `ft_memmove` function copies `n` bytes from `src` to `dst`. Unlike `ft_memcpy`, `ft_memmove` is safe for overlapping memory areas.

### **Prototype**:

```c
void *ft_memmove(void *dst, const void *src, size_t len);

```

- **Input**:
    - `dst`: The destination buffer.
    - `src`: The source buffer.
    - `len`: The number of bytes to copy.
- **Output**: Returns a pointer to `dst`.

---

### **Code Implementation**:

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d = (unsigned char *)dst;
	const unsigned char	*s = (const unsigned char *)src;

	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

```

---

### **Explanation**:

- The function handles overlapping memory areas by adjusting the direction of copying based on whether the destination is located before or after the source in memory.
- If `dst` is before `src`, copying happens forward (left to right).
- If `dst` is after `src`, copying happens backward (right to left).

---

### **Visual Focus**

We’ll illustrate the case of **overlapping memory regions**, where the memory areas overlap, and we need to ensure the copying works correctly.

### **Before `ft_memmove` Execution**

We’ll move the string `"Hello"` within the same memory block but overlapping by 2 bytes.

- **Source (`src`)**: Starting at index `0`
- **Destination (`dst`)**: Overlapping, starting at index `2`

Here’s the layout before the function runs:

```jsx
Memory:      [ H | e | l | l | o | \0 | \0 | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  | 6  | 7  ]
Src start:     ^
Dst start:             ^

```

---

### **After `ft_memmove` Execution**

The function will safely move `"Hello"` to the destination, taking care of the overlap.

```jsx
Memory:      [ H | e | H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7  ]
Dst end:                                   ^
                             Safely moved, handling overlap

```

---

### **Step-by-Step Breakdown**:

1. **Index 2**: Copy `'H'` from `src[0]` to `dst[2]`.
2. **Index 3**: Copy `'e'` from `src[1]` to `dst[3]`.
3. **Index 4**: Copy `'l'` from `src[2]` to `dst[4]`.
4. **Index 5**: Copy `'l'` from `src[3]` to `dst[5]`.
5. **Index 6**: Copy `'o'` from `src[4]` to `dst[6]`.

---

### **Final State**:

- The memory has safely moved the string `"Hello"` into an overlapping section.
- The destination now holds `"Hello"` without any data corruption, as the copy handles the overlap correctly.

---

### **Conclusion**

This optimized version of `ft_memmove`:

- **Handles overlapping memory regions** safely by copying in the appropriate direction (forward or backward).
- **Prevents data corruption** by ensuring the correct copy order for overlapping memory areas.
- Ensures safety and correctness when moving data in memory, making it ideal for complex memory operations.

---