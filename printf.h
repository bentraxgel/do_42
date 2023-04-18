/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:20:05 by seok              #+#    #+#             */
/*   Updated: 2023/04/18 17:33:24 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h> //write
# include <stdarg.h> //가변인자
# include <stdlib.h> //malloc

//TODO how to ues libft?
# include "libft/libft.h"

# define SPECIFIER "cspdiuxX%"
int	my_specifier(char ch, va_list *ap);
int	my_va_int(char ch, long long num);
int	my_va_void(void *str);
int	my_print(char *str);

#endif