### **Purpose**:

The `ft_atol` function converts a string representation of a number into a `long` integer. It handles leading whitespaces, optional signs (`+` or `-`), and includes checks to prevent overflow or underflow. If an overflow or underflow occurs, it returns `LONG_MAX` or `LONG_MIN` accordingly.

---

### **Prototype**:

```c
long	ft_atol(const char *str);

```

- **Parameters**:
    - `str`: The string to convert, which may include leading whitespace and an optional sign.
- **Return Value**:
    - The corresponding `long` integer value.
    - Returns `LONG_MAX` if the number is too large and causes an overflow.
    - Returns `LONG_MIN` if the number is too small and causes an underflow.

---

### **Code Implementation**:

```c
static long	handle_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = ft_get_sign(&str);
	result = 0;
	while (ft_isdigit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (handle_overflow(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

```

---

### **Explanation**:

1. **Whitespace Handling**:
    - The function uses `ft_isspace` to skip any leading whitespace characters (`' '`, `'\t'`, etc.) in the input string before processing the number. This ensures the conversion begins at the first valid character.
2. **Sign Handling**:
    - The `ft_get_sign` function detects an optional `+` or `` sign and adjusts the sign of the result accordingly. The string pointer is advanced to skip the sign character.
    - If the string starts with `'-'`, the sign is set to `1`, otherwise it remains `1` (for positive numbers).
3. **Conversion Loop**:
    - The main loop processes each digit in the string. It uses `ft_isdigit` to ensure that only valid digit characters are processed.
    - The function multiplies the `result` by 10 and adds the value of the current digit (by subtracting `'0'` from the character) to accumulate the final number.
4. **Overflow Detection**:
    - Before multiplying `result` by 10, the function checks for potential overflow. It compares `result` against `(LONG_MAX - digit) / 10` to ensure that multiplying and adding the next digit will not exceed the maximum value of a `long`.
    - If overflow is detected, the function returns `LONG_MAX` or `LONG_MIN`, depending on the sign of the number.
5. **Return**:
    - After processing all valid digits, the function returns the final result, applying the sign (`result * sign`).

---

### **Visual Focus**:

Let’s consider the input string `" -9223372036854775809"`, which exceeds the minimum value representable by a `long`.

1. **Whitespace Skip**:
    - The function skips the leading spaces in the string, moving the pointer to `'-'`.
2. **Sign Detection**:
    - The function detects the `'-'` and sets the sign to `1`.
3. **Conversion**:
    - The function processes each digit, updating `result` by multiplying the current result by `10` and adding the value of the next digit.
4. **Overflow**:
    - When processing the last few digits, the function detects that multiplying the current result by `10` and adding the next digit would exceed `LONG_MIN`, and therefore returns `LONG_MIN` as the result.

---

### **Example Usage**:

Here’s how you can use `ft_atol`:

```c
int	main(void)
{
	const char	*str1 = "9223372036854775807";  // LONG_MAX
	const char	*str2 = "-9223372036854775809"; // Overflow to LONG_MIN
	const char	*str3 = "42";                   // Regular number
	const char	*str4 = "   -123abc";           // Stops at non-digit

	printf("Result 1: %ld\n", ft_atol(str1));  // Output: LONG_MAX (9223372036854775807)
	printf("Result 2: %ld\n", ft_atol(str2));  // Output: LONG_MIN (-9223372036854775808)
	printf("Result 3: %ld\n", ft_atol(str3));  // Output: 42
	printf("Result 4: %ld\n", ft_atol(str4));  // Output: -123

	return (0);
}

```

---

### **Optimizations**:

- **Overflow Detection**: By calculating `(LONG_MAX - (*str - '0')) / 10`, the function avoids performing operations that could lead to overflow. If the number is too large, the function returns the appropriate value (`LONG_MAX` or `LONG_MIN`).
- **Pointer Arithmetic**: The function advances the string pointer `str` directly during conversion, avoiding unnecessary indexing.
- **Use of `Libft` Functions**: The use of `ft_isspace` and `ft_isdigit` integrates well with the rest of *Libft*, keeping the code consistent and reusable.

---

### **Edge Cases**:

1. **Overflow and Underflow**:
    - The function detects and handles cases where the number is too large or too small to fit in a `long`, returning `LONG_MAX` or `LONG_MIN` as appropriate.
2. **Leading Whitespace**:
    - Leading whitespace is ignored, allowing the function to handle strings like `" 123"` correctly.
3. **Invalid Characters**:
    - The function stops converting when it encounters a non-numeric character, returning the result accumulated so far. For example, `"123abc"` would return `123`.
4. **Empty or Non-Numeric Strings**:
    - If the string contains no valid digits, the function will return `0`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the length of the numeric portion of the string. The function processes each character exactly once.
- **Space Complexity**: O(1), as the function only uses a constant amount of extra space for variables such as `result`, `sign`, and `str`.

---

### **Conclusion**:

`ft_atol` is a robust function that handles the conversion of strings to `long` integers, including the proper handling of whitespace, signs, and overflow detection. By leveraging *Libft* functions like `ft_isspace` and `ft_isdigit`, and using efficient pointer arithmetic, it ensures high performance while adhering to the 42 Norm.

---
