#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void my_memcpy(void *dst, const void *src, size_t size)
{
    char *c_dst = (char*)(dst);
    char *c_src = (char*)(src);
    for (int i = 0; i < size; ++i) c_dst[i] = c_src[i];
}

void *my_memcpy2(const void *src, size_t size)
{
    char *p;
    p = (char*)malloc(size * sizeof(char));
    char *c_src = (char*)(src);
    for (int i = 0; i < size; ++i) p[i] = c_src[i];
    p[size] = '\0';
    return p;
}

void *my_memchr(const void *mem, size_t size, char value)
{
    char *c_mem = (char*)(mem);
    for (int i = 0; i < size; ++i) if (c_mem[i] == value) return &c_mem[i];
    return NULL;
}

void my_memset(const void *mem, size_t size, char value)
{
    char *c_mem = (char*)(mem);
    for (int i = 0; i < size; ++i) c_mem[i] = value;
}


size_t my_strlen(const char *str)
{
    int n = 0;
    while (str[n] != '\0') ++n;
    return n;
}

int my_strcmp(const char *str1, const char *str2)
{
    int size1 = 0; int size2 = 0; int n = 0;
    while (str1[n] != '\0') {++n; size1 += (int)(str1[n]);}
    n = 0;
    while (str2[n] != '\0') {++n; size2 += (int)(str2[n]);}
    if (size1 < size2) return -1;
    if (size1 == size2) return 0;
    return 1;
}

void my_strcpy(char *dst, const char *src)
{
    char *c_src = (char*)(src);
    char *c_dst = (char*)(dst);
    for (int i = 0; i < my_strlen(c_src); ++i) c_dst[i] = c_src[i];
    c_dst[my_strlen(c_src)] = '\0';
}

char *my_strcpy2(const char *src)
{
    char *dst = (char*)(src);
    return dst;
}


void my_strcat(char *dst, const char *src)
{
    char *c_dst = (char*)(dst);
    char *c_src = (char*)(src);
    int len1 = my_strlen(c_dst);
    int len2 = my_strlen(c_src);
    for (int i = len1; i < len1 + len2; ++i) c_dst[i] = c_src[i - (len1)];
    c_dst[len1+len2] = '\0';
}


char *my_strcat2(const char *src1, const char *src2)
{
    char *st1 = (char*)src1;
    char *st2 = (char*)src2;

    int len1 = my_strlen(st1);
    int len2 = my_strlen(st2);
    char *s;
    s = (char*)malloc((len1 + len2 - 2) * sizeof(char));
    for (int i = 0; i < len1; ++i) s[i] = st1[i];
    for (int i = len1; i < len1 + len2; ++i) s[i] = st2[i - len1];
    s[len1 + len2] = '\0';
    return s;
}

char **string_split(const char *str, const char *separator)
{
    char *s = (char*)str;
    char *sep = (char*)separator;

    int len_s = my_strlen(s);
    int len_sep = my_strlen(sep);
    int c = 0;
    int w_c = 0;
    int current = 0;
    char **n;
    n = (char**)malloc(len_s * sizeof(char*));
    for (int i = 0; i < len_s; ++i) n[i] = (char*)malloc(len_s * sizeof(char));
    for (int i = 0; i < len_s; ++i)
    {
        if (s[i] == sep[c])
        {
            ++c;
            if (c == len_sep)
            {
                n[w_c][current - c + 1] = '\0';
                current = 0;
                c = 0;
                printf("%s ", n[w_c]);
                ++w_c;
                continue;
            }
        }
        else c = 0;
        n[w_c][current] = s[i];
        ++current;

    }
    n[w_c][current] = '\0';
    printf("%s", n[w_c]);
    return n;
}

int main()
{
        printf("MEMORY\n\n");


    printf("\nmy_memcpy\n");

    char *src="0123456789";
    char dst[10]="";
    memcpy (dst, src, 4*sizeof(char));
    printf ("dst: %s\n",dst);

    char my_dst[10] = "";
    my_memcpy(my_dst, src, 4*sizeof(char));
    printf("%s \n", my_dst);


    printf("\nmy_memcpy2\n");
    char *dst2 = my_memcpy2(src + 2, 4 * sizeof(char));
    printf("dst2 %s\n", dst2);

    printf("\nmy_memset\n");
    char st[100] = "Cool kids never sleep.";
    printf("\nBefore my_memset(): %s\n", st);
    my_memset(st + 10, 5*sizeof(char), '.');
    printf("After my_memset(): %s\n", st);

    printf("\nmy_memchr\n");
    char *p;
    p = memchr("stroka iz primera", ' ', 17);
    printf("%s \n", p);
    p = my_memchr("stroka iz primera", 17*sizeof(char), 'r');
    printf("%s \n", p);



    printf("\n\nSTRINGS\n\n");
    char s1[100] = "COOL KIDS";
    char s2[100] = " NEVER SLEEP";
    printf("%d \n", my_strlen(s1));
    printf("%d \n", my_strcmp(s1, s2));
    my_strcat(s1, s2);
    printf("%s \n", s1);
    char *s3 = my_strcat2(s1, s2);
    printf("%s \n", s3);
    char s4[100];
    my_strcpy(s4, s2);
    printf("%s \n", s4);
    char *s5 = my_strcpy2(s2);
    printf("%s \n", s5);

    char **mas;
    mas = string_split(s1, "NE");
    //printf("%s \n", mas[0][0]);

}
