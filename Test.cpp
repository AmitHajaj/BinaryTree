//
// Created by amit on 25/05/2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/BinaryTree.hpp"
#include "doctest.h"
using namespace ariel;

TEST_CASE("build tree and check not throw"){
    BinaryTree<int> tree_of_int;
    CHECK_NOTHROW(tree_of_int.add_root(0));
    for(int i=0; i<20; i++){
        CHECK_NOTHROW(tree_of_int.add_left(i, i+1));
        CHECK_NOTHROW(tree_of_int.add_left(i, i+2));
    }

    for(int i=0; i<20; i++){
        CHECK_THROWS(tree_of_int.add_left(i, i));
                CHECK_THROWS(tree_of_int.add_left(i, i+1));

    }

    BinaryTree<string> tree_of_strings;
            CHECK_NOTHROW(tree_of_strings.add_root("0"));
    for(int i=0; i<20; i++){
                CHECK_NOTHROW(tree_of_strings.add_left("i", "i+1"));
                CHECK_NOTHROW(tree_of_strings.add_left("i", "i+2"));
    }

    for(int i=0; i<20; i++){
                CHECK_THROWS(tree_of_strings.add_left("i", "i"));
                CHECK_THROWS(tree_of_strings.add_left("i", "i+1"));
    }

}

