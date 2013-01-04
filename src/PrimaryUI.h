/*
 * PrimaryUI.h
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

#ifndef PRIMARYUI_H_
#define PRIMARYUI_H_
#include "Room.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class PrimaryUI {
public:
	PrimaryUI(void);
	~PrimaryUI(void);

	static const int WIDTH = 640;
	static const int HEIGHT = 480;

	void spawn_ui(void);
	void render_ui(void);

	SDL_Surface* screen;
	Room* current_room;
	SDL_Rect room_rect;
};
#endif /* PRIMARYUI_H_ */
