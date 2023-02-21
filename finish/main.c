#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	leak_check()
{
	system("leaks --list -- a.out");
	// system("leaks a.out");
}

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	atexit(leak_check);
	idx = 1;
	// printf("1_fd : %d\n", fd);

	// str = get_next_line(-1);
	// printf("%s\n", str);
	// str = get_next_line(100);
	// printf("%s\n", str);
	// fd = open("text.txt", O_RDWR);
	// close(fd);
	// printf("close_fd : %d\n", fd);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	fd = open("text.txt", O_RDWR);
	printf("new open_fd : %d\n", fd);

		// str = get_next_line(fd);
		// printf("%d: <%s\n", idx, str);
		// str = get_next_line(fd);
		// printf("%d: <%s\n", idx, str);
		// str = get_next_line(fd);
		// printf("%d: <%s\n", idx, str);
		// close(fd);
		// fd = open("text.txt", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break ;
		}
		free(str);
	}
	close(fd);
	return (0);
}

	int			idx;
	char *temp;

	ret = 0;
	check = 0;
	find = my_lst_find(head, fd);
	while (ret == 0)
	{
		idx = BUFFER_SIZE + 1;
		while (idx--)
			find->buf[idx] = 0;
		check = read(find->fd, find->buf, BUFFER_SIZE);
		find->save = ft_strjoin(find->save, find->buf);
		idx = -1;
		while (find->save[++idx])
		{
			if (find->save[idx] == '\n')
			{
				ret = ft_substr(find->save, 0, idx + 1);
				temp = ft_substr(find->save, idx + 1,\
								ft_strlen(find->save) - (idx + 1));
				free(find->save);
				find->save = temp;
				return (ret);
			}
		}

		Error in test 2: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: "\n\n\n"
Error in test 3: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 3: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 4: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 4: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 5: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 5: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 7: get_next_line(5: "multiple_nl.txt"): 
Memory leak: 0x602000000170 - 2 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:135:2

Error in test 5: get_next_line(5: "lines_around_10.txt"): expected: "xxxx\n", got: <NULL>
Error in test 5: get_next_line(5: "lines_around_10.txt"): not enough memory allocated, needed: 6, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "xxxx\n"
Error in test 7: get_next_line(5: "lines_around_10.txt"): 
Memory leak: 0x602000000230 - 6 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:56:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:162:2

Error in test 50: get_next_line(5: "limits.txt"): expected: "lmnopqrs\n", got: <NULL>
asking for line: 2 of file:
1: abcdefghij\n
2: lmnopqrs\n
3: 

Error in test 50: get_next_line(5: "limits.txt"): not enough memory allocated, needed: 10, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "lmnopqrs\n"
Error in test 52: get_next_line(5: "limits.txt"): 
Memory leak: 0x6020000009d0 - 10 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:56:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func_limits file_utils.c:73:8
     in test_limit tester.c:84:7
     in main tester.c:235:3

for file:
1: abcdefghij\n
2: lmnopqrs\n
3: 

Error in test 5: get_next_line(0: "stdin"): expected: "xxxx\n", got: <NULL>
Error in test 5: get_next_line(0: "stdin"): not enough memory allocated, needed: 6, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "xxxx\n"
Error in test 7: get_next_line(0: "stdin"): 
Memory leak: 0x602000000230 - 6 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:56:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:243:2

Error in test 2: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: "\n\n\n"
Error in test 3: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 3: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 4: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 4: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 5: get_next_line(5: "multiple_nl.txt"): expected: "\n", got: <NULL>
Error in test 5: get_next_line(5: "multiple_nl.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 7: get_next_line(5: "multiple_nl.txt"): 
Memory leak: 0x602000000170 - 2 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:135:2

Error in test 2: get_next_line(5: "variable_nls.txt"): expected: "0123456789012345678901234567890123456789x2\n", got: "01234567890123456789[...]34567890123456789x12"(178 characters)
Error in test 3: get_next_line(5: "variable_nls.txt"): expected: "0123456789012345678901234567890123456789x3\n", got: <NULL>
Error in test 3: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 44, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789012345678901234567890123456789x3\n"
Error in test 4: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 4: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 5: get_next_line(5: "variable_nls.txt"): expected: "0123456789012345678901234567890123456789x5\n", got: <NULL>
Error in test 5: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 44, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789012345678901234567890123456789x5\n"
Error in test 6: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 6: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 7: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 7: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 8: get_next_line(5: "variable_nls.txt"): expected: "0123456789012345678901234567890123456789x8\n", got: <NULL>
Error in test 8: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 44, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789012345678901234567890123456789x8\n"
Error in test 9: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 9: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 10: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 10: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 11: get_next_line(5: "variable_nls.txt"): expected: "\n", got: <NULL>
Error in test 11: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 2, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "\n"
Error in test 12: get_next_line(5: "variable_nls.txt"): expected: "0123456789012345678901234567890123456789x12", got: <NULL>
Error in test 12: get_next_line(5: "variable_nls.txt"): not enough memory allocated, needed: 44, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789012345678901234567890123456789x12"
Error in test 14: get_next_line(5: "variable_nls.txt"): 
Memory leak: 0x6040000002d0 - 44 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:145:2

Error in test 2: get_next_line(5: "lines_around_10.txt"): expected: "012345678\n", got: "90123456789\n0123456789\nxxxx\n"
Error in test 3: get_next_line(5: "lines_around_10.txt"): expected: "90123456789\n", got: <NULL>
Error in test 3: get_next_line(5: "lines_around_10.txt"): not enough memory allocated, needed: 13, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "90123456789\n"
Error in test 4: get_next_line(5: "lines_around_10.txt"): expected: "0123456789\n", got: <NULL>
Error in test 4: get_next_line(5: "lines_around_10.txt"): not enough memory allocated, needed: 12, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789\n"
Error in test 5: get_next_line(5: "lines_around_10.txt"): expected: "xxxx\n", got: <NULL>
Error in test 5: get_next_line(5: "lines_around_10.txt"): not enough memory allocated, needed: 6, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "xxxx\n"
Error in test 7: get_next_line(5: "lines_around_10.txt"): 
Memory leak: 0x602000000110 - 11 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:162:2

Error in test 2: get_next_line(5: "read_error.txt"): expected: "bbbbbbbbbb\n", got: "cccccccccc\ndddddddddd\n"
Error in test 5: get_next_line(5: "read_error.txt"): expected: "bbbbbbbbbb\n", got: "cccccccccc\ndddddddddd\n"
Error in test 6: get_next_line(5: "read_error.txt"): expected: "cccccccccc\n", got: <NULL>
Error in test 6: get_next_line(5: "read_error.txt"): not enough memory allocated, needed: 12, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "cccccccccc\n"
Error in test 7: get_next_line(5: "read_error.txt"): expected: "dddddddddd\n", got: <NULL>
Error in test 7: get_next_line(5: "read_error.txt"): not enough memory allocated, needed: 12, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "dddddddddd\n"
Probable reason: You should clear the static buffer when a call to read returns -1
Error in test 9: get_next_line(5: "read_error.txt"): 
Memory leak: 0x602000000110 - 12 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:193:2

Memory leak: 0x602000000170 - 12 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:193:2

Error in test 2: get_next_line(0: "stdin"): expected: "012345678\n", got: "90123456789\n0123456789\nxxxx\n"
Error in test 3: get_next_line(0: "stdin"): expected: "90123456789\n", got: <NULL>
Error in test 3: get_next_line(0: "stdin"): not enough memory allocated, needed: 13, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "90123456789\n"
Error in test 4: get_next_line(0: "stdin"): expected: "0123456789\n", got: <NULL>
Error in test 4: get_next_line(0: "stdin"): not enough memory allocated, needed: 12, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "0123456789\n"
Error in test 5: get_next_line(0: "stdin"): expected: "xxxx\n", got: <NULL>
Error in test 5: get_next_line(0: "stdin"): not enough memory allocated, needed: 6, reserved: 0
Could not find the corresponding allocation or the pointer 0x0
should reserve space for the string: "xxxx\n"
Error in test 7: get_next_line(0: "stdin"): 
Memory leak: 0x602000000110 - 11 bytes
You failed to free the memory allocated at:
     in _add_malloc malloc_mock.c:29:8
     in malloc malloc_mock.c:75:10
  -> in ft_substr get_next_line_utils.c:58:7
     in my_save get_next_line.c:66:5
     in my_save_buf get_next_line.c:91:9
     in get_next_line get_next_line.c:127:6
     in test_gnl_func file_utils.c:40:8
     in main tester.c:243:2

