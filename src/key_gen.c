#include <sys/random.h>
#include <stdio.h>
#include <stdint.h>

void binary_to_decimal(uint8_t val, int arr[]) {
	// Traverse all 8 binary values of the integer

        // The first four bits sum to the first hexadecimal value,
        // and the last four bits sum to the second
        // hexadecimal value
        int first_hex = 0;
        int second_hex = 0;

        for (int i = 7; i >= 0; i--) {
        	uint8_t mask = 1 << i;

                if (mask & val) {
                	if (i == 7) {
                        	first_hex += 8;
                        }
                        else if (i == 6) {
                                first_hex += 4;
                        }
                        else if (i == 5) {
                                first_hex += 2;
                        }
                        else if (i == 4) {
                                first_hex += 1;
                        }
                        else if (i == 3) {
                                second_hex += 8;
                        }
                        else if (i == 2) {
                                second_hex += 4;
                        }
                        else if (i == 1) {
                                second_hex += 2;
                        }
                        else if (i == 0) {
                                second_hex += 1;
                        }
                }
	}
	arr[0] = first_hex;
	arr[1] = second_hex;
}

char decimal_to_hexadecimal(int hex) {
	// Use only on values 0-15
	char hex_c;

        if (0 <= hex && hex < 10) {
        	hex_c = (char)(hex + '0');
        }
        else if (hex == 10) {
                hex_c = 'a';
        }
        else if (hex == 11) {
                hex_c = 'b';
        }
        else if (hex == 12) {
                hex_c = 'c';
	}
	else if (hex == 13) {
		hex_c = 'd';
	}
	else if (hex == 14) {
		hex_c = 'e';
	}
	else if (hex == 15) {
		hex_c = 'f';
	}
	return hex_c;
}

void print_bits(uint8_t value) {
	int bits = sizeof(value) * 8;
	
	for (int i = bits - 1; i >= 0; i--) {
		uint8_t mask = 1 << i;

		if (mask & value) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
}

int main() {
	uint8_t decimal_buffer[32];
	
	// Use system entropy to generate a random 256 bit
	// buffer
	// The buffer is split into 32 decimal numbers whose
	// values range from 0 to 255
	getentropy(decimal_buffer, 32);
	
	// Represent the private key in decimal
	printf("Private key (decimal): ");
	for (int i = 0; i < 31; i++) {
		printf("%d-", decimal_buffer[i]);
	}
	printf("%d\n", decimal_buffer[31]);

	// Represent the private key in binary
	printf("Private key (binary): ");
	for (int i = 0; i < 31; i++) {
		print_bits(decimal_buffer[i]);
		printf("-");
	}
	print_bits(decimal_buffer[31]);
	printf("\n");

	// Represent the private key in hexadecimal
	printf("Private key (hexadecimal): ");
	for (int i = 0; i < 32; i++) {
		int hex_arr[2];

		binary_to_decimal(decimal_buffer[i], hex_arr);
		for (int j = 0; j < 2; j++) {
			char hex_c = decimal_to_hexadecimal(hex_arr[j]);
			printf("%c", hex_c);
		}
	}
	printf("\n");
}
