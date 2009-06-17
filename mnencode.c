#include <stdio.h>
#include <string.h>
#include "mnemonic.h"

int main(void) {
	mn_byte buf[0x10000];
	char outbuf[0x90000];
	int buflen;
	int n;

	fprintf (stderr, "%s\n", mn_wordlist_version);

	buflen = fread (buf, 1, sizeof (buf), stdin);
	n = mn_encode (buf, buflen, outbuf, sizeof outbuf, "x x x. x x x. x x x\n");
	if (n == 0)
		fwrite (outbuf, 1, strlen (outbuf), stdout);
	else
		fprintf (stderr, "mn_encode error %d\n", n);
	putchar ('\n');

	return 0;
}
