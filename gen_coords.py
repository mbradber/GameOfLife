from random import randint
import sys

num_coords = int(sys.argv[1])
min_range = int(sys.argv[2])
max_range = int(sys.argv[3])

coord_set = set()

while len(coord_set) < num_coords:
    rand_x = randint(min_range, max_range)
    rand_y = randint(min_range, max_range)

    coord_set.add((rand_x, rand_y))

print "Writing coordinates to state_test.in..."

with open('state_test.in', 'w') as fp:
    for coord in coord_set:
        coord_line = "{0},{1}\n".format(coord[0], coord[1])
        fp.write(coord_line)
