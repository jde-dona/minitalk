####### NAME #########

NAMES = server 
NAMEC = client

###### VARIABLE ######

INCLUDE = include

DIRSRCS =
DIROBJS = obj/

FLSRCS = ft_printf.c ft_printf_utils.c

FLOBJS = ${FLSRCS:.c=.o}
OBJS = $(addprefix $(DIROBJS),$(FLOBJS))

CLISRC = client.c
SRVSRC = server.c

CLIOBJ = ${CLISRC:.c=.o}
SRVOBJ = ${SRVSRC:.c=.o}

COBJS = $(addprefix $(DIROBJS),$(CLIOBJ))
SOBJS = $(addprefix $(DIROBJS),$(SRVOBJ))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: ${NAMES} ${NAMEC}

${NAMEC}: ${OBJS} ${COBJS}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${NAMEC}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(NAMEC) ${COBJS} $(OBJS)

${NAMES}: ${OBJS} ${SOBJS}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${NAMES}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(NAMES) ${SOBJS} $(OBJS)

bonus:	all

clean:
	${RM} ${OBJS} ${COBJS} ${SOBJS}  

fclean: clean
	${RM} ${NAMEC} ${NAMES}

re: fclean all

.PHONY: all clean fclean re bonus .c.o
.SUFFIXES: .c .o 
