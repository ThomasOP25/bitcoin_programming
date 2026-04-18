#include <stdio.h>
#include <stdint.h>
#include "bitfuncts.h"

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
