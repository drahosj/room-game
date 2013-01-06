/*
 * Room.h
 *
 *  Created on: Jan 3, 2013
 *      Author: jake
 *
 *  Copyright (C) 2013  Jake Drahos
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef ROOM_H_
#define ROOM_H_


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Room {
public:
	Room();
	~Room();

	static const int WIDTH = 352;
	static const int HEIGHT = 256;
	static const int DOOR_WIDTH = 16;
	static const int DOOR_HEIGHT = 16;
	static const unsigned char DOOR_NORTH = 	0b00001000;
	static const unsigned char DOOR_EAST = 		0b00000100;
	static const unsigned char DOOR_SOUTH = 	0b00000010;
	static const unsigned char DOOR_WEST = 		0b00000001;

	void generate_door_mask();
	void generate_surface();

	unsigned char door_mask;
	SDL_Surface* room_surface;
};

#endif /* ROOM_H_ */
