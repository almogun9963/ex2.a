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
        int level = print_level(relation);
        int isMother = 0;
        int len = relation.length();
        if(relation.find("mother") < len || relation.find("Mother") < len)
            isMother = 1;
        Node* n = (Node*)(this->search_by_level(level, isMother));
        return n->getName();
    }

    void Tree::display()
    {
        std::cout << r->getName() << std::endl;
        printsmalltree(r, "");
        std::cout << std::endl;
    }

    void Tree::remove(std::string name)
    {
        if(name == this->root->getName())
            throw std::runtime_error("Can not remove the root!");

        Node* n = (Node*)(this->search_by_name(name));
        Node* n_child = n->getChild();

        if(n_child->getLeft() != nullptr && n_child->getLeft()->getName() == name)
            n_child->setLeft(nullptr);
        else
            n_child->setRight(nullptr);

        n = this->destroy_family(n);
    }
}