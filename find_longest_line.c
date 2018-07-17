#include <stdio.h>

#define  MAXLINE  1000  /* maximum input line size */

char line[MAXLINE];  /* input line */
char save[MAXLINE];  /* longest line saved here */
int max;  /* length of longest line seen so far */

int main()		/* find longest line; specialized version */
{
	int len;
	extern int max;
	extern char save[];

	int my_getline();
	int my_copy();

	max = 0;
	while ((len = my_getline()) > 0 )
		if (len > max) {
			max = len;
			my_copy();
		}
	if (max > 0)  /* there was a line */
		printf ("%s", save );

	return(0);
}

int my_getline()	/* specialized version */
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1
		&& (c = getchar()) != EOF && c != '\n'; ++i)
			line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return(i);
}

int my_copy()  /* specialized version */
{
	int i;
	extern char line[], save [];

	i = 0;
	while ((save[i] = line[i]) != '\0')
		++i;

	return(0);
}
