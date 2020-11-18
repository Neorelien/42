int main()
{
	char *st;
	char *str;

	st = (char*)ft_calloc(3, 1);
	printf("%c\n", st[0]);
	str = (char*)calloc(3, 1);
	printf("%c", str[0]);

