# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 23:08:04 by ldedier           #+#    #+#              #
#    Updated: 2019/10/19 20:03:15 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro

CC		= clang++

ECHO = echo
MKDIR = mkdir
RM = rm

DEBUG ?= 0

SRCDIR			=	srcs/
OBJ_DIR			=	objs/
BINDIR			=	./
INCLUDESDIR		=	includes/

INCLUDES		=	AbstractEnemy.hpp \
					AbstractEntity.hpp \
					AbstractForegroundEntity.hpp \
					AbstractProjectile.hpp \
					AbstractPickup.hpp \
					WeaponSlot.hpp \
					AbstractWeapon.hpp \
					Map.hpp \
					Game.hpp \
					Player.hpp \
					PlayingScreen.hpp \
					Blueprint.hpp \
					Vec2.hpp \
					EntityContainer.hpp \
					IShooter.hpp \
					EntityFactory.hpp \
					WeaponFactory.hpp \
					LaserThrower.hpp

SRCS		=		main.cpp \
					AbstractEnemy.cpp \
					AbstractEntity.cpp \
					AbstractForegroundEntity.cpp \
					AbstractProjectile.cpp \
					AbstractPickup.cpp \
					WeaponSlot.cpp \
					AbstractWeapon.cpp \
					Map.cpp \
					Game.cpp \
					Player.cpp \
					PlayingScreen.cpp \
					Blueprint.cpp \
					Vec2.cpp \
					EntityContainer.cpp \
					EntityFactory.cpp \
					WeaponFactory.cpp \
					LaserThrower.cpp

 


VPATH			=	$(INCLUDESDIR) \
					$(SRCDIR)

OBJECTS			=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

CFLAGS			= -I $(INCLUDESDIR) -Wall -Wextra -Werror -std=c++98

OK_COLOR	=	\x1b[32;01m
EOC			=	\033[0m

LFLAGS = -lncurses

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
	CC += -g3
endif
	
SPEED = -j8

all: $(NAME)

debug:
	@$(MAKE) all DEBUG=1

$(BINDIR)$(NAME): $(OBJ_DIR) $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LFLAGS)
	@$(ECHO) "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJ_DIR):
	@$(MKDIR) $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -f $(BINDIR)$(NAME)

re: fclean all

.PHONY: all clean fclean re debug
