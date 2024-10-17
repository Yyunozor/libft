# **`ft_lstmap`**

### **Purpose**:

The `ft_lstmap` function creates a new linked list where each node’s content is the result of applying a specified function to the content of the corresponding node in the original list. It’s useful for transforming a list while leaving the original list unchanged. Additionally, a function is provided to free the content in case of failure.

---

### **Prototype**:

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

```

- **Parameters**:
    - `lst`: A pointer to the first node of the original list.
    - `f`: A function pointer that takes the content of a node and returns the transformed content.
    - `del`: A function pointer used to delete the content in case of failure.
- **Return Value**:
    - A pointer to the first node of the new list.
    - Returns `NULL` if the memory allocation fails for any node.

---

### **Optimized Code Implementation**:

```c
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_node;

    if (lst == NULL || f == NULL)  // Check for NULL inputs
        return NULL;

    while (lst != NULL)
    {
        new_node = ft_lstnew(f(lst->content));  // Apply function 'f' to create a new node
        if (new_node == NULL)
        {
            ft_lstclear(&new_list, del);  // Clear new list if memory allocation fails
            return NULL;
        }
        ft_lstadd_back(&new_list, new_node);  // Add new node to the new list
        lst = lst->next;  // Move to the next node in the original list
    }

    return new_list;
}

```

---

### **Explanation**:

1. **Null Checks**:
    - The function first checks if either `lst` (the list) or `f` (the function pointer) is `NULL`. If either is `NULL`, the function returns `NULL` to prevent segmentation faults or invalid operations.
2. **Applying the Function `f`**:
    - For each node in the original list, the function `f` is applied to the node’s content to create a new transformed content for the new list. The transformed content is used to create a new node with `ft_lstnew`.
3. **Memory Allocation Check**:
    - If the allocation of the new node fails at any point, the function clears the newly created list (using `ft_lstclear`) to avoid memory leaks and returns `NULL`.
4. **Building the New List**:
    - The newly created nodes are added to the new list using `ft_lstadd_back`, preserving the order of the original list.
5. **Return**:
    - After successfully creating the new list, the function returns a pointer to the first node of the new list.

---

### **Visual Representation**:

Let’s say you have the following linked list:

```css
[42 | Next] -> [21 | Next] -> [84 | NULL]

```

You want to create a new list where each value is doubled. You can define a function `double_content` that doubles the node content:

```c
void *double_content(void *content)
{
    int *new_value = malloc(sizeof(int));
    if (new_value == NULL)
        return NULL;
    *new_value = *(int *)content * 2;
    return new_value;
}

```

Calling `ft_lstmap`:

```c
t_list *new_list = ft_lstmap(original_list, &double_content, &free);

```

The new list will be:

```css
[84 | Next] -> [42 | Next] -> [168 | NULL]

```

The original list remains unchanged.

---

### **Example Usage**:

Here’s how you can use `ft_lstmap` to create a new list with transformed content:

```c
#include "libft.h"#include <stdio.h>#include <stdlib.h>void *double_content(void *content)
{
    int *new_value = malloc(sizeof(int));
    if (new_value == NULL)
        return NULL;
    *new_value = *(int *)content * 2;  // Double the content of the node
    return new_value;
}

void free_content(void *content)
{
    free(content);  // Free the content of the node
}

int main()
{
    // Create the original list
    t_list *node1 = ft_lstnew(malloc(sizeof(int)));
    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    t_list *node3 = ft_lstnew(malloc(sizeof(int)));

    *(int *)node1->content = 42;
    *(int *)node2->content = 21;
    *(int *)node3->content = 84;

    node1->next = node2;
    node2->next = node3;

    // Create a new list by doubling each node's content
    t_list *new_list = ft_lstmap(node1, &double_content, &free_content);

    // Print the content of the new list
    t_list *current = new_list;
    while (current != NULL)
    {
        printf("%d\n", *(int *)current->content);  // Output: 84, 42, 168
        current = current->next;
    }

    // Clean up both lists
    ft_lstclear(&node1, &free_content);  // Free the original list
    ft_lstclear(&new_list, &free_content);  // Free the new list

    return 0;
}

```

In this example:

- A new list is created where the content of each node is doubled.
- The original list remains unchanged.
- Both the original and new lists are properly freed using `ft_lstclear`.

---

### **Optimizations and Improvements**:

### **1. Null Checks and Safety**:

- The function includes safety checks for `NULL` inputs to ensure that it won’t operate on invalid pointers, preventing segmentation faults.

### **2. Memory Allocation Failure Handling**:

- If memory allocation fails while creating the new list, the function frees any already created nodes in the new list using `ft_lstclear`. This prevents memory leaks and ensures the program is safe even in low-memory conditions.

### **3. Tail Pointer Optimization**:

- If you want to optimize the `ft_lstadd_back` calls inside the loop (which can be O(n) for each node), you can use a **tail pointer** to keep track of the last node in the new list, ensuring constant-time insertion. Here’s how you could do it:

```c
t_list *ft_lstmap_optimized(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_node, *tail = NULL;

    if (lst == NULL || f == NULL)
        return NULL;

    while (lst != NULL)
    {
        new_node = ft_lstnew(f(lst->content));
        if (new_node == NULL)
        {
            ft_lstclear(&new_list, del);
            return NULL;
        }

        if (new_list == NULL)  // First node
        {
            new_list = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }

        lst = lst->next;
    }

    return new_list;
}

```

This version ensures that appending to the new list happens in constant time, O(1), rather than O(n).

---

### **Common Questions**:

1. **What happens if memory allocation fails?**
    - If memory allocation fails when creating a new node, the function frees all previously allocated nodes in the new list using `ft_lstclear` and returns `NULL` to signal the failure.
2. **Does the original list get modified?**
    - No, `ft_lstmap` creates a new list and doesn’t modify the original list. The transformation is applied to the content of the original list, but the original nodes remain unchanged.
3. **What if the list is empty?**
    - If `lst == NULL`, the function returns `NULL`. An empty list remains unchanged, and no transformation is applied.

---

### **Edge Cases**:

- **Empty List**: If the original list is empty (`lst == NULL`), the function returns `NULL`.
- **Memory Allocation Failure**: If memory allocation fails, the function ensures no memory leaks by freeing any previously allocated nodes.
- **NULL Function Pointer**: If the function pointer (`f` or `del`) is `NULL`, the function safely exits without modifying the list or applying any transformation.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n) – The function traverses the entire list and applies the transformation to each node, where `n` is the number of nodes in the list.
- **Space Complexity**: O(n) – The function creates a new list with the same number of nodes as the original list, so the space complexity is proportional to the size of the original list.

---

### **Possible Improvements**:

- **Tail Pointer Optimization**: As shown earlier, using a tail pointer for appending nodes improves the performance of `ft_lstadd_back` from O(n) to O(1) for each insertion.
- **Handling More Complex Data**: You can extend the `del` and `f` functions to handle more complex data types, ensuring correct memory management and transformation.

---

### **Conclusion**:

`ft_lstmap` is a versatile function that allows you to create a transformed version of a linked list without modifying the original list. With built-in safety checks and memory management, it ensures efficient operation even in failure cases. Whether you’re doubling numbers, transforming strings, or applying other complex transformations, `ft_lstmap` gives you the flexibility to handle linked lists dynamically and safely.

---