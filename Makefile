# Variables
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
      ft_calloc.c ft_strdup.c ft_isspace.c ft_substr.c ft_strjoin.c ft_strtrim.c \
      ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
      ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

# Default target
all: takeoff $(NAME)
	@echo "░  ░░░░░░░░        ░░        ░░       ░░         ░"
	@echo "▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒"
	@echo "▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓       ▓▓▓      ▓▓▓▓▓▓▓  ▓▓▓▓"
	@echo "█  ███████████  █████  ████  ██  ███████████  ████"
	@echo "█ _ _ ___ █        ██        ██  ███████████  ████"
	@echo " | | |_  )               ▗▄▄▖ ▗▄▄▄▖ ▗▄▖ ▗▄▄▄▗▖  ▗▖"
	@echo " |_  _/ /                ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █▝▚▞▘ "
	@echo "   |_/___|               ▐▛▀▚▖▐▛▀▀▘▐▛▀▜▌▐▌  █ ▐▌  "
	@echo "                         ▐▌ ▐▌▐▙▄▄▖▐▌ ▐▌▐▙▄▄▀ ▐▌  "
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "> ✨libft.a has been created successfully!"
	@echo "--------------------------------------------------"
	@echo "> 🔊Bravo! Well Done! Bien joué! すごい!"
	@echo "> 🔊إنه عمل جيد! но да, это ясно, 青鼠 !"
	@echo "=================================================="

# Animation target for the takeoff sequence
takeoff:
	@echo "=================================================="
	@i=1; \
	while [ $$i -le 15 ]; do \
		sleep $$(echo "scale=2; 0.5/$$i" | bc); \
		clear; \
		padding=$$(printf "%*s" $$i ""); \
		printf "🔥%slibft takes off 🚀\n" "$${padding// /🔥}"; \
		i=$$((i + 1)); \
	done
	@echo "=================================================="

# Rule to create the library file
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[1;37m📂 .o count:  $(words $(OBJ)) out of 43(max)\033[0m"
	@echo " "
	@echo "\033[1;37m✔️ ended                          ...libft built!"
	@echo "--------------------------------------------------"
	@echo " "

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;30m🛠️ Compiling: \033[0m \033[1;30m$<\033[0m"
	@echo "   \033[1;37m⚙️ Output: \033[0m \033[1;37m$@\033[0m \033[1;30m\t[.o]\033[0m\033[1;30m\t🔍checked.\033[0m"
	@echo "\033[1;37m──────────────────────────────────────────────────\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡟⠛⠛⠛⠛⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⣤⣼⣧⣤⣤⣤⣤⣼⣧⣤⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠛⣛⣛⣛⣛⣛⣛⣛⣛⣛⣛⣛⣛⣛⣛⠛⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⢹⣿⣿⡏⢹⣿⣿⡏⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠘⣿⣿⡇⢸⣿⣿⠃⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⠀⣿⣿⡇⢸⣿⣿⠀⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀*.o⠀>>⠀⣿⣿⠀⣿⣿⡇⢸⣿⣿⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⢿⣿⡇⢸⣿⡿⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡆⢸⣿⡇⢸⣿⡇⢰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⢸⣿⡇⢸⣿⡇⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣷⣾⣿⣷⣾⣿⣷⣾⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "----------------------------------"
	@echo "Object files removed."
	@echo "=================================="

fclean: clean
	@rm -f $(NAME)
	@echo "⠀⣠⣶⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠹⢿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⢀⣀⡀⠀< Libft⠀⠀⠀"
	@echo "⠀⠀⣠⣤⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀"
	@echo "⢀⣼⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀"
	@echo "⣸⣿⣿⣿⣿⣿⣿⣤⣤⣤⣤⡀⠀⠀⠻⠿⠿⠿⠿⠛⠛⠉⠉⢿⣿⣿⣿⣿⣷⡀"
	@echo "⣿⣿⢻⣿⣿⣿⣿⡿⠿⠟⠛⠁⣀⣠⣤⣤⣶⣶⣶⣶⣶⣶⠀⠀⠻⣿⣿⣿⣿⣇"
	@echo "⢻⣿⡆⢿⣿⣿⣿⣿⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠀⣠⣶⣿⣿⣿⣿⡟"
	@echo "⠈⠛⠃⠈⢿⣿⣿⣿⣿⣿⣿⠿⠟⠛⠋⠉⠁⠀⠀⠀⠀⣠⣾⣿⣿⣿⠟⠋⠁⠀"
	@echo "⠀⠀⠀⠀⠀⠙⢿⣿⣿⡏⠀⠀⠀⠀^⠀⠀⠀⠀⠀⣴⣿⣿⣿⠟⠁⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀fclean⠀⠀⣼⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣼⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠻⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "----------------------------------"
	@echo "Library removed."
	@echo "=================================="

re: fclean all


capuche: 
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⠃⠀⠀⠙⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠋⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠾⢛⠒⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣶⣄⡈⠓⢄⠠⡀⠀⠀⠀⣄⣷⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣷⠀⠈⠱⡄⠑⣌⠆⠀⠀⡜⢻⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡿⠳⡆⠐⢿⣆⠈⢿⠀⠀⡇⠘⡆⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣷⡇⠀⠀⠈⢆⠈⠆⢸⠀⠀⢣⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣧⠀⠀⠈⢂⠀⡇⠀⠀⢨⠓⣄⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣦⣤⠖⡏⡸⠀⣀⡴⠋⠀⠈⠢⡀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⠁⣹⣿⣿⣿⣷⣾⠽⠖⠊⢹⣀⠄⠀⠀⠀⠈⢣⡀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣇⣰⢫⢻⢉⠉⠀⣿⡆⠀⠀⡸⡏⠀⠀⠀⠀⠀⠀⢇"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⡇⡇⠈⢸⢸⢸⠀⠀⡇⡇⠀⠀⠁⠻⡄⡠⠂⠀⠀⠀⠘"
	@echo "⢤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠛⠓⡇⠀⠸⡆⢸⠀⢠⣿⠀⠀⠀⠀⣰⣿⣵⡆⠀⠀⠀⠀"
	@echo "⠈⢻⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿⣦⣀⡇⠀⢧⡇⠀⠀⢺⡟⠀⠀⠀⢰⠉⣰⠟⠊⣠⠂⠀⡸"
	@echo "⠀⠀⢻⣿⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢧⡙⠺⠿⡇⠀⠘⠇⠀⠀⢸⣧⠀⠀⢠⠃⣾⣌⠉⠩⠭⠍⣉⡇"
	@echo "⠀⠀⠀⠻⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣞⣋⠀⠈⠀⡳⣧⠀⠀⠀⠀⠀⢸⡏⠀⠀⡞⢰⠉⠉⠉⠉⠉⠓⢻⠃"
	@echo "⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⢀⣀⠠⠤⣤⣤⠤⠞⠓⢠⠈⡆⠀⢣⣸⣾⠆⠀⠀⠀⠀⠀⢀⣀⡼⠁⡿⠈⣉⣉⣒⡒⠢⡼⠀"
	@echo "⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣎⣽⣶⣤⡶⢋⣤⠃⣠⡦⢀⡼⢦⣾⡤⠚⣟⣁⣀⣀⣀⣀⠀⣀⣈⣀⣠⣾⣅⠀⠑⠂⠤⠌⣩⡇⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⣺⢁⣞⣉⡴⠟⡀⠀⠀⠀⠁⠸⡅⠀⠈⢷⠈⠏⠙⠀⢹⡛⠀⢉⠀⠀⠀⣀⣀⣼⡇⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⡟⢡⠖⣡⡴⠂⣀⣀⣀⣰⣁⣀⣀⣸⠀⠀⠀⠀⠈⠁⠀⠀⠈⠀⣠⠜⠋⣠⠁⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⡟⢿⣿⣿⣷⡟⢋⣥⣖⣉⠀⠈⢁⡀⠤⠚⠿⣷⡦⢀⣠⣀⠢⣄⣀⡠⠔⠋⠁⠀⣼⠃⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⡄⠈⠻⣿⣿⢿⣛⣩⠤⠒⠉⠁⠀⠀⠀⠀⠀⠉⠒⢤⡀⠉⠁⠀⠀⠀⠀⠀⢀⡿⠀⠀⠀"

lama:
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠖⢊⣯⣀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⣺⡥⢲⠂⠈⢻⡯"
	@echo "⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠎⡸⠋⠀⢸⢀⡴⠋⠀"
	@echo "⣀⡿⠀⠙⣳⠦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣰⣖⣄⣿⣶⣆⣾⣦⣴⣶⡶⣇⣠⡀⠀⠀⠀⢠⠞⠁⡼⠁⠀⠀⢸⣼⠁⠀⠀"
	@echo "⠈⣧⣬⡻⡀⠉⠱⢽⡲⢤⣀⡀⠀⠀⠀⠀⣤⢴⣾⣿⠿⠋⠉⠉⠁⠈⠀⠀⠀⠀⠉⠀⠉⠻⠧⡿⣤⠞⠁⢀⡼⠁⠀⠀⠀⣸⡏⠀⠀⠀"
	@echo "⠀⠙⠁⣷⢣⠀⠀⠀⠹⢄⠀⠉⠓⡦⣄⣾⡟⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣖⣋⠀⠀⠀⠀⠀⣿⠁⠀⠀⠀"
	@echo "⠀⠀⠀⠘⢎⢧⠀⠀⠀⠈⠓⠦⢄⣛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢿⣄⠀⠀⠀⢰⢻⠂⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠈⠻⣧⠀⠀⠀⠀⣤⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣧⠀⠀⣯⠎⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢯⣣⡀⠀⣠⣿⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⡄⡼⡟⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠸⡵⣄⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠟⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠙⢬⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣆⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠨⣿⢄⠀⠀⠀⠀⢀⣀⣠⣀⠀⠀⠀⢠⠖⠋⠁⠀⠀⠈⠓⢦⠀⢠⣿⣿⣿⣟⠷⡄⠀⠀⣸⡏⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡶⠀⠀⠀⣠⣾⡿⣿⣿⣿⣆⣠⡏⠀⠀⠀⠀⠀⠀⠀⠈⣦⠟⣽⣿⣿⣻⠀⣇⡠⠴⠿⣁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢦⠀⠀⢹⡙⢯⣿⣿⣫⠋⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢻⡦⠽⠷⠾⠓⠋⠁⠀⠀⠘⢏⠁⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣳⠞⠒⠓⠚⠩⠝⠛⠂⣹⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡄⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡁⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⣆⣀⣀⢀⣤⣘⣆⠀⠀⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠉⠀⠀⠀⠀⠀⠀⣠⣾⡆⠀⢀⣿⣧⣌⠉⣼⢶⡿⠀⠀⡿⢺⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⡀⠀⠀⠀⠀⠀⠀⠀⡏⣿⠀⠀⠉⠁⠙⣮⠏⠀⠀⠀⠀⣇⡼⠀⠀⠀⠀⠀⠀⠀⠐⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠀⠀⠀⠳⣘⢄⠀⠀⠀⠀⢸⡀⠀⠀⢀⣼⠟⠀⠀⠀⠀⠀⠀⠀⢀⣿⠋⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡄⠀⠀⠀⠀⠀⠀⠀⠈⠚⠷⣤⠤⠴⠿⠿⠒⢊⡝⠁⠀⠀⠀⠀⠀⠀⠀⠀⢛⣹⣄⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⣶⠄⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠤⠤⠤⠔⠋⠀⠀⠀⠀⠀⠀⢀⣠⠖⠀⠈⣏⠉⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢿⡆⠀⠀⠰⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠒⠉⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠀⠀⠀⠀⠉⠉⠒⠒⠒⠒⠒⠒⠒⠒⠚⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⢼⡄⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡿⠟⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡄⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⠇⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠟⠉⠀⠀⠀⠀⠀"

chef:
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣄⣀⣀⣤⣶⣶⣿⣿⣿⣿⣶⣦⣄⣀⣀⣠⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣶⣶⣦⣴⣶⣿⣿⠿⠿⠿⢿⣿⡿⠟⠛⠉⠉⠉⠉⠉⠙⠻⠿⠿⠿⠿⠟⠛⢿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠿⠛⠛⠛⠛⠿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣇⠀⠀⠀⠀⢀⠀⠀⠀⠀⢀⣤⣀⠀⠀⠀⠀⠀⢀⣤⣶⣄⣀⠀⠀⠀⣀⣴⣿⣿⡿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣷⣶⣶⣾⣿⣿⣶⣶⣾⡿⠿⣿⣷⣶⣶⣶⣶⣿⠟⠛⠿⣿⣿⣿⣿⣿⠿⠋⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢻⡟⠉⠉⠉⡉⠉⠁⠀⠀⠀⠈⠉⢉⡉⠉⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠿⠀⠀⢀⣠⣦⣤⣤⣤⣤⣴⣶⣾⣶⣤⣄⣀⣈⣀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⣤⣤⣴⡶⢾⣿⣿⣿⠿⠿⢿⣿⣿⣿⠿⠛⠛⠿⣿⣿⠛⠻⠿⠿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠋⠁⠀⠀⣼⣿⡟⠀⠀⠀⣀⠹⣿⡏⣠⡀⠀⠀⠈⢿⣿⠂⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠁⢰⣿⣷⡀⠀⠀⠀⠀⣸⡇⠀⠀⠀⣼⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡀⠀⠀⠀⠀⢿⣦⣄⣀⣤⡴⠟⠉⠙⢿⣶⣤⣤⡾⠟⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣇⠀⠀⠀⠀⠀⠉⠉⠉⢉⢀⣀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⢰⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠈⢛⣛⣉⣉⡉⠉⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣦⣀⠀⠀⢀⣶⠿⠛⠛⢻⣿⠛⠛⠛⠿⣷⣦⢀⣠⣾⣿⣿⣿⣿⣿⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣀⣀⣤⣄⣀⣤⣤⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠈⠉⠛⠿⣷⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠁⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠈⠙⠻⢷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢀⣴⠟⠋⠀⠀⢀⣤⡀⠀⠉⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⠀⠀⢀⣶⣦⡀⠀⠀⠀⢀⣤⡀⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⣠⠟⠁⠀⠀⠀⠀⢸⣿⠙⣦⡀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠈⢻⣦⣤⡴⠿⢿⡇⠀⠀⠹⣷⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⢠⡾⠃⠀⢠⣶⣶⣶⣴⣾⣿⠀⠈⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣸⣇⠀⠀⠛⠋⠀⠀⢾⣿⡿⣿⡆⠘⣷⡀⠀⠀⠀⠀"
	@echo "⠀⠀⣴⠟⠀⠀⠀⣾⣇⠀⠀⠈⠉⠛⠀⠀⠈⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣾⡿⠿⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡇⠀⢹⣷⠀⠀⠀⠀"

42:
	@echo "        :::     :::::::: "
	@echo "      :+:     :+:    :+: "
	@echo "    +:+ +:+        +:+   "
	@echo "  +#+  +:+      +#+      "
	@echo "+#+#+#+#+#+  +#+         "
	@echo "     #+#   #+#           "
	@echo "    ###  ##########      "

tutti: 42 lama capuche chef 

.PHONY: all clean fclean re takeoff tutti 42 lama capuche chef 
