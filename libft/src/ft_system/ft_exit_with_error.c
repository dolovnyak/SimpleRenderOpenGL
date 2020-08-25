#include <libft.h>

void	ft_exit_with_error(const char **error_strs, int error_code)
{
	if (!error_strs)
		exit(error_code);
	int i = 0;
	while (error_strs[i])
	{
		ft_printf("%s ", error_strs[i]);
		i++;
	}
	ft_printf("\n");
	exit(error_code);
}
