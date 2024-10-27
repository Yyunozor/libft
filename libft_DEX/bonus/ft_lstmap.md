# **`ft_lstmap`**

### **Purpose**:

The `ft_lstmap` function generates a new list by applying a given function (`f`) to the content of each node in an existing list (`lst`). It returns a pointer to the new list. If any memory allocation fails during the process, it frees all allocated nodes to prevent memory leaks.

---

### **Prototype**:

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

```

- **Parameters**:
    - `lst`: A pointer to the first node in the list to be transformed.
    - `f`: A function applied to the content of each node, returning a new transformed value.
    - `del`: A function to free the content of a node in case of an error.
- **Return Value**:
    - Returns a new list where each node’s content is the result of applying `f` to the corresponding node in the original list.
    - Returns `NULL` if any memory allocation fails.

---

### **Code Implementation**:

```c
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst && f)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

```

---

### **Explanation**:

1. **Initialization**:
    - `new_list` is initialized to `NULL` to create an empty list. The function iterates through the input list (`lst`) and applies the function `f` to each element.
2. **Content Transformation**:
    - The function `f` is applied to the `content` of the current node (`lst->content`), producing `new_content`.
    - If `f` fails and returns `NULL`, the function immediately clears any nodes created in `new_list` using `ft_lstclear` and returns `NULL` to indicate failure.
3. **Node Creation**:
    - A new node is created using `ft_lstnew(new_content)`. If this fails (i.e., `new_node` is `NULL`), the content is freed using `del`, and the entire `new_list` is cleared with `ft_lstclear`.
4. **Adding New Node to the List**:
    - The newly created node is added to the end of `new_list` using `ft_lstadd_back`, maintaining the order of nodes from the original list.
5. **Returning the New List**:
    - If all nodes are processed successfully, the function returns `new_list`.
    - If any error occurs, it returns `NULL` after clearing `new_list`.

---

### **Edge Cases**:

1. **Empty List (`lst == NULL`)**:
    - The function returns `NULL` if the input list is empty, as there is nothing to map.
2. **Memory Allocation Failure**:
    - If any memory allocation fails (either while transforming content or creating a new node), the function ensures all allocated nodes in `new_list` are cleared to avoid memory leaks.
3. **Null Function (`f == NULL`)**:
    - If `f` is `NULL`, no transformation can occur, and the function returns `NULL`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the number of nodes in the input list. Each node is processed once.
- **Space Complexity**: O(n) for the new list and O(1) for auxiliary space.

---

### **Testing the Implementation**:

To demonstrate the function's usage, here is a sample test case:

```c
#include "libft.h"#include <stdio.h>#include <stdlib.h>

void	*transform_content(void *content)
{
	char	*str = (char *)content;
	return (ft_strdup(str)); // Duplicates the string content
}

// Example function to delete content
void	delete_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list = ft_lstnew(ft_strdup("Node 1"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 2")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 3")));

	t_list	*new_list = ft_lstmap(list, transform_content, delete_content);
	if (!new_list)
		printf("Failed to map the list\n");
	else
	{
		t_list	*temp = new_list;
		while (temp)
		{
			printf("Content: %s\n", (char *)temp->content);
			temp = temp->next;
		}
	}

	ft_lstclear(&list, delete_content);
	ft_lstclear(&new_list, delete_content);
	return (0);
}

```

**Expected Output**:

```less
Content: Node 1
Content: Node 2
Content: Node 3

```

### **Conclusion**:

The **`ft_lstmap`** function provides a reliable way to apply transformations to each node in a linked list while ensuring memory is managed correctly, even if an error occurs. This function is highly flexible, allowing you to apply custom transformations and cleanup procedures for any linked list application.