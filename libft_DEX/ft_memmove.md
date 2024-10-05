# **ft_memmove**

---

### **Purpose**:

The `ft_memmove` function copies `n` bytes from `src` to `dst`, ensuring that it handles overlapping memory areas safely.

### **Prototype**:

```c
void *ft_memmove(void *dst, const void *src, size_t len);

```

- **Input**:
    - `dst`: The destination memory area.
    - `src`: The source memory area.
    - `len`: The number of bytes to copy.
- **Output**: Returns a pointer to `dst`.

---

### **Code Implementation**:

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;

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

### **Visual Focus**

We are copying `6` bytes from `src` to `dst`, with overlapping memory areas.

### **Memory Representation (Before `ft_memmove`)**:

| H | e | l | l | o | W | o | r | l | d |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

---

### **Case 1: Safe Forward Copy (No Overlap)**

If `dst < src`, the bytes are copied forward.

### **After Forward Copy**:

| H | e | l | l | o | W | o | r | l | d |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| [ Copied Section (dst) ] |  |  |  |  |  |  |  |  |  |

---

### **Case 2: Safe Backward Copy (Overlap)**

If `dst > src`, the bytes are copied backward.

### **After Backward Copy**:

| H | e | l | l | o | W | o | r | l | d |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [ Copied Section (dst) ] |  |  |  |  |  |  |  |  |  |

### **Visual Representatio**

```jsx
String : [ H | e | l | l | o | W | o | r | l | d ]
Before : [ e | l | l | o | W | o ] (src starts)
After  : [ o | r | l | d | l | d ] (dst after backward copy)
Index  : [ 0 | 1 | 2 | 3 | 4 | 5 ]
                               ^
                               Memory safely moved

```

---