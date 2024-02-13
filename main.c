#include  <stdio.h>
#include "OffFile/OffFile.h"

int main(void) {
	OffFile* valid_off_file = read_off_file("teapot.off");

	
	free_off_file(valid_off_file);
	return 0;
}
