# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 20:22:36 by marvin            #+#    #+#              #
#    Updated: 2025/11/06 20:22:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# O nome do seu programa executável final
NAME = gnl_tester

# O compilador que você usará (cc é o padrão da 42, geralmente linkado para gcc ou clang)
CC = cc

# Flags de compilação:
# -Wall -Wextra -Werror: Mostra todos os avisos e os trata como erros (padrão 42)
# -g: Adiciona símbolos de debug (ESSENCIAL para usar o GDB)
CFLAGS = -Wall -Wextra -Werror -g

# Definição do BUFFER_SIZE:
# Pega o valor da variável BUFFER_SIZE, se não for definido, usa 42 como padrão.
# Você pode compilar com um buffer diferente usando: make BUFFER_SIZE=1024
BUFFER_SIZE = 42
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)

# Arquivos de remoção
RM = rm -f

# Seus arquivos fonte (.c)
# IMPORTANTE: Adicione seu arquivo main.c aqui quando o criar!
SRCS = get_next_line.c \
       get_next_line_utils.c \
       main.c

# Arquivos de objeto (.o) - O Makefile os gera automaticamente a partir de SRCS
OBJS = $(SRCS:.c=.o)

# Seu arquivo header (.h)
HEADER = get_next_line.h

#
# REGRAS DO MAKEFILE
#

# Regra 'all' (padrão): Compila o programa $(NAME)
all: $(NAME)

# Regra para criar o programa final $(NAME)
# Depende dos arquivos .o
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "GNL compilado com BUFFER_SIZE = $(BUFFER_SIZE) -> $(NAME)"

# Regra genérica para transformar qualquer .c em .o
# Depende do .c correspondente e do seu ARQUIVO HEADER
# Se você mudar o .h, todos os .o serão recompilados.
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regra 'clean': Remove apenas os arquivos de objeto (.o)
clean:
	@$(RM) $(OBJS)
	@echo "Arquivos objeto (.o) removidos."

# Regra 'fclean': Remove os .o e o executável final
fclean: clean
	@$(RM) $(NAME)
	@echo "Executável ($(NAME)) removido."

# Regra 're': Força uma recompilação completa
re: fclean all

# Declara quais regras não são arquivos (boa prática)
.PHONY: all clean fclean re
