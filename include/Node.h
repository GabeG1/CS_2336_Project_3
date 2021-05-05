//Gabriel Goldstein
//gjg180000
#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
public:
    Node();
    Node(std::string, int, int, Node*, Node*);
    Node(std::string, int, int);
    Node(std::string);
    bool operator==(const Node&) const;
    bool operator!=(const Node&) const;
    bool operator>(const Node&) const;
    bool operator<(const Node&) const;
    std::string getTitle() const
    {
        return title;
    }
    void setTitle(std::string t)
    {
        title = t;
    }
    int getAvailable() const
    {

        return available;
    }
    void setAvailable(int a)
    {

        available = a;
    }
    int getRented() const
    {

        return rented;
    }
    void setRented(int r)
    {
        rented = r;
    }
    Node* getRight() const
    {
        return right;
    }
    void setRight(Node* r)
    {
        right = r;
    }
    Node* getLeft() const
    {
        return left;
    }
    void setLeft(Node* l)
    {
        left = l;
    }

    virtual ~Node();
    Node(Node & otherNode);
    Node* operator=(const Node &otherNode);

protected:
private:
    std::string title;
    int available;
    int rented;
    Node * left;
    Node * right;

};

#endif // NODE_H
