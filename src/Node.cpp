//Gabriel Goldstein
//gjg180000
#include "Node.h"
#include <string>
#include <cctype>

Node::Node()
{
    title = "";
    available = 0;
    rented = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(std::string t, int a, int r, Node* le, Node* ri)
{
    title = t;
    available = a;
    rented = r;
    left = le;
    right = ri;
}
Node::Node(std::string t, int a, int r)
{
    title = t;
    available = a;
    rented = r;
    right = nullptr;
    left = nullptr;
}
Node::~Node()
{

}
Node::Node(std::string t)
{
    title = t;
    available = 0;
    rented = 0;
    right = nullptr;
    left = nullptr;
}

Node::Node(Node &otherNode)
{
    title = otherNode.title;
    available = otherNode.available;
    rented = otherNode.rented;
    right = otherNode.right;
    left = otherNode.left;

}

//Give the values (title, available and rented) to another node
Node* Node::operator=(const Node &otherNode)
{
    title = otherNode.title;
    available = otherNode.available;
    rented = otherNode.rented;

    return this;
}

//Check if two titles equal each other
bool Node::operator==(const Node& otherNode) const
{
    return title == otherNode.title;

}


//Check if two titles do not equal each other
bool Node::operator!=(const Node& otherNode) const
{
    return title != otherNode.title;

}

bool Node::operator>(const Node& otherNode) const
{
    std::string tempTitle;
    std::string otherTitle;

    //convert each character of the two titles to uppercase to compare them
    for(char c : title)
    {
        tempTitle+=char(toupper(c));

    }
    for(char c : otherNode.title)
    {
        otherTitle+=char(toupper(c));

    }
    return tempTitle > otherTitle;
}
bool Node::operator<(const Node& otherNode) const
{
    std::string tempTitle;
    std::string otherTitle;

    //convert each character of the two titles to uppercase to compare them
    for(char c : title)
    {
        tempTitle+=char(toupper(c));

    }
    for(char c : otherNode.title)
    {
        otherTitle+=char(toupper(c));

    }
    return tempTitle < otherTitle;
}


