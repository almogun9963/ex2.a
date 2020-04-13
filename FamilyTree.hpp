#pragma once

#include <bits/stdc++.h>
#include "node.hpp"
#include <string>

//used codes from: https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
// and https://www.geeksforgeeks.org/level-order-tree-traversal/


namespace family {

    class Tree {
        node* r = nullptr;

    public:
        Tree& addMother(std::string name, std::string mother);
        void display();
        std::string relation(std::string name);
        std::string find(std::string relation);
        void remove(std::string name);
        Tree& addFather(std::string name, std::string father);

        Tree(std::string name) {
            this->r = new node(name);
        }

        ~Tree() {
            this->r = destroy(this->r);
        }

    private:
        node* destroy(node* n){
            if(n == nullptr)
            {
                return nullptr;
            }
            destroy(n->getLeft());
            destroy(n->getRight());
            delete n;
            return nullptr;
        }
        void printsmalltree(node* r, const std::string& prefix) {
            if(r == nullptr)
                return;
            if(r->getLeft() == nullptr && r->getRight() == nullptr)
                return;
            bool hasLeft = (r->getLeft() != nullptr);
            bool hasRight = (r->getRight() != nullptr);
            std::cout << prefix;
            std::cout << ((hasLeft && hasRight) ? "─ " : "");
            std::cout << ((!hasLeft && hasRight) ? "─ " : "");
            if (hasRight) {
                bool printStrand;
                printStrand = ((r->getRight()->getRight() != nullptr || r->getRight()->getLeft() != nullptr) && hasRight && hasLeft);

                std::string newPrefix = prefix + (printStrand ? "│ " : "  ");
                std::cout << r->getRight()->getName() << std::endl;
                printsmalltree(r->getRight(), newPrefix);
            }
            if (hasLeft) {
                std::cout << (hasRight ? prefix : "") << "─ " << r->getLeft()->getName() << std::endl;
                printsmalltree(r->getLeft(), prefix + "  ");
            }
        }

        node* findp(std::string toFind){
            if (this->r->getName() == toFind)
            {
                return this->r;
            }
            std::queue<node *> q;
            q.push(this->r);
            while(!q.empty()) {
                node *n = q.front();
                if(n->getName() == toFind)
                {
                    return n;
                }
                q.pop();
                if (n->getLeft() != nullptr)
                {
                    q.push(n->getLeft());
                }
                if (n->getRight() != nullptr)
                {
                    q.push(n->getRight());
                }
            }
            throw std::runtime_error("error 404, not found");
        }

        std::string print_relation( int level, std::string relation)
        {
            if(level == 1)
            {
                return relation;
            }

            else if(level == 2)
            {
                return "grand " + relation;
            }

            else{
                std::string ans = "grand " + relation;
                for(int i = 0; i < level-2; i++)
                {
                    ans = "great-" + ans;
                }
                return ans;
            }
        }
    };
}