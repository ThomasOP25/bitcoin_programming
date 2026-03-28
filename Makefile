key_gen: key_gen.c
	gcc -Wall -Werror key_gen.c -o key_gen

clean:
	rm -f key_gen
