#include "library/lib_for_str.h"
#include "file_read.h"


int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Number of arguments must be 3 (program name, file_in, file_out)");
        return -1;
    }

    char *file_read = argv[1];
    char *file_write = argv[2];

    // if you want to see more testing of functionality
    // testing_functions(file_read, file_write);

    my_str_t str;
    my_str_create(&str, 256);

    const char *str_c = "We did it... ";
    my_str_from_cstr(&str, str_c);

    my_str_resize(&str, 18, 'a');
    printf("Resizing string adding char 'a': %s\n", str.data);

    char to[]="blablalbla";
    my_str_substr_cstr(&str, to, 0, 6);
    printf("Copying [0:6) elements from previous string: %s\n", to);

    const char *str1_c = "Hooray... ";
    my_str_insert_cstr(&str, str1_c, 0);
    printf("Inserting C string to the previous string: %s\n\n", str.data);
    my_str_free(&str);

    my_str_t new_str;
    my_str_create(&new_str, 7);
    const char *line1 = "student";
    my_str_from_cstr(&new_str, line1);
    printf("Testing reserve function. String: %s, ", new_str.data);
    printf("buffer - %d\n", my_str_capacity(&new_str));
    my_str_reserve(&new_str, 10);
    printf("buffer after reserve - %d ", my_str_capacity(&new_str));
    printf("String: %s\n\n", new_str.data);
    my_str_free(&new_str);

    // ------------------------------- pushback ---------------------------------------------
    printf("Testing pushback function...\n");
    my_str_t str2;
    my_str_create(&str2, 7);

    const char *word = "Student";
    my_str_from_cstr(&str2, word);

    printf("Created string: %s\n", str2.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str2), my_str_capacity(&str2));

    printf("Added a symbol to the end: ");
    my_str_pushback(&str2, 's');
    printf("%s\n", str2.data);
    printf("Size - %d, Buffer - %d\n\n", my_str_size(&str2), my_str_capacity(&str2));
    my_str_free(&str2);

    // ------------------------------insert_c function----------------------------------------
    printf("Testing insert_c function...\n");
    my_str_t str3;
    my_str_create(&str3, 4);

    const char *word2 = "Mow!";
    my_str_from_cstr(&str3, word2);

    printf("Created string: %s\n", str3.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str3), my_str_capacity(&str3));
    printf("Insert a symbol on the position 1: ");
    my_str_insert_c(&str3, 'e', 1);
    printf("%s\n", str3.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str3), my_str_capacity(&str3));

    //----------------------------------------------------------------------------------------
    printf("Testing shrink_to_fit function...");
    my_str_shrink_to_fit(&str3);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str3), my_str_capacity(&str3));
    printf("%s\n", str3.data);
    my_str_free(&str3);

    my_str_t reading;
    my_str_create(&reading, 7);
    FILE *file = fopen(file_read, "r");
    if (file == NULL) {
        printf("\nEmpty file to read str! \n");
        return -1;
    }
    my_str_read_file_delim(&reading, file, '"');
    printf("Read from file until '': %s", reading.data);


    printf("Created by Sofiya, Oksana, Yarka, Anastasia.\nWith love <3.");



    return 0;
}
