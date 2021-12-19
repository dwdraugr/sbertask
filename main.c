#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "match_3_turn_searcher.h"

static char* get_turn_name(t_turns_types type);

int main(int argc, char** argv) {
	t_match_3_result* results = NULL;
	t_match_3_data data;

	if (argc < 3) {
		puts("usage: match_3 <width> <height>");
		exit(2);
	}

	data.x = 0;
	data.y = 0;
	data.width = (short)atoi(argv[1]);
	data.height = (short)atoi(argv[2]);

	data.map = malloc(data.y * sizeof(size_t));
	for (int y = 0; y < data.height; y++) {
		data.map[y] = malloc(data.x * sizeof(unsigned char));
		for (int x = 0; x < data.width; x++) {
			data.map[y][x] = getchar();
		}
	}

	for (int i = 0; i < data.height; i++) {
		for (int j = 0; j < data.width; j++) {
			printf("%c ", data.map[i][j]);
		}
		puts("");
	}

	results = search_turn(&data);
	if (NULL == results) {
		puts("There is no turns for this map");
		exit(1);
	}

	int i = 0;
	while (NULL != results) {
		printf("turn:%d\tY:%d\tX:%d\tmsg:%s\n", ++i, results->y, results->x, get_turn_name(results->turn_type));
		results = results->next;
	}

	return 0;
}

static char* get_turn_name(t_turns_types type) {
	switch (type)
	{
		case turns_type_up:
			return "up";
		case turns_type_left:
			return "left";
		case turns_type_down:
			return "down";
		case turns_type_right:
			return "right";
		case turns_type_vertical_up_left:
			return "vertical up left";
		case turns_type_vertical_up_right:
			return "vertical up right";
		case turns_type_vertical_down_left:
			return "vertical down left";
		case turns_type_vertical_down_right:
			return "vertical down right";
		case turns_type_horizontal_up_left:
			return "horizontal up left";
		case turns_type_horizontal_up_right:
			return "horizontal up right";
		case turns_type_horizontal_down_left:
			return "horizontal down left";
		case turns_type_horizontal_down_right:
			return "horizontal down right";
		case turns_type_none:
			return "none. what?";
		default:
			return "getting incorrect value, something wrong";
	}
}
