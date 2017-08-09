import sys

input_file = sys.argv[1]
x_offset = int(sys.argv[2])
y_offset = int(sys.argv[3])

line_list = []

with open(input_file, 'r') as fp:
    for line in fp:
        line_list.append(line)

num_rows = len(line_list)
num_cols = len(line_list[0])

o_offset_x = num_cols / 2
o_offst_y = num_rows / 2

for i, line in enumerate(line_list):
    for j, entry in enumerate(line):
        if entry == 'O':
            print("{0},{1}".format(i + x_offset - o_offset_x, j + y_offset - o_offst_y))
