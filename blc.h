/* BLC - Binary Lambda Calculus VM and DSL on top of it
 * Copyright (C) 2013  Jan Wedekind
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
#ifndef __BLC_H
#define __BLC_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stdio.h>

int gc_push(int expression);

void gc_pop(int n);

int read_expression(int input);

int eval_expression(int expression, int local_env);

void print_expression(int expression, FILE *file);

void print_variable(int variable, FILE *file);

int make_input(FILE *file);

int make_false(void);

int make_true(void);

int make_pair(int first, int second);

int first(int list);

int second(int list);

#endif

