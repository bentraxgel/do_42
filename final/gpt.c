#include <stdio.h>
#include <string.h>

int main() {
    char original_string[] = "Hello, World!";
    char remaining_string[100];
    
    int print_length = strlen(original_string) - 6;
    strncpy(remaining_string, original_string + print_length, 100);
    
    printf("fir : %.*s\n", print_length, original_string);
    printf("sec : %s\n", remaining_string);
    
    return 0;
}
