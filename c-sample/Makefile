CFLAGS := -Wall -Werror

.deflault: app

.PHONY: app
# let's cheat a bit and hardcode main.o, foo.o and bar.o
app: foo.o bar.o main.o
# link object files
 ${CC} -o app $^

%.o: %.c
 @echo building $@
 ${CC} ${CFLAGS} -c $<

clean:
 rm -f *.o app