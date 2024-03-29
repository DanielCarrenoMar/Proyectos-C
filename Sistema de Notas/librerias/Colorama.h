#ifndef _COLORAMA_H_
#define _COLORAMA_H_

#ifdef _WIN32
void just_fix_windows_console();
#include "Colorama.c"
#endif

#define Style_RESET_ALL "\x1b[0m"
#define Style_BRIGHT    "\x1b[1m"
#define Style_DIM       "\x1b[2m"
#define Style_NORMAL    "\x1b[22m"

#define Fore_BLACK "\x1b[30m"
#define Fore_RED "\x1b[31m"
#define Fore_GREEN "\x1b[32m"
#define Fore_YELLOW "\x1b[33m"
#define Fore_BLUE "\x1b[34m"
#define Fore_MAGENTA "\x1b[35m"
#define Fore_CYAN "\x1b[36m"
#define Fore_WHITE "\x1b[37m"
#define Fore_LIGHTBLACK_EX "\x1b[90m"
#define Fore_LIGHTRED_EX "\x1b[91m"
#define Fore_LIGHTGREEN_EX "\x1b[92m"
#define Fore_LIGHTYELLOW_EX "\x1b[93m"
#define Fore_LIGHTBLUE_EX "\x1b[94m"
#define Fore_LIGHTMAGENTA_EX "\x1b[95m"
#define Fore_LIGHTCYAN_EX "\x1b[96m"
#define Fore_LIGHTWHITE_EX "\x1b[97m"

#define Back_BLACK "\x1b[40m"
#define Back_RED "\x1b[41m"
#define Back_GREEN "\x1b[42m"
#define Back_YELLOW "\x1b[43m"
#define Back_BLUE "\x1b[44m"
#define Back_MAGENTA "\x1b[45m"
#define Back_CYAN "\x1b[46m"
#define Back_WHITE "\x1b[47m"
#define Back_LIGHTBLACK_EX "\x1b[100m"
#define Back_LIGHTRED_EX "\x1b[101m"
#define Back_LIGHTGREEN_EX "\x1b[102m"
#define Back_LIGHTYELLOW_EX "\x1b[103m"
#define Back_LIGHTBLUE_EX "\x1b[104m"
#define Back_LIGHTMAGENTA_EX "\x1b[105m"
#define Back_LIGHTCYAN_EX "\x1b[106m"
#define Back_LIGHTWHITE_EX "\x1b[107m"

#endif