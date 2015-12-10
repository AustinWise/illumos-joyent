
#include <intrin.h>

/*
 * Utility function for converting a long integer to a string, avoiding stdio.
 * 'base' must be one of 10 or 16
 */
void
ultos(unsigned __int64 n, int base, char *s)
{
	char lbuf[24];		/* 64 bits fits in 16 hex digits, 20 decimal */
	char *cp = lbuf;

	do {
		*cp++ = "0123456789abcdef"[n%base];
		n /= base;
	} while (n);
	if (base == 16) {
		*s++ = '0';
		*s++ = 'x';
	}
	do {
		*s++ = *--cp;
	} while (cp > lbuf);
	*s = '\0';
}

void
__assfail(const char *assertion, const char *filename, int line_num)
{
	__debugbreak();
}

/*
* We define and export this version of assfail() just because libaio
* used to define and export it, needlessly.  Now that libaio is folded
* into libc, we need to continue this for ABI/version reasons.
* We don't use "#pragma weak assfail __assfail" in order to avoid
* warnings from the check_fnames utility at build time for libraries
* that define their own version of assfail().
*/
void
assfail(const char *assertion, const char *filename, int line_num)
{
	__assfail(assertion, filename, line_num);
}

void
assfail3(const char *assertion, unsigned __int64 lv, const char *op, unsigned __int64 rv,
	const char *filename, int line_num)
{
	char buf[1000];
	(void)strcpy(buf, assertion);
	(void)strcat(buf, " (");
	ultos((unsigned __int64)lv, 16, buf + strlen(buf));
	(void)strcat(buf, " ");
	(void)strcat(buf, op);
	(void)strcat(buf, " ");
	ultos((unsigned __int64)rv, 16, buf + strlen(buf));
	(void)strcat(buf, ")");
	__assfail(buf, filename, line_num);
}
