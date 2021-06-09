#include <stdio.h>
#include <wchar.h>

void inline funny_monkey(wchar_t* ip)
{
	wprintf(L"You ip is %s\n", ip);
}

int wmain(int argc, wchar_t** argv)
{
#define get_arg(var) if (argend > ++argptr) var = *argptr;
	wchar_t** argptr, ** argend, *usage_str;
	wchar_t* host_ip = 0;
	wchar_t* conn_ip = 0;

	/* All very funny stuff. We use argend to mark the end of all arguments, and we use
	argptr to traverse over the arguments, very nice! */
	for (argptr = argv + 1, argend = argv + argc; argend > argptr; ++argptr)
	{
		if (**argptr != '-') /* First char of current arg */
			goto usage;

		switch (*(*argptr + 1)) /* Second char of current arg */
		{
		case 'h': /* h for host */
			get_arg(host_ip);
			break;
		case 'c': /* c for connect */
			get_arg(conn_ip);
			break;
		default:
			goto usage;
		}
	}

	/* FUNNY MONKEY (or in other words, just when checking stuff) */
	funny_monkey(host_ip);

	goto exit;
usage:
	usage_str = L"No bro! you don't know how to use this prog??\n";

	wprintf(usage_str);

exit:
	return 0;
}