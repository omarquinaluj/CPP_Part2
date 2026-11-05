NAME		:=	convert

CC			:=	c++

SRCS		:=	main.cpp \
				ScalarConverter.cpp

OBJS		:=	$(SRCS:%.cpp=%.o)

CFLAGS		=	-Wall -Wextra -Werror -std=c++98
DFLAG		:=	-g -D DEBUG=1

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

debug: CFLAGS += $(DFLAG)
debug: re
	./$(NAME)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

val:
	valgrind --leak-check=full -s ./$(NAME) 42.0

leak:
	leaks --atExit -- ./$(NAME) 42.0

test:
	# ===== Official examples =====
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f

	# ===== CHAR =====
	./convert "'P'"
	./convert "'Z'"
	./convert "'*'"
	./convert "'0'"

	# ===== INT =====
	./$(NAME) 42
	./$(NAME) -42
	./$(NAME) +42
	./$(NAME) 1
	./$(NAME) -1
	./$(NAME) 2147483647
	./$(NAME) -2147483648

	# ===== FLOAT =====
	./$(NAME) 42.42f
	./$(NAME) -42.42f
	./$(NAME) +42.42f
	./$(NAME) 0.0f
	./$(NAME) 1.5f
	./$(NAME) -0.5f

	# ===== DOUBLE =====
	./$(NAME) 65.65
	./$(NAME) -65.65
	./$(NAME) +65.65
	./$(NAME) 0.0
	./$(NAME) 42.42
	./$(NAME) -0.5

	# ===== PSEUDO-LITERALS =====
	./$(NAME) nan
	./$(NAME) nanf
	./$(NAME) +inf
	./$(NAME) -inf
	./$(NAME) +inff
	./$(NAME) -inff

	# ===== INT OVERFLOW =====
	./$(NAME) 2147483648
	./$(NAME) -2147483649
	./$(NAME) 65489616545

	# ===== DOUBLE -> INT / CHAR =====
	./$(NAME) 42.9
	./$(NAME) 65.9
	./$(NAME) 127.9
	./$(NAME) 128.0
	./$(NAME) -1.0

	# ===== CHAR DISPLAYABILITY =====
	./$(NAME) 0
	./$(NAME) 9
	./$(NAME) 31
	./$(NAME) 32
	./$(NAME) 65
	./$(NAME) 126
	./$(NAME) 127

	# ===== FLOAT / DOUBLE LARGE VALUES =====
	./$(NAME) 340282346638528859811704183484516925440.0f
	./$(NAME) 1e10
	./$(NAME) 65489616545.65

	# ===== HUGE VALUES =====
	./$(NAME) 15454568454651561653435865488946519616545.65
	./$(NAME) 6548894848994848484865154645454564659616545.65f

	# ===== INVALID INPUT =====
	./$(NAME) ZU
	./$(NAME) abc
	./$(NAME) 42abc
	./$(NAME) 42f
	./$(NAME) 42.
	./$(NAME) .42
	./$(NAME) 42.42ff
	./$(NAME) ++42
	./$(NAME) --42
	./$(NAME) +
	./$(NAME) -
	./$(NAME) ""

.PHONY: clean fclean re test