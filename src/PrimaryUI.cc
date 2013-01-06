/*
 * PrimaryUI.cpp
 *
 *  Created on: Jan 3, 2013
 *      Author: jake*
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

#include "PrimaryUI.h"
#include "Room.h"
#include <iostream>

PrimaryUI::PrimaryUI() {
	screen = NULL;
	current_room = NULL;

	room_rect.h = Room::HEIGHT;
	room_rect.w = Room::WIDTH;
	room_rect.x = (PrimaryUI::WIDTH - Room::WIDTH) / 2;
	room_rect.y = (PrimaryUI::HEIGHT - Room::HEIGHT) / 2;

	SDL_Init(SDL_INIT_EVERYTHING);

	current_room = new Room;
}

PrimaryUI::~PrimaryUI() {
	delete current_room;
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void PrimaryUI::spawn_ui() {
	screen = SDL_SetVideoMode(PrimaryUI::WIDTH, PrimaryUI::HEIGHT, 32, SDL_SWSURFACE);
	render_ui();
}

void PrimaryUI::render_ui() {
	SDL_BlitSurface(current_room->room_surface, NULL, screen, &room_rect);
	SDL_Flip(screen);
}
