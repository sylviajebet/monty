#include "monty.h"

/**
 * textfile_to_array - reads a text file and prints it to the POSIX
 * standard output
 * @filename: pointer to the file name
 * Return:  the actual number of letters it could read and print
*/

line_t *textfile_to_array(const char *filename)
{
FILE *file = fopen(filename, "r");
char *lineBuffer = NULL;
size_t size = 0;
int lineNumber = 0;
line_t *lines;
line_t *tmp;

if (filename == NULL)
	return (0);
if (file == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

lines = NULL;
while (getline(&lineBuffer, &size, file) != -1)
{

	tmp = realloc(lines, sizeof(line_t) * (lineNumber + 2));
	if (tmp == NULL)
	{
		fclose(file);
		return (0);
	}
	lines = tmp;

	(lines + lineNumber)->content = strdup(lineBuffer);
	(lines + lineNumber)->number = lineNumber;
	lineNumber++;
	tmp = lines;
}

free(lineBuffer);
(lines + lineNumber)->content = NULL;
fclose(file);
return (lines);
}
