#include "library/lib_for_str.h"
#include "file_read.h"

int static compare(char c);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Number of arguments must be 3 (program name, file_in, file_out)");
        return -1;
    }

    char *file_read = argv[1];
    char *file_write = argv[2];

    printf("Program starts!\n");

    my_str_t str;
    printf("Creating a string with buffer size 3...\n");
    my_str_create(&str, 3);

    printf("Creating a C string: ");
    const char *line = "girls";
    printf("%s\n", line);

    printf("Recreating string from C string with buffer 6...\n");
    my_str_from_cstr(&str, line);
    printf("Created string: %s\n", str.data);

    printf("Size of the string is %d, size of the buffer is %d, it is empty: ", my_str_size(&str), my_str_capacity(&str));
    if (my_str_empty(&str)) {
        printf("yes.\n");
    } else {
        printf("no\n");
    }

    my_str_clear(&str);
    printf("Clearing string...\nSize of the string is %d and size of the buffer is %d.\n", my_str_size(&str), my_str_capacity(&str));
    my_str_free(&str);
    printf("Freeing string...\nSize of the string is %d and size of the buffer is %d.\n\n", my_str_size(&str),my_str_capacity(&str));

    printf("Creating a new string...\n");
    my_str_t str2;
    my_str_create(&str2, 128);
    const char *str2_c = "R love POK";
    my_str_from_cstr(&str2, str2_c);
    printf("Created string: %s\n", str2.data);

    printf("Getting char at the position 3 is %c.\n", (char) my_str_getc(&str2, (size_t) 3));
    printf("First symbol: %c \n", my_str_getc(&str2, 0));

    printf("Putting char 'I' at the position 0.\n");
    my_str_putc(&str2, 0, 'I');
    printf("Modified string: %s\n", str2.data);

    printf("Popping last element from string...\n");
    my_str_popback(&str2);
    printf("Modified string: %s\n", str2.data);

    printf("Pushing 'K' to the end of the string...\n");
    my_str_pushback(&str2, 'K');
    printf("Modified string: %s\n", str2.data);

    my_str_t str3;
    my_str_create(&str3, 30);
    const char *str3_c = "I do not love POK";
    my_str_from_cstr(&str3, str3_c);

    printf("Copying string with saving buffer size of the copied string...\n");
    printf("String to which str2 will be copied: %s\n", str3.data);
    my_str_copy(&str2, &str3, 1);
    printf("String to which str2 was copied: %s\n\n", str3.data);

    printf("Appending string to the end of another string...\n");
    my_str_t str4;
    my_str_create(&str4, 3);
    const char *str4_c = "I am a BA girl. ";
    my_str_from_cstr(&str4, str4_c);

    my_str_append(&str4, &str3);
    printf("String to which str3 was appended: %s\n", str4.data);

    printf("Appending C string to the end of another string...\n");
    const char *str5_c = " very-very-very much";
    printf("%s| %s ljl\n", str4.data, str5_c);
    my_str_append_cstr(&str4, str5_c);
    printf("String to which str3 was appended: %s\n", str4.data);
    const char *str6_c = my_str_get_cstr(&str4);
    printf("Getting equal c string: %s\n\n", str6_c);

    printf("Number of element 'A' in string: '%s' is %d\n", str4.data, my_str_find_c(&str4, 'A', (size_t) 1));

    my_str_t str6;
    my_str_create(&str6, 10);
    const char *test_line = "BAgirls";
    my_str_from_cstr(&str6, test_line);

    printf("Number of element 'A' in string '%s': %d\n\n", str6.data, my_str_find_if(&str6, &compare));

    my_str_t str7;
    my_str_create(&str7, 3);
    my_str_from_cstr(&str7, "BA");
    printf("Index of the first substring 'BA' in %s: %d\n", str6.data, my_str_find(&str6, &str7, 0));

    my_str_t str8;
    my_str_create(&str8, 10);

    my_str_substr(&str7, &str8, 0, 2);
    printf("Substring of the string 'BAgirls' from 0 to 2 is %s.\n", str8.data);

    my_str_t str9;
    my_str_create(&str9, 1024);
    printf("Enter some text for my_str_read function: ");
    my_str_read(&str9);
    printf("Your input was %s\n", str9.data);

    my_str_t str10;
    my_str_create(&str10, 1024);
    FILE *file_read1 = fopen("../test_read_file.txt", "r");
    my_str_read_file(&str10, file_read1);
    printf("String in file was: %s\n", str10.data);

    my_str_t str13;
    my_str_create(&str13, 1024);
    const char str13_c[128] = "BA girl";
    my_str_from_cstr(&str13, str13_c);

    printf("Strings %s and %s are equal: %d.\n\n", str13.data, str13_c, my_str_cmp(&str13, str13_c));
    printf("Inserted 's' into the position 16 in string '%s': ", str13.data);
    my_str_insert_c(&str13, 's', 16);
    printf("%s\n", str13.data);

    printf("Inserted ' are here' into the position -5 in string '%s': ", str13.data);
    my_str_t str14;
    my_str_create(&str14, 1024);
    const char *str14_c = " are here";
    my_str_from_cstr(&str14, str14_c);

    my_str_insert(&str13, &str14, (size_t)-5);
    printf("%s\n", str13.data);

    printf("Inserted C string 'trying to study POK' in into the position 13 in string '%s': ", str13.data);
    my_str_insert_cstr(&str13, "trying to study POK ", 13);
    printf("%s\n", str13.data);

    printf("Now run function that uses our library.\n");
    read_write(file_read, file_write);

    my_str_free(&str2);
    my_str_free(&str3);
    my_str_free(&str4);
    my_str_free(&str6);
    my_str_free(&str7);
    my_str_free(&str8);
    my_str_free(&str9);
    my_str_free(&str10);
    my_str_free(&str13);

    my_str_t str20;
    my_str_create(&str20, 256);
    const char *str20_c = "We did it... ";
    my_str_from_cstr(&str20, str20_c);
    my_str_resize(&str20, 18, 'a');
    printf("Resizing string adding char 'a': %s\n", str20.data);
    char to[]="blablalbla";
    my_str_substr_cstr(&str20, to, 0, 6);
    printf("Copying [0:6) elements from previous string: %s\n", to);

    const char *str21_c = "Hooray... ";
    my_str_insert_cstr(&str20, str21_c, 0);
    printf("Inserting C string to the previous string: %s\n", str20.data);


    my_str_t new_str;
    my_str_create(&new_str, 7);
    const char *line1 = "student";
    my_str_from_cstr(&new_str, line1);
    printf("Testing reserve function. String: %s, ", new_str.data);
    printf("buffer - %d\n", my_str_capacity(&new_str));
    my_str_reserve(&new_str, 10);
    printf("buffer after reserve - %d ", my_str_capacity(&new_str));
    printf("String: %s\n", new_str.data);

    // TODO: але якщо минулі тести в інший файл кидати будемо то str22 і str23 можна і перейменувати норм
    // а так то тести до тих двох ф-цій готові :-)
    // ------------------------------- pushback ---------------------------------------------
    printf("Testing pushback function...\n");
    my_str_t str22;
    my_str_create(&str22, 7);

    const char *word = "Student";
    my_str_from_cstr(&str22, word);

    printf("Created string: %s\n", str22.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str22), my_str_capacity(&str22));

    printf("Added a symbol to the end: ");
    my_str_pushback(&str22, 's');
    printf("%s\n", str22.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str22), my_str_capacity(&str22));
    printf("\n");
    //----------------------------------------------------------------------------------------


    // ------------------------------insert_c function----------------------------------------
    printf("Testing insert_c function...\n");
    my_str_t str23;
    my_str_create(&str23, 4);

    const char *word2 = "Mow!";
    my_str_from_cstr(&str23, word2);

    printf("Created string: %s\n", str23.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str23), my_str_capacity(&str23));
    printf("Insert a symbol on the position 1: ");
    my_str_insert_c(&str23, 'e', 1);
    printf("%s\n", str23.data);
    printf("Size - %d, Buffer - %d\n", my_str_size(&str23), my_str_capacity(&str23));
    //----------------------------------------------------------------------------------------



    printf("Created by Sofiya, Oksana, Yarka, Anastasia.\nWith love <3.");



    return 0;
}

int static compare(char c) {
    return c == 'A';
}
