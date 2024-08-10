/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:00:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/13 20:26:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <limits.h>
#include "../libft.h"
#define BONUS
//#define DEBUG

static void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_RDWR|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

void	finally(int *out, int *save)
{
	fflush(stdout);
       	close(*out);
	dup2(*save, fileno(stdout));
	close(*out);
}

int	a0(void)
{
	return printf("hello world\n");
}

int	b0(void)
{
	return ft_printf("hello world\n");
}

int	a1(void)
{
	return printf("hello%c world\n", '@');
}

int	b1(void)
{
	return ft_printf("hello%c world\n", '@');
}

int	a2(void)
{
	return printf("hello%s world\n", "qwe#\0\noo");
}

int	b2(void)
{
	return ft_printf("hello%s world\n", "qwe#\0\noo");
}

int	a3(void)
{
	return printf("hello%-11s world\n", "qwe#\0\noo");
}

int	b3(void)
{
	return ft_printf("hello%-11s world\n", "qwe#\0\noo");
}

int	a4(void)
{
	return printf("hello%-11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b4(void)
{
	return ft_printf("hello%-11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a5(void)
{
	return printf("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b5(void)
{
	return ft_printf("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a6(void)
{
	return printf("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b6(void)
{
	return ft_printf("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a7(void)
{
	return printf("hello%-+4.3i world\n", 12435);
}

int	b7(void)
{
	return ft_printf("hello%-+4.3i world\n", 12435);
}

int	a8(void)
{
	return printf("hello% 03.4i world\n", 12435);
}

int	b8(void)
{
	return ft_printf("hello% 03.4i world\n", 12435);
}

int	a9(void)
{
	return printf("hello%0+3.4d world\n", 12435);
}

int	b9(void)
{
	return ft_printf("hello%0+3.4d world\n", 12435);
}

int tst_g = 0;

int	a10(void)
{
	return printf("hello%3.p world\n", &tst_g);
}

int	b10(void)
{
	return ft_printf("hello%3.p world\n", &tst_g);
}

int	a11(void)
{
	return printf("hel%%lo%-4p world\n", (void*)12435);
}

int	b11(void)
{
	return ft_printf("hel%%lo%-4p world\n", (void*)12435);
}

int	a12(void)
{
	return printf("hel%%lo%---4.3u world\n", 12435);
}

int	b12(void)
{
	return ft_printf("hel%%lo%---4.3u world\n", 12435);
}

int	a13(void)
{
	return printf("hel%%lo%-#--4.3x world\n", 12445);
}

int	b13(void)
{
	return ft_printf("hel%%lo%-#--4.3x world\n", 12445);
}

int	a14(void)
{
	return printf("hel%%lo%3.4u world\n", 12435);
}

int	b14(void)
{
	return ft_printf("hel%%lo%3.4u world\n", 12435);
}

int	a15(void)
{
	return printf("hel%%lo%3.4X world\n", 12445);
}

int	b15(void)
{
	return ft_printf("hel%%lo%3.4X world\n", 12445);
}

int	a16(void)
{
	return printf("hel%%lo%##3.4X world\n", 1);
}

int	b16(void)
{
	return ft_printf("hel%%lo%##3.4X world\n", 1);
}

int	a17(void)
{
	return printf("hel%%lo%-3.p world\n", &tst_g);
}

int	b17(void)
{
	return ft_printf("hel%%lo%-3.p world\n", &tst_g);
}

int	a18(void)
{
	return printf("hel%%lo%4.p world\n", &tst_g);
}

int	b18(void)
{
	return ft_printf("hel%%lo%4.p world\n", &tst_g);
}

int	a19(void)
{
	return printf("hel%%lo%##13.14X world\n", 12445);
}

int	b19(void)
{
	return ft_printf("hel%%lo%##13.14X world\n", 12445);
}

int	a20(void)
{
	return printf("hel%%lo%5.0X world\n", 0);
}

int	b20(void)
{
	return ft_printf("hel%%lo%5.0X world\n", 0);
}

int	a21(void)
{
	return printf("hel%%lo%5.0i world\n", 0);
}

int	b21(void)
{
	return ft_printf("hel%%lo%5.0i world\n", 0);
}

int	a22(void)
{
	return printf("hel%%lo%#.0X world\n", 0);
}

int	b22(void)
{
	return ft_printf("hel%%lo%#.0X world\n", 0);
}

int	a23(void)
{
	return printf("hel%%lo%.0i world\n", 0);
}

int	b23(void)
{
	return ft_printf("hel%%lo%.0i world\n", 0);
}

int	a24(void)
{
	return printf("%s", (char*)0);
}

int	b24(void)
{
	return ft_printf("%s", (char*)0);
}

int	a25(void)
{
	return printf("%i", 0);
}

int	b25(void)
{
	return ft_printf("%i", 0);
}

int	a26(void)
{
	return printf("%u", 0);
}

int	b26(void)
{
	return ft_printf("%u", 0);
}

int	a27(void)
{
	return printf("%x", 0);
}

int	b27(void)
{
	return ft_printf("%x", 0);
}

int	a28(void)
{
	return printf("%#x", 0);
}

int	b28(void)
{
	return ft_printf("%#x", 0);
}

int	a29(void)
{
	return printf("%c", 0);
}

int	b29(void)
{
	return ft_printf("%c", 0);
}

int	a30(void)
{
	return printf("%p", (void *)0);
}

int	b30(void)
{
	return ft_printf("%p", (void *)0);
}

int	a31(void)
{
	return printf("%c", -2);
}

int	b31(void)
{
	return ft_printf("%c", -2);
}

int	a32(void)
{
	return printf("%i", INT_MAX);
}

int	b32(void)
{
	return ft_printf("%i", INT_MAX);
}

int	a33(void)
{
	return printf("%i", INT_MIN);
}

int	b33(void)
{
	return ft_printf("%i", INT_MIN);
}

int	a34(void)
{
	return printf("%p", (void*)ULLONG_MAX);
}

int	b34(void)
{
	return ft_printf("%p", (void*)ULLONG_MAX);
}

char g_c;
int	a35(void)
{
	char			d;
	unsigned int	u;
	int				pf;
	int				fp;
	int				num;
	char			*s = "@@@";
	char			*s2 = NULL;

	g_c = 'a';
	d = 'b';
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	return printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&g_c, d, u, s, num, 0, u, u);
}
int	b35(void)
{
	char			d;
	unsigned int	u;
	int				pf;
	int				fp;
	int				num;
	char			*s = "@@@";
	char			*s2 = NULL;

	g_c = 'a';
	d = 'b';
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	return ft_printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&g_c, d, u, s, num, 0, u, u);
}

int	a36(void)
{
	char			*s2 = NULL;

	return printf("%8p-%8s\n", NULL, s2);
}

int	b36(void)
{
	char			*s2 = NULL;

	return ft_printf("%8p-%8s\n", NULL, s2);
}

int	a37(void)
{
	return printf("%-9sScience!\n", "Aperture");
}

int	b37(void)
{
	return ft_printf("%-9sScience!\n", "Aperture");
}

int	a38(void)
{
	return printf("%.3d\n", -1234);
}

int	b38(void)
{
	return ft_printf("%.3d\n", -1234);
}

int	a39(void)
{
	return printf("%10.12i", INT_MIN);
}

int	b39(void)
{
	return ft_printf("%10.12i", INT_MIN);
}

int	a40(void)
{
	return printf("%12.10i", INT_MIN);
}

int	b40(void)
{
	return ft_printf("%12.10i", INT_MIN);
}

int 	a41(void)
{
	return printf("[%+-20.15d]", INT_MAX);
}

int 	b41(void)
{
	return ft_printf("[%+-20.15d]", INT_MAX);
}

int	a42(void)
{
	return printf("[%#20.15X][%#x]", UINT_MAX, UINT_MAX);
}

int	b42(void)
{
	return ft_printf("[%#20.15X][%#x]", UINT_MAX, UINT_MAX);
}

char	*s_g = "ab";

int	a43(void)
{
	return printf("[%20.p][%20.s][%15.p][%15.s]", s_g, s_g, s_g, s_g);
}

int	b43(void)
{
	return ft_printf("[%20.p][%20.s][%15.p][%15.s]", s_g, s_g, s_g, s_g);
}

int	a44(void)
{
	return printf("[%#3.4x][%#4.3x][%-#3.4x][%0#4.3X]", 0xf, 0xf, 0xf, 0xf);
}

int	b44(void)
{
	return ft_printf("[%#3.4x][%#4.3x][%-#3.4x][%0#4.3X]", 0xf, 0xf, 0xf, 0xf);
}

int	a45(void)
{
	return printf("[%.03s][%3.1s][%9.1s][%-3.1s][%-9.1s]", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b45(void)
{
	return ft_printf("[%.03s][%3.1s][%9.1s][%-3.1s][%-9.1s]", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a46(void)
{
	return printf("[%-s][%s][%2s][%-3s][%10s][%-10s]", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b46(void)
{
	return ft_printf("[%-s][%s][%2s][%-3s][%10s][%-10s]", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a47(void)
{
	return printf("[%08.5d][%08.5u][%08.5d][%08.5u]", 0, 0, 34, 34);
}

int	b47(void)
{
	return ft_printf("[%08.5d][%08.5u][%08.5d][%08.5u]", 0, 0, 34, 34);
}

int	a48(void)
{
	return printf("[%05d][%07i][%03d][%05u][%-5u][%-5.u][%-5.0u]", 43, -43, 0, 34, 34, 34, 34);
}

int	b48(void)
{
	return ft_printf("[%05d][%07i][%03d][%05u][%-5u][%-5.u][%-5.0u]", 43, -43, 0, 34, 34, 34, 34);
}

int	a49(void)
{
	return printf("[%.0u][%.u][%5.0d][%5.0u][%-5.0u]", 0, 0, 0, 0, 0);
}

int	b49(void)
{
	return ft_printf("[%.0u][%.u][%5.0d][%5.0u][%-5.0u]", 0, 0, 0, 0, 0);
}

int	a50(void)
{
	return printf("[%.0x][%.x][%5.0x][%-5.x][%-5.0x]", 0, 0, 0, 0, 0);
}

int	b50(void)
{
	return ft_printf("[%.0x][%.x][%5.0x][%-5.x][%-5.0x]", 0, 0, 0, 0, 0);
}

int	a51(void)
{
	return printf("[%08.0x][%.x][%5.0x][%-5.x][%-5.0x]", 243, 243, 243, 243, 243);
}

int	b51(void)
{
	return ft_printf("[%08.0x][%.x][%5.0x][%-5.x][%-5.0x]", 243, 243, 243, 243, 243);
}

int	a52(void)
{
	return printf("a%ib%ic%id%de%df%dgh%ci%cj%ck%%l%um%un%uo\t\r\np%xq%xr%xs", INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, UINT_MAX, INT_MIN, 0, UINT_MAX);
}

int	b52(void)
{
	return ft_printf("a%ib%ic%id%de%df%dgh%ci%cj%ck%%l%um%un%uo\t\r\np%xq%xr%xs", INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, UINT_MAX, INT_MIN, 0, UINT_MAX);
}

int	a53(void)
{
	return printf("a%pb%pc%pd%pe%sf%sg%shi", (void *)0, &a53, (void *)ULLONG_MAX, (void *)LLONG_MIN, (char *)0, "", "ab\0cd");
}

int	b53(void)
{
	return ft_printf("a%pb%pc%pd%pe%sf%sg%shi", (void *)0, &a53, (void *)ULLONG_MAX, (void *)LLONG_MIN, (char *)0, "", "ab\0cd");
}

int	a54(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	b54(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	a55(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	b55(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	a56(void)
{
	return printf("a%-.pb%-10.pc%-10.pd%-5.pe%-10pf%-pg%-.ph%-.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	b56(void)
{
	return ft_printf("a%-.pb%-10.pc%-10.pd%-5.pe%-10pf%-pg%-.ph%-.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	a57(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	b57(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	a58(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	b58(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

int	a59(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b59(void)
{
	return ft_printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a60(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b60(void)
{
	return ft_printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a61(void)
{
	return printf("a%-.10s@%-10.s@%-10.5s@%-5.10s@%-10s@%-s@%-.0s@%-.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b61(void)
{
	return ft_printf("a%-.10s@%-10.s@%-10.5s@%-5.10s@%-10s@%-s@%-.0s@%-.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a62(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b62(void)
{
	return ft_printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%0s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a63(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	b63(void)
{
	return ft_printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
}

int	a64(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi%p", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	b64(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi%p", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	a65(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	b65(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	a66(void)
{
	return printf("a%-.pb%-10.pc%-10.pd%-5.pe%-10pf%-pg%-.ph%-.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	b66(void)
{
	return ft_printf("a%-.pb%-10.pc%-10.pd%-5.pe%-10pf%-pg%-.ph%-.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	a67(void)
{
	return printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	b67(void)
{
	return ft_printf("a%.pb%10.pc%10.pd%5.pe%10pf%pg%.ph%.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	a68(void)
{
	return printf("a%.pb%2.pc%.pd%2.pe%10pf%2pg%.ph%10.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

int	b68(void)
{
	return ft_printf("a%.pb%2.pc%.pd%2.pe%10pf%2pg%.ph%10.pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}


#define SZ_REG 14
#define SZ_BONUS 69
#ifdef BONUS
# define SZ SZ_BONUS
#else
# define SZ SZ_REG
#endif
#define START 0 

int (*as[SZ])();
int (*bs[SZ])();

void	fill_bonus(void);
void	fill_reg(void);

int	ft_printf_test(void)
{
	int fs;
	int fc;
	int out, save;
	char rs = 0, rc = 0;
	int rets, retc;
	remove("std.tmp");
	remove("custom.tmp");
#ifdef BONUS
	fill_bonus();
#else
	fill_reg();
#endif
#ifdef DEBUG
	printf("Starting %d tests.\n", SZ);
#endif
	for (int i = START; i < SZ; i ++)
	{
#ifdef DEBUG
		printf("%i\n", i);
#endif
		catch("std.tmp", &out, &save);
		rets = as[i]();
		finally(&out, &save);
		catch("custom.tmp", &out, &save);
		retc = bs[i]();
		finally(&out, &save);
#ifdef DEBUG
		printf("%i %i\n", rets, retc);
#endif
		assert(rets == retc);
		fs = open("std.tmp", O_RDONLY, 0600);
		fc = open("custom.tmp", O_RDONLY, 0600);
		rs = 1;
		rc = 1;
		int c = 0;
		while (1)
		{
			retc = read(fc, &rc, 1);
			rets = read(fs, &rs, 1);
			assert(retc == rets);
			if (rets != 1)
				break;
#ifdef DEBUG
			if (rs != rc)
				printf("error on symbol #%i\n", c);
#endif
			assert(rs == rc);
			c ++;
		}
		close(fs);
		close(fc);
	}
	remove("std.tmp");
	remove("custom.tmp");
	return (0);
}

void	fill_bonus(void)
{
	as[0] = a0;
	bs[0] = b0;
	as[1] = a1;
	bs[1] = b1;
	as[2] = a2;
	bs[2] = b2;
	as[3] = a3;
	bs[3] = b3;
	as[4] = a4;
	bs[4] = b4;
	as[5] = a5;
	bs[5] = b5;
	as[6] = a6;
	bs[6] = b6;
	as[7] = a7;
	bs[7] = b7;
	as[8] = a8;
	bs[8] = b8;
	as[9] = a9;
	bs[9] = b9;
	as[10] = a10;
	bs[10] = b10;
	as[11] = a11;
	bs[11] = b11;
	as[12] = a12;
	bs[12] = b12;
	as[13] = a13;
	bs[13] = b13;
	as[14] = a14;
	bs[14] = b14;
	as[15] = a15;
	bs[15] = b15;
	as[16] = a16;
	bs[16] = b16;
	as[17] = a17;
	bs[17] = b17;
	as[18] = a18;
	bs[18] = b18;
	as[19] = a19;
	bs[19] = b19;
	as[20] = a20;
	bs[20] = b20;
	as[21] = a21;
	bs[21] = b21;
	as[22] = a22;
	bs[22] = b22;
	as[23] = a23;
	bs[23] = b23;
	as[24] = a24;
	bs[24] = b24;
	as[25] = a25;
	bs[25] = b25;
	as[26] = a26;
	bs[26] = b26;
	as[27] = a27;
	bs[27] = b27;
	as[28] = a28;
	bs[28] = b28;
	as[29] = a29;
	bs[29] = b29;
	as[30] = a30;
	bs[30] = b30;
	as[31] = a31;
	bs[31] = b31;
	as[32] = a32;
	bs[32] = b32;
	as[33] = a33;
	bs[33] = b33;
	as[34] = a34;
	bs[34] = b34;
	as[35] = a35;
	bs[35] = b35;
	as[36] = a36;
	bs[36] = b36;
	as[37] = a37;
	bs[37] = b37;
	as[38] = a38;
	bs[38] = b38;
	as[39] = a39;
	bs[39] = b39;
	as[40] = a40;
	bs[40] = b40;
	as[41] = a41;
	bs[41] = b41;
	as[42] = a42;
	bs[42] = b42;
	as[43] = a43;
	bs[43] = b43;
	as[44] = a44;
	bs[44] = b44;
	as[45] = a45;
	bs[45] = b45;
	as[46] = a46;
	bs[46] = b46;
	as[47] = a47;
	bs[47] = b47;
	as[48] = a48;
	bs[48] = b48;
	as[49] = a49;
	bs[49] = b49;
	as[50] = a50;
	bs[50] = b50;
	as[51] = a51;
	bs[51] = b51;
	as[52] = a52;
	bs[52] = b52;
	as[53] = a53;
	bs[53] = b53;
	as[54] = a54;
	bs[54] = b54;
	as[55] = a55;
	bs[55] = b55;
	as[56] = a56;
	bs[56] = b56;
	as[57] = a57;
	bs[57] = b57;
	as[58] = a58;
	bs[58] = b58;
	as[59] = a59;
	bs[59] = b59;
	as[60] = a60;
	bs[60] = b60;
	as[61] = a61;
	bs[61] = b61;
	as[62] = a62;
	bs[62] = b62;
	as[63] = a63;
	bs[63] = b63;
	as[64] = a64;
	bs[64] = b64;
	as[65] = a65;
	bs[65] = b65;
	as[66] = a66;
	bs[66] = b66;
	as[67] = a67;
	bs[67] = b67;
	as[68] = a68;
	bs[68] = b68;
}

void	fill_reg(void)
{
	as[0]=a0;
	bs[0]=b0;
	as[1]=a1;
	bs[1]=b1;
	as[2]=a24;
	bs[2]=b24;
	as[3]=a25;
	bs[3]=b25;
	as[4]=a26;
	bs[4]=b26;
	as[5]=a27;
	bs[5]=b27;
	as[6]=a29;
	bs[6]=b29;
	as[7]=a30;
	bs[7]=b30;
	as[8]=a31;
	bs[8]=b31;
	as[9]=a32;
	bs[9]=b32;
	as[10]=a33;
	bs[10]=b33;
	as[11]=a34;
	bs[11]=b34;
	as[12]=a52;
	bs[12]=b52;
	as[13]=a53;
	bs[13]=b53;
}
