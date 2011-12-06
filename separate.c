#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// tokenises standard input, emitting one line/token, with trailing
// whitespace (possibly empty) following each token represented by a
// colon followed by percent-encoded ascii.

// Example, input:

//   The quick, brown
// fox  jumps! over

// generated output:

// :%32%32
// The:%32
// quick:
// ,:%32
// brown:%13
// fox:%32%32
// jumps:
// !:%32
// over:%13

// Note: compile with -DNDEBUG to turn off debugging chatter.

void
usage()
{
  fprintf(stderr, "Tokenize stdin, stdout is one token/line, whitespace encoded.\n");
  fprintf(stderr, "Usage: separate < file-to-tokenize > token-file\n");
  fprintf(stderr, "Example: (echo a man, a; echo plan)|separate\n");
}


int
main (int argc, char *argv[])
{
  if (argc != 1)
    {
      usage();
      exit(1);
    }

  char temp;
  int i = 0;
  int ch;

  while ((ch = getchar ()) != EOF)
    {
#ifndef NDEBUG
      fprintf (stderr, "(%c)", ch);
#endif
      if (ch == '\t' && (isalpha (temp)))
	{
	  puts (": ");
	  puts ("%9");
	}
      else if (i == 0 && (isalpha (ch)))
	{
	  putchar (ch);
	}
      else if ((isalpha (temp)) && ch == '\n')
	{
	  puts (": ");
	  puts ("%13");
	  putchar ('\n');

	}
      else if (!(isalpha (temp)) && ch == '\n')
	{
	  puts (": ");
	  puts ("%13");
	  putchar ('\n');

	}
      else if (temp == ' ' && ch == '\n')
	{
	  puts ("%13");
	  putchar ('\n');

	}
      else if (ch == '\n')
	{
	  puts (": ");
	  puts ("%13");
	  putchar ('\n');

	}
      else if (temp == '\n' && isalpha (ch))
	{
	  putchar (ch);
	}
      else if (temp == '\n' && (!isalpha (ch)))
	{
	  putchar (ch);
	}
      else if (temp == ' ' && (isalpha (ch)))
	{
	  putchar ('\n');
	  putchar (ch);
	}

      else if ((!(isalpha (temp))) && (isalpha (ch)))
	{
	  putchar ('\n');
	  putchar (ch);
	}
      else if (isalpha (ch))
	{
	  putchar (ch);
	}

      else if ((isalpha (temp)) && ch == ' ')
	{
	  puts (": ");
	  puts ("%32");

	}
      else if ((!(isalpha (temp))) && temp != ' ' && ch == ' ')
	{
	  puts (": ");
	  puts ("%32");
	}
      else if (ch == ' ')
	{
	  puts ("%32");
	}
      else if ((!(isalpha (ch))) && temp == ' ')
	{
	  putchar ('\n');
	  putchar (ch);


	}

      else if ((isalpha (temp)) && (!(isalpha (ch))))
	{
	  putchar ('\n');
	  putchar (ch);

	}
      else if (!(isalpha (temp)) && (!(isalpha (ch))))
	{
	  putchar ('\n');
	  putchar (ch);

	}

      else
	{
	  putchar (ch);
	}

      temp = ch;
      i++;
    }
}
