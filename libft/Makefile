# Nom de l'archive de la librairie
NAME = libft.a

# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Utilitaires pour créer l'archive
AR = ar
ARFLAGS = rcs

# Répertoire contenant les fichiers source
SRCS = ./src/

# Liste des fichiers source de la libft (sans les bonus)
SOURCES = ft_split.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_ifchr.c ft_ifhex.c ft_ifstr.c ft_ifptr.c ft_ifint.c ft_ifudi.c \
			ft_printf.c

# Conversion des fichiers .c en fichiers objets .o
OBJECTS = ${addprefix ${SRCS}, ${SOURCES:.c=.o}}

# Règle principale: créer la librairie (libft.a)
all : ${NAME}

# Crée l'archive à partir des objets
${NAME} : ${OBJECTS}
		@echo "Création de l'archive ${NAME}..."
		${AR} ${ARFLAGS} $@ $^
		@echo "${NAME} créé avec succès !"

# Règle pour compiler les fichiers source en objets
${SRCS}%.o : ${SRCS}%.c
		@echo "Compilation de $<..."
		${CC} ${CFLAGS} -I ../includes -o $@ -c $<
		@echo "Fichier objet $@ généré."

# Nettoyer les fichiers objets
clean :
		@echo "Suppression des fichiers objets..."
		rm -rf ${OBJECTS} $(NAME)
		@echo "Fichiers objets supprimés."

# Nettoyer les fichiers objets et l'archive
fclean : clean
		@echo "Suppression de l'archive ${NAME}..."
		rm -rf ${NAME}
		@echo "${NAME} supprimé avec succès."

# Recompiler tout depuis le début
re : fclean all

# Spécifie que ces règles ne correspondent pas à des fichiers
.PHONY: all clean fclean re
