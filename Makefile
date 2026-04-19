key_gen: src/key_gen.c src/bitfuncts.c
	gcc -o seckey_gen src/seckey_gen.c src/bitfuncts.c

clean:
	rm -rf seckey_gen sec_key.bin
