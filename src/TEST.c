#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(strlen_test) {
  ck_assert_int_eq(s21_strlen("Hello world\0"), strlen("Hello world\0"));
  ck_assert_int_eq(s21_strlen("Hello world\0"), strlen("Hello world\0"));
  ck_assert_int_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
  ck_assert_int_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
  ck_assert_int_eq(s21_strlen(" \0"), strlen(" \0"));
  ck_assert_int_eq(s21_strlen("\n\0"), strlen("\n\0"));
  ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
}
END_TEST

START_TEST(strcmp_test) {
  char str_cmp[] = "Hello World\0";
  ck_assert_int_eq(s21_strcmp(str_cmp, "Hello world\0"),
                   strcmp(str_cmp, "Hello world\0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, "Hello world\n\0"),
                   strcmp(str_cmp, "Hello world\n\0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, "a\n\0"), strcmp(str_cmp, "a\n\0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, " \n\0"), strcmp(str_cmp, " \n\0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, " \0"), strcmp(str_cmp, " \0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, "\n\0"), strcmp(str_cmp, "\n\0"));
  ck_assert_int_eq(s21_strcmp(str_cmp, "\0"), strcmp(str_cmp, "\0"));
}
END_TEST

START_TEST(strncmp_test) {
  char str_cmp[] = "Hello World\0";
  ck_assert_int_eq(s21_strncmp(str_cmp, "Hello world\0", 11),
                   strncmp(str_cmp, "Hello world\0", 11));
  ck_assert_int_eq(s21_strncmp(str_cmp, "Hello world\n\0", 5),
                   strncmp(str_cmp, "Hello world\n\0", 5));
  ck_assert_int_eq(s21_strncmp(str_cmp, "a\n\0", 2),
                   strncmp(str_cmp, "a\n\0", 2));
  ck_assert_int_eq(s21_strncmp(str_cmp, " \n\0", 2),
                   strncmp(str_cmp, " \n\0", 2));
  ck_assert_int_eq(s21_strncmp(str_cmp, " \0", 1), strncmp(str_cmp, " \0", 1));
  ck_assert_int_eq(s21_strncmp(str_cmp, "\n\0", 1),
                   strncmp(str_cmp, "\n\0", 1));
  ck_assert_int_eq(s21_strncmp(str_cmp, "\0", 1), strncmp(str_cmp, "\0", 1));
}
END_TEST

START_TEST(strcpy_test) {
  char dest[50];
  ck_assert_str_eq(s21_strcpy(dest, "Hello world\0"),
                   strcpy(dest, "Hello world\0"));
  ck_assert_str_eq(s21_strcpy(dest, "Hello world\n\0"),
                   strcpy(dest, "Hello world\n\0"));
  ck_assert_str_eq(s21_strcpy(dest, "a\n\0"), strcpy(dest, "a\n\0"));
  ck_assert_str_eq(s21_strcpy(dest, " \n\0"), strcpy(dest, " \n\0"));
  ck_assert_str_eq(s21_strcpy(dest, " \0"), strcpy(dest, " \0"));
  ck_assert_str_eq(s21_strcpy(dest, "\n\0"), strcpy(dest, "\n\0"));
  ck_assert_str_eq(s21_strcpy(dest, "\0"), strcpy(dest, "\0"));
}
END_TEST

START_TEST(strncpy_test) {
  char dest[50];
  ck_assert_str_eq(s21_strncpy(dest, "Hello world\0", 12),
                   strncpy(dest, "Hello world\0", 12));
  ck_assert_str_eq(s21_strncpy(dest, "Hello world\n\0", 13),
                   strncpy(dest, "Hello world\n\0", 13));
  ck_assert_str_eq(s21_strncpy(dest, "a\n\0", 3), strncpy(dest, "a\n\0", 3));
  ck_assert_str_eq(s21_strncpy(dest, " \n\0", 5), strncpy(dest, " \n\0", 5));
  ck_assert_str_eq(s21_strncpy(dest, " \0", 2), strncpy(dest, " \0", 2));
  ck_assert_str_eq(s21_strncpy(dest, "\n\0", 4), strncpy(dest, "\n\0", 4));
  ck_assert_str_eq(s21_strncpy(dest, "\0", 1), strncpy(dest, "\0", 1));
}
END_TEST

START_TEST(strcat_test) {
  char dest[100] = "Test string";
  ck_assert_str_eq(s21_strcat(dest, "Hello world\0"),
                   strcat(dest, "Hello world\0"));
  ck_assert_str_eq(s21_strcat(dest, "Hello world\n\0"),
                   strcat(dest, "Hello world\n\0"));
  ck_assert_str_eq(s21_strcat(dest, "a\n\0"), strcat(dest, "a\n\0"));
  ck_assert_str_eq(s21_strcat(dest, " \n\0"), strcat(dest, " \n\0"));
  ck_assert_str_eq(s21_strcat(dest, " \0"), strcat(dest, " \0"));
  ck_assert_str_eq(s21_strcat(dest, "\n\0"), strcat(dest, "\n\0"));
  ck_assert_str_eq(s21_strcat(dest, "\0"), strcat(dest, "\0"));
}
END_TEST

START_TEST(strncat_test) {
  char dest[50] = "test string";
  ck_assert_str_eq(s21_strncat(dest, "Hello world\0", 12),
                   strncat(dest, "Hello world\0", 12));
  ck_assert_str_eq(s21_strncat(dest, "Hello world\n\0", 5),
                   strncat(dest, "Hello world\n\0", 5));
  ck_assert_str_eq(s21_strncat(dest, "a\n\0", 1), strncat(dest, "a\n\0", 1));
  ck_assert_str_eq(s21_strncat(dest, " \n\0", 1), strncat(dest, " \n\0", 1));
  ck_assert_str_eq(s21_strncat(dest, " \0", 0), strncat(dest, " \0", 0));
}
END_TEST

START_TEST(strchr_test) {
  ck_assert_str_eq(s21_strchr("Hello world\0", 'w'),
                   strchr("Hello world\0", 'w'));
  ck_assert_str_eq(s21_strchr("Hello world\n\0", 'l'),
                   strchr("Hello world\n\0", 'l'));
  ck_assert_str_eq(s21_strchr("a\n\0", 'a'), strchr("a\n\0", 'a'));
  ck_assert_str_eq(s21_strchr(" \n\0", '\0'), strchr(" \n\0", '\0'));
  ck_assert_str_eq(s21_strchr(" \0", ' '), strchr(" \0", ' '));
  ck_assert_str_eq(s21_strchr("\n\0", '\n'), strchr("\n\0", '\n'));
  ck_assert_str_eq(s21_strchr("\0", '\0'), strchr("\0", '\0'));
  ck_assert_ptr_eq(s21_strchr("Hello world\0", 'Q'),
                   strchr("Hello world\0", 'Q'));
}
END_TEST

START_TEST(strrchr_test) {
  ck_assert_str_eq(s21_strrchr("Hello world\0", 'o'),
                   strrchr("Hello world\0", 'o'));
  ck_assert_str_eq(s21_strrchr("Hello world\n\0", 'l'),
                   strrchr("Hello world\n\0", 'l'));
  ck_assert_str_eq(s21_strrchr("aa\n\0", 'a'), strrchr("aa\n\0", 'a'));
  ck_assert_str_eq(s21_strrchr(" \n\0", '\0'), strrchr(" \n\0", '\0'));
  ck_assert_str_eq(s21_strrchr(" \0", ' '), strrchr(" \0", ' '));
  ck_assert_str_eq(s21_strrchr("\n\0", '\n'), strrchr("\n\0", '\n'));
  ck_assert_str_eq(s21_strrchr("\0", '\0'), strrchr("\0", '\0'));
  ck_assert_ptr_eq(s21_strrchr("Hello world\0", 'Q'),
                   strrchr("Hello world\0", 'Q'));
}
END_TEST

START_TEST(memcmp_test) {
  char str_cmp[] = "HellO World\0";
  ck_assert_int_eq(s21_memcmp(str_cmp, "Hello world\0", 11),
                   memcmp(str_cmp, "Hello world\0", 11));
  ck_assert_int_eq(s21_memcmp(str_cmp, "Hello world\n\0", 5),
                   memcmp(str_cmp, "Hello world\n\0", 5));
  ck_assert_int_eq(s21_memcmp(str_cmp, "a\n\0", 2),
                   memcmp(str_cmp, "a\n\0", 2));
  ck_assert_int_eq(s21_memcmp(str_cmp, " \n\0", 2),
                   memcmp(str_cmp, " \n\0", 2));
  ck_assert_int_eq(s21_memcmp(str_cmp, " \0", 1), memcmp(str_cmp, " \0", 1));
  ck_assert_int_eq(s21_memcmp(str_cmp, "\n\0", 1), memcmp(str_cmp, "\n\0", 1));
  ck_assert_int_eq(s21_memcmp(str_cmp, "\0", 1), memcmp(str_cmp, "\0", 1));
}
END_TEST

START_TEST(memchr_test) {
  ck_assert_str_eq(s21_memchr("Hello world\0", 'w', 8),
                   s21_memchr("Hello world\0", 'w', 8));
  ck_assert_str_eq(s21_memchr("Hello world\n\0", 'l', 5),
                   s21_memchr("Hello world\n\0", 'l', 5));
  ck_assert_str_eq(s21_memchr("a\n\0", 'a', 2), s21_memchr("a\n\0", 'a', 2));
  ck_assert_str_eq(s21_memchr(" \n\0", '\0', 3), s21_memchr(" \n\0", '\0', 3));
  ck_assert_str_eq(s21_memchr(" \0", ' ', 4), s21_memchr(" \0", ' ', 4));
  ck_assert_str_eq(s21_memchr("\n\0", '\n', 10), s21_memchr("\n\0", '\n', 10));
  ck_assert_str_eq(s21_memchr("\0", '\0', 3), s21_memchr("\0", '\0', 3));
  ck_assert_ptr_eq(s21_memchr("Hello world\0", 'R', 12),
                   s21_memchr("Hello world\0", 'R', 12));
  ck_assert_ptr_eq(s21_memchr("Hello world\0", 'w', 3),
                   s21_memchr("Hello world\0", 'w', 3));
  ck_assert_ptr_eq(s21_memchr("Hello world\0", 'H', 0),
                   s21_memchr("Hello world\0", 'H', 0));
}
END_TEST

START_TEST(memcpy_test) {
  char dest[50];
  ck_assert_str_eq(s21_memcpy(dest, "Hello world\0", 12),
                   memcpy(dest, "Hello world\0", 12));
  ck_assert_str_eq(s21_memcpy(dest, "Hello world\n\0", 13),
                   memcpy(dest, "Hello world\n\0", 13));
  ck_assert_str_eq(s21_memcpy(dest, "a\n\0", 3), memcpy(dest, "a\n\0", 3));
  ck_assert_str_eq(s21_memcpy(dest, " \n\0", 3), memcpy(dest, " \n\0", 3));
  ck_assert_str_eq(s21_memcpy(dest, " \0", 2), memcpy(dest, " \0", 2));
  ck_assert_str_eq(s21_memcpy(dest, "\n\0", 2), memcpy(dest, "\n\0", 2));
  ck_assert_str_eq(s21_memcpy(dest, "\0", 1), memcpy(dest, "\0", 1));
}
END_TEST

START_TEST(memmove_test) {
  char dest[50];
  ck_assert_str_eq(s21_memmove(dest, "Hello world\0", 12),
                   memmove(dest, "Hello world\0", 12));
  ck_assert_str_eq(s21_memmove(dest, "Hello world\n\0", 13),
                   memmove(dest, "Hello world\n\0", 13));
  ck_assert_str_eq(s21_memmove(dest, "a\n\0", 3), memmove(dest, "a\n\0", 3));
  ck_assert_str_eq(s21_memmove(dest, " \n\0", 3), memmove(dest, " \n\0", 3));
  ck_assert_str_eq(s21_memmove(dest, " \0", 2), memmove(dest, " \0", 2));
  ck_assert_str_eq(s21_memmove(dest, "\n\0", 2), memmove(dest, "\n\0", 2));
  ck_assert_str_eq(s21_memmove(dest, "\0", 1), memmove(dest, "\0", 1));
}
END_TEST

START_TEST(memset_test) {
  char str1[] = "Hello world\0";
  ck_assert_str_eq(s21_memset(str1, '*', 5), memset(str1, '*', 5));
  char str2[] = "Hello world\n\0";
  ck_assert_str_eq(s21_memset(str2, '*', 12), memset(str2, '*', 12));
  char str3[] = "a\n\0";
  ck_assert_str_eq(s21_memset(str3, '*', 3), memset(str3, '*', 3));
  char str4[] = " \n\0";
  ck_assert_str_eq(s21_memset(str4, '*', 2), memset(str4, '*', 2));
  char str5[] = " \0";
  ck_assert_str_eq(s21_memset(str5, '*', 2), memset(str5, '*', 2));
  char str6[] = "\n\0";
  ck_assert_str_eq(s21_memset(str6, '*', 1), memset(str6, '*', 1));
  char str7[] = "\0";
  ck_assert_str_eq(s21_memset(str7, '*', 1), memset(str7, '*', 1));
}
END_TEST

START_TEST(strcspn_test) {
  ck_assert_int_eq(s21_strcspn("1234567890", "456"),
                   strcspn("1234567890", "456"));
  ck_assert_int_eq(s21_strcspn("1234567890", "987"),
                   strcspn("1234567890", "987"));
  ck_assert_int_eq(s21_strcspn("1234567890", "123"),
                   strcspn("1234567890", "123"));
  ck_assert_int_eq(s21_strcspn("1234567980", "7892"),
                   strcspn("1234567980", "7892"));
  ck_assert_int_eq(s21_strcspn("1234567890", "\0"),
                   strcspn("1234567890", "\0"));
  ck_assert_int_eq(s21_strcspn("12345\n67890", "\n"),
                   strcspn("12345\n67890", "\n"));
  ck_assert_int_eq(s21_strcspn("test test", " "), strcspn("test test", " "));
  ck_assert_int_eq(s21_strcspn("\0", "\0"), strcspn("\0", "\0"));
}
END_TEST

START_TEST(strspn_test) {
  ck_assert_int_eq(s21_strspn("0123456789", "0123"),
                   strspn("0123456789", "0123"));
  ck_assert_int_eq(s21_strspn("0123456789", "43210"),
                   strspn("0123456789", "43210"));
  ck_assert_int_eq(s21_strspn("0123456789", "7890"),
                   strspn("0123456789", "7890"));
  ck_assert_int_eq(s21_strspn("0123456798", "abcd0253486"),
                   strspn("0123456798", "abcd0253486"));
  ck_assert_int_eq(s21_strspn("0123456789", "\0"), strspn("0123456789", "\0"));
  ck_assert_int_eq(s21_strspn("0123\n456789", "\n120"),
                   strspn("0123\n456789", "\n120"));
  ck_assert_int_eq(s21_strspn("\0", "\0"), strspn("\0", "\0"));
}
END_TEST

START_TEST(strpbrk_test) {
  ck_assert_str_eq(s21_strpbrk("0123456789", "456"),
                   strpbrk("0123456789", "456"));
  ck_assert_str_eq(s21_strpbrk("0123456789", "987"),
                   strpbrk("0123456789", "987"));
  ck_assert_str_eq(s21_strpbrk("0123456789", "951"),
                   strpbrk("0123456789", "951"));
  ck_assert_str_eq(s21_strpbrk("01 23456789", " 2"),
                   strpbrk("01 23456789", " 2"));
  ck_assert_str_eq(s21_strpbrk("012345367389", "4563"),
                   strpbrk("012345367389", "4563"));
  ck_assert_str_eq(s21_strpbrk("0123\n4567\n89", "\n6"),
                   strpbrk("0123\n4567\n89", "\n6"));
  ck_assert_ptr_eq(s21_strpbrk("0123456789", "abc"),
                   strpbrk("0123456789", "abc"));
}
END_TEST

START_TEST(strstr_test) {
  ck_assert_str_eq(s21_strstr("0123456789", "345"),
                   strstr("0123456789", "345"));
  ck_assert_str_eq(s21_strstr("111123123123", "123"),
                   strstr("111123123123", "123"));
  ck_assert_str_eq(s21_strstr("aaatesTteSttest", "test"),
                   strstr("aaatesTteSttest", "test"));
  ck_assert_str_eq(s21_strstr("01\n2345 6789", "789"),
                   strstr("01\n2345 6789", "789"));
  ck_assert_str_eq(s21_strstr("test string strstr", "string"),
                   strstr("test string strstr", "string"));
  ck_assert_str_eq(s21_strstr("0123456789", "\0"), strstr("0123456789", "\0"));
  ck_assert_str_eq(s21_strstr("test\nstring", "test\n"),
                   strstr("test\nstring", "test\n"));
  ck_assert_ptr_eq(s21_strstr("0123456789", "375"),
                   strstr("0123456789", "375"));
}
END_TEST

START_TEST(strtok_test) {
  char str_s21[] = "test1/test2.test3;test4,test5 test6";
  char str_orig[] = "test1/test2.test3;test4,test5 test6";
  char delim[] = "/.;, ";
  char *tok_s21 = s21_strtok(str_s21, delim);
  char *tok_orig = strtok(str_orig, delim);
  ck_assert_str_eq(tok_s21, tok_orig);
  int n = 5;
  while (n--) {
    tok_s21 = s21_strtok(s21_NULL, delim);
    tok_orig = strtok(s21_NULL, delim);
    ck_assert_str_eq(tok_s21, tok_orig);
  }
  char str[] = "test1test2test3";
  ck_assert_str_eq(s21_strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(strerror_test) {
#if defined(__linux__)
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
#elif defined(__APPLE__)
  for (int i = 0; i < 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
#endif  // __linux__/__APPLE__
}
END_TEST

START_TEST(to_upper_test) {
  char str[] = "HeLlo WorlD!";
  char str1[] = "aaaHellO 123 woRld @#*zZz!!!";
  char str2[] = "\0";
  char *p_str;
  p_str = s21_to_upper(str);
  ck_assert_str_eq(p_str, "HELLO WORLD!");
  free(p_str);
  p_str = s21_to_upper(str1);
  ck_assert_str_eq(p_str, "AAAHELLO 123 WORLD @#*ZZZ!!!");
  free(p_str);
  p_str = s21_to_upper(str2);
  ck_assert_str_eq(p_str, "");
  free(p_str);
}
END_TEST

START_TEST(to_lower_test) {
  char str[] = "HeLlo WorlD!";
  char str1[] = "aaaHellO 123 woRld @#*zZz!!!";
  char str2[] = "\0";
  char *p_str;
  p_str = s21_to_lower(str);
  ck_assert_str_eq(p_str, "hello world!");
  free(p_str);
  p_str = s21_to_lower(str1);
  ck_assert_str_eq(p_str, "aaahello 123 world @#*zzz!!!");
  free(p_str);
  p_str = s21_to_lower(str2);
  ck_assert_str_eq(p_str, "");
  free(p_str);
}
END_TEST

START_TEST(insert_test) {
  char *p_str;
  char src[] = "Hello !";
  char str[] = "world";
  p_str = s21_insert(src, str, 6);
  ck_assert_str_eq(p_str, "Hello world!");
  free(p_str);

  char src1[] = "\0";
  char str1[] = "Hello world!";
  p_str = s21_insert(src1, str1, 0);
  ck_assert_str_eq(p_str, "Hello world!");
  free(p_str);

  char src2[] = "Hello world!";
  char str2[] = "!!";
  p_str = s21_insert(src2, str2, 11);
  ck_assert_str_eq(p_str, "Hello world!!!");
  free(p_str);
}
END_TEST

START_TEST(trim_test) {
  char *p_str;
  char src[] = "11100012343421001111";
  char trim_chars[] = "1";
  p_str = s21_trim(src, trim_chars);
  ck_assert_str_eq(p_str, "0001234342100");
  free(p_str);

  char src1[] = "aaabbbcccdddbbbaaa";
  char trim_chars1[] = "ab";
  p_str = s21_trim(src1, trim_chars1);
  ck_assert_str_eq(p_str, "cccddd");
  free(p_str);

  char src2[] = "111100002222";
  char trim_chars2[] = "012";
  p_str = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(p_str, "");
  free(p_str);
}
END_TEST

START_TEST(sprintf_c) {
  char format[] = "%c %c %c";
  char *str_s21 = calloc(5, sizeof(char));
  char *str_orig = calloc(5, sizeof(char));
  s21_sprintf(str_s21, format, 'Q', '^', '7');
  sprintf(str_orig, format, 'Q', '^', '7');
  ck_assert_str_eq(str_s21, str_orig);
  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_s) {
  char format1[] = "%s %s %s";
  char format2[] = "%20s";
  char format3[] = "%.5s";
  char format4[] = "%20.5s";
  char format5[] = "%-20.5s";
  char format6[] = "%*s";
  char format7[] = "%.*s";
  char format8[] = "%*.*s";

  char *str_s21 = calloc(50, sizeof(char));
  char *str_orig = calloc(50, sizeof(char));

  s21_sprintf(str_s21, format1, "test string", "123", "\0");
  sprintf(str_orig, format1, "test string", "123", "\0");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format2, "test string");
  sprintf(str_orig, format2, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format3, "test string");
  sprintf(str_orig, format3, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format4, "test string");
  sprintf(str_orig, format4, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format5, "test string");
  sprintf(str_orig, format5, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, 20, "test string");
  sprintf(str_orig, format6, 20, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format7, 5, "test string");
  sprintf(str_orig, format7, 5, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format8, 20, 5, "test string");
  sprintf(str_orig, format8, 20, 5, "test string");
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_o) {
  char format1[] = "%o %lo";
  char format2[] = "%30o %30lo";
  char format3[] = "%.10o %.10lo";
  char format4[] = "%30.10o %30.10lo";
  char format5[] = "%-30.10o";
  char format6[] = "%*o %*lo";
  char format7[] = "%.*o %.*lo";
  char format8[] = "%*.*o %*.*lo";
  char format9[] = "%#o %#lo";
  char format10[] = "%#30.10o %#30.10lo";
  char format11[] = "%030o";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678, 8765432112345678);
  sprintf(str_orig, format1, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345678, 8765432112345678);
  sprintf(str_orig, format2, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345678, 8765432112345678);
  sprintf(str_orig, format3, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345678, 8765432112345678);
  sprintf(str_orig, format4, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345678, 8765432112345678);
  sprintf(str_orig, format5, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, 30, 12345678, 40, 8765432112345678);
  sprintf(str_orig, format6, 30, 12345678, 40, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 20, 12345678, 30, 8765432112345678);
  sprintf(str_orig, format7, 20, 12345678, 30, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  sprintf(str_orig, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345678, 8765432112345678);
  sprintf(str_orig, format9, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12345678, 8765432112345678);
  sprintf(str_orig, format10, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12345678, 8765432112345678);
  sprintf(str_orig, format11, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_d) {
  char format1[] = "%d %ld %d %ld";
  char format2[] = "%20d %20ld %20d %20ld";
  char format3[] = "%.10d %.10ld %.10d %.10ld";
  char format4[] = "%20.10d %20.10ld %20.10d %20.10ld";
  char format5[] = "%-20.10d %-20.10ld %-20.10d %-20.10ld";
  char format6[] = "%*d %*d";
  char format7[] = "%.*d %.*d";
  char format8[] = "%*.*d %*.*d";
  char format9[] = "%020d %020d";
  char format10[] = "%+d %+d %+ld %+ld";
  char format11[] = "% d % d % ld % ld";

  char *st_s21 = calloc(100, sizeof(char));
  char *st_orig = calloc(100, sizeof(char));

  s21_sprintf(st_s21, format1, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(st_orig, format1, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format2, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(st_orig, format2, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format3, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(st_orig, format3, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format4, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(st_orig, format4, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format5, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(st_orig, format5, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format6, 10, 12345678, 10, -12345678);
  sprintf(st_orig, format6, 10, 12345678, 10, -12345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format7, 10, 12345678, 10, -12345678);
  sprintf(st_orig, format7, 10, 12345678, 10, -12345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format8, 20, 10, 12345678, 20, 10, -12345678);
  sprintf(st_orig, format8, 20, 10, 12345678, 20, 10, -12345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format9, 12345678, -12345678);
  sprintf(st_orig, format9, 12345678, -12345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format10, 12345678, -12345678, 8765432112345678,
              -8765432112345678);
  sprintf(st_orig, format10, 12345678, -12345678, 8765432112345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  s21_sprintf(st_s21, format11, 12345678, -12345678, 8765432112345678,
              -8765432112345678);
  sprintf(st_orig, format11, 12345678, -12345678, 8765432112345678,
          -8765432112345678);
  ck_assert_str_eq(st_s21, st_orig);
  s21_memset(st_s21, '\0', 100);
  s21_memset(st_orig, '\0', 100);

  free(st_s21);
  free(st_orig);
}
END_TEST

START_TEST(sprintf_i) {
  char format1[] = "%i %li %i %li";
  char format2[] = "%20i %20li %20i %20li";
  char format3[] = "%.10i %.10li %.10i %.10li";
  char format4[] = "%20.10i %20.10li %20.10i %20.10li";
  char format5[] = "%-20.10i %-20.10li %-20.10i %-20.10li";
  char format6[] = "%*i %*i";
  char format7[] = "%.*i %.*i";
  char format8[] = "%*.*i %*.*i";
  char format9[] = "%020i %020i";
  char format10[] = "%+i %+i %+li %+li";
  char format11[] = "% i % i % li % li";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(str_orig, format1, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(str_orig, format2, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(str_orig, format3, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(str_orig, format4, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345678, 8765432112345678, -12345678,
              -8765432112345678);
  sprintf(str_orig, format5, 12345678, 8765432112345678, -12345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345678, 10, -12345678);
  sprintf(str_orig, format6, 10, 12345678, 10, -12345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345678, 10, -12345678);
  sprintf(str_orig, format7, 10, 12345678, 10, -12345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 20, 10, 12345678, 20, 10, -12345678);
  sprintf(str_orig, format8, 20, 10, 12345678, 20, 10, -12345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345678, -12345678);
  sprintf(str_orig, format9, 12345678, -12345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12345678, -12345678, 8765432112345678,
              -8765432112345678);
  sprintf(str_orig, format10, 12345678, -12345678, 8765432112345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12345678, -12345678, 8765432112345678,
              -8765432112345678);
  sprintf(str_orig, format11, 12345678, -12345678, 8765432112345678,
          -8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_x) {
  char format1[] = "%x %lx";
  char format2[] = "%30x %30lx";
  char format3[] = "%.10x %.10lx";
  char format4[] = "%30.10x %30.10lx";
  char format5[] = "%-30.10x";
  char format6[] = "%*x %*lx";
  char format7[] = "%.*x %.*lx";
  char format8[] = "%*.*x %*.*lx";
  char format9[] = "%#x %#lx";
  char format10[] = "%#30.10x %#30.10lx";
  char format11[] = "%030x";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678, 8765432112345678);
  sprintf(str_orig, format1, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345678, 8765432112345678);
  sprintf(str_orig, format2, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345678, 8765432112345678);
  sprintf(str_orig, format3, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345678, 8765432112345678);
  sprintf(str_orig, format4, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345678, 8765432112345678);
  sprintf(str_orig, format5, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, 30, 12345678, 40, 8765432112345678);
  sprintf(str_orig, format6, 30, 12345678, 40, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 20, 12345678, 30, 8765432112345678);
  sprintf(str_orig, format7, 20, 12345678, 30, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  sprintf(str_orig, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345678, 8765432112345678);
  sprintf(str_orig, format9, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12345678, 8765432112345678);
  sprintf(str_orig, format10, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12345678, 8765432112345678);
  sprintf(str_orig, format11, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_X) {
  char format1[] = "%X %lX";
  char format2[] = "%30X %30lX";
  char format3[] = "%.10X %.10lX";
  char format4[] = "%30.10X %30.10lX";
  char format5[] = "%-30.10X";
  char format6[] = "%*X %*lX";
  char format7[] = "%.*X %.*lX";
  char format8[] = "%*.*X %*.*lX";
  char format9[] = "%#X %#lX";
  char format10[] = "%#30.10X %#30.10lX";
  char format11[] = "%030X";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678, 8765432112345678);
  sprintf(str_orig, format1, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345678, 8765432112345678);
  sprintf(str_orig, format2, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345678, 8765432112345678);
  sprintf(str_orig, format3, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345678, 8765432112345678);
  sprintf(str_orig, format4, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345678, 8765432112345678);
  sprintf(str_orig, format5, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, 30, 12345678, 40, 8765432112345678);
  sprintf(str_orig, format6, 30, 12345678, 40, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 20, 12345678, 30, 8765432112345678);
  sprintf(str_orig, format7, 20, 12345678, 30, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  sprintf(str_orig, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345678, 8765432112345678);
  sprintf(str_orig, format9, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12345678, 8765432112345678);
  sprintf(str_orig, format10, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12345678, 8765432112345678);
  sprintf(str_orig, format11, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_u) {
  char format1[] = "%u %lu";
  char format2[] = "%30u %30lu";
  char format3[] = "%.10o %.10lu";
  char format4[] = "%30.10u %30.10lo";
  char format5[] = "%-30.10u";
  char format6[] = "%*o %*lu";
  char format7[] = "%.*u %.*lu";
  char format8[] = "%*.*u %*.*lu";
  char format9[] = "%030u";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678, 8765432112345678);
  sprintf(str_orig, format1, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345678, 8765432112345678);
  sprintf(str_orig, format2, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345678, 8765432112345678);
  sprintf(str_orig, format3, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345678, 8765432112345678);
  sprintf(str_orig, format4, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345678, 8765432112345678);
  sprintf(str_orig, format5, 12345678, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, 30, 12345678, 40, 8765432112345678);
  sprintf(str_orig, format6, 30, 12345678, 40, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 20, 12345678, 30, 8765432112345678);
  sprintf(str_orig, format7, 20, 12345678, 30, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  sprintf(str_orig, format8, 40, 20, 12345678, 40, 20, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 40, 20, 12345678, 40, 20, 8765432112345678);
  sprintf(str_orig, format9, 40, 20, 12345678, 40, 20, 8765432112345678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_p) {
  char format1[] = "%p";
  char format2[] = "%30p";
  char format3[] = "%-30p";
  char format4[] = "%.20o";
  char format5[] = "%30.20p";
  char format6[] = "%-30.20p";
  char format7[] = "%*p";
  char format8[] = "%.*p";
  char format9[] = "%*.*p";
  char format10[] = "%030p";
  void *ptr = &format1;

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, ptr);
  sprintf(str_orig, format1, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, ptr);
  sprintf(str_orig, format2, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, ptr);
  sprintf(str_orig, format3, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, ptr);
  sprintf(str_orig, format4, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, ptr);
  sprintf(str_orig, format5, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 50);
  s21_memset(str_orig, '\0', 50);

  s21_sprintf(str_s21, format6, ptr);
  sprintf(str_orig, format6, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 20, ptr);
  sprintf(str_orig, format7, 20, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 20, ptr);
  sprintf(str_orig, format8, 20, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 40, 20, ptr);
  sprintf(str_orig, format9, 40, 20, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, ptr);
  sprintf(str_orig, format10, ptr);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_n_percent) {
  int a_s21, a_orig;
  char str_s21[30] = "\0";
  char str_orig[30] = "\0";
  s21_sprintf(str_s21, "test%n %%", &a_s21);
  sprintf(str_orig, "test%n %%", &a_orig);
  ck_assert_str_eq(str_s21, str_orig);
  ck_assert_int_eq(a_s21, a_orig);
}
END_TEST

START_TEST(sprintf_f) {
  char format1[] = "%f %Lf %f %Lf";
  char format2[] = "%20f %20Lf %20f %20Lf";
  char format3[] = "-+ #024f %-+ #024Lf -+ #024f %-+ #024Lf";
  char format4[] = "%- .12f %- .12Lf %- .12f %- .12Lf";
  char format5[] = "%+ 0.0f %+ 0.0Lf %+ 0.0f %+ 0.0Lf";
  char format6[] = "%*f %*Lf %*f %*Lf";
  char format7[] = "%.*f %.*Lf %.*f %.*Lf";
  char format8[] = "%+015.8f %+015.8f";
  char format9[] = "%-+ #0f %-+ #0f";
  char format10[] = "% 24.8f| |% 24.8f";
  char format11[] = "%- 24f| |%+ 24f";
  char format12[] = "%+024f % 024f";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 12345.678, -12345.678);
  sprintf(str_orig, format8, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345.678, -12345.678);
  sprintf(str_orig, format9, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12.345678123, -12.345678123);
  sprintf(str_orig, format10, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12.345678123, -12.345678123);
  sprintf(str_orig, format11, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format12, 12.345678123, -12.345678123);
  sprintf(str_orig, format12, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_e) {
  char format1[] = "%e %Le %e %Le";
  char format2[] = "%20e %20Le %20e %20Le";
  char format3[] = "-+ #024e %-+ #024Le -+ #024e %-+ #024Le";
  char format4[] = "%- .12e %- .12Le %- .12e %- .12Le";
  char format5[] = "%+ 0.0e %+ 0.0Le %+ 0.0e %+ 0.0Le";
  char format6[] = "%*e %*Le %*e %*Le";
  char format7[] = "%.*e %.*Le %.*e %.*Le";
  char format8[] = "%+015.8e %+015.8e";
  char format9[] = "%-+ #0e %-+ #0e";
  char format10[] = "% 24.8e % 24.8e";
  char format11[] = "|%- 24e| |%+ 24e|";
  char format12[] = "%+024e % 024e";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 12345.678, -12345.678);
  sprintf(str_orig, format8, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345.678, -12345.678);
  sprintf(str_orig, format9, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12.345678123, -12.345678123);
  sprintf(str_orig, format10, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12.345678123, -12.345678123);
  sprintf(str_orig, format11, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format12, 12.345678123, -12.345678123);
  sprintf(str_orig, format12, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_E) {
  char format1[] = "%E %LE %E %LE";
  char format2[] = "%20E %20LE %20E %20LE";
  char format3[] = "-+ #024E %-+ #024LE -+ #024E %-+ #024LE";
  char format4[] = "%- .12E %- .12LE %- .12E %- .12LE";
  char format5[] = "%+ 0.0E %+ 0.0LE %+ 0.0E %+ 0.0LE";
  char format6[] = "%*E %*LE %*E %*LE";
  char format7[] = "%.*E %.*LE %.*E %.*LE";
  char format8[] = "%+015.8E %+015.8E";
  char format9[] = "%-+ #0E %-+ #0E";
  char format10[] = "% 24.8E % 24.8E";
  char format11[] = "%- 24E %+ 24E";
  char format12[] = "%+024E % 024E";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format1, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 12345.678, -12345.678);
  sprintf(str_orig, format8, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345.678, -12345.678);
  sprintf(str_orig, format9, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12.345678123, -12.345678123);
  sprintf(str_orig, format10, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12.345678123, -12.345678123);
  sprintf(str_orig, format11, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format12, 12.345678123, -12.345678123);
  sprintf(str_orig, format12, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_g) {
  char format1[] = "|%g| |%Lg| |%g| |%Lg|";
  char format2[] = "%20g %20Lg %20g %20Lg";
  char format3[] = "-+ #024g %-+ #024Lg -+ #024g %-+ #024Lg";
  char format4[] = "%- .12g %- .12Lg %- .12g %- .12Lg";
  char format5[] = "%+ 0.0g %+ 0.0Lg %+ 0.0g %+ 0.0Lg";
  char format6[] = "%*g %*Lg %*g %*Lg";
  char format7[] = "%.*g %.*Lg %.*g %.*Lg";
  char format8[] = "%+015.8g %+015.8g";
  char format9[] = "%-+ #0g %-+ #0g";
  char format10[] = "% 24.8g % 24.8g";
  char format11[] = "%- 24g %+ 24g";
  char format12[] = "%+024g % 024g";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678.678, 12345678.678L, -12345678.678,
              -12345678.678L);
  sprintf(str_orig, format1, 12345678.678, 12345678.678L, -12345678.678,
          -12345678.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 12345.678, -12345.678);
  sprintf(str_orig, format8, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345.678, -12345.678);
  sprintf(str_orig, format9, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12.345678123, -12.345678123);
  sprintf(str_orig, format10, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12.345678123, -12.345678123);
  sprintf(str_orig, format11, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format12, 12.345678123, -12.345678123);
  sprintf(str_orig, format12, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

START_TEST(sprintf_G) {
  char format1[] = "%G %LG %G %LG";
  char format2[] = "%20G %20LG %20G %20LG";
  char format3[] = "-+ #024G %-+ #024LG -+ #024G %-+ #024LG";
  char format4[] = "%- .12G %- .12LG %- .12G %- .12LG";
  char format5[] = "%+ 0.0G %+ 0.0LG %+ 0.0G %+ 0.0LG";
  char format6[] = "%*G %*LG %*G %*LG";
  char format7[] = "%.*G %.*LG %.*G %.*LG";
  char format8[] = "%+015.8G %+015.8G";
  char format9[] = "%-+ #0G %-+ #0G";
  char format10[] = "% 24.8G % 24.8G";
  char format11[] = "%- 24G %+ 24G";
  char format12[] = "%+024G % 024G";

  char *str_s21 = calloc(100, sizeof(char));
  char *str_orig = calloc(100, sizeof(char));

  s21_sprintf(str_s21, format1, 12345678.678, 12345678.678L, -12345678.678,
              -12345678.678L);
  sprintf(str_orig, format1, 12345678.678, 12345678.678L, -12345678.678,
          -12345678.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format2, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format3, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format4, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  sprintf(str_orig, format5, 12345.678, 12345.678L, -12345.678, -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format6, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678,
              10, -12345.678L);
  sprintf(str_orig, format7, 10, 12345.678, 10, 12345.678L, 10, -12345.678, 10,
          -12345.678L);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format8, 12345.678, -12345.678);
  sprintf(str_orig, format8, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format9, 12345.678, -12345.678);
  sprintf(str_orig, format9, 12345.678, -12345.678);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format10, 12.345678123, -12.345678123);
  sprintf(str_orig, format10, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format11, 12.345678123, -12.345678123);
  sprintf(str_orig, format11, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  s21_sprintf(str_s21, format12, 12.345678123, -12.345678123);
  sprintf(str_orig, format12, 12.345678123, -12.345678123);
  ck_assert_str_eq(str_s21, str_orig);
  s21_memset(str_s21, '\0', 100);
  s21_memset(str_orig, '\0', 100);

  free(str_s21);
  free(str_orig);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("test_string");
  TCase *test = tcase_create("test_string");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, test);
  tcase_add_test(test, strlen_test);
  tcase_add_test(test, strcmp_test);
  tcase_add_test(test, strncmp_test);
  tcase_add_test(test, strcpy_test);
  tcase_add_test(test, strncpy_test);
  tcase_add_test(test, strcat_test);
  tcase_add_test(test, strncat_test);
  tcase_add_test(test, strchr_test);
  tcase_add_test(test, strrchr_test);
  tcase_add_test(test, memcmp_test);
  tcase_add_test(test, memchr_test);
  tcase_add_test(test, memcpy_test);
  tcase_add_test(test, memmove_test);
  tcase_add_test(test, memset_test);
  tcase_add_test(test, strcspn_test);
  tcase_add_test(test, strspn_test);
  tcase_add_test(test, strpbrk_test);
  tcase_add_test(test, strstr_test);
  tcase_add_test(test, strtok_test);
  tcase_add_test(test, strerror_test);
  tcase_add_test(test, to_upper_test);
  tcase_add_test(test, to_lower_test);
  tcase_add_test(test, insert_test);
  tcase_add_test(test, trim_test);
  tcase_add_test(test, sprintf_c);
  tcase_add_test(test, sprintf_s);
  tcase_add_test(test, sprintf_o);
  tcase_add_test(test, sprintf_d);
  tcase_add_test(test, sprintf_i);
  tcase_add_test(test, sprintf_x);
  tcase_add_test(test, sprintf_X);
  tcase_add_test(test, sprintf_u);
  tcase_add_test(test, sprintf_p);
  tcase_add_test(test, sprintf_n_percent);
  tcase_add_test(test, sprintf_f);
  tcase_add_test(test, sprintf_e);
  tcase_add_test(test, sprintf_E);
  tcase_add_test(test, sprintf_g);
  tcase_add_test(test, sprintf_G);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
