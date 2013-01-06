/*
 * Room.cpp
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

#include "Room.h"

Room::Room() {
	generate_door_mask();
	generate_surface();
}

Room::~Room() {
	SDL_FreeSurface(room_surface);
}

void Room::generate_door_mask() {
	door_mask = rand() % 16;
}

void Room::generate_surface() {
	room_surface = IMG_Load("assets/test_room.png");

	SDL_Surface *door_surface = IMG_Load("assets/test_door.png");

	SDL_Rect dstrect;
	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = DOOR_WIDTH;
	dstrect.h = DOOR_HEIGHT;

	if (door_mask & DOOR_NORTH) {
		dstrect.x = (WIDTH / 2) - (DOOR_WIDTH / 2);
		dstrect.y = 0;
		SDL_BlitSurface(door_surface, NULL, room_surface, &dstrect);
	}
	if (door_mask & DOOR_EAST) {
		dstrect.x = WIDTH - DOOR_WIDTH;
		dstrect.y = (HEIGHT / 2) - (DOOR_HEIGHT / 2);
		SDL_BlitSurface(door_surface, NULL, room_surface, &dstrect);
	}
	if (door_mask & DOOR_SOUTH) {
		dstrect.x = (WIDTH / 2) - (DOOR_WIDTH / 2);
		dstrect.y = HEIGHT - DOOR_HEIGHT;
		SDL_BlitSurface(door_surface, NULL, room_surface, &dstrect);
	}
	if (door_mask & DOOR_WEST) {
		dstrect.x = 0;
		dstrect.y = (HEIGHT / 2) - (DOOR_HEIGHT / 2);
		SDL_BlitSurface(door_surface, NULL, room_surface, &dstrect);
	}
	SDL_FreeSurface(door_surface);
}
