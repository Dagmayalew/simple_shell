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
char *_duplicateString(char *mik);
int _convertString(char *d);
int out(char d);
void p_string(char *tsi);
int compTwoString(const char *tom, const char *hlu, size_t length);
void *anotherSize(void *tek, unsigned int arg, unsigned int adi);
void d_hand(int ante_id);
int kot_in(char *lis);
int kot_del(char *lis, char *dst);
char *rem_new(char *lis);

#endif
