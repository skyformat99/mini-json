#ifndef MINI_JSON_H
#define MINI_JSON_H

typedef struct mj_writer {
	char *buffer;
	int buffer_len, sp, ep, depth;
} mj_writer_t;

typedef enum mj_status {
	MJ_OK 			= 0,
	MJ_NOMEM 		= -1,
	MJ_STATE 		= -2,
	MJ_UNSUPPORTED	= -3
} mj_status_t;

void mj_writer_init(mj_writer_t *w, char *buffer, int len);
mj_status_t mj_writer_start_array(mj_writer_t *w);
mj_status_t mj_writer_start_object(mj_writer_t *w);
mj_status_t mj_writer_end(mj_writer_t *w);
mj_status_t mj_writer_put_key(mj_writer_t *w, const char *key);
mj_status_t mj_writer_put_bool(mj_writer_t *w, int val);
mj_status_t mj_writer_put_string(mj_writer_t *w, const char *str);
mj_status_t mj_writer_put_null(mj_writer_t *w);
mj_status_t mj_writer_put_int(mj_writer_t *w, int val);
mj_status_t mj_writer_put_float(mj_writer_t *w, float val);
mj_status_t mj_writer_put_double(mj_writer_t *w, double val);

#endif