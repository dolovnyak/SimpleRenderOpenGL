NAME			:= 		glsr

SRC_DIR			:= 		./srcs
INC_DIR			:= 		./includes
OBJ_DIR			:=		./objs
JC_OBJ_DIR		:=		./objs/rt_jtoc
MVM_OBJ_DIR		:=		./objs/matrix_vector_math
PFJ_OBJ_DIR		:=		./objs/parse_from_json
LOAD_OBJ_DIR	:=		./objs/loaders
EVENTS_OBJ_DIR	:=		./objs/events_processing

CC				:=		gcc
#CFLAGS			:= 		-Wall -Wextra -Werror -g -fsanitize=address

SRC				:=		main.c \
						init.c \
						utilities.c \
						create_object_from_raw.c \
						events_processing/events_processing.c \
						events_processing/objects_events_processing.c \
						loaders/load_and_create_shader_program.c \
						loaders/load_bmp.c \
						loaders/load_obj_file.c \
						matrix_vector_math/mvm_add.c \
						matrix_vector_math/mvm_identity.c \
						matrix_vector_math/mvm_multiply.c \
						matrix_vector_math/mvm_projection.c \
						matrix_vector_math/mvm_rotate.c \
						matrix_vector_math/mvm_scale.c \
						matrix_vector_math/mvm_translate.c \
						matrix_vector_math/mvm_utilities.c \
						parse_from_json/pfj_parse_main.c \
						parse_from_json/pfj_parse_scene_objects.c \
						parse_from_json/pfj_parse_scenes.c \
						parse_from_json/pfj_parse_window.c \
						parse_from_json/pfj_utilities.c

SRCS			:=		$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				:= 		$(SRC:.c=.o)
OBJS			:=		$(addprefix $(OBJ_DIR)/, $(OBJ))

FT				:=		./libs/libft/
FT_LIB			:=		$(addprefix $(FT),libft.a)
FT_INC			:=		-I ./libs/libft/include
FT_LNK			:=		-L ./libs/libft -l ft

JC				:=		./libs/libjtoc/
JC_LIB			:=		$(addprefix $(JC),libjtoc.a)
JC_INC			:=		-I ./libs/libjtoc/include
JC_LNK			:=		-L ./libs/libjtoc -l jtoc

GLEW			:=		./libs/libglew/
GLEW_LIB		:=		$(addprefix $(GLEW),libGLEW.a)
GLEW_INC		:=		-I ./libs/libglew/include
GLEW_LNK		:=		-L ./libs/libglew/lib -l glew

GLFW_INC		:=		-I ~/.brew/include
GLFW_LNK		:=		-L ~/.brew/lib -lglfw

FRAMEWORKS		:=		-framework OpenGL -framework AppKit

all:			dirs $(FT_LIB) $(JC_LIB) $(GLEW_LIB) $(OBJ_DIR) $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(FT_LNK) $(JC_LNK) $(GLFW_LNK) $(GLEW_LNK) $(FRAMEWORKS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) $(GLEW_INC) $(GLFW_INC) -I $(INC_DIR) $(FT_INC) $(JC_INC) -o $@ -c $<

$(FT_LIB):
				make -C $(FT)

$(JC_LIB):
				make -C $(JC)

$(GLEW_LIB):
				make -C $(GLEW)

dirs:			$(OBJ_DIR) $(JC_OBJ_DIR) $(MVM_OBJ_DIR) $(PFJ_OBJ_DIR) $(LOAD_OBJ_DIR) $(EVENTS_OBJ_DIR)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(JC_OBJ_DIR):
				mkdir -p $(JC_OBJ_DIR)

$(MVM_OBJ_DIR):
				mkdir -p $(MVM_OBJ_DIR)

$(PFJ_OBJ_DIR):
				mkdir -p $(PFJ_OBJ_DIR)

$(LOAD_OBJ_DIR):
				mkdir -p $(LOAD_OBJ_DIR)

$(EVENTS_OBJ_DIR):
				mkdir -p $(EVENTS_OBJ_DIR)

clean:
				rm -f $(OBJS)
				make -C $(FT) clean
				make -C $(JC) clean
				make -C $(GLEW) clean

fclean: 		clean
				rm -f $(NAME)
				make -C $(FT) fclean
				make -C $(JC) fclean

re: 			fclean all

