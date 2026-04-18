#include <sys/random.h>
#include <stdio.h>
#include <stdint.h>
#include "bitfuncts.h"
        	
int main() {
	uint8_t buffer[32];
	
	// Use system entropy to generate a random 256 bit
	// buffer
	// The buffer is split into 32 decimal numbers whose
	// values range from 0 to 255
	getentropy(buffer, 32);

	// Write the private key to a binary file
	FILE *fp = NULL;
	fp = fopen("sec_key.bin", "wb");
	// Parameters: (pointer to data, size of 1 element, number of elements, file pointer)
	size_t written = fwrite(buffer, sizeof(uint8_t), 32, fp);
	if (written != 32) {
		fprintf(stderr, "Error: Wrote %zu bytes instead of 32 bytes.\n", written);
		return 1;
	}
	
	// Represent the private key in decimal
	printf("Private key (decimal): ");
	for (int i = 0; i < 31; i++) {
		printf("%d-", buffer[i]);
	}
	printf("%d\n", buffer[31]);

	// Represent the private key in binary
	printf("Private key (binary): ");
	for (int i = 0; i < 31; i++) {
		print_bits(buffer[i]);
		printf("-");
	}
	print_bits(buffer[31]);
	printf("\n");

	// Represent the private key in hexadecimal
	printf("Private key (hexadecimal): 0x");
	for (int i = 0; i < 32; i++) {
		printf("%hx", buffer[i]);
	}
	printf("\n");
}
