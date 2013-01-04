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
	this->screen = NULL;
	this->current_room = NULL;

	this->room_rect.h = Room::HEIGHT;
	this->room_rect.w = Room::WIDTH;
	this->room_rect.x = (PrimaryUI::WIDTH - Room::WIDTH) / 2;
	this->room_rect.y = (PrimaryUI::HEIGHT - Room::HEIGHT) / 2;

	SDL_Init(SDL_INIT_EVERYTHING);

	this->current_room = new Room;
}

PrimaryUI::~PrimaryUI() {
	delete this->current_room;
	SDL_FreeSurface(this->screen);
	SDL_Quit();
}

void PrimaryUI::spawn_ui() {
	this->screen = SDL_SetVideoMode(PrimaryUI::WIDTH, PrimaryUI::HEIGHT, 32, SDL_SWSURFACE);
	this->render_ui();
}

void PrimaryUI::render_ui() {
	SDL_BlitSurface(this->current_room->room_surface, NULL, this->screen, &this->room_rect);
	SDL_Flip(this->screen);
}
