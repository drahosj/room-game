/*
 * FileNode.cpp
 *
 *  Created on: Jan 15, 2013
 *      Author: jake
 */

#include "FileNode.h"

FileNode::FileNode(std::string name, unsigned long int offset, unsigned long int length) {
	this->name = name;
	this->length = length;
	this->offset = offset;
}

FileNode::~FileNode() {
	// TODO Auto-generated destructor stub
}

