SRC_DIR	= ./src/

SRCS	= format.c \
          \
          char_handler.c \
          decimal_handler.c \
          float_handler.c \
          handler.c \
          percent_handler.c \
          pointer_handler.c \
          string_handler.c \
          unsigned_handler.c \
          hexa_handler.c \
          number_handler.c \
          scientific_handler.c \
          gravity_handler.c \
          \
          parser.c \
          \
          printer.c \
          \
          ft_negative.c \
          ft_atoi.c \
          ft_calloc.c \
          ft_ftoa.c \
          ft_is_digit.c \
          ft_isinf.c \
          ft_isnan.c \
          ft_memcpy.c \
          ft_memset.c \
          ft_realloc.c \
          ft_strdup.c \
          ft_strlen.c \
          ft_tohexa.c \
          ft_power.c \
          ft_print_wchar.c \
          ft_ftoe.c \
          \
          ft_printf.c \


HEADERS		= ./include/ft_printf.h \
              ./include/format.h \
              ./include/handler.h \
              ./include/parser.h \
              ./include/printer.h \
              ./include/utils.h \


NAME = libftprintf.a
OBJECTS = $(SRCS:.c=.o)
INCLUDES = -I ./include
CC = gcc
CFLAGS = -Werror -Wall -Wextra -c

.PHONY: all clean fclean re bonus

%.o: $(SRC_DIR)%.c $(HEADERS)
	@ echo "Compiling $<..."
	@ $(CC) -g $(CFLAGS) $< $(INCLUDES)

$(NAME): $(OBJECTS)
	@ echo -n "Creating library $(NAME)..."
	@ ar rc $(NAME) $(OBJECTS)
	@ ranlib $(NAME)
	@ echo "Successfully completed."

all: $(NAME)

bonus: $(NAME)

clean:
	@ rm -f $(OBJECTS)
	@ echo "Successfully cleaned objects."

fclean: clean
	@ rm -f $(NAME)
	@ echo "Successfully cleaned library."

re: fclean all
	@ echo "Successfully recompiled."