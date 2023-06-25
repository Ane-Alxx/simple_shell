#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define REBUF_LEN 1024
#define WIBUF_LEN 1024
#define FLUSH_BUFFER -1


#define NORM_COM 0
#define OR_COM  1
#define AND_COM 2
#define CHAIN_COM 3


#define LOWER_CONV 1
#define UNSIGNED_CONV 2


#define LINE_USE 0
#define STROKE_USE 0

#define FILE_STORY  ".simple_shell_history"
#define MAX_STORY  4096

extern char **environ;


/**
* struct sting_show - structure for list
* @m: the number field
* @stringy: a string
* @nxt: next node pointer
*/
typedef struct string_show
{
	int m;
	char *stringy;
	struct string_show *nxt;
} list_t;

/**
* struct info_put - function for
* @arg: an argument
* @argv:an argument
* @path: a path
* @argc: an argument counter
* @error_store: store number of errors
* @error_code: error code keeper
* @countln: line count
* @file_name: filename
* @env: local environ
* @environ: another one
* @histy: node
* @alyas: node
* @env_status: status
* @state: state
* @com_buffer: command
* @com_buffer_type: symbol
* @rfd: tread
* @history_clock: keep track of count
*/
typedef struct info_put
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int error_store;
	int err_code;
	int countln;
	char *file_name;
	list_t *env;
	list_t *histy;
	list_t *alyas;
	char **environ;
	int env_status;
	int state;

	char **com_buffer; 
	int com_buffer_type;
	int rfd;
	int history_clock;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
* struct prefab - contains a prefab string
* @flag_type: command flag
* @subroutine: function
*/
typedef struct prefab
{
	char *flag_type;
	int (*subroutine)(info_t *);
} builtin_table;


int hasher(info_t *, char **);
int search_prefab(info_t *);
void search_com(info_t *);
void com_branch(info_t *);


int com_on(info_t *, char *);
char *c_doubles(char *, int, int);
char *pathfinder(info_t *, char *, char *);


int sh_loop(char **);


void _envputs(char *);
int _envputchar(char);
int _fdput(char c, int fd);
int _fdputs(char *str, int fd);


int _strlen(char *);
int _strcmp(char *, char *);
char *begin_char(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


char **string_token(char *, char *);
char **string_tokens(char *, char);


char *_memset(char *, char, unsigned int);
void file_free(char **);
void *_realloc(void *, unsigned int, unsigned int);


int buf_free(void **);


int active(info_t *);
int delimeter_on(char, char *);
int _isalpha(int);
int _atoi(char *);


int _erroratoi(char *);
void p_error(info_t *, char *);
int p_d(int, int);
char *c_num(long int, int, int);
void del_coms(char *);


int _unikexit(info_t *);
int _unikcd(info_t *);
int _unikhelp(info_t *);

int _unikhistory(info_t *);
int _unikalias(info_t *);

ssize_t fetch_in(info_t *);
int _fetch_ln(info_t *, char **, size_t *);
void sign_boss(int);

void info_clr(info_t *);
void info_st(info_t *, char **);
void info_f(info_t *, int);

char *_getenv(info_t *, const char *);
int _unikenv(info_t *);
int _uniksetenv(info_t *);
int _unikunsetenv(info_t *);
int fill_envlist(info_t *);

char **getenviron(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_histy_file(info_t *info);
int write_histy(info_t *info);
int read_histy(info_t *info);
int build_histy_list(info_t *info, char *buf, int linecount);
int renumber_histy(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_nodeend(list_t **, const char *, int);
size_t print_liststr(const list_t *);
int del_node(list_t **, unsigned int);
void free_list(list_t **);


size_t list_lenny(const list_t *);
char **list_to_str(list_t *);
size_t p_list(const list_t *);
list_t *node_s(list_t *, char *, char);
ssize_t get_nodeindex(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void c_chain(info_t *, char *, size_t *, size_t, size_t);
int r_alias(info_t *);
int r_vars(info_t *);
int r_str(char **, char *);

#endif
