key_gen: src/key_gen.c src/bitfuncts.c
	gcc -o key_gen src/key_gen.c src/bitfuncts.c

clean:
	rm -rf key_gen sec_key.bin
