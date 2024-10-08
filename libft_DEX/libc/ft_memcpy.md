# **ft_memcpy**

---

### **Purpose**:

The `ft_memcpy` function copies `n` bytes from the memory area `src` to the memory area `dst`.

### **Prototype**:

```c
void *ft_memcpy(void *dst, const void *src, size_t n);

```

- **Input**:
    - `dst`: The destination memory area.
    - `src`: The source memory area.
    - `n`: The number of bytes to copy.
- **Output**: Returns a pointer to `dst`.

---

### **Code Implementation**:

```c
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!dst && !src && n == 0)
		return (NULL);
	p_dest = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	while (n--)
		*p_dest++ = *p_src++;
	return (dst);
}

```

---

### **Visual Focus**

We are copying the first `6` bytes from `src` to `dst`.

### **Memory Representation (Before `ft_memcpy`)**:

- **Source (`src`)**: | H | e | l | l | o | W | | --- | --- | --- | --- | --- | --- | | 0 | 1 | 2 | 3 | 4 | 5 |
- **Destination (`dst`)**: | ? | ? | ? | ? | ? | ? | | --- | --- | --- | --- | --- | --- | | 0 | 1 | 2 | 3 | 4 | 5 |

### **After `ft_memcpy`**:

- **Destination (`dst`)**: | H | e | l | l | o | W | | --- | --- | --- | --- | --- | --- | | 0 | 1 | 2 | 3 | 4 | 5 |

### **Visual Representation**

```jsx
Source : [ H | e | l | l | o | W ]
Dest   : [ H | e | l | l | o | W ]
Index  : [ 0 | 1 | 2 | 3 | 4 | 5 ]
                               ^
     Finished copying at index 5

```

---