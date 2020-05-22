#include "mini-json.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	mj_writer_t w;
	char buffer[512];

	mj_writer_init(&w, buffer, 512);
	
	mj_writer_start_array(&w);
		mj_writer_put_string(&w, "awe\r\nsome");
		mj_writer_put_bool(&w, 0);
		mj_writer_start_object(&w);
			mj_writer_put_key(&w, "fo\"o");
			mj_writer_put_string(&w, "bar");
			mj_writer_put_key(&w, "bleem");
			mj_writer_put_bool(&w, 0);
			mj_writer_put_key(&w, "quux");
			mj_writer_put_null(&w);
			mj_writer_put_key(&w, "empty");
			mj_writer_start_array(&w);
			mj_writer_end(&w);
			mj_writer_put_key(&w, "float");
			mj_writer_put_float(&w, 123.23);
			mj_writer_put_key(&w, "double");
			mj_writer_put_double(&w, -14.0000232);
		mj_writer_end(&w);
		mj_writer_put_int(&w, 1234211);
		mj_writer_put_int(&w, -456);
		mj_writer_put_null(&w);
		mj_writer_put_bool(&w, 1);
		mj_writer_put_bool(&w, 0);
	mj_writer_end(&w);
	
	mj_writer_end(&w);

	puts("Here's your JSON:");
	puts(buffer);

	return 0;
}