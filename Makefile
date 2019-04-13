NAME := poker

CC = clang -std=c11 -Wall -Wextra -Werror -Wpedantic

INCDIR := ./inc
SRCDIR := ./src
OBJDIR := ./obj

SRC := $(addprefix $(SRCDIR)/, 	main.c libft.c utils.c validate.c solution.c)

OBJ := $(addprefix $(OBJDIR)/, 	main.o libft.o utils.o validate.o solution.o)


$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $< -o $@ -I $(INCDIR)

all: install

install: $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(OBJ) -o $(NAME) -I $(INCDIR)

$(OBJ) : | $(OBJDIR)

$(OBJDIR):
			mkdir $(OBJDIR)

clean:
			rm -rf $(OBJDIR)
	
uninstall: clean
			rm -f $(NAME)

reinstall: uninstall install
