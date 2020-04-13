//
// Created by Almog on 13/04/2020.
//

#pragma once
#include <iostream>

class node {
    std::string name;
    char gender;
    node* child;
    node* left;
    node* right;
    int level;

public:
    std::string getName()
    {
        return this->name;
    }
    char getGender()
    {
        return this->gender;
    }
    void setChild(node* n)
    {
        this->child = n;
    }
    node* getChild()
    {
        return this->child;
    }
    node* getLeft()
    {
        return this->left;
    }
    node* getRight()
    {
        return this->right;
    }
    int getLevel()
    {
        return this->level;
    }

    void setLevel( int l)
    {
        this->level = l;
    }
    void setLeft(node* n)
    {
        this->left = n;
    }
    void setRight(node* n)
    {
        this->right = n;
    }
    void setGender(char g)
    {
        this->gender = g;
    }
    node(std::string name, int l = 0)
    {
        this->name = name;
        this->level = l;
        this->left = this->right = this->child = nullptr;
    }
};