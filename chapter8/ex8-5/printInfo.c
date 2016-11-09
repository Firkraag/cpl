/*************************************************************************
	> File Name: printInfo.c
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Nov 2016 04:09:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include <pwd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

static void printType(struct stat *bufptr);
static void printOwner(struct stat *bufptr);
static void printTime(struct stat *bufptr);
static void printPermission(struct stat *bufptr);
static void printSize(struct stat *bufptr);

void printInfo(struct stat *bufptr, char *filename) {
    printType(bufptr);
    printPermission(bufptr);
    putchar(' ');
    printOwner(bufptr);
    putchar(' ');
    printTime(bufptr);
    putchar(' ');
    printSize(bufptr);
	printf(" %s\n", filename);

}

static void printTime(struct stat *bufptr)
{
    char s[100];
    time_t time = bufptr->st_ctim.tv_sec;

    strftime(s, 100, "%b %d %R %G", localtime(&time));
    printf("%s", s);
}
static void printPermission(struct stat *bufptr)
{
    putchar(bufptr->st_mode & S_IRUSR ? 'r' : '-');
    putchar(bufptr->st_mode & S_IWUSR ? 'w' : '-');
    if (bufptr->st_mode & S_ISUID)
        putchar('S');
    else
        putchar(bufptr->st_mode & S_IXUSR ? 'x' : '-');
    putchar(bufptr->st_mode & S_IRGRP ? 'r' : '-');
    putchar(bufptr->st_mode & S_IWGRP ? 'w' : '-');
    if (bufptr->st_mode & S_ISGID)
        putchar('S');
    else
        putchar(bufptr->st_mode & S_IXGRP ? 'x' : '-');
    putchar(bufptr->st_mode & S_IROTH ? 'r' : '-');
    putchar(bufptr->st_mode & S_IWOTH ? 'w' : '-');
    if (bufptr->st_mode & S_ISVTX)
        putchar('t');
    else
        putchar(bufptr->st_mode & S_IXOTH ? 'x' : '-');
}

static void printOwner(struct stat *bufptr)
{
    struct passwd *pwptr1 = getpwuid(bufptr->st_uid);
    struct passwd *pwptr2 = getpwuid(bufptr->st_gid);

    printf("%s %s", pwptr1 ?  pwptr1->pw_name: "Unknown", pwptr2 ? pwptr2->pw_name:"Unknown" );
}

static void printType(struct stat *bufptr) {
    switch (bufptr->st_mode & S_IFMT) {
    case S_IFSOCK:
        putchar('s');
        break;
    case S_IFLNK:
        putchar('l');
        break;
    case S_IFREG:
        putchar('-');
        break;
    case S_IFBLK:
        putchar('b');
        break;
    case S_IFDIR:
        putchar('d');
        break;
    case S_IFCHR:
        putchar('c');
        break;
    case S_IFIFO:
        putchar('f');
        break;
    }
}

static void printSize(struct stat *bufptr) {
    printf("%8ld", bufptr->st_size);
}
