NAME			=	libft.a

CC				=	gcc -g
CFLAGS			=	-Wall -Werror -Wextra

SRC_DIR			=	./src
INC_DIR			=	./include

OBJ_DIR			=	./obj
OBJ_CH_DIR		=	./obj/ft_ch
OBJ_LST_DIR		=	./obj/ft_lst
OBJ_MEM_DIR		=	./obj/ft_mem
OBJ_NUM_DIR		=	./obj/ft_num
OBJ_PRINTF_DIR	=	./obj/ft_printf
OBJ_PUT_DIR		=	./obj/ft_put
OBJ_READ_DIR	=	./obj/ft_read
OBJ_STR_DIR		=	./obj/ft_str
OBJ_SWAP_DIR	=	./obj/ft_swap
OBJ_SYSTEM_DIR	=	./obj/ft_system
OBJ_VECTOR_DIR	=	./obj/ft_vector

SRC				=	ft_ch/ft_isalnum.c \
					ft_ch/ft_isalpha.c \
					ft_ch/ft_isascii.c \
					ft_ch/ft_isdigit.c \
					ft_ch/ft_isprintable.c \
					ft_ch/ft_isspace.c \
					ft_ch/ft_tolower.c \
					ft_ch/ft_toupper.c \
					ft_lst/ft_lstadd.c \
					ft_lst/ft_lstaddend.c \
					ft_lst/ft_lstdel.c \
					ft_lst/ft_lstdelone.c \
					ft_lst/ft_lstiter.c \
					ft_lst/ft_lstmap.c \
					ft_lst/ft_lstnew.c \
					ft_mem/ft_dpclear.c \
					ft_mem/ft_memalloc.c \
					ft_mem/ft_memchr.c \
					ft_mem/ft_memcpy.c \
					ft_mem/ft_memmove.c \
					ft_mem/ft_bzero.c \
					ft_mem/ft_dpclearnum.c \
					ft_mem/ft_memccpy.c \
					ft_mem/ft_memcmp.c \
					ft_mem/ft_memdel.c \
					ft_mem/ft_memset.c \
					ft_num/ft_atoi.c \
					ft_num/ft_atoi_base.c \
					ft_num/ft_itoa.c \
					ft_num/ft_ltoa_base.c \
					ft_num/ft_numlen.c \
					ft_num/ft_utoa_base.c \
					ft_printf/ft_printf.c \
					ft_printf/get_integer.c \
					ft_printf/int_output.c \
					ft_printf/output_processing_f.c \
					ft_printf/processing_functions.c \
					ft_printf/char_and_nonstandard_output.c \
					ft_printf/get_float_components.c \
					ft_printf/help_functions_for_float.c \
					ft_printf/other_and_bonus.c \
					ft_printf/output_processing_uob.c \
					ft_printf/float_output.c \
					ft_printf/get_fraction.c \
					ft_printf/help_functions_for_int.c \
					ft_printf/output_processing_di.c \
					ft_printf/output_processing_x.c \
					ft_put/ft_putchar.c \
					ft_put/ft_putchar_fd.c \
					ft_put/ft_putendl.c \
					ft_put/ft_putendl_fd.c \
					ft_put/ft_putnbr.c \
					ft_put/ft_putnbr_fd.c \
					ft_put/ft_putstr.c \
					ft_put/ft_putstr_fd.c \
					ft_read/ft_multi_files_read_line.c \
					ft_read/ft_read_file.c \
					ft_read/ft_single_file_read_line.c \
					ft_str/ft_strclr.c \
					ft_str/ft_strequ.c \
					ft_str/ft_strjoinfree.c \
					ft_str/ft_strmapi.c \
					ft_str/ft_strnew.c \
					ft_str/ft_strstr.c \
					ft_str/ft_strwclen.c \
					ft_str/ft_strcat.c \
					ft_str/ft_strcmp.c \
					ft_str/ft_strisnum.c \
					ft_str/ft_strlcat.c \
					ft_str/ft_strncat.c \
					ft_str/ft_strnewsetchar.c \
					ft_str/ft_strsub.c \
					ft_str/ft_strwcnumber.c \
					ft_str/ft_strchnum.c \
					ft_str/ft_strcpy.c \
					ft_str/ft_striter.c \
					ft_str/ft_strlen.c \
					ft_str/ft_strncmp.c \
					ft_str/ft_strnstr.c \
					ft_str/ft_strsubfree.c \
					ft_str/ft_strwlen.c \
					ft_str/ft_strchr.c \
					ft_str/ft_strdel.c \
					ft_str/ft_striteri.c \
					ft_str/ft_strlowcase.c \
					ft_str/ft_strncpy.c \
					ft_str/ft_strrchr.c \
					ft_str/ft_strtrim.c \
					ft_str/ft_strwnumber.c \
					ft_str/ft_strchrpos.c \
					ft_str/ft_strdup.c \
					ft_str/ft_strjoin.c \
					ft_str/ft_strmap.c \
					ft_str/ft_strnequ.c \
					ft_str/ft_strsplit.c \
					ft_str/ft_strupcase.c \
					ft_swap/ft_dswap.c \
					ft_swap/ft_fswap.c \
					ft_swap/ft_swap.c \
					ft_system/ft_exit_with_error.c \
					ft_system/ft_log_error.c \
					ft_vector/ft_vector_create.c \
					ft_vector/ft_vector_free.c \
					ft_vector/ft_vector_push_back.c

INCS			=	$(INC_DIR)/ft_printf.h \
					$(INC_DIR)/ft_read.h \
					$(INC_DIR)/libft.h

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				= 	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all:			dirs $(OBJ_DIR) $(NAME)

$(NAME):		$(OBJS) $(INCS)
				ar rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

dirs:			$(OBJ_DIR) $(OBJ_CH_DIR) $(OBJ_LST_DIR) $(OBJ_MEM_DIR) $(OBJ_NUM_DIR) $(OBJ_PRINTF_DIR) $(OBJ_PUT_DIR) $(OBJ_READ_DIR) $(OBJ_STR_DIR) $(OBJ_SWAP_DIR) $(OBJ_SYSTEM_DIR) $(OBJ_VECTOR_DIR)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)
$(OBJ_CH_DIR):
				mkdir -p $(OBJ_CH_DIR)
$(OBJ_LST_DIR):
				mkdir -p $(OBJ_LST_DIR)
$(OBJ_MEM_DIR):
				mkdir -p $(OBJ_MEM_DIR)
$(OBJ_NUM_DIR):
				mkdir -p $(OBJ_NUM_DIR)
$(OBJ_PRINTF_DIR):
				mkdir -p $(OBJ_PRINTF_DIR)
$(OBJ_PUT_DIR):
				mkdir -p $(OBJ_PUT_DIR)
$(OBJ_READ_DIR):
				mkdir -p $(OBJ_READ_DIR)
$(OBJ_STR_DIR):
				mkdir -p $(OBJ_STR_DIR)
$(OBJ_SWAP_DIR):
				mkdir -p $(OBJ_SWAP_DIR)
$(OBJ_SYSTEM_DIR):
				mkdir -p $(OBJ_SYSTEM_DIR)
$(OBJ_VECTOR_DIR):
				mkdir -p $(OBJ_VECTOR_DIR)

clean:
			/bin/rm -rf $(OBJ_DIR)

fclean: clean
			/bin/rm -f $(NAME)

re: fclean all
