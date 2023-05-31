.PHONY: clean

RM = rm -f

all: similarity ls_c

similarity: similarity.c
        gcc -o similarity similarity.c `pkg-config --cflags --libs gtk+-3.0`

ls_c: ls_c.c
        gcc -o ls_c ls_c.c

clean:
        $(RM) similarity ls_c
