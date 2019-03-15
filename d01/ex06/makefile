# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 12:38:55 by pbie              #+#    #+#              #
#    Updated: 2019/03/15 16:35:12 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = violence

SRC = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
