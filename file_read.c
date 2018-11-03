//
// Created by yarka on 10/23/18.
//

#include "library/lib_for_str.h"

int read_write(const char *file_read, const char *file_write) {


    FILE *file = fopen(file_read, "r");

    if (file == NULL) {
        printf("Empty file");
        return -1;
    }
    my_str_t str;
    my_str_create(&str, 1024);

    FILE *result = fopen(file_write, "a");
    while (my_str_read_word(&str, file) != -1) {
        my_str_sort(&str);
        fwrite(my_str_get_cstr(&str), my_str_size(&str), 1, result);
        fwrite(" ", 1, 1, result);
        my_str_clear(&str);
    }

    fclose(file);
    fclose(result);


    return 0;
}
