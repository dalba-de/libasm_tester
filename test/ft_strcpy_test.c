/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:04:55 by dalba-de          #+#    #+#             */
/*   Updated: 2020/06/21 10:13:05 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"

#define	BFSIZE			0xF0000
#define STRCPY_TEST(b, s, m)   printf("|" RED "%-28s"RESET" |"GREEN"%-28s "RESET"|"PURPLE"%-28s"RESET"|\n", m, strcpy(b, s), ft_strcpy(b, s));
#define STRCPY_LTEST(b, bt, j, s, m)   strcpy(b, s); ft_strcpy(bt, s); if(strcmp(b, bt) == 0){j = "No diff [OK]";} else{j = "Diff [KO]";} printf("|" RED "%-28s"RESET" |"GREEN"%-28s "RESET"|"PURPLE"%-28s"RESET"|\n", m, j, j);

void	ft_strcpy_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ███████╗████████╗██████╗  ██████╗███████═╗██    ██╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╔════╝╚══██╔══╝██╔══██╗██╔════╝██╔═══██║╚██╔═██╔╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║        ███████╗   ██║   ██████╔╝██║     ███████═╝  ████╔╝     ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║        ╚════██║   ██║   ██╔══██╗██║     ██║         ██╔╝      ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗███████║   ██║   ██║  ██║╚██████╗██║         ██║       ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝╚═╝         ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
								\n\n");
	char buf[4096] = {0};
	char buftest[4096] = {0};
	char *j;

	printf("" CYAN"Testeando función "PURPLE"'FT_STRCPY' "RESET""CYAN"espere...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-31s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "STRCPY", "FT_STRCPY");
	printf(" ");
	while (i++ < 88)
		printf("_");
	printf(" ");
	printf("\n");
	STRCPY_TEST(buf, "", "Empty string");
	STRCPY_TEST(buf, "abc", "abc");
	STRCPY_TEST(buf, "asl;fjl;asdjfjkasdl;fjadjsf", "Random characters");
	STRCPY_TEST(buf, "yope\0la", "\\0 hidden");
	STRCPY_LTEST(buf, buftest, j, "Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.", "Long string");
	STRCPY_LTEST(buf, buftest, j, "œð˛ʼˇ,´˛ˀ-ºª•¶ªˆ§´", "Unicode test");

	// Overflow test
	char	*src = "AAAA";
	char	dst1[80];
	char	dst2[80];

	memset(dst1, 'B', sizeof(dst1));
	memset(dst2, 'B', sizeof(dst2));
	STRCPY_LTEST(dst1, dst2, j, "AAAA", "Overflow test");

	//Speed test
	size_t	size = BFSIZE * 2;
	src = malloc(size + 1);
	char *dst = malloc(size + 1);

	memset(src, 'A', size);
	src[size] = 0;
	STRCPY_LTEST(dst, dst, j, src, "Speed test");

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
