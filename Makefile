src = 	$(wildcard src/adt/*.c) \ 
		$(wildcard src/engine/*.c)

obj = $(src:.c=.o)

