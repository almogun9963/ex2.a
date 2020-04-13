#include "FamilyTree.hpp"


namespace family {

    Tree& Tree::addFather(std::string name, std::string father) {
        node* n = (node*)(this->findp(name));
        if(n->getRight() == nullptr){
            n->setRight(new node(father, n->getLevel() + 1));
            n->getRight()->setChild(n);
            n->getRight()->setGender('m');
        }
        else
            throw std::runtime_error("Father is already in the tree");
        return *this;
    }

    Tree& Tree::addMother(std::string name, std::string mother)
    {
        node* n = (node*)(this->findp(name));
        if(n->getLeft() == nullptr)
        {
            n->setLeft(new node(mother, n->getLevel() + 1));
            n->getLeft()->setChild(n);
            n->getLeft()->setGender('f');
        }
        else
            throw std::runtime_error("Mother is already in the tree");
        return *this;
    }
    std::string Tree::relation(std::string name) {
        node* n = nullptr;
        try{
            n = (node*)(this->findp(name));
        } catch(const std::exception& ex){
            return "unrelated";
        }
        int levelDiffer = n->getLevel() - this->r->getLevel();
        if(levelDiffer == 0){
            return "me";
        }
        else if(n->getGender() == 'f')
        {
            return this->print_relation(levelDiffer, "Mother");
        }
        else{
            return this->print_relation(levelDiffer, "Father");
        }
    }

    std::string Tree::find(std::string relation)
    {
        return "";
    }

    void Tree::display()
    {
        std::cout << r->getName() << std::endl;
        printsmalltree(r, "");
        std::cout << std::endl;
    }

    void Tree::remove(std::string name)
    {

        if(name == this->r->getName()){
            throw std::runtime_error("can't remove you");
        }
        node* n = (node*)(this->findp(name));
        node* n_child = n->getChild();

        if( n_child->getLeft()->getName() == name && n_child->getLeft() != nullptr )
        {
            n_child->setLeft(nullptr);
        }
        else
            {
            n_child->setRight(nullptr);
            }
        n = this->destroy(n);
    }
}