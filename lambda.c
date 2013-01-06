/* Bracket - Attempt at writing a small Racket (Scheme) interpreter
 * Copyright (C) 2012  Jan Wedekind
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */
#include <ctype.h>
#include "lambda.h"

#define NAMEBUFSIZE 65536

char names[NAMEBUFSIZE];
char *name_p = names;

typedef enum {QUIT = 0, INIT, MINUS, LAMBDA} state_t;

int compile_lambda(FILE *f_in, FILE *f_out)
{
  int retval = 0;
  state_t state = INIT;
  while (state) {
    int c = fgetc(f_in);
    switch (state) {
    case INIT:
      switch (c) {
      case '-':
        state = MINUS;
        break;
      case EOF:
        state = QUIT;
        break;
      default:
        fputc(c, f_out);
      };
      break;
    case MINUS:
      switch (c) {
      case '-':
        fputc('-', f_out);
        break;
      case '>':
        fputs("00", f_out);
        state = LAMBDA;
        break;
      case EOF:
        fputc('-', f_out);
        state = QUIT;
        break;
      default:
        fputc('-', f_out);
        fputc(c, f_out);
        state = INIT;
      };
      break;
    case LAMBDA:
      if (isalpha(c))
        *name_p++ = c;
      else {
        *name_p++ = '\0';
        switch (c) {
        case EOF:
          state = QUIT;
          break;
        case '.':
          state = INIT;
          break;
        default:
          fputc(c, f_out);
          state = INIT;
        };
      };
      break;
    default:
      break;
    };
    fflush(f_out);
  };
  return retval;
}

