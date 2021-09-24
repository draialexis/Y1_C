//
// Created by draia on 11/02/2021.
//

#ifndef TP4BONUS_STRINGY_H
#define TP4BONUS_STRINGY_H

int strlen_y(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

int strcmp_y(const char *lhs, const char *rhs) {
    int i = 0;
    while (rhs[i] != '\0' && lhs[i] != '\0') {
        if (lhs[i] != rhs[i]) {
            return (lhs[i] - rhs[i]) > 0 ? 1 : -1;
        }
        ++i;
    }
    return 0;
}

char *strcpy_y(char *restrict dest, const char *restrict src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = src[i]; //copies the '\0'
    return dest;
}

char *strcat_y(char *restrict dest, const char *restrict src) {
    int i = 0;
    while (dest[i] != '\0') {
        ++i;
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        ++i;
        ++j;
    }
    return dest;
}

#endif //TP4BONUS_STRINGY_H
