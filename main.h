#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

extern char **environ;

char *_concat2(char *dag, char *eyu);
int _stringLength(const char *d);
int _compareStrings(char *tom, char *hlu);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_duplicateString(char *mik);
int _convertString(char *d);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int count_input(char *str);
int count_delims(char *str, char *del);
char *remove_new_line(char *str);
void signal_handler(int sig_id);
void _open_help(void);
void _print_env(void);
void _handle_exit(char **u_tokns, char *line);
int execBuiltInCommands(char **u_tokns, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tokns);
int exec(char *cname, char **opts);
char *_getenv(const char *name);
char **tokenize(char *str, char *del, int len);
char *find(char *cname);

#endif
