# `ft_itoa`

---

### **Purpose**:

The `ft_itoa` function converts an integer to its string representation. It handles both positive and negative integers, as well as zero.

---

### **Prototype**:

```c
char *ft_itoa(int n);

```

- **Parameters**:
    - `n`: The integer to convert to a string.
- **Return Value**:
    - A pointer to a newly allocated string representing the integer.
    - Returns `NULL` if the memory allocation fails.

---

### **Code Implementation**:

```c
#include "libft.h"
// Helper function to count the number of digits in an integer, including sign
static size_t	count_digits(int n)
{
	size_t	digits;

	if (n <= 0)
		digits = 1;
	else
		digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

// Helper function to convert the number into the string
static void	convert_to_str(char *str, long nb, size_t len)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*str;

	nb = (long)n;
	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	convert_to_str(str + (n < 0), nb, len - (n < 0));
	return (str);
}

```

---

### **Explanation**:

1. **Helper Functions**:
    - `count_digits(int n)`: Calculates the number of digits in the integer, accounting for a possible negative sign.
    - `convert_to_str(char *str, long nb, size_t len)`: Converts the number to a string representation, starting from the least significant digit.
2. **Main Function (`ft_itoa`)**:
    - Converts the integer `n` to a long (`nb`) to handle the edge case of `INT_MIN` safely.
    - Calculates the length of the resulting string, including space for a negative sign if needed.
    - Allocates memory for the string, returning `NULL` if the allocation fails.
    - Sets the negative sign if `n` is negative, then converts the absolute value of `nb` to a string.
    - Returns the pointer to the allocated string.

---

### **Edge Cases Handled**:

- **Zero (`0`)**:
    - Returns `"0"` as a string.
- **Negative Numbers**:
    - Properly handles negative signs and converts the absolute value.
- **Minimum Integer Value (`INT_MIN`)**:
    - Safely converts to a string using the `long` data type.

---

### **Visual Focus**:

Let’s consider the input `-12345`:

1. **Counting Digits**:
    - `count_digits(-12345)` returns `6` (5 digits + 1 for the negative sign).
2. **Memory Allocation**:
    - Allocates memory for `7` characters (`6` digits + null terminator).
3. **Converting to a String**:

| Step | String State | Explanation |
| --- | --- | --- |
| Init | `_ _ _ _ _ _ \0` | Initial state, memory allocated. |
| -1 | `- _ _ _ _ _ \0` | Set the negative sign. |
| 5 | `- _ _ _ _ 5 \0` | Add the last digit. |
| 4 | `- _ _ _ 4 5 \0` | Add the next digit. |
| 3 | `- _ _ 3 4 5 \0` | Add the next digit. |
| 2 | `- _ 2 3 4 5 \0` | Add the next digit. |
| 1 | `- 1 2 3 4 5 \0` | Add the first digit. |

The final result is `"-12345"`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(d), where `d` is the number of digits in the integer.
- **Space Complexity**: O(d), accounting for the string representation of the integer.

---

### **Edge Case Handling**:

- **Zero Input**:
    - If `n` is `0`, the function returns a string `"0"`.
- **Handling Negative Numbers**:
    - When `n` is negative, the first character of the string is set to `'-'`, and the conversion is performed on the absolute value.
- **Handling Integer Overflow**:
    - The use of `long` ensures that the function correctly handles the case where `n` is equal to `INT_MIN`.

---

### **Possible Improvements**:

- Further optimization is not required as the current implementation efficiently converts an integer to its string representation with minimal operations.

---