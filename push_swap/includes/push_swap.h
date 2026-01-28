/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:45:27 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/28 22:42:16 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
	int expected_index;
	int index;
} t_node;

// Lists
void insert_back(t_node **node, int content);
void insert_front(t_node **node, int content);
void clean_list(t_node **node);
int size_list(t_node **node);
t_node *last_node(t_node **node);

// Parsing
int check_num(int ac, char **av);
int is_numeric(char *str);
long long ft_atol(char *nptr);
t_node *get_num(int ac, char **av);
int is_digit(char c);
int is_numeric(char *str);

// Utils
void get_expected_index(t_node **stack);
int get_min(t_node **stack);
int is_sorted(t_node **stack);
void get_actual_index(t_node **stack);
int get_chunks(t_node **stack_a);
t_node *get_min_node(t_node **stack);
int	abs_value(int nb);

// Operations
void swap_stack(t_node **stack, char c, int print);
void swap_both(t_node **stack_a, t_node **stack_b, int print);
void push_a(t_node **stack_a, t_node **stack_b, int print);
void push_b(t_node **stack_a, t_node **stack_b, int print);
void rotate_stack(t_node **stack, char c, int print);
void rotate_both(t_node **stack_a, t_node **stack_b, int print);
void reverse_rotate_stack(t_node **stack, char c, int print);
void reverse_rotate_both(t_node **stack_a, t_node **stack_b,
						 int print);

// Sort small
void sort_2_nb(t_node **stack_a);
void sort_3_nb(t_node **stack_a);
void sort_4_nb(t_node **stack_a, t_node **stack_b);

// Sort
void push_chunks_to_b(t_node **stack_a, t_node **stack_b);
void	sorting(t_node **stack_a, t_node **stack_b);
void	rotate_to_min(t_node **stack_a);

#endif