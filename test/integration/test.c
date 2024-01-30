#include "include/plib.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		struct s_allocator *heap = heap_init();
		struct s_allocator *log = logging_allocator_init(heap);
		t_file *file = file_create(log);
		file->in = file_open(argv[1], O_RDONLY);
		file_buffer_create(file);
		while (file_buffer_load_chunk(file, READ_SIZE) == READ_SIZE);
		char **result = split_nsplit(log, buffer_ptr(file->buffer), 10);

		for (int i = 0; result[i]; i++) {
			print_fmt("%s\n",result[i]);
		}
		file_destroy(file);
		split_destroy(log, result);
		logging_allocator_deinit(log);
		heap_deinit(heap);
	}
	return (0);
}
