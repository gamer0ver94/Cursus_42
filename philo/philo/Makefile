########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -Wall -Werror -Wextra -g -pthread
LDFLAGS = 

APPNAME = philo
EXT = .c
SRCDIR = srcs/
OBJDIR = objs/
SANITIZER = -g3 
# -fsanitize=address
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
RM = rm
DELOBJ = $(OBJ)

all: $(APPNAME)

$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(SANITIZER)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(APPNAME)

fclean:	clean

re: fclean all
