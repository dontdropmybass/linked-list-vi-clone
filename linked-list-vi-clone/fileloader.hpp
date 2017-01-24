//
//  fileloader.hpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef fileloader_hpp
#define fileloader_hpp

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>

#include "linkedlist.hpp"

class fileloader {
public:
    static void loadFileToLinkedList(std::string filename, linkedlist* ll);
    static void saveLinkedListToFile(linkedlist* ll, std::string filename);
};

#endif /* fileloader_hpp */
