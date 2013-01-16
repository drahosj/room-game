/*
 * ResourceFile.cpp
 *
 *  Created on: Jan 15, 2013
 *      Author: jake
 */

#include "ResourceFile.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

ResourceFile::ResourceFile(std::string name) {
	FILE *file;
	unsigned long int length;

	//load buffer
	file = fopen("assets/data.dat", "r");

	//get length
	fseek(file, 0l, 2/*SEEK_END*/);	//This will get me in trouble, but Eclipse is
	length = ftell(file); 			//convinced that the constants don't exist.
	fseek(file, 0l, 0/*SEEK_SET*/);	//They do.

	buffer = (char *)malloc(length * sizeof(char));

	fread(buffer, sizeof(char), length, file);

	fclose(file); //end load buffer

	//Populate index
	file = fopen("assets/data.index", "r");

	char *name_buffer;
	name_buffer = (char *)malloc(32*sizeof(char));
	unsigned long int length_buffer;
	unsigned long int offset_buffer;

	fscanf(file, "%s %li %li", name_buffer, &offset_buffer, &length_buffer);

	std::string name_string = name_buffer;

	free(name_buffer);

	FileNode * temp_node = (new FileNode(name_string, offset_buffer, length_buffer));

	index.push_back(*temp_node);
}

ResourceFile::~ResourceFile() {
	free(buffer);
}

unsigned long int ResourceFile::get_file_offset(std::string name) {
	std::list<FileNode>::iterator iterator = index.begin();

	return iterator->offset;
}

unsigned long int ResourceFile::get_file_length(std::string name) {
	std::list<FileNode>::iterator iterator = index.begin();

	return iterator->length;
}

