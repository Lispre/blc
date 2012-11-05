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
#include "boot-eval.h"

int main(void)
{
  initialize();
  while (1) {
#ifndef NDEBUG
    // fputs("----------------------------------------\n", stderr);
#endif
    int expr = read_expression(stdin);
    if (feof(stdin)) break;
#if 0
    print_expression(expr, stderr);
    fputc('\n', stderr);
#endif
    print_quoted(eval_expression(expr, environment), stdout);
#if 0
    fputc('\n', stderr);
#endif
  };
  return 0;
}