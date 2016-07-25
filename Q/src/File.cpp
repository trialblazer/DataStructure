#include "File.h"

#include <stdio.h>

File::File() {
    if ((fp=fopen("Mess.txt", "rb")) == NULL) {
		fp = fopen("Mess.txt", "wb");
		fclose(fp);
	}
}










