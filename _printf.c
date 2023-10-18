#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...) {
    int i = 0, printed_chars = 0, flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (!format)
        return -1;

    va_start(list, format);

    while (format[i]) {
        if (format[i] != '%') {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        } else {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            i++;
            printed_chars += handle_print(format, &i, list, buffer, flags, width, precision, size);
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind) {
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);
    *buff_ind = 0;
}
