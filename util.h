/* See LICENSE file for copyright and license details. */
#ifndef UTIL
#define UTIL

#define CMDLENGTH		50
#define STATUSLENGTH (LENGTH(blocks) * CMDLENGTH + 1)

#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))
#define LENGTH(X)               (sizeof X / sizeof X[0])

#include <stddef.h>

void die(const char *fmt, ...);
void *ecalloc(size_t nmemb, size_t size);

#endif /* UTIL */
