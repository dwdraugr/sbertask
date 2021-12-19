//
// Created by dwdraugr on 19.12.2021.
//

#ifndef MATCH_3_MATCH_3_TURN_SEARCHER_H
# define MATCH_3_MATCH_3_TURN_SEARCHER_H

# define MAP_DEFAULT_HEIGHT 6
# define MAP_DEFAULT_WIDTH 6

typedef enum e_turns_types {
	turns_type_none,
	turns_type_up,
	turns_type_left,
	turns_type_down,
	turns_type_right,
	turns_type_vertical_up_left,
	turns_type_vertical_up_right,
	turns_type_vertical_down_left,
	turns_type_vertical_down_right,
	turns_type_horizontal_up_left,
	turns_type_horizontal_up_right,
	turns_type_horizontal_down_left,
	turns_type_horizontal_down_right
} t_turns_types;

typedef struct s_match_3_data {
	unsigned short y;
	unsigned short x;
	unsigned short height;
	unsigned short width;
	unsigned char **map;
} t_match_3_data;

typedef struct s_match_3_result {
	unsigned short y;
	unsigned short x;
	t_turns_types turn_type;
	struct s_match_3_result* next;
} t_match_3_result;

t_match_3_result* search_turn(t_match_3_data* data);

#endif //MATCH_3_MATCH_3_TURN_SEARCHER_H
