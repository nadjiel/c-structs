#ifndef ERROR_H
#define ERROR_H

#define SUCCESS 0
#define ERR_NULL_POINTER 1
#define ERR_OUT_OF_BOUNDS 2
#define ERR_INVALID_OPERATION 3

const char* get_error_msg(int error);

#endif
