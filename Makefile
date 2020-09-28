NAME			:= 		glsr

SRC_DIR			:= 		./srcs
INC_DIR			:= 		./includes
OBJ_DIR			:=		./objs
MVM_OBJ_DIR		:=		./objs/matrix_vector_math
PFJ_OBJ_DIR		:=		./objs/parse_from_json
LOAD_OBJ_DIR	:=		./objs/loaders
EVENTS_OBJ_DIR	:=		./objs/events_processing

CC				:=		gcc
CFLAGS			:=		-Wall -Wextra -Werror -O2

SRC				:=		main.c \
						init.c \
						utilities.c \
						create_object_from_raw.c \
						render_loop.c \
						events_processing.c \
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

INCS			:=		$(INC_DIR)/bmpheader.h \
						$(INC_DIR)/matrix_vector_math.h \
						$(INC_DIR)/opengl_simple_render.h \
						$(INC_DIR)/parse_json.h

FT				:=		./libs/libft/
FT_LIB			:=		$(addprefix $(FT),libft.a)
FT_INC			:=		-I ./libs/libft/include
FT_LNK			:=		-L ./libs/libft -l ft

CJSON			:=		~/.brew/lib
CJSON_INC		:=		-I ~/.brew/include/cjson/
CJSON_LNK		:=		-L ~/.brew -l cjson

GLEW			:=		./libs/libglew/
GLEW_LIB		:=		$(addprefix $(GLEW)lib/,libGLEW.a)
GLEW_INC		:=		-I ./libs/libglew/include
GLEW_LNK		:=		-L ./libs/libglew/lib -l glew

SDL_INC			:=		-I ~/.brew/include/SDL2/
SDL_LNK			:=		-L ~/.brew/lib -lsdl2

FRAMEWORKS		:=		-framework OpenGL -framework AppKit

$(info $$GLEW_LIB is [${GLEW_LIB}])
$(info $$CJSON_LNK is [${CJSON_LNK}])

all:			dirs $(NAME)

$(NAME):		$(FT_LIB) $(GLEW_LIB) $(OBJ_DIR) $(INCS) $(FT_INC) $(GLEW_INCt ) $(OBJS)
				$(CC) $(CFLAGS) $(FT_LNK) $(CJSON_LNK) $(SDL_LNK) $(GLEW_LNK) $(FRAMEWORKS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) $(GLEW_INC) $(SDL_INC) -I $(INC_DIR) $(FT_INC) $(CJSON_INC) -o $@ -c $<

$(FT_LIB):
				make -C $(FT)

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

fclean: 		clean
				rm -f $(NAME)
				make -C $(FT) fclean

re: 			fclean all

