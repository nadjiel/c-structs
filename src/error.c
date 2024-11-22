#include "error.h"

const char* get_error_msg(int error) {
    switch(error) {
        case SUCCESS: return "SUCCESS";
        case ERR_NULL_POINTER: return "ERR_NULL_POINTER";
        case ERR_OUT_OF_BOUNDS: return "ERR_OUT_OF_BOUNDS";
        case ERR_INVALID_OPERATION: return "ERR_INVALID_OPERATION";
        default: return "ERR_UNKNOWM";
    }
}
