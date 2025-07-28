#include<stdio.h>

#define HEAP_SIZE 1024
char heap_buf[HEAP_SIZE];
int pos = 0;

void *my_malloc(int size)
{
    if (pos + size > HEAP_SIZE) {
        // 超過記憶體池大小
        printf("my_malloc: out of memory!\n");
        return NULL;
    }

    int old_pos = pos;
    pos += size;
    return &heap_buf[old_pos];
}

void c_fun(void)
{

}

void b_fun(void)
{

}

int a_fun(int val)
{
    int a = 8;
    a += val;

    b_fun();

    c_fun();

    return a;
}

int main(){
    char ch = 65; // char ch = 'A'
    int i = 0;
    char *buf = my_malloc(100);
    //char *buf = (char *)my_malloc(sizeof(*buf)*100);
    //char *buf = (char *)my_malloc(sizeof(char)*100);
    unsigned char uch = 200;

    for (i = 0; i < 26; i++)
    {
        buf[i] = 'A' + i;
        printf("buf[%d] = %c, &buf[%d] = %x\n", i, buf[i], i, buf);
    }
    
    a_fun(46);

    return 0;
}