/*
 * ResourceFile.h
 *
 *  Created on: Jan 15, 2013
 *      Author: jake
 */

#ifndef RESOURCEFILE_H_
#define RESOURCEFILE_H_

#include <string>
#include <list>
#include "FileNode.h"

class ResourceFile {
private:
	char *buffer;
public:
	ResourceFile(std::string name);
	~ResourceFile();

	std::string resource_name;

	std::list<FileNode> index;

	unsigned long int get_file_length(std::string);
	unsigned long int get_file_offset(std::string);
};

#endif /* RESOURCEFILE_H_ */
