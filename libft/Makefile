NAME = libft.a
CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
SRC = ft_atoi.c \
	  ft_isdigit.c \
	  ft_memcpy.c \
	  ft_strcmp.c \
	  ft_strncat.c \
	  ft_strstr.c \
	  ft_bzero.c \
	  ft_isprintable.c \
	  ft_memmove.c \
	  ft_strcpy.c \
	  ft_strncmp.c \
	  ft_tolower.c \
	  ft_isalnum.c \
	  ft_memccpy.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strncpy.c \
	  ft_toupper.c \
	  ft_isalpha.c \
	  ft_memchr.c \
	  ft_strcat.c \
	  ft_strlcat.c \
	  ft_strnstr.c \
	  ft_isascii.c \
	  ft_memcmp.c \
	  ft_strchr.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strwnumber.c \
	  ft_strwcnumber.c \
	  ft_strsplit.c \
	  ft_strwlen.c \
	  ft_strwclen.c \
	  ft_numlen.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_dpclear.c \
	  ft_numlen.c \
	  ft_strchnum.c \
	  ft_strlowcase.c \
	  ft_strupcase.c \
	  ft_isspace.c \
	  ft_strisnum.c \
	  ft_whereisch.c \
	  ft_strjoinfree.c \
	  get_next_line.c \
	  ft_dpclearnum.c \
	  ft_swap.c \
	  ft_dswap.c \
	  ft_fswap.c \
	  ft_atoi_base.c \
	  ft_restrsub.c \
	  ft_strnewsetchar.c \
	  ft_ltoa_base.c \
	  ft_utoa_base.c \
	  char_and_nonstandard_output.c \
	  get_fraction.c \
	  int_output.c \
	  output_processing_uob.c \
	  float_output.c \
	  get_integer.c \
	  other_and_bonus.c \
	  output_processing_x.c \
	  ft_printf.c \
	  help_functions_for_float.c \
	  output_processing_di.c \
	  processing_functions.c \
	  get_float_components.c \
	  help_functions_for_int.c \
	  output_processing_f.c

OBJ=$(SRC:.c=.o)
%.c : %.o

all: $(NAME)

$(NAME): $(OBJ)
			ar rc $(NAME) *.o
.c.o:
			$(CC) $(CFLAGS) -o $@ $<

clean:
			/bin/rm -f *.o

fclean: clean
			/bin/rm -f $(NAME)

re: fclean all
