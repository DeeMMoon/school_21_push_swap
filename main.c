#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 2)
		valid_line(argc, argv);
	if (argc > 2)
	{
		data = (t_data *) malloc(sizeof(t_data));
		if (!data)
		{
			free(data);
			exit(EXIT_FAILURE);
		}
		valid_line(argc, argv);
		init_struct(data, argc);
		create_stacks(data, argc, argv);
		free(data);
	}
}
