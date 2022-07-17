#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

//  PART 1

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; *(str + len); len++) {
  }
  return len;
}

int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return (*str1 - *str2);
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;  // отработка 0
  if (n != 0) {
    while (n-- && *str1 == *str2) {
      if (n == 0) break;
      str1++;
      str2++;
    }
    res = *str1 - *str2;
  }
  return (res);
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  do {
    dest[i] = src[i];
  } while (src[i++]);
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && *(src + i) != '\0'; i++) {
    *(dest + i) = *(src + i);
  }
  *(dest + i) = '\0';
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  if (dest == s21_NULL) return s21_NULL;
  s21_size_t i;
  for (i = 0; dest[i] != '\0'; i++) {
  }
  do {
    dest[i] = *src++;
  } while (dest[i++]);
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;  // перемещение указателя
  s21_size_t j = 0;  // перемещение указателя
  for (; *(dest + i); i++) {
  }
  for (; *(src + j); j++) {
    if (j == n) break;
    *(dest + i + j) = *(src + j);
  }
  *(dest + i + j + 1) = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  if ((char)c != '\0') {
    for (s21_size_t i = 0; *(str + i); i++) {
      if (*(str + i) == (char)c) {
        res = (char *)(str + i);
        break;
      }
    }
  } else {
    res = "\0";
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t i;
  int len = s21_strlen(str);
  for (i = len; str[i] != (char)c; i--) {
    if (i == 0) return s21_NULL;
  }
  return (char *)str + i;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;  // отработка 0
  if (n != 0) {
    while (--n > 0 && *(char *)str1 == *(char *)str2) {
      str1 = (char *)str1 + 1;
      str2 = (char *)str2 + 1;
    }
    res = (*((unsigned char *)str1) - *((unsigned char *)str2));
  }
  return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  if ((char)c != '\0') {
    while (n-- && *(char *)str) {
      if (*(unsigned char *)str == (char)c) {
        res = (char *)str;
        break;
      }
      str = (char *)str + 1;
    }
  } else {
    res = "\0";
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_tmp = dest;
  const char *src_tmp = src;
  while (n > 0) {
    *dest_tmp++ = *src_tmp++;
    n--;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *dest_tmp = dest;
  const char *src_tmp = src;
  if ((dest_tmp >= src_tmp) && (dest_tmp <= (src_tmp + n))) {
    for (s21_size_t i = 0; i < n; i++) {
      *(dest_tmp + i) = *(src_tmp + i);
    }
  } else {
    for (s21_size_t i = n - 1; i > 0; i--) {
      *(dest_tmp + i) = *(src_tmp + i);
    }
    *(dest_tmp) = *(src_tmp);
  }
  return dest_tmp;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *res = str;
  for (s21_size_t i = 0; i < n; i++) {
    *(res + i) = (char)c;
  }
  return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  while (*str1++) {
    len++;
  }
  str1 = str1 - len - 1;
  for (s21_size_t i = 0; *(str1 + i) != '\0'; i++) {
    for (s21_size_t j = 0; *(str2 + j) != '\0'; j++) {
      if (*(str1 + i) == *(str2 + j) && len > i) {
        len = i;
      }
    }
  }
  return len;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  for (s21_size_t i = 0; *(str1 + i) != '\0'; i++) {
    int flag = 0;
    for (s21_size_t j = 0; *(str2 + j) != '\0'; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        len++;
        flag = 1;
        break;
      }
    }
    if (flag == 0) break;
  }
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  for (s21_size_t i = 0; *(str1 + i) != '\0'; i++) {
    for (s21_size_t j = 0; *(str2 + j) != '\0'; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        res = (char *)(str1 + i);
      }
    }
    if (res != s21_NULL) break;
  }
  return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t lenght1, lenght2;
  char *res = s21_NULL;
  lenght1 = s21_strlen(haystack);
  lenght2 = s21_strlen(needle);
  if (lenght2 == 0) return (char *)haystack;
  while (lenght1 >= lenght2) {
    if (s21_memcmp(haystack, needle, lenght2) == 0) {
      res = (char *)haystack;
      break;
    }
    haystack++;
    lenght1--;
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *str_tmp = s21_NULL;
  char *tok = s21_NULL;
  int flag = 1;
  if (str == s21_NULL) {
    if (str_tmp == s21_NULL) {
      flag = 0;
    }
  } else {
    str_tmp = str;
  }
  if (flag) {
    while (*str_tmp) {
      s21_size_t i;
      for (i = 0; (*(delim + i) != '\0') && (*str_tmp != *(delim + i)); i++) {
      }
      if (*(delim + i) == '\0') break;
      str_tmp++;
    }
    if (*str_tmp == '\0') {
      str_tmp = s21_NULL;
      flag = 0;
    }
    if (flag) {
      tok = str_tmp;
      for (s21_size_t i = 0; *str_tmp; str_tmp++) {
        for (i = 0; (*(delim + i) != '\0') && (*str_tmp != *(delim + i)); i++) {
        }
        if (*(delim + i) != '\0') break;
      }
      if (*str_tmp != '\0') {
        *str_tmp = '\0';
        str_tmp++;
      }
    }
  }
  return tok;
}

char *s21_strerror(int errnum) {
  const char *strerr[] = STRERR;
  return (char *)strerr[errnum];
}

// PART 3

void *s21_to_upper(const char *str) {
  s21_size_t length = s21_strlen(str);
  char *result = calloc(length + 1, sizeof(char));
  if (result != s21_NULL) {
    char *p = result;
    for (s21_size_t i = 0; i < length; i++) {
      if (*str >= 'a' && *str <= 'z') {
        *p = *str - 32;
      } else {
        *p = *str;
      }
      p++;
      str++;
    }
    *p = '\0';
  }
  return result;
}

void *s21_to_lower(const char *str) {
  s21_size_t length = s21_strlen(str);
  char *result = calloc(length + 1, sizeof(char));
  if (result != s21_NULL) {
    char *p = result;
    for (s21_size_t i = 0; i < length; i++) {
      if (*str >= 'A' && *str <= 'Z') {
        *p = *str + 32;
      } else {
        *p = *str;
      }
      p++;
      str++;
    }
    *p = '\0';
  }
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (start_index > s21_strlen(src)) return s21_NULL;
  char *res = s21_NULL;
  res = calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char));
  if (res == s21_NULL) return s21_NULL;
  res = s21_strncat(res, src, start_index);
  res[start_index + 1] = '\0';
  res = s21_strcat(res, str);
  res = s21_strcat(res, (src + start_index));
  return (void *)res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) return s21_NULL;
  // удаляем перед строкой:
  int len = s21_strlen(src);
  int len2 = s21_strlen(trim_chars);
  char *z = s21_NULL;
  char *res = calloc(len + 1, sizeof(char));
  if (res != s21_NULL) {
    int i = 0;
    int flag = 0;
    int k = 0;
    while (src[i] != '\0') {
      while (trim_chars[k] != '\0') {
        if (src[i] != trim_chars[k]) {
          k++;
          flag++;
        } else {
          i++;
          k = 0;
          flag = 0;
        }
      }
      if (flag == len2) {
        break;
      }
    }
    int j = 0;
    for (j = 0; j < len; j++) {
      res[j] = src[j + i];
    }
    res[j] = '\0';
    len = s21_strlen(res);
    // удаляем после строки:
    i = len - 1;
    flag = 0;
    k = 0;
    while (i > 0) {
      while (trim_chars[k] != '\0') {
        if (res[i] != trim_chars[k]) {
          k++;
          flag++;
        } else {
          flag = 0;
          i--;
        }
      }
      if (flag == len2) {
        break;
      }
      k = 0;
      flag = 0;
    }
    res[i + 1] = '\0';
    z = res;
  }
  return z;
}

// PART 2 - SPRINTF

int s21_sprintf(char *str, const char *format, ...) {
  unsigned int format_position = 0;
  int str_position = 0;
  va_list next_arg;
  va_start(next_arg, format);
  while (format_position <= s21_strlen(format)) {
    if (format[format_position] == 37) {
      int width_marker = 0;  // если 1, ширина считана
      int exact_marker = 0;  // если 1, точность считана
      char spec_result[10000] = "\0";
      int flag_plus = 0;
      int flag_minus = 0;
      int flag_space = 0;
      int flag_grid = 0;
      int flag_zero = 0;
      int flag_width = 0;
      int width_num = 0;
      int flag_exact = 0;
      int exact_num = 0;
      int flag_length = 0;
      int num_int_arg = 0;                      // для типов d, i
      long int num_long_int_arg = 0;            // long для типов d, i
      unsigned long long int num_lint_arg = 0;  // для типа u, o, x, X
      double num_doub_arg = 0.0;  // double для типов e, E, f, g, G
      long double num_long_doub_arg = 0.0;  // long для типов e, E, f, g, G
      char char_arg = '\0';  // для аргумента типа c
      char *str_arg = 0;     // для аргумента типа s
      int start = 1;
      while (start) {
        start = 0;
        start = 1;
        format_position++;
        if (format[format_position] == 101) {  // спецификатор e
          if (flag_length == 3) {
            num_long_doub_arg = va_arg(next_arg, long double);
            num_doub_arg = 0.0;
          } else {
            num_doub_arg = va_arg(next_arg, double);
            num_long_doub_arg = 0.0;
          }
          if (isnan(num_long_doub_arg) == 1 || isnan(num_doub_arg) == 1) {
            spec_result[0] = 'n';
            spec_result[1] = 'a';
            spec_result[2] = 'n';
            spec_result[3] = '\0';
          } else {
            specif_e(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
                     flag_width, width_num, flag_exact, exact_num, flag_length,
                     num_doub_arg, num_long_doub_arg, 'e', spec_result);
          }
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 69) {  // спецификатор E
          if (flag_length == 3) {
            num_long_doub_arg = va_arg(next_arg, long double);
            num_doub_arg = 0.0;
          } else {
            num_doub_arg = va_arg(next_arg, double);
            num_long_doub_arg = 0.0;
          }
          if (isnan(num_long_doub_arg) == 1 || isnan(num_doub_arg) == 1) {
            spec_result[0] = 'N';
            spec_result[1] = 'A';
            spec_result[2] = 'N';
            spec_result[3] = '\0';
          } else {
            specif_e(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
                     flag_width, width_num, flag_exact, exact_num, flag_length,
                     num_doub_arg, num_long_doub_arg, 'E', spec_result);
          }
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 102) {  // спецификатор f
          if (flag_length == 3) {
            num_long_doub_arg = va_arg(next_arg, long double);
            num_doub_arg = 0.0;
          } else {
            num_doub_arg = va_arg(next_arg, double);
            num_long_doub_arg = 0.0;
          }
          specif_f(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
                   flag_width, width_num, flag_exact, exact_num, flag_length,
                   num_doub_arg, num_long_doub_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 103) {  // спецификатор g
          if (flag_length == 3) {
            num_long_doub_arg = va_arg(next_arg, long double);
            num_doub_arg = 0.0;
          } else {
            num_doub_arg = va_arg(next_arg, double);
            num_long_doub_arg = 0.0;
          }
          if (isnan(num_long_doub_arg) == 1 || isnan(num_doub_arg) == 1) {
            spec_result[0] = 'N';
            spec_result[1] = 'A';
            spec_result[2] = 'N';
            spec_result[3] = '\0';
          } else {
            specif_g(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
                     flag_width, width_num, flag_exact, exact_num, flag_length,
                     num_doub_arg, num_long_doub_arg, 'g', spec_result);
          }
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 71) {  // спецификатор G
          if (flag_length == 3) {
            num_long_doub_arg = va_arg(next_arg, long double);
            num_doub_arg = 0.0;
          } else {
            num_doub_arg = va_arg(next_arg, double);
            num_long_doub_arg = 0.0;
          }
          if (isnan(num_long_doub_arg) == 1 || isnan(num_doub_arg) == 1) {
            spec_result[0] = 'N';
            spec_result[1] = 'A';
            spec_result[2] = 'N';
            spec_result[3] = '\0';
          } else {
            specif_g(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
                     flag_width, width_num, flag_exact, exact_num, flag_length,
                     num_doub_arg, num_long_doub_arg, 'G', spec_result);
          }
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 100) {  // спецификатор d
          if (flag_length == 2) {
            num_long_int_arg = va_arg(next_arg, long int);
            num_int_arg = 0;
          } else {
            num_int_arg = va_arg(next_arg, int);
            num_long_int_arg = 0;
          }
          specif_d(flag_plus, flag_minus, flag_space, flag_zero, flag_width,
                   width_num, flag_exact, exact_num, flag_length, num_int_arg,
                   num_long_int_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 105) {  // спецификатор i
          if (flag_length == 2) {
            num_long_int_arg = va_arg(next_arg, long int);
            num_int_arg = 0;
          } else {
            num_int_arg = va_arg(next_arg, int);
            num_long_int_arg = 0;
          }
          specif_d(flag_plus, flag_minus, flag_space, flag_zero, flag_width,
                   width_num, flag_exact, exact_num, flag_length, num_int_arg,
                   num_long_int_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 111) {  // спецификатор o
          num_lint_arg = va_arg(next_arg, unsigned long long int);
          specif_o(flag_minus, flag_grid, flag_zero, flag_width, width_num,
                   flag_exact, exact_num, flag_length, num_lint_arg,
                   spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 117) {  // спецификатор u
          num_lint_arg = va_arg(next_arg, unsigned long long);
          specif_u(flag_minus, flag_zero, flag_width, width_num, flag_exact,
                   exact_num, flag_length, num_lint_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 120) {  // спецификатор x
          num_lint_arg = va_arg(next_arg, unsigned long long int);
          specif_x(flag_minus, flag_grid, flag_zero, flag_width, width_num,
                   flag_exact, exact_num, flag_length, num_lint_arg,
                   spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 88) {  // спецификатор X
          num_lint_arg = va_arg(next_arg, unsigned long long int);
          specif_X(flag_minus, flag_grid, flag_zero, flag_width, width_num,
                   flag_exact, exact_num, flag_length, num_lint_arg,
                   spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 99) {  // спецификатор c
          char_arg = va_arg(next_arg, int);
          str[str_position] = char_arg;
          str_position++;
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 115) {  // спецификатор s
          str_arg = va_arg(next_arg, char *);
          specif_s(flag_minus, flag_zero, flag_width, width_num, flag_exact,
                   exact_num, flag_length, str_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 112) {  // спецификатор p
          num_lint_arg = va_arg(next_arg, unsigned long long int);
          specif_p(flag_minus, flag_zero, flag_width, width_num, flag_exact,
                   exact_num, num_lint_arg, spec_result);
          s21_strcat(str, spec_result);
          str_position = s21_strlen(str);
          str[str_position] = '\0';
          format_position++;
          break;
        } else if (format[format_position] == 37) {  // спецификатор %
          str[str_position] = format[format_position];
          str_position++;
          format_position++;
          str[str_position] = '\0';
          break;
        } else if (format[format_position] == 110) {  // спецификатор n
          int *ptr = va_arg(next_arg, int *);
          *ptr = s21_strlen(str);
          format_position++;
          break;
        } else if (format[format_position] == 43) {  // есть флаг +
          flag_plus = 1;
        } else if (format[format_position] == 45) {  // есть флаг -
          flag_minus = 1;
        } else if (format[format_position] == 32) {  // есть флаг ' '
          flag_space = 1;
        } else if (format[format_position] == 35) {  // есть флаг #
          flag_grid = 1;
        } else if (format[format_position] == 48 && flag_zero == 0 &&
                   flag_width == 0 && flag_exact == 0) {  // есть флаг 0
          flag_zero = 1;
        } else if (format[format_position] == 46) {  // пошел параметр точность
          exact_marker = 1;
          flag_exact = 1;
        } else if (format[format_position] == 42 && exact_marker == 1) {
          exact_num = va_arg(next_arg, int);  // взяли точность из аргумента
          flag_exact = 1;
        } else if (format[format_position] > 47 &&
                   format[format_position] < 58 &&
                   exact_marker == 1) {  // точность цифрами
          exact_num = exact_num * 10 + (format[format_position] - 48);
          flag_exact = 1;
        } else if (format[format_position] == 42 && exact_marker == 0 &&
                   width_marker == 0) {
          width_num = va_arg(next_arg, int);  // взяли ширину из аргумента
          width_marker = 1;
          flag_width = 1;
        } else if (format[format_position] > 47 &&
                   format[format_position] < 58 && width_marker == 0 &&
                   exact_marker == 0) {  // ширина цифрами
          width_num = width_num * 10 + (format[format_position] - 48);
          flag_width = 1;
        } else if (format[format_position] == 104) {  // есть длина 1
          flag_length = 1;
        } else if (format[format_position] == 108) {  // есть длина 2
          flag_length = 2;
        } else if (format[format_position] == 76) {  // есть длина 3
          flag_length = 3;
        }
      }
    } else {
      str[str_position] = format[format_position];
      str_position++;
      format_position++;
      str[str_position] = '\0';
    }
  }
  if (str_position > 0) {
    str_position--;
  }
  va_end(next_arg);
  return str_position;
}

void *specif_d(int flag_plus, int flag_minus, int flag_space, int flag_zero,
               int flag_width, int width_num, int flag_exact, int exact_num,
               int flag_length, int num_int_arg, long int num_long_int_arg,
               char *spec_result) {
  char temp[20];
  int flag_otric = 0;
  if (flag_length == 2) {
    if (num_long_int_arg < 0) {
      flag_otric = 1;
      num_long_int_arg = -num_long_int_arg;
    }
    long_dec(num_long_int_arg, spec_result);
  } else if (flag_length == 1) {
    num_int_arg = (short)num_int_arg;
    if (num_int_arg < 0) {
      flag_otric = 1;
      num_int_arg = -num_int_arg;
    }
    dec(num_int_arg, spec_result);
  } else if (flag_length == 0) {
    if (num_int_arg < 0) {
      flag_otric = 1;
      num_int_arg = -num_int_arg;
    }
    dec(num_int_arg, spec_result);
  }
  int length = s21_strlen(spec_result);
  s21_strcpy(temp, spec_result);
  if (flag_width == 1 && flag_exact == 1 && exact_num >= length) {
    if (width_num > exact_num) {
      if (flag_minus) {
        if (flag_otric == 1 || flag_space == 1 || flag_plus == 1) {
          if (flag_space == 1) spec_result[0] = ' ';
          if (flag_plus == 1) spec_result[0] = '+';
          if (flag_otric == 1) spec_result[0] = '-';
          s21_memset(&spec_result[1], 48, (exact_num - length));
          s21_strncpy(&spec_result[exact_num - length + 1], temp, length);
          s21_memset(&spec_result[width_num - exact_num + 1], ' ',
                     width_num - exact_num - 1);
        } else {
          s21_memset(spec_result, 48, (exact_num - length));
          s21_strncpy(&spec_result[exact_num - length], temp, length);
          s21_memset(&spec_result[exact_num], ' ', width_num - exact_num);
        }
      } else {
        s21_memset(spec_result, ' ', (width_num - exact_num));
        s21_memset(&spec_result[width_num - exact_num], 48, exact_num - length);
        s21_strncpy(&spec_result[width_num - length], temp, length);
        if (flag_otric)
          spec_result[width_num - exact_num - 1] = '-';
        else if (flag_plus)
          spec_result[width_num - exact_num - 1] = '+';
      }
    } else {
      if (flag_plus) {
        if (flag_otric) {
          spec_result[0] = '-';
        } else {
          spec_result[0] = '+';
        }
        s21_memset(&spec_result[1], 48, (exact_num - length));
        s21_strcpy(&spec_result[exact_num - length + 1], temp);
      } else {
        s21_memset(spec_result, 48, (exact_num - length));
        s21_strncpy(&spec_result[exact_num - length], temp, length);
      }
    }
  } else if (flag_width == 1 && (flag_exact == 0 || exact_num < length) &&
             (width_num > length)) {
    s21_memset(spec_result, ' ', (width_num - length));
    s21_strcpy(&spec_result[width_num - length], temp);
    if (flag_otric)
      spec_result[width_num - length - 1] = '-';
    else if (flag_plus)
      spec_result[width_num - length - 1] = '+';
    if (flag_minus) {
      if (flag_otric == 1 || flag_plus == 1) {
        if (flag_plus) spec_result[0] = '+';
        if (flag_otric) spec_result[0] = '-';
        s21_strcpy(&spec_result[1], temp);
        s21_memset(&spec_result[length + 1], ' ', (width_num - length - 1));
      } else {
        s21_strcpy(spec_result, temp);
        s21_memset(&spec_result[length], ' ', (width_num - length));
      }
    }
    if (flag_zero == 1 && flag_minus == 0) {
      if (flag_otric) {
        spec_result[0] = '-';
        s21_memset(&spec_result[1], 48, (width_num - length - 1));
        s21_strcpy(&spec_result[width_num - length], temp);
      } else {
        s21_memset(spec_result, 48, (width_num - length));
        s21_strcpy(&spec_result[width_num - length], temp);
      }
    }
  } else if (flag_width == 0 && flag_exact == 1 && exact_num >= length) {
    if (flag_otric == 1 || flag_plus == 1) {
      if (flag_plus) spec_result[0] = '+';
      if (flag_otric) spec_result[0] = '-';
      s21_memset(&spec_result[1], 48, (exact_num - length + 1));
      s21_strcpy(&spec_result[exact_num - length + 1], temp);
    } else {
      s21_memset(spec_result, 48, (exact_num - length));
      s21_strcpy(&spec_result[exact_num - length], temp);
    }
  } else if (num_int_arg == 0 && flag_exact == 1 && exact_num == 0) {
    if (flag_plus)
      spec_result[0] = '+';
    else
      spec_result[0] = '\0';
  } else if (flag_space) {
    spec_result[0] = ' ';
    if (flag_plus) spec_result[0] = '+';
    if (flag_otric) spec_result[0] = '-';
    s21_strcpy(&spec_result[1], temp);
  } else {
    if (flag_otric == 1 || flag_plus == 1) {
      if (flag_plus) spec_result[0] = '+';
      if (flag_otric) spec_result[0] = '-';
      s21_strcpy(&spec_result[1], temp);
    }
  }
  return 0;
}

void *specif_e(int flag_plus, int flag_minus, int flag_space, int flag_grid,
               int flag_zero, int flag_width, int width_num, int flag_exact,
               int exact_num, int flag_length, double arg, long double long_arg,
               char letter, char *spec_result) {
  char even[2], even1[500], deg[500], sign[2], expon[500], extra_nul[2], lt[2];
  s21_memset(even, '\0', 2);
  s21_memset(even1, '\0', 500);
  s21_memset(deg, '\0', 500);
  s21_memset(expon, '\0', 500);
  lt[0] = letter;
  lt[1] = '\0';
  if (flag_length != 3) {
    long_arg = (long double)arg;
  }
  sign[1] = '\0';
  if (long_arg < 0) {
    sign[0] = '-';  // записываем знак минус
    long_arg = long_arg * (-1.0);
  } else {
    sign[0] = '+';  // записываем знак плюс
  }
  long long int a = (long long int)long_arg;  // целая часть поступившего числа
  long double b = long_arg - (long double)a;  // дробная часть поступвшего числа
  int i = 0, j = 0, m = 0, digits = 6, exp = 0, ev = 0;
  if (exact_num != 0) {
    digits = exact_num;
  }
  if (a > 0 && a < 10) {  // a =  целая часть мантиссы
    ev = (int)a;
  } else if (a > 9) {  // сдвигаем точку влево, экспонента +
    long long int d = a;
    while (d > 9) {
      d = d / 10;
      exp++;
    }
    ev = (int)d;
  } else if (a == 0) {  // сдвигаем точку вправо, экспонента -
    while (b < 1) {
      b = b * 10;
      exp--;
    }
    ev = (int)b;
    b = b - (long double)ev;
  }
  if (exp > 0) {  // часть дробной части мантиссы сидит в целом
    while (1) {
      if (a < 10) {
        break;
      } else {
        long long int a1 = a;
        a = a / 10;
        a1 = a1 - a * 10;
        even1[i] = a1 + 48;
        i++;
      }  // в этом блоке собрали целую часть (наоборот)
    }
    for (j = 0; j < i; j++) {
      deg[j] = even1[i - 1 - j];
    }  // и развернули ее
  }
  int d;
  int start = 1;
  while (start) {  // а сейчас добавим туда еще знаков после запятой
    start = 0;
    start = 1;
    b = b * 10.0;
    d = (int)b;
    b = b - (long double)d;
    if (m < (digits + 1)) {
      deg[j] = d + 48;
      j++;
      m++;
      deg[j] = '\0';
    } else {
      break;
    }
  }
  j = digits;
  d = deg[j] - 48;
  while (start) {
    start = 0;
    start = 1;
    j--;
    if (j < 0) {
      ev++;
      break;
    }
    if (d < 5) {
      break;
    } else if ((deg[j] - 48) < 9) {
      d = deg[j] - 48;
      deg[j] = d + 49;
      break;
    } else if ((deg[j] - 48) == 9) {
      d = deg[j] - 48;
      deg[j] = 48;
    }  // в этой части округлили результат по парамерту "ширина"
  }
  deg[digits] = '\0';
  if (flag_exact == 1 && exact_num == 0) {
    deg[0] = '\0';
  }
  if (ev < 10) {
    even[0] = ev + 48;
    even[1] = '\0';
    extra_nul[0] = '\0';
  } else {
    even[0] = ev / 10 + 48;
    even[1] = '\0';
    extra_nul[0] = '0';
    extra_nul[1] = '\0';
    deg[digits - 1] = '\0';
    exp++;
  }
  if (exp < 0) {
    expon[0] = '-';
    exp = exp * (-1);
  } else {
    expon[0] = '+';
  }
  j = 0;
  i = exp;
  while (i >= 1) {
    i = i / 10;
    j++;
  }
  if (j > 1) {
    expon[j + 1] = '\0';
    i = exp;
    for (int w = j; w > 0; w--) {
      expon[w] = i - (i / 10) * 10 + 48;
      i = i / 10;
    }
  }
  if (exp < 10) {
    expon[1] = '0';
    expon[2] = exp + 48;
    expon[3] = '\0';
  }
  char tem[500];
  s21_memset(tem, '\0', 500);
  s21_strcat(tem, even);
  if (flag_exact == 1 && exact_num == 0 && flag_grid == 0) {
  } else {
    s21_strcat(tem, ".");
    s21_strcat(tem, extra_nul);
    s21_strcat(tem, deg);
  }
  s21_strcat(tem, lt);
  s21_strcat(tem, expon);
  spec_result[0] = '\0';
  m = s21_strlen(tem);

  char space_l[500], space_s[500], null_l[500], null_s[500];
  if (width_num >
      (m + 1)) {  // здесь делаю заготовки с нулями и пробелами для строки
    s21_memset(space_l, ' ', width_num - m);
    space_l[width_num - m] = '\0';
    s21_memset(space_s, ' ', width_num - m - 1);
    space_s[width_num - m - 1] = '\0';
    s21_memset(null_l, '0', width_num - m);
    null_l[width_num - m] = '\0';
    s21_memset(null_s, '0', width_num - m - 1);
    null_s[width_num - m - 1] = '\0';
  }
  if ((sign[0] == '-' && width_num < (m + 2)) ||
      (sign[0] == '+' && width_num < (m + 2) &&
       flag_plus == 1)) {  // ширина меньше, рисуем знак
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num < (m + 2) && flag_plus == 0 &&
             flag_space == 1) {  // ширина меньше, рисуем пробел вместо  +
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num < (m + 1) && flag_plus == 0 &&
             flag_space == 0) {  // ширина меньше, без знака
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '-' && width_num > (m + 1) &&
             flag_minus == 1) {  // ширина больше слева минус
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '-' && width_num > (m + 1) && flag_minus == 0 &&
             flag_zero == 0) {  // ширина больше без нолей минус
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '-' && width_num > (m + 1) && flag_minus == 0 &&
             flag_zero == 1) {  // ширина больше с нулями минус
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 0 &&
             flag_space == 0) {  // ширина больше слева без знака плюс
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_l);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 0 &&
             flag_space == 1) {  // ширина больше слева без знака плюс, пробелы
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 1) {  // ширина больше слева со знаком +
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 &&
             flag_space == 1) {  // ширина больше слева с пробелом
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 &&
             flag_zero == 0) {  // ширина больше справа пробел без 0
    s21_strcat(spec_result, space_l);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 1 &&
             flag_zero == 0) {  // ширина больше справа плюс без 0
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 && flag_space == 1 &&
             flag_zero == 1) {  // ширина больше справа пробел c 0
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 && flag_space == 0 &&
             flag_zero == 1) {  // ширина больше справа без знака c 0
    s21_strcat(spec_result, null_l);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 1 &&
             flag_zero == 1) {  // ширина больше справа плюс с 0
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  }
  return 0;
}

void *specif_f(int flag_plus, int flag_minus, int flag_space, int flag_grid,
               int flag_zero, int flag_width, int width_num, int flag_exact,
               int exact_num, int flag_length, double arg, long double long_arg,
               char *spec_result) {
  char even[500], even1[500], deg[500], sign[2];
  s21_memset(even, '\0', 500);
  s21_memset(even1, '\0', 500);
  s21_memset(deg, '\0', 500);
  s21_memset(sign, '\0', 2);
  if (flag_length != 3) {
    long_arg = (long double)arg;
  }
  sign[1] = '\0';
  if (long_arg < 0) {
    sign[0] = '-';  // записываем знак минус
    long_arg = long_arg * (-1.0);
  } else {
    sign[0] = '+';  // записываем знак плюс
  }
  long long int a = (long long int)long_arg;
  long double b = long_arg - (long double)a;
  long long int a1;
  int d = 0, i = 0, j = 0, m = 0, digits = 6;
  if (exact_num > 0) {
    digits = exact_num;
  }
  int first_after_point = (int)(b * 10);
  int start = 1;
  while (start) {
    start = 0;
    start = 1;
    b = b * 10.0;
    d = (int)b;
    b = b - (long double)d;
    if (m < digits) {
      deg[m] = d + 48;
      m++;
      deg[m] = '\0';
    } else {
      break;
    }  // в этом блоке собрали в строку часть после запятой
  }
  while (start) {
    m--;
    if (m < 0) {
      a++;
      break;
    }
    if (d < 6) {
      break;
    } else if ((deg[m] - 48) < 9) {
      d = deg[m] - 48;
      deg[m] = d + 49;
      break;
    } else if ((deg[m] - 48) == 9) {
      d = deg[m] - 48;
      deg[m] = 48;
    }  // в этой части округлили результат по парамерту "ширина"
  }
  if (flag_exact == 1 && exact_num == 0) {
    if (first_after_point > 4) a++;
    deg[0] = '\0';
  }
  while (start) {
    if (a < 10) {
      even1[i] = a + 48;
      break;
    } else {
      a1 = a;
      a = a / 10;
      a1 = a1 - a * 10;
      even1[i] = a1 + 48;
      i++;
    }  // в этом блоке собрали целую часть (наоборот)
  }
  while (i >= 0) {
    even[j] = even1[i];
    i--;
    j++;
  }  // здесь развернули целую часть нормально
  even[j] = '\0';
  char tem[500];
  s21_memset(tem, '\0', 500);
  s21_strcat(tem, even);
  if (flag_exact == 1 && exact_num == 0 && flag_grid == 0) {
  } else {
    s21_strcat(tem, ".");
    s21_strcat(tem, deg);
  }
  spec_result[0] = '\0';
  m = s21_strlen(tem);
  char space_l[500], space_s[500], null_l[500], null_s[500];
  if (width_num >
      (m + 1)) {  // здесь делаю заготовки с нулями и пробелами для строки
    s21_memset(space_l, ' ', width_num - m);
    space_l[width_num - m] = '\0';
    s21_memset(space_s, ' ', width_num - m - 1);
    space_s[width_num - m - 1] = '\0';
    s21_memset(null_l, '0', width_num - m);
    null_l[width_num - m] = '\0';
    s21_memset(null_s, '0', width_num - m - 1);
    null_s[width_num - m - 1] = '\0';
  }
  if ((sign[0] == '-' && width_num < (m + 2)) ||
      (sign[0] == '+' && width_num < (m + 2) &&
       flag_plus == 1)) {  // ширина меньше, рисуем знак
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num < (m + 2) && flag_plus == 0 &&
             flag_space == 1) {  // ширина меньше, рисуем пробел вместо  +
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num < (m + 1) && flag_plus == 0 &&
             flag_space == 0) {  // ширина меньше, без знака
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '-' && width_num > (m + 1) &&
             flag_minus == 1) {  // ширина больше слева минус
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '-' && width_num > (m + 1) && flag_minus == 0 &&
             flag_zero == 0) {  // ширина больше без нолей минус
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '-' && width_num > (m + 1) && flag_minus == 0 &&
             flag_zero == 1) {  // ширина больше с нулями минус
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 0 &&
             flag_space == 0) {  // ширина больше слева без знака плюс
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_l);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 0 &&
             flag_space == 1) {  // ширина больше слева без знака плюс
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 1 &&
             flag_plus == 1) {  // ширина больше слева со знаком +
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
    s21_strcat(spec_result, space_s);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 &&
             flag_space == 1) {  // ширина больше слева с пробелом
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 &&
             flag_zero == 0) {  // ширина больше справа пробел без 0
    s21_strcat(spec_result, space_l);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 1 &&
             flag_zero == 0) {  // ширина больше справа плюс без 0
    s21_strcat(spec_result, space_s);
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 && flag_space == 1 &&
             flag_zero == 1) {  // ширина больше справа пробел c 0
    s21_strcat(spec_result, " ");
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 0 && flag_space == 0 &&
             flag_zero == 1) {  // ширина больше справа без знака c 0
    s21_strcat(spec_result, null_l);
    s21_strcat(spec_result, tem);
  } else if (sign[0] == '+' && width_num > (m + 1) && flag_minus == 0 &&
             flag_plus == 1 &&
             flag_zero == 1) {  // ширина больше справа плюс с 0
    s21_strcat(spec_result, sign);
    s21_strcat(spec_result, null_s);
    s21_strcat(spec_result, tem);
  }
  return 0;
}

void *specif_g(int flag_plus, int flag_minus, int flag_space, int flag_grid,
               int flag_zero, int flag_width, int width_num, int flag_exact,
               int exact_num, int flag_length, double arg, long double long_arg,
               char letter, char *spec_result) {
  if (flag_length != 3) {
    long_arg = (long double)arg;
  }
  long long int even = (long long int)long_arg;
  int even_digits = 0;
  int exact = 6;
  if (even < 0) {
    even *= -1;
  }
  while (1) {
    if (even < 1) {
      break;
    }
    even = even / 10;
    even_digits++;
  }
  if (flag_exact == 1) {
    exact = exact_num;
  }

  if (even_digits > exact && letter == 'g') {
    if (flag_exact == 1 && exact_num > 0) {
      exact = exact_num - 1;
    } else if (flag_exact == 1 && exact_num == 0) {
      exact = exact_num;
    } else if (flag_exact == 0) {
      flag_exact = 1;
      exact_num = 5;
    }
    specif_e(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
             flag_width, width_num, flag_exact, exact_num, flag_length, arg,
             long_arg, 'e', spec_result);
  }
  if (even_digits > exact && letter == 'G') {
    if (flag_exact == 1 && exact_num > 0) {
      exact = exact_num - 1;
    } else if (flag_exact == 1 && exact_num == 0) {
      exact = exact_num;
    } else if (flag_exact == 0) {
      flag_exact = 1;
      exact_num = 5;
    }
    specif_e(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
             flag_width, width_num, flag_exact, exact_num, flag_length, arg,
             long_arg, 'E', spec_result);
  }
  if (even_digits <= exact) {
    long double long_arg_temp = long_arg;
    double arg_temp = arg;
    if (arg < 0.0) {
      arg_temp = arg * (-1.0);
    }
    if (long_arg < 0.0) {
      long_arg_temp = long_arg * (-1.0);
    }
    specif_f(0, 1, 0, 0, 0, 0, 0, 0, 0, flag_length, arg_temp, long_arg_temp,
             spec_result);
    int l = s21_strlen(spec_result);
    int odd_nulls = 0;
    for (int i = 0; i < l; i++) {
      if (spec_result[i] == '0') {
        odd_nulls++;
      }
      if (spec_result[i] != '.' && spec_result[i] != '0') {
        break;
      }
    }
    if (odd_nulls == 0) {
      flag_exact = 1;
      exact_num = exact - even_digits;
    }
    if (odd_nulls == 1) {
      flag_exact = 1;
      exact_num = exact;
    }
    if (odd_nulls > 1) {
      flag_exact = 1;
      exact_num = exact + odd_nulls - 1;
    }
    s21_memset(spec_result, '\0', 1000);
    specif_f(flag_plus, flag_minus, flag_space, flag_grid, flag_zero,
             flag_width, width_num, flag_exact, exact_num, flag_length, arg,
             long_arg, spec_result);
    if (flag_exact == 1) {
      l = s21_strlen(spec_result);
      for (int i = l - 1; i > 0; i--) {
        if (spec_result[i] != 48) {
          spec_result[i + 1] = '\0';
          break;
        }
      }
    }
  }
  return 0;
}

void *specif_o(int flag_minus, int flag_grid, int flag_zero, int flag_width,
               int width_num, int flag_exact, int exact_num, int flag_length,
               long long int num_lint_arg, char *spec_result) {
  char temp[21] = "\0";
  if (flag_length == 2) long_octa(num_lint_arg, spec_result);
  if (flag_length == 1) {
    num_lint_arg = (unsigned short)num_lint_arg;
    octa(num_lint_arg, spec_result);
  }
  if (flag_length == 0) octa(num_lint_arg, spec_result);
  if (flag_grid) {
    temp[0] = '0';
    s21_strcpy(&temp[1], spec_result);
    s21_strcpy(spec_result, temp);
  } else {
    s21_strcpy(temp, spec_result);
  }
  int length = s21_strlen(spec_result);
  if (flag_width == 1 && flag_exact == 1 && exact_num >= length) {
    if (width_num > exact_num) {
      if (flag_minus) {
        s21_memset(spec_result, 48, (exact_num - length));
        s21_strncpy(&spec_result[exact_num - length], temp, length);
        s21_memset(&spec_result[exact_num], ' ', width_num - exact_num);
      } else {
        s21_memset(spec_result, ' ', (width_num - exact_num));
        s21_memset(&spec_result[width_num - exact_num], 48, exact_num - length);
        s21_strncpy(&spec_result[width_num - length], temp, length);
      }
    } else {
      s21_memset(spec_result, 48, (exact_num - length));
      s21_strncpy(&spec_result[exact_num - length], temp, length);
    }
  } else if (flag_width == 1 && (flag_exact == 0 || exact_num < length) &&
             width_num >= length) {
    if (flag_minus) {
      s21_memset(&spec_result[length], ' ', (width_num - length));
    } else if (flag_zero) {
      s21_memset(spec_result, 48, (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    } else {
      s21_memset(spec_result, ' ', (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    }
  } else if (flag_width == 0 && flag_exact == 1 && exact_num > length) {
    s21_memset(spec_result, 48, (exact_num - length));
    s21_strncpy(&spec_result[exact_num - length], temp, length);
  }
  return 0;
}

void *specif_u(int flag_minus, int flag_zero, int flag_width, int width_num,
               int flag_exact, int exact_num, int flag_length,
               unsigned long long int num_int_arg, char *spec_result) {
  char temp[20] = "\0";
  if (flag_length == 2) long_unsigned_dec(num_int_arg, spec_result);
  if (flag_length == 1) {
    num_int_arg = (unsigned short)num_int_arg;
    unsigned_dec(num_int_arg, spec_result);
  }
  if (flag_length == 0) unsigned_dec(num_int_arg, spec_result);
  int length = s21_strlen(spec_result);
  s21_strcpy(temp, spec_result);
  if (flag_width == 1 && flag_exact == 1 && exact_num >= length) {
    if (width_num > exact_num) {
      if (flag_minus) {
        s21_memset(spec_result, 48, (exact_num - length));
        s21_strncpy(&spec_result[exact_num - length], temp, length);
        s21_memset(&spec_result[exact_num], ' ', width_num - exact_num);
      } else {
        s21_memset(spec_result, ' ', (width_num - exact_num));
        s21_memset(&spec_result[width_num - exact_num], 48, exact_num - length);
        s21_strncpy(&spec_result[width_num - length], temp, length);
      }
    } else {
      s21_memset(spec_result, 48, (exact_num - length));
      s21_strncpy(&spec_result[exact_num - length], temp, length);
    }
  } else if (flag_width == 1 && (flag_exact == 0 || exact_num < length) &&
             width_num >= length) {
    if (flag_minus) {
      s21_memset(&spec_result[length], ' ', (width_num - length));
    } else if (flag_zero) {
      s21_memset(spec_result, 48, (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    } else {
      s21_memset(spec_result, ' ', (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    }
  } else if (flag_width == 0 && flag_exact == 1 && exact_num > length) {
    s21_memset(spec_result, 48, (exact_num - length));
    s21_strcpy(&spec_result[exact_num - length], temp);
  }
  return 0;
}

void *specif_x(int flag_minus, int flag_grid, int flag_zero, int flag_width,
               int width_num, int flag_exact, int exact_num, int flag_length,
               long long int num_lint_arg, char *spec_result) {
  char temp[500] = "\0";
  if (flag_length == 2) long_hex(num_lint_arg, spec_result, 'a');
  if (flag_length == 1) {
    num_lint_arg = (unsigned short)num_lint_arg;
    hex(num_lint_arg, spec_result, 'a');
  }
  if (flag_length == 0) hex(num_lint_arg, spec_result, 'a');
  int length = s21_strlen(spec_result);
  if (flag_grid) {
    if (flag_exact == 0 || (flag_exact == 1 && exact_num < length)) {
      temp[0] = '0';
      temp[1] = 'x';
      s21_strcpy(&temp[2], spec_result);
      s21_strcpy(spec_result, temp);
    } else if (flag_exact == 1 && exact_num > length) {
      temp[0] = '0';
      temp[1] = 'x';
      s21_memset(&temp[2], 48, (exact_num - length));
      s21_strcpy(&temp[exact_num - length + 2], spec_result);
      s21_strcpy(spec_result, temp);
    }
  } else {
    s21_strcpy(temp, spec_result);
  }
  length = s21_strlen(spec_result);
  if (flag_width == 1 && flag_exact == 1 && exact_num >= length) {
    if (width_num > exact_num) {
      if (flag_minus) {
        s21_memset(spec_result, 48, (exact_num - length));
        s21_strncpy(&spec_result[exact_num - length], temp, length);
        s21_memset(&spec_result[exact_num], ' ', width_num - exact_num);
      } else {
        s21_memset(spec_result, ' ', (width_num - exact_num));
        s21_memset(&spec_result[width_num - exact_num], 48, exact_num - length);
        s21_strncpy(&spec_result[width_num - length], temp, length);
      }
    } else {
      s21_memset(spec_result, 48, (exact_num - length));
      s21_strncpy(&spec_result[exact_num - length], temp, length);
    }
  } else if (flag_width == 1 && (flag_exact == 0 || exact_num < length) &&
             width_num >= length) {
    if (flag_minus) {
      s21_memset(&spec_result[length], ' ', (width_num - length));
    } else if (flag_zero) {
      s21_memset(spec_result, 48, (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    } else {
      s21_memset(spec_result, ' ', (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    }
  } else if (flag_width == 0 && flag_exact == 1 && exact_num >= length) {
    s21_memset(spec_result, 48, (exact_num - length));
    s21_strncpy(&spec_result[exact_num - length], temp, length);
  }
  return 0;
}

void *specif_X(int flag_minus, int flag_grid, int flag_zero, int flag_width,
               int width_num, int flag_exact, int exact_num, int flag_length,
               long long int num_lint_arg, char *spec_result) {
  char temp[500] = "\0";
  if (flag_length == 2) long_hex(num_lint_arg, spec_result, 'A');
  if (flag_length == 1) {
    num_lint_arg = (unsigned short)num_lint_arg;
    hex(num_lint_arg, spec_result, 'A');
  }
  if (flag_length == 0) hex(num_lint_arg, spec_result, 'A');
  int length = s21_strlen(spec_result);
  if (flag_grid) {
    if (flag_exact == 0 || (flag_exact == 1 && exact_num < length)) {
      temp[0] = '0';
      temp[1] = 'X';
      s21_strcpy(&temp[2], spec_result);
      s21_strcpy(spec_result, temp);
    } else if (flag_exact == 1 && exact_num > length) {
      temp[0] = '0';
      temp[1] = 'X';
      s21_memset(&temp[2], 48, (exact_num - length));
      s21_strcpy(&temp[exact_num - length + 2], spec_result);
      s21_strcpy(spec_result, temp);
    }
  } else {
    s21_strcpy(temp, spec_result);
  }
  length = s21_strlen(spec_result);
  if (flag_width == 1 && flag_exact == 1 && exact_num >= length) {
    if (width_num > exact_num) {
      if (flag_minus) {
        s21_memset(spec_result, 48, (exact_num - length));
        s21_strncpy(&spec_result[exact_num - length], temp, length);
        s21_memset(&spec_result[exact_num], ' ', width_num - exact_num);
      } else {
        s21_memset(spec_result, ' ', (width_num - exact_num));
        s21_memset(&spec_result[width_num - exact_num], 48, exact_num - length);
        s21_strncpy(&spec_result[width_num - length], temp, length);
      }
    } else {
      s21_memset(spec_result, 48, (exact_num - length));
      s21_strncpy(&spec_result[exact_num - length], temp, length);
    }
  } else if (flag_width == 1 && (flag_exact == 0 || exact_num < length) &&
             width_num >= length) {
    if (flag_minus) {
      s21_memset(&spec_result[length], ' ', (width_num - length));
    } else if (flag_zero) {
      s21_memset(spec_result, 48, (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    } else {
      s21_memset(spec_result, ' ', (width_num - length));
      s21_strncpy(&spec_result[width_num - length], temp, length);
    }
  } else if (flag_width == 0 && flag_exact == 1 && exact_num >= length) {
    s21_memset(spec_result, 48, (exact_num - length));
    s21_strncpy(&spec_result[exact_num - length], temp, length);
  }
  return 0;
}

void *specif_s(int flag_minus, int flag_zero, int flag_width, int width_num,
               int flag_exact, int exact_num, int flag_length, char *str_arg,
               char *spec_result) {
  if (flag_width == 1 && flag_exact == 1) {
    if (width_num < exact_num) {
      s21_strncpy(spec_result, str_arg, exact_num);
    } else {
      if (flag_minus == 1) {
        s21_strncpy(spec_result, str_arg, exact_num);
        s21_memset(&spec_result[exact_num], '0', (width_num - exact_num));
        s21_memset(&spec_result[exact_num], ' ', (width_num - exact_num));
      } else {
        if (flag_zero) {
          s21_memset(spec_result, '0', width_num);
        } else {
          s21_memset(spec_result, ' ', width_num);
        }

        s21_strncpy(&spec_result[width_num - exact_num], str_arg, exact_num);
      }
    }
  } else if (flag_width == 1 && flag_exact == 0) {
    if (width_num >= s21_strlen(str_arg)) {
      if (flag_minus == 1) {
        s21_strcpy(spec_result, str_arg);
        s21_memset(&spec_result[s21_strlen(str_arg)], ' ',
                   (width_num - s21_strlen(str_arg)));
      } else {
        if (flag_zero) {
          s21_memset(spec_result, '0', (width_num - s21_strlen(str_arg)));
        } else {
          s21_memset(spec_result, ' ', (width_num - s21_strlen(str_arg)));
        }
        s21_strcpy(&spec_result[width_num - s21_strlen(str_arg)], str_arg);
      }
    } else {
      s21_strcpy(spec_result, str_arg);
    }
  } else if (flag_width == 0 && flag_exact == 1) {
    s21_strncpy(spec_result, str_arg, exact_num);
  } else {
    s21_strcpy(spec_result, str_arg);
  }
  spec_result[s21_strlen(str_arg) + width_num] = '\0';
  return 0;
}

void *specif_p(int flag_minus, int flag_zero, int flag_width, int width_num,
               int flag_exact, int exact_num,
               unsigned long long int num_lint_arg, char *spec_result) {
  char temp[30] = "\0";
  long_hex(num_lint_arg, temp, 'a');
  int length = s21_strlen(temp) + 2;
  if (flag_exact == 1) {
    if (flag_width == 1 && flag_minus == 1 && exact_num > (length - 2)) {
      spec_result[0] = '0';
      spec_result[1] = 'x';
      s21_memset(&spec_result[2], '0', exact_num - length + 2);
      s21_strcpy(&spec_result[exact_num - length + 4], temp);
      s21_memset(&spec_result[exact_num + 2], ' ', width_num - exact_num - 2);
    } else if (flag_width == 1 && flag_minus == 0 && exact_num > (length - 2)) {
      s21_memset(spec_result, ' ', width_num - exact_num - 2);
      spec_result[width_num - exact_num - 2] = '0';
      spec_result[width_num - exact_num - 1] = 'x';
      s21_memset(&spec_result[width_num - exact_num], '0',
                 exact_num - length + 2);
      s21_strcpy(&spec_result[width_num - length + 2], temp);
    } else if (exact_num > (length - 2)) {
      spec_result[0] = '0';
      spec_result[1] = 'x';
      s21_memset(&spec_result[2], '0', exact_num - length + 2);
      s21_strcpy(&spec_result[exact_num - length + 4], temp);
    } else if (flag_minus && exact_num < (length - 2)) {
      spec_result[0] = '0';
      spec_result[1] = 'x';
      s21_strcpy(&spec_result[2], temp);
      s21_memset(&spec_result[length], ' ', width_num - length);
    } else {
      s21_memset(spec_result, ' ', width_num - length);
      spec_result[width_num - length] = '0';
      spec_result[width_num - length + 1] = 'x';
      s21_strcpy(&spec_result[width_num - length + 2], temp);
    }
  } else if (flag_width == 1 && flag_zero == 0) {
    if (width_num > length) {
      if (flag_minus) {
        spec_result[0] = '0';
        spec_result[1] = 'x';
        s21_strcpy(&spec_result[2], temp);
        s21_memset(&spec_result[length], ' ', width_num - length);
      } else {
        s21_memset(spec_result, ' ', width_num - length);
        spec_result[width_num - length] = '0';
        spec_result[width_num - length + 1] = 'x';
        s21_strcpy(&spec_result[width_num - length + 2], temp);
      }
    }
  } else if (flag_width == 1 && flag_zero == 1) {
    if (width_num > length) {
      spec_result[0] = '0';
      spec_result[1] = 'x';
      s21_memset(&spec_result[2], '0', width_num - length);
      s21_strcpy(&spec_result[width_num - length + 2], temp);
    } else {
      s21_memset(spec_result, ' ', width_num - length);
      spec_result[width_num - length - 2] = '0';
      spec_result[width_num - length - 1] = 'x';
      s21_strcpy(&spec_result[width_num - length], temp);
    }
  } else {
    spec_result[0] = '0';
    spec_result[1] = 'x';
    s21_strcpy(&spec_result[2], temp);
  }
  return 0;
}

void *dec(int num, char *str) {
  char *p_str = str;
  p_str += 11;
  do {
    *--p_str = num % 10 + 48;
    num /= 10;
  } while (num != 0);

  s21_strcpy(str, p_str);
  return 0;
}

void *long_dec(long int num, char *str) {
  char *p_str = str;
  p_str += 20;
  do {
    *--p_str = num % 10 + 48;
    num /= 10;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *unsigned_dec(unsigned int num, char *str) {
  char *p_str = str;
  p_str += 11;
  do {
    *--p_str = num % 10 + 48;
    num /= 10;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *long_unsigned_dec(unsigned long int num, char *str) {
  char *p_str = str;
  p_str += 20;
  do {
    *--p_str = num % 10 + 48;
    num /= 10;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *hex(unsigned int num, char *str, char ch) {
  char *p_str = str;
  p_str += 11;
  do {
    int tmp = num % 16;
    *--p_str = (tmp < 10) ? tmp + 48 : (tmp - 10) + ch;
    num /= 16;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *long_hex(unsigned long int num, char *str, char ch) {
  char *p_str = str;
  p_str += 20;
  do {
    int tmp = num % 16;
    *--p_str = (tmp < 10) ? tmp + 48 : (tmp - 10) + ch;
    num /= 16;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *octa(unsigned int num, char *str) {
  char *p_str = str;
  p_str += 11;
  do {
    *--p_str = num % 8 + 48;
    num /= 8;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}

void *long_octa(unsigned long int num, char *str) {
  char *p_str = str;
  p_str += 20;
  do {
    *--p_str = num % 8 + 48;
    num /= 8;
  } while (num != 0);
  s21_strcpy(str, p_str);
  return 0;
}
