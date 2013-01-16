/*
 * FileNode.h
 *
 *  Created on: Jan 15, 2013
 *      Author: jake
 */

#ifndef FILENODE_H_
#define FILENODE_H_
#include <string>

class FileNode {
public:
	FileNode(std::string, unsigned long int, unsigned long int);
	~FileNode();

	std::string name;
	unsigned int length;
	unsigned int offset;

};

#endif /* FILENODE_H_ */
