/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 10:06:57 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/11 17:27:57 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"

#define	BFSIZE			0xF0000
#define STRDUP_TEST(s, m)   printf("|" RED "%-28s"RESET" |"GREEN"%-28s "RESET"|"PURPLE"%-28s"RESET"|\n", m, strdup(s), ft_strdup(s));
#define STRDUP_LTEST(b, bt, j, s, m)   b = strdup(s); bt = ft_strdup(s); if(strcmp(b, bt) == 0){j = "No diff [OK]";} else{j = "Diff [KO]";} printf("|" RED "%-28s"RESET" |"GREEN"%-28s "RESET"|"PURPLE"%-28s"RESET"|\n", m, j, j);

void	ft_strdup_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ███████╗████████╗██████╗ ███████═╗██╗  ██╗███████═╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╔════╝╚══██╔══╝██╔══██╗██╔═══██║██║  ██║██╔═══██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║        ███████╗   ██║   ██████╔╝██║   ██║██║  ██║███████═╝    ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║        ╚════██║   ██║   ██╔══██╗██║   ██║██║  ██║██║          ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗███████║   ██║   ██║  ██║███████╔╝ █████╔╝██║          ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚══════╝  ╚════╝ ╚═╝          ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					by dalba-de			\n\n");
	printf("" CYAN"Testeando función "PURPLE"'FT_STRDUP' "RESET""CYAN"espere...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-31s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "STRDUP", "FT_STRDUP");
	printf(" ");
	while (i++ < 88)
		printf("_");
	printf(" ");
	printf("\n");
	STRDUP_TEST("", "Empty string");
	STRDUP_TEST("hola", "hola");
	STRDUP_TEST("asl;fjl;asdjfjkasdl;fjadjsf", "Random characters");
	STRDUP_TEST("the\0hidden", "\\0hidden");

	//long test
	char *buf;
	char *buftest;
	char *j;
	STRDUP_LTEST(buf, buftest, j, "Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.", "Long string");

	//Speed test
	size_t	size = BFSIZE * 16;
	char *str = malloc(size + 1);

	memset(str, 'A', size);
	str[size] = 0;
	STRDUP_LTEST(buf, buftest, j, str, "Speed test");

	i = 0;
	printf("|");
	while (i++ < 29)
		printf("_");
	printf("|");
	while (i++ < 59)
		printf("_");
	printf("|");
	while (i++ < 88)
		printf("_");
	printf("|");
	printf("\n\n");
}