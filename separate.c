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
usage ()
{
  fprintf (stderr,
	   "Tokenize stdin, stdout is one token/line, whitespace encoded.\n");
  fprintf (stderr, "Usage: separate < file-to-tokenize > token-file\n");
  fprintf (stderr, "Example: (echo a man, a; echo plan)|separate\n");
}

inline int
putss (char *s)
{
  return fputs (s, stdout);
}


int
main (int argc, char *argv[])
{
  if (argc != 1)
    {
      usage ();
      exit (1);
    }

  char temp = 0;
  int i = 0;
  int ch;

  while ((ch = getchar ()) != EOF)
    {
#ifndef NDEBUG
      fprintf (stderr, "(%c)", ch);
#endif

     if (i == 0 && ((isalpha (ch))))
	{
	  putchar (ch);
	}
     else if (i == 0 && (!(isalpha (ch))) && ch != ' ' && ch !='\t' && ch !='\n')
	{
	  putchar (ch);
	}


      else if (ch == '\t' && (isalpha (temp)))
	{
	  putss (": ");
	  putss ("%9");
	}

      else if (ch == ' ' && temp == '\t'){
	  putss ("%32");
	}

      else if(ch == '\t' && temp == '\t'){
	  putss ("%9");
	}

      else if (ch == '\t' && (!(isalpha (temp))) && (temp != ' '))
	{
	  putss (": ");
	  putss ("%9");
	}

      else if ((isalpha (temp)) && ch == '\n')
	{
	  putss (": ");
	  putss ("%13");
	  putchar ('\n');

	}
      else if (!(isalpha (temp)) && (temp != ' ') && ch == '\n')
	{
	  putss (": ");
	  putss ("%13");
	  putchar ('\n');

	}

      else if (temp == ' ' && ch == '\n')
	{
	  putss ("%13");
	  putchar ('\n');

	}
      else if (ch == '\n')
	{
	  putss (": ");
	  putss ("%13");
	  putchar ('\n');

	}
      else if (ch == '\t')
	{
	  putss ("%9");
	}
 	else if (temp == '\t' && isalpha (ch))
	{
	  putchar ('\n');
	  putchar (ch);
	}
      else if (temp == '\t' && (!isalpha (ch) && (ch != ' ')))
	{
	   putchar ('\n');
	  putchar (ch);
	}
      else if (temp == '\n' && isalpha (ch))
	{
	  putchar (ch);
	}
	else if(temp == '\n' && ch == ' ')
	{
	  putss (": ");
	  putss ("%32");
	}
      else if (temp == '\n' && (!isalpha (ch)) && (ch != ' '))
	{
	  putchar (ch);
	}
      else if (temp == ' ' && (isalpha (ch)))
	{
	  putchar ('\n');
	  putchar (ch);
	}

	

      else if ((!(isalpha (temp))) && (temp != ' ') && (isalpha (ch)))
	{
	  if (temp == ':'){
	  putchar(':');
	  }
	  if (temp == '%'){
	  putchar(':');
	  }
	  putchar ('\n');
	  putchar (ch);
	}
      else if (isalpha (ch))
	{
	  putchar (ch);
	}

      else if ((isalpha (temp)) && ch == ' ')
	{
	  putss (": ");
	  putss ("%32");

	}
      else if ((!(isalpha (temp))) && temp != ' ' && ch == ' ')
	{
	  putss (": ");
	  putss ("%32");
	}
	else if ((isalpha (temp)) && ch == ' ')
	{
	  putss (": ");
	  putss ("%32");

	}
	else if ((!(isalpha (temp))) && (temp != ' ') && ch == ' ')
	{
	  putss (": ");
	  putss ("%32");

	}
      else if (ch == ' ')
	{
	  putss ("%32");
	}
      else if ((!(isalpha (ch))) && (ch != ' ') && temp == ' ')
	{
	  putchar ('\n');
	  putchar (ch);


	}

      else if ((isalpha (temp)) && (!(isalpha (ch))) && (ch != ' '))
	{
	  putchar ('\n');
	  putchar (ch);

	}
      else if (!(isalpha (temp)) && (temp != ' ') && (!(isalpha (ch))) && (ch != ' '))
	{
	  if (temp == ':'){
	  putchar(':');
	  }
	  if (temp == '%'){
	  putchar(':');
	  }	
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
