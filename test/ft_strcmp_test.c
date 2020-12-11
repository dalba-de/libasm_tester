/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:16:43 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/11 17:27:42 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"

#define	BFSIZE			0xF0000
#define STRCMP_TEST(s, s1, b)   i = ft_strcmp(s, s1); printf("|" RED "%-40s"RESET" |"GREEN"%-28d "RESET"|"PURPLE"%-28d"RESET"|\n", b, strcmp(s, s1), i);

void    ft_strcmp_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ███████╗████████╗██████╗  ██████╗████  ████╗███████═╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╔════╝╚══██╔══╝██╔══██╗██╔════╝██╔████═██║██╔═══██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║        ███████╗   ██║   ██████╔╝██║     ██║ ██  ██║███████═╝    ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║        ╚════██║   ██║   ██╔══██╗██║     ██║     ██║██║          ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗███████║   ██║   ██║  ██║╚██████╗██║     ██║██║          ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝╚═╝     ╚═╝╚═╝          ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					by dalba-de			\n\n");
	printf("" CYAN"Testeando función "PURPLE"'FT_STRCMP' "RESET""CYAN"espere...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-43s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "STRCMP", "FT_STRCMP");
	printf(" ");
	while (i++ < 100)
		printf("_");
	printf(" ");
	printf("\n");

	char *s;
	char *s1;

	// No diff test
	STRCMP_TEST("", "", "Empty string");
	STRCMP_TEST("hola", "hola", "hola");
	STRCMP_TEST("abcdefghijasdf1324''klji//", "abcdefghijasdf1324''klji//", "Random characters");
	STRCMP_TEST("the\0hidden", "the\0hidden", "\\0 hidden");
	STRCMP_TEST("Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.",
	"Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.", "Long String");
	STRCMP_TEST("\x01", "\x01", "Hexadecimal input");

	// Diff test
	s = "hola";
	s1 = "";
	STRCMP_TEST(s, s1, "hola / Empty string");
	s = "asdklfjasdfj////asdf'''asdf3##";
	s1 = "";
	STRCMP_TEST(s, s1, "Random characters / Empty string");
	s = "the\0hidden";
	s1 = "";
	STRCMP_TEST(s, s1, "\\0 hidden / Empty string");
	s = "Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.";
	s1 = "";
	STRCMP_TEST(s, s1, "Long string / Empty string");
	s = "";
	s1 = "hola";
	STRCMP_TEST(s, s1, "Empty string / hola");
	s = "hola";
	s1 = "ho";
	STRCMP_TEST(s, s1, "hola / ho");
	s = "hola";
	s1 = "ola";
	STRCMP_TEST(s, s1, "hola / ola");
	s = "the\0hidden";
	s1 = "thehidden";
	STRCMP_TEST(s, s1, "\\0 hidden / thehidden");
	s = "\x02";
	s1 = "\x01";
	STRCMP_TEST(s, s1, "\\x02 / \\x01 (hexadecimal)");
	s = "\xff";
	s1 = "\xfe";
	STRCMP_TEST(s, s1, "\\xff / \\xfe (hexadecimal)");
	s = "\x01\x01";
	s1 = "\x01";
	STRCMP_TEST(s, s1, "\\x01\\x01 / \\x01 (hexadecimal)");
	s = "\x01";
	s1 = "\x01\x01";
	STRCMP_TEST(s, s1, "\\x01 / \\x01\\x01 (hexadecimal)");
	s = "\0";
	s1 = "\200";
	STRCMP_TEST(s, s1, "\\0 / \\200 (Unsigned test)");
	s = "\x12\xff\x65\x12\xbd\xde\xad";
	s1 = "\x12\x02";
	STRCMP_TEST(s, s1, "Ascii char test");
	
	//Speed test
	size_t	size = BFSIZE * 4;
	s = malloc(size + 1);
	s1 = malloc(size + 1);
	memset(s, 'A', size);
	memset(s1, 'A', size);
	s[size] = s1[size] = 0;
	STRCMP_TEST(s, s1, "Speed test");
	
	i = 0;
	printf("|");
	while (i++ < 41)
		printf("_");
	printf("|");
	while (i++ < 71)
		printf("_");
	printf("|");
	while (i++ < 100)
		printf("_");
	printf("|");
	printf("\n\n");
}
