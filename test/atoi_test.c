/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 08:42:56 by dalba-de          #+#    #+#             */
/*   Updated: 2020/06/22 02:25:47 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm_bonus.h"

# define ATOI_BASE(s, b)	i = ft_atoi_base(s, b); printf("|" RED "%-28s"RESET" |"GREEN"%-28s "RESET"|"PURPLE"%-28d"RESET"|\n", s, b, i);

void	ft_atoi_alpha_test()
{
	printf("" CYAN"Checking "PURPLE"'ATOI BASE' "RESET""CYAN" function with alphabetic base, please wait...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-31s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "BASE", "RESULT");
	printf(" ");
	while (i++ < 88)
		printf("_");
	printf(" ");
	printf("\n");
	ATOI_BASE("test", "incorrecta");
	ATOI_BASE("test", "tambien incorrecta");
	ATOI_BASE("test", "+test");
	ATOI_BASE("test", "-test");
	ATOI_BASE("test", "  con espacios");
	ATOI_BASE("test", "te");
	ATOI_BASE("ff", "abcc");
	ATOI_BASE("ff", "a");
	ATOI_BASE("a\0bb", "ab");
	ATOI_BASE("-b\0bb", "ab");
	ATOI_BASE("poney", "poney");
	ATOI_BASE("yenop", "poney");
	ATOI_BASE("oo", "poney");
	ATOI_BASE("--+--+opney", "poney");
	ATOI_BASE("--+-+opney", "poney");
	ATOI_BASE(" --+--+opney", "poney");
	ATOI_BASE("--+--+  opney", "poney");
	ATOI_BASE("poneyland", "poney");
	ATOI_BASE("yyyyyyyyyyy", "poney");
	i = 0;
	printf("|");
	while (i++ < 88)
		printf("_");
	printf("|");
	printf("\n\n");
}

void	ft_atoi_test()
{
	printf(""CYAN"\n\n \
			    ██═╗ ████████╗ ██████═╗██╗ ████████╗███████╗███████╗████████╗\n \
			   ████╚╗╚══██╔══╝██╔═══██║██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			  ██╔═██╚╗  ██║   ██║   ██║██║    ██║   █████╗  ███████╗   ██║\n \
			 ████████║  ██║   ██║   ██║██║    ██║   ██╔══╝  ╚════██║   ██║\n \
			 ██╔═══██║  ██║    ██████╔╝██║    ██║   ███████╗███████║   ██║\n \
			 ╚═╝   ╚═╝  ╚═╝    ╚═════╝ ╚═╝    ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
								\n\n");
	printf("" CYAN"Checking "PURPLE"'ATOI BASE' "RESET""CYAN" function with number base, please wait...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-31s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "BASE", "RESULT");
	printf(" ");
	while (i++ < 88)
		printf("_");
	printf(" ");
	printf("\n");
	ATOI_BASE("''", "''");
	ATOI_BASE("10", "''");
	ATOI_BASE("''", "01");
	ATOI_BASE("123", "0123456789");
	ATOI_BASE("101", "01");
	ATOI_BASE("ffe0", "0123456789abcdef");
	ATOI_BASE("         4", "01234");
	ATOI_BASE("45", "''");
	ATOI_BASE("45", "0");
	ATOI_BASE("45", "01");
	ATOI_BASE("10", "011");
	ATOI_BASE("10", "0+");
	ATOI_BASE("10", "-0");
	ATOI_BASE("10111", "  541");
	ATOI_BASE("10111", "98  541");
	ATOI_BASE("10111", "7  541");
	ATOI_BASE("10111", "0  541");
	ATOI_BASE("10111", "1  541");
	ATOI_BASE("10111", "54 1");
	ATOI_BASE("111000", "01");
	ATOI_BASE("ff", "0123456789abcdef");
	ATOI_BASE("52", "01234567");
	ATOI_BASE("2a", "0123456789abcdef");
	ATOI_BASE("7fffffff", "0123456789abcdef");
	ATOI_BASE("ff", "0123-456789abcdef");
	ATOI_BASE("ff", "01  23456789abcdef");
	ATOI_BASE("ff", "''");
	ATOI_BASE("-ff", "0123456789abcdef");
	ATOI_BASE("--ff", "0123456789abcdef");
	ATOI_BASE("+--ff", "0123456789abcdef");
	ATOI_BASE("-++++++-+--ff", "0123456789abcdef");
	ATOI_BASE("-++++++-+--ff\xff", "0123456789abcdef");
	ATOI_BASE("-+  ++-+--ff\xff", "0123456789abcdef");
	ATOI_BASE("-01", "01");
	ATOI_BASE("--11101", "01");
	ATOI_BASE("+-123", "01");
	ATOI_BASE("-++++01++-+--ff", "01");
	ATOI_BASE("-++10101\xff", "01");
	ATOI_BASE("-+ ++-+--01\x01", "01");
	ATOI_BASE("     -++++++-+--ff\xff", "0123456789abcdef");
	ATOI_BASE("  -+  ++-+--ff\xff", "0123456789abcdef");
	ATOI_BASE("  -01", "01");
	ATOI_BASE("\xff--11101", "01");
	ATOI_BASE(" 755x+", "01234567");
	ATOI_BASE(" 700chmod", "01234567");
	ATOI_BASE(" 644yo", "01234567");
	ATOI_BASE("2147483647", "0123456789");
	ATOI_BASE("-2147483648", "0123456789");
	i = 0;
	printf("|");
	while (i++ < 88)
		printf("_");
	printf("|");
	printf("\n\n");
}

int main()
{
    ft_atoi_test();
	ft_atoi_alpha_test();
	return (0);
}
