/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_PRINTF_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:00:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/26 23:43:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
#define BONUS
//#define DEBUG
#ifdef PRINTF_ALLOWED
int	ft_printf_test(void)
{
	return (0); // we're using the real printf, so no need to test it
}
# else
static void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_RDWR|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

static void	finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

static int	a0(void)
{
	return printf("hello world\n");
}

static int	b0(void)
{
	return FT_PRINTF("hello world\n");
}

static int	a1(void)
{
	return printf("hello%c world\n", '@');
}

static int	b1(void)
{
	return FT_PRINTF("hello%c world\n", '@');
}

static int	a2(void)
{
	return printf("hello%s world\n", "qwe#\0\noo");
}

static int	b2(void)
{
	return FT_PRINTF("hello%s world\n", "qwe#\0\noo");
}

static int	a3(void)
{
	return printf("hello%-11s world\n", "qwe#\0\noo");
}

static int	b3(void)
{
	return FT_PRINTF("hello%-11s world\n", "qwe#\0\noo");
}

static int	a4(void)
{
	return printf("hello%-11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	b4(void)
{
	return FT_PRINTF("hello%-11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	a5(void)
{
	return printf("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	b5(void)
{
	return FT_PRINTF("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	a6(void)
{
	return printf("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	b6(void)
{
	return FT_PRINTF("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

static int	a7(void)
{
	return printf("hello%-+4.3i world\n", 12435);
}

static int	b7(void)
{
	return FT_PRINTF("hello%-+4.3i world\n", 12435);
}

static int	a8(void)
{
	return printf("hello% 3.4i world\n", 12435);
}

static int	b8(void)
{
	return FT_PRINTF("hello% 3.4i world\n", 12435);
}

static int	a9(void)
{
	return printf("hello%+3.4d world\n", 12435);
}

static int	b9(void)
{
	return FT_PRINTF("hello%+3.4d world\n", 12435);
}

int tst_g = 0;

static int	a10(void)
{
	return printf("hello%p world\n", &tst_g);
}

static int	b10(void)
{
	return FT_PRINTF("hello%p world\n", &tst_g);
}

static int	a11(void)
{
	return printf("hel%%lo%-4p world\n", (void*)12435);
}

static int	b11(void)
{
	return FT_PRINTF("hel%%lo%-4p world\n", (void*)12435);
}

static int	a12(void)
{
	return printf("hel%%lo%-4.3u world\n", 12435);
}

static int	b12(void)
{
	return FT_PRINTF("hel%%lo%-4.3u world\n", 12435);
}

static int	a13(void)
{
	return printf("hel%%lo%-#4.3x world\n", 12445);
}

static int	b13(void)
{
	return FT_PRINTF("hel%%lo%-#4.3x world\n", 12445);
}

static int	a14(void)
{
	return printf("hel%%lo%3.4u world\n", 12435);
}

static int	b14(void)
{
	return FT_PRINTF("hel%%lo%3.4u world\n", 12435);
}

static int	a15(void)
{
	return printf("hel%%lo%3.4X world\n", 12445);
}

static int	b15(void)
{
	return FT_PRINTF("hel%%lo%3.4X world\n", 12445);
}

static int	a16(void)
{
	return printf("hel%%lo%#3.4X world\n", 1);
}

static int	b16(void)
{
	return FT_PRINTF("hel%%lo%#3.4X world\n", 1);
}

static int	a17(void)
{
	return printf("hel%%lo%-p world\n", &tst_g);
}

static int	b17(void)
{
	return FT_PRINTF("hel%%lo%-p world\n", &tst_g);
}

static int	a18(void)
{
	return printf("hel%%lo%p world\n", &tst_g);
}

static int	b18(void)
{
	return FT_PRINTF("hel%%lo%p world\n", &tst_g);
}

static int	a19(void)
{
	return printf("hel%%lo%#13.14X world\n", 12445);
}

static int	b19(void)
{
	return FT_PRINTF("hel%%lo%#13.14X world\n", 12445);
}

static int	a20(void)
{
	return printf("hel%%lo%5.0X world\n", 0);
}

static int	b20(void)
{
	return FT_PRINTF("hel%%lo%5.0X world\n", 0);
}

static int	a21(void)
{
	return printf("hel%%lo%5.0i world\n", 0);
}

static int	b21(void)
{
	return FT_PRINTF("hel%%lo%5.0i world\n", 0);
}

static int	a22(void)
{
	return printf("hel%%lo%#.0X world\n", 0);
}

static int	b22(void)
{
	return FT_PRINTF("hel%%lo%#.0X world\n", 0);
}

static int	a23(void)
{
	return printf("hel%%lo%.0i world\n", 0);
}

static int	b23(void)
{
	return FT_PRINTF("hel%%lo%.0i world\n", 0);
}

char *a24s = "";

static int	a24(void)
{
	return printf("%s", a24s);
}

static int	b24(void)
{
	return FT_PRINTF("%s", a24s);
}

static int	a25(void)
{
	return printf("%i", 0);
}

static int	b25(void)
{
	return FT_PRINTF("%i", 0);
}

static int	a26(void)
{
	return printf("%u", 0);
}

static int	b26(void)
{
	return FT_PRINTF("%u", 0);
}

static int	a27(void)
{
	return printf("%x", 0);
}

static int	b27(void)
{
	return FT_PRINTF("%x", 0);
}

static int	a28(void)
{
	return printf("%#x", 0);
}

static int	b28(void)
{
	return FT_PRINTF("%#x", 0);
}

static int	a29(void)
{
	return printf("%c", 0);
}

static int	b29(void)
{
	return FT_PRINTF("%c", 0);
}

static int	a30(void)
{
	return printf("%p", (void *)0);
}

static int	b30(void)
{
	return FT_PRINTF("%p", (void *)0);
}

static int	a31(void)
{
	return printf("%c", -2);
}

static int	b31(void)
{
	return FT_PRINTF("%c", -2);
}

static int	a32(void)
{
	return printf("%i", INT_MAX);
}

static int	b32(void)
{
	return FT_PRINTF("%i", INT_MAX);
}

static int	a33(void)
{
	return printf("%i", INT_MIN);
}

static int	b33(void)
{
	return FT_PRINTF("%i", INT_MIN);
}

static int	a34(void)
{
	return printf("%p", (void*)ULLONG_MAX);
}

static int	b34(void)
{
	return FT_PRINTF("%p", (void*)ULLONG_MAX);
}

char g_c;
static int	a35(void)
{
	char			d;
	unsigned int	u;
	int				num;
	char			*s = "@@@";

	g_c = 'a';
	d = 'b';
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	return printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&g_c, d, u, s, num, 0, u, u);
}
static int	b35(void)
{
	char			d;
	unsigned int	u;
	int				num;
	char			*s = "@@@";

	g_c = 'a';
	d = 'b';
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	return FT_PRINTF("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&g_c, d, u, s, num, 0, u, u);
}

static int	a36(void)
{
	char			*s2 = NULL;

	return printf("%8p-%8s\n", NULL, s2);
}

static int	b36(void)
{
	char			*s2 = NULL;

	return FT_PRINTF("%8p-%8s\n", NULL, s2);
}

static int	a37(void)
{
	return printf("%-9sScience!\n", "Aperture");
}

static int	b37(void)
{
	return FT_PRINTF("%-9sScience!\n", "Aperture");
}

static int	a38(void)
{
	return printf("%.3d\n", -1234);
}

static int	b38(void)
{
	return FT_PRINTF("%.3d\n", -1234);
}

static int	a39(void)
{
	return printf("%10.12i", INT_MIN);
}

static int	b39(void)
{
	return FT_PRINTF("%10.12i", INT_MIN);
}

static int	a40(void)
{
	return printf("%12.10i", INT_MIN);
}

static int	b40(void)
{
	return FT_PRINTF("%12.10i", INT_MIN);
}

int 	a41(void)
{
	return printf("[%+-20.15d]", INT_MAX);
}

int 	b41(void)
{
	return FT_PRINTF("[%+-20.15d]", INT_MAX);
}

static int	a42(void)
{
	return printf("[%#20.15X][%#x]", UINT_MAX, UINT_MAX);
}

static int	b42(void)
{
	return FT_PRINTF("[%#20.15X][%#x]", UINT_MAX, UINT_MAX);
}

char	*s_g = "ab";

static int	a43(void)
{
	return printf("[%p][%20.s][%p][%15.s]", s_g, s_g, s_g, s_g);
}

static int	b43(void)
{
	return FT_PRINTF("[%p][%20.s][%p][%15.s]", s_g, s_g, s_g, s_g);
}

static int	a44(void)
{
	return printf("[%#3.4x][%#4.3x][%-#3.4x][%#4.3X]", 0xf, 0xf, 0xf, 0xf);
}

static int	b44(void)
{
	return FT_PRINTF("[%#3.4x][%#4.3x][%-#3.4x][%#4.3X]", 0xf, 0xf, 0xf, 0xf);
}

char *a45s = "";

static int	a45(void)
{
	return printf("[%.03s][%3.1s][%9.1s][%-3.1s][%-9.1s]", a45s, a45s, a45s, a45s, a45s);
}

static int	b45(void)
{
	return FT_PRINTF("[%.03s][%3.1s][%9.1s][%-3.1s][%-9.1s]", a45s, a45s, a45s, a45s, a45s);
}

static int	a46(void)
{
	return printf("[%-s][%s][%2s][%-3s][%10s][%-10s]", a45s, a45s, a45s, a45s, a45s, a45s);
}

static int	b46(void)
{
	return FT_PRINTF("[%-s][%s][%2s][%-3s][%10s][%-10s]", a45s, a45s, a45s, a45s, a45s, a45s);
}

static int	a47(void)
{
	return printf("[%8.5d][%8.5u][%8.5d][%8.5u]", 0, 0, 34, 34);
}

static int	b47(void)
{
	return FT_PRINTF("[%8.5d][%8.5u][%8.5d][%8.5u]", 0, 0, 34, 34);
}

static int	a48(void)
{
	return printf("[%05d][%07i][%03d][%05u][%-5u][%-5.u][%-5.0u]", 43, -43, 0, 34, 34, 34, 34);
}

static int	b48(void)
{
	return FT_PRINTF("[%05d][%07i][%03d][%05u][%-5u][%-5.u][%-5.0u]", 43, -43, 0, 34, 34, 34, 34);
}

static int	a49(void)
{
	return printf("[%.0u][%.u][%5.0d][%5.0u][%-5.0u]", 0, 0, 0, 0, 0);
}

static int	b49(void)
{
	return FT_PRINTF("[%.0u][%.u][%5.0d][%5.0u][%-5.0u]", 0, 0, 0, 0, 0);
}

static int	a50(void)
{
	return printf("[%.0x][%.x][%5.0x][%-5.x][%-5.0x]", 0, 0, 0, 0, 0);
}

static int	b50(void)
{
	return FT_PRINTF("[%.0x][%.x][%5.0x][%-5.x][%-5.0x]", 0, 0, 0, 0, 0);
}

static int	a51(void)
{
	return printf("[%08x][%x][%5x][%-5x][%-5x]", 243, 243, 243, 243, 243);
}

static int	b51(void)
{
	return FT_PRINTF("[%08x][%x][%5x][%-5x][%-5x]", 243, 243, 243, 243, 243);
}

static int	a52(void)
{
	return printf("a%ib%ic%id%de%df%dgh%ci%cj%ck%%l%um%un%uo\t\r\np%xq%xr%xs", INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, UINT_MAX, INT_MIN, 0, UINT_MAX);
}

static int	b52(void)
{
	return FT_PRINTF("a%ib%ic%id%de%df%dgh%ci%cj%ck%%l%um%un%uo\t\r\np%xq%xr%xs", INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, UINT_MAX, INT_MIN, 0, UINT_MAX);
}

static int	a53(void)
{
	return printf("a%pb%pc%pd%pe%sf%sg%shi", (void *)0, &a53, (void *)ULLONG_MAX, (void *)LLONG_MIN, (char *)0, "", "ab\0cd");
}

static int	b53(void)
{
	return FT_PRINTF("a%pb%pc%pd%pe%sf%sg%shi", (void *)0, &a53, (void *)ULLONG_MAX, (void *)LLONG_MIN, (char *)0, "", "ab\0cd");
}

static int	a54(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	b54(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	a55(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	b55(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	a56(void)
{
	return printf("a%-pb%-10pc%-10pd%-5pe%-10pf%-pg%-ph%-pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	b56(void)
{
	return FT_PRINTF("a%-pb%-10pc%-10pd%-5pe%-10pf%-pg%-ph%-pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	a57(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	b57(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	a58(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

static int	b58(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}

char *a59s = "\0";

static int	a59(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	b59(void)
{
	return FT_PRINTF("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	a60(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	b60(void)
{
	return FT_PRINTF("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	a61(void)
{
	return printf("a%-.10s@%-10.s@%-10.5s@%-5.10s@%-10s@%-s@%-.0s@%-.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	b61(void)
{
	return FT_PRINTF("a%-.10s@%-10.s@%-10.5s@%-5.10s@%-10s@%-s@%-.0s@%-.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	a62(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	b62(void)
{
	return FT_PRINTF("a%.10s@%10.s@%10.5s@%5.10s@%10s@%0s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	a63(void)
{
	return printf("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	b63(void)
{
	return FT_PRINTF("a%.10s@%10.s@%10.5s@%5.10s@%10s@%s@%.0s@%.s@", a59s, a59s, a59s, a59s, a59s, a59s, a59s, a59s);
}

static int	a64(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi%p", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	b64(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi%p", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	a65(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	b65(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	a66(void)
{
	return printf("a%-pb%-10pc%-10pd%-5pe%-10pf%-pg%-ph%-pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	b66(void)
{
	return FT_PRINTF("a%-pb%-10pc%-10pd%-5pe%-10pf%-pg%-ph%-pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	a67(void)
{
	return printf("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	b67(void)
{
	return FT_PRINTF("a%pb%10pc%10pd%5pe%10pf%pg%ph%pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	a68(void)
{
	return printf("a%pb%2pc%pd%2pe%10pf%2pg%ph%10pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
}

static int	b68(void)
{
	return FT_PRINTF("a%pb%2pc%pd%2pe%10pf%2pg%ph%10pi", (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
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

#ifdef BONUS
static void	fill_bonus(void);
#else
static void	fill_reg(void);
#endif

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

#ifdef BONUS
static void	fill_bonus(void)
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
#else
static void	fill_reg(void)
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
#endif

#endif // printf_allowed