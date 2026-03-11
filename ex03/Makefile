CXX := c++
# CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CXXFLAGS := 

NAME := a.out
SRC := AForm.cpp main.cpp Bureacrat.cpp PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp

OBJ_DIR := obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re