//
// Created by dwdraugr on 19.12.2021.
//

#include <stdlib.h>
#include <stdio.h>

#include "match_3_turn_searcher.h"

static t_match_3_result* add_element(t_match_3_result* results, t_match_3_result* element);
static t_match_3_result* make_result(int x, int y, t_turns_types type);

t_match_3_result *search_turn(t_match_3_data *data)
{
	unsigned char current_char;
	t_match_3_result* results = NULL;

	for (int y = 0; y < data->height; y++) {
		for (int x = 0; x < data->width; ++x) {
			current_char = data->map[y][x];
			if (current_char == 0 || current_char == '0') {
				continue;
			}

			/** vertical */
			// vertical up
			if (y - 3 >= 0 && current_char == data->map[y - 2][x] && current_char == data->map[y - 3][x]) {
				results = add_element(results, make_result(x, y, turns_type_up));
			}
			// vertical down
			if (y + 3 < data->height && current_char == data->map[y + 2][x] && current_char == data->map[y + 3][x]) {
				results = add_element(results, make_result(x, y, turns_type_down));
			}

			/** horizontal */
			// horizontal left
			if (x - 3 >= 0 && current_char == data->map[y][x - 2] && current_char == data->map[y][x - 3]) {
				results = add_element(results, make_result(x, y, turns_type_left));
			}
			// horizontal right
			if (x + 3 < data->width && current_char == data->map[y][x + 2] && current_char == data->map[y][x + 3]) {
				results = add_element(results, make_result(x, y, turns_type_right));
			}

			/** horizontal X */
			// up left
			if (y - 1 >= 0 && x - 2 >= 0 && current_char == data->map[y - 1][x - 1] && current_char == data->map[y - 1][x - 2]) {
				results = add_element(results, make_result(x, y, turns_type_horizontal_up_left));
			}
			// up right
			if (y - 1 >= 0 && x + 2 < data->width && current_char == data->map[y - 1][x + 1] && current_char == data->map[y - 1][x + 2]) {
				results = add_element(results, make_result(x, y, turns_type_horizontal_up_right));
			}
			// down right
			if (y + 1 < data->height && x + 2 < data->width && current_char == data->map[y + 1][x + 1] && current_char == data->map[y + 1][x + 2]) {
				results = add_element(results, make_result(x, y, turns_type_horizontal_down_right));
			}
			// down left
			if (y + 1 < data->height && x - 2 >= 0 && current_char == data->map[y + 1][x - 1] && current_char == data->map[y + 1][x - 2]) {
				results = add_element(results, make_result(x, y, turns_type_horizontal_down_left));
			}

			/** vertical X */
			// up left
			if (y - 2 >= 0 && x - 1 >= 0 && current_char == data->map[y - 1][x - 1] && current_char == data->map[y - 2][x - 1]) {
				results = add_element(results, make_result(x, y, turns_type_vertical_up_left));
			}
			// up right
			if (y - 2 >= 0 && x + 1 < data->width && current_char == data->map[y - 1][x + 1] && current_char == data->map[y - 2][x + 1]) {
				results = add_element(results, make_result(x, y, turns_type_vertical_up_right));
			}
			// down right
			if (y + 2 < data->height && x + 1 < data->width && current_char == data->map[y + 1][x + 1] && current_char == data->map[y + 2][x + 1]) {
				results = add_element(results, make_result(x, y, turns_type_vertical_down_right));
			}
			// down left
			if (y + 2 < data->height && x - 1 >= 0 && current_char == data->map[y + 1][x - 1] && current_char == data->map[y + 2][x - 1]) {
				results = add_element(results, make_result(x, y, turns_type_vertical_down_left));
			}
		}
	}

	return results;
}


static t_match_3_result *make_result(int x, int y, t_turns_types type) {
	t_match_3_result* new_result = malloc(sizeof(t_match_3_result));
	new_result->x = x;
	new_result->y = y;
	new_result->turn_type = type;
	new_result->next = NULL;

	return new_result;
}

static t_match_3_result* add_element(t_match_3_result* results, t_match_3_result* element) {
	t_match_3_result* current_node = NULL;

	if (results == NULL) {
		return element;
	}
	current_node = results;

	while (current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = element;

	return results;
}
