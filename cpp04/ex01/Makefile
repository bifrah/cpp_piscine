DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

NAME			= AnimalWithBrain.out
CC				= c++
PARAMS			= -Wall -Wextra -Werror -std=c++98

INC_PATH 		= ./
OBJ_PATH		= obj/
SRC_PATH		= ./

OBJ_NAME		= $(SRC_NAME:.cpp=.o)
SRC_NAME		= main.cpp \
					Animal.cpp \
					Dog.cpp \
					Cat.cpp \
					Brain.cpp

INC				= -I $(INC_PATH)
OBJ				= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[ex01] : $(DEF)Compilation..."
	@$(CC) $(PARAMS) $(OBJ) -o $(NAME) $(INC)
	@echo "$(RED)[ex01] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[ex01] :$(DEF) Compiling $@"
	@$(CC) $(PARAMS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)[ex01] : $(DEF)Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[ex01] : $(DEF)Full Cleaning               $(GRN)[OK]$(DEF)"

re: fclean all