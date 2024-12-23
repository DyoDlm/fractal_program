NAME = fractol 

TDIR = tools
SDIR = graphic_management
HDIR = h_files
MDIR = minilibx-linux
ODIR = objs

HEADERS = $(wildcard $(HDIR)/*.h)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HDIR) -I$(MDIR)
DFLAGS = -fsanitize=address -g
MFLAGS = -L$(MDIR) -lmlx_Linux -lXext -lX11 -lm

SRCS = $(wildcard $(SDIR)/*.c) $(wildcard $(TDIR)/*.c) main.c

MLX = $(MDIR)/libmlx_Linux.a

OBJS = $(addprefix $(ODIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(MLX):
	@make -C $(MDIR)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -o $@
	@echo "Compilation effectuée."

$(ODIR)/%.o: $(SDIR)/%.c $(HEADERS) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(TDIR)/%.c $(HEADERS) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: %.c $(HEADERS) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	@mkdir -p $(ODIR)

clean:
	@rm -rf $(ODIR)
	@echo "Nettoyage des fichiers objets effectué."

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet effectué."

re: fclean all

dbug: CFLAGS += $(DFLAGS)
dbug: re

.PHONY: all clean fclean re dbug
