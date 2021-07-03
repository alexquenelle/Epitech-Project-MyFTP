##
## EPITECH PROJECT, 2021
## B-FUN-300-BDX-3-1-funPoolDay2-alexandre.quenelle
## File description:
## Makefile
##

SRC			=	src/main.c					\
				src/launch_ftp.c			\
				src/handle_command.c		\
				src/lib_command_first.c		\
				src/lib_command_second.c	\
				src/lib_command_third.c		\
				src/setup_ftp.c

BUILDDIR	=	obj

OBJ			=	$(SRC:%.c=$(BUILDDIR)/%.o)

NAME		=	myftp

CC			=	gcc

LD			=	$(CC)

CFLAGS		=	-I./include

LDFLAGS		=

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

clean:
	rm -rf $(BUILDDIR)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re:	fclean all

.SECONDEXPANSION:
$(BUILDDIR)/%.o : override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o : %.c | $$(@D)/.
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/.:
	mkdir $@

$(BUILDDIR)%/.:
	mkdir -p $@

.PRECIOUS:	$(BUILDDIR)/. $(BUILDDIR)%/.

.PHONY: all re clean fclean

-include $(OBJ:.o=.d)