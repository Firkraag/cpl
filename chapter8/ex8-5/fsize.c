#include "dirent.h"

static int isDir(struct stat *bufptr);

int main(int argc, char **argv) {
	if (argc == 1)
		fsize(".");
	else 
		while (--argc > 0) 
			fsize(*++argv);
	return 0;
}

void fsize(char *filename) {
	struct stat stbuf;
    void printInfo(struct stat *bufptr, char *filename);
    
	if (stat(filename, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", filename);
		return;
	}
	if (isDir(&stbuf))
		dirwalk(filename, fsize);
    printInfo(&stbuf, filename);
}

void dirwalk(char *dir, void (*fcn)(char *)) {
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
    while (1) {
        dp = readdir(dfd);
        if (dp == NULL) {
            if (errno)
                fprintf(stderr, "dirwalk: error encountered while reading directory %s\n", dir);
            break;
        }
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;
		if ((strlen(dir) + strlen(dp->name) + 2) > sizeof(name))
			fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}


static int isDir(struct stat *bufptr) {
    return (bufptr->st_mode & S_IFMT) == S_IFDIR;  
}


DIR *opendir(char *dirname) {
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	dp->nread = -2;
	dp->bpos = 0;
	return dp;
}	

void closedir(DIR *dp) {
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

Dirent *readdir(DIR *dp) {
	struct linux_dirent {
	   long           d_ino;
	   off_t          d_off;
	   unsigned short d_reclen;
	   char           d_name[];
	} *dirbuf;
	static Dirent d;

	if (dp->nread == -2)	
        //Can't apply read to directory, so use getdents to implement readdir
		dp->nread = syscall(SYS_getdents, dp->fd, dp->buf, BUF_SIZE);
    if (dp->nread == -1) {
        perror("readdir");
        errno = EBADF;
        return NULL;
    }
	else if (dp->nread == 0)
		return NULL;
	dirbuf = (struct linux_dirent *) (dp->buf + dp->bpos);
	d.ino  = dirbuf->d_ino;
	strncpy(d.name, dirbuf->d_name, NAME_MAX);
	d.name[strlen(dirbuf->d_name) < NAME_MAX ? strlen(dirbuf->d_name) : NAME_MAX ] = '\0';
	dp->bpos += dirbuf->d_reclen;
    
	if (dp->bpos >= dp->nread) {
		dp->bpos = 0;
		dp->nread = -2;
	}
	return &d;
}
