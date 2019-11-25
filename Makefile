#Cara pakenya:
#ketik make di terminal di root atau di src

CC=gcc
TARGET=catur
src = 	$(src/*.c) \ 
		$(src/adt/*.c) \ 
		$(src/engine/*.c)

obj = $(src:.c=.o)

$(TARGET) : $(obj)
	$(CC) -o $@ $^



