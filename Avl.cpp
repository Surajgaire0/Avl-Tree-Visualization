
#include <iostream>
#include "Avl.hpp"
using namespace std;


Avl::Avl()
{
    root=NULL;
}

Avl::~Avl()
{

}

int Avl::NodeHeight(Node *q)
{
    if (q==NULL)
        return 0;
    int Hlchild=q&&q->lchild?q->lchild->height:0;
    int Hrchild=q&&q->rchild?q->rchild->height:0;
    return (Hrchild>Hlchild?Hrchild+1:Hlchild+1);
}

int Avl::BalanceFactor(Node *q)
{
    if (q==NULL)
        return 0;
    int Hlchild=q&&q->lchild?q->lchild->height:0;
    int Hrchild=q&&q->rchild?q->rchild->height:0;
    return (Hlchild-Hrchild);
}

Node * Avl::Insert(Node *q,int key)
{
    Node *t=NULL;
    if (q==NULL)
    {
        t=new Node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if (q->data<key)
    {
        q->rchild=Avl::Insert(q->rchild,key);
    }
    else if (q->data>key)
    {
        q->lchild=Avl::Insert(q->lchild,key);
    }
    q->height=Avl::NodeHeight(q);
    if (BalanceFactor(q)==2 && BalanceFactor(q->lchild)==1)
        return LLRotation(q);
    if (BalanceFactor(q)==2 && BalanceFactor(q->lchild)==-1)
        return LRRotation(q);
    if (BalanceFactor(q)==-2 && BalanceFactor(q->rchild)==-1)
        return RRRotation(q);
    if (BalanceFactor(q)==-2 && BalanceFactor(q->rchild)==1)
        return RLRotation(q);
    return q;
}

Node * Avl::Delete (int key, Node *p)
{
    Node *q;
    if (p==NULL)
        return NULL;
    if (!p->lchild &&!p->rchild && p->data==key)
    {
        if (p==root)
            root=NULL;
        delete p;
        return NULL;
    }
    if (key<p->data)
        p->lchild=Delete(key, p->lchild);
    else if (key>p->data)
        p->rchild=Delete(key, p->rchild);
    else 
    {
        if (NodeHeight(p->lchild)> NodeHeight(p->rchild))
        {
            q=pre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(q->data,p->lchild);
        }

        else
        {
            q=succ(p->rchild);
            p->data=q->data;
            p->rchild=Delete(q->data,p->rchild);
        }
    
    }
    if (!p)
        return p;
    p->height=NodeHeight(p);
    if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
        return LLRotation(p);
    if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
        return RRRotation(p);
    return p;
}

Node * Avl::LLRotation(Node *q)
{
    Node *ql=q->lchild;
    Node *qlr=ql->rchild;
    q->lchild=qlr;
    ql->rchild=q;
    q->height=NodeHeight(q);
    ql->height=NodeHeight(ql);
    if (q==root)
        root=ql;
    return ql;
}

Node * Avl::LRRotation(Node *q)
{
    Node *ql=q->lchild;
    Node *qlr=ql->rchild;
    ql->rchild=qlr->lchild;
    q->lchild=qlr->rchild;
    qlr->lchild=ql;
    qlr->rchild=q;
    q->height=NodeHeight(q);
    ql->height=NodeHeight(ql);
    qlr->height=NodeHeight(qlr);
    if (q==root)
        root=qlr;
    return qlr;
}

Node * Avl::RLRotation(Node *q)
{
    Node *qr=q->rchild;
    Node *qrl=qr->lchild;
    qr->lchild=qrl->rchild;
    q->rchild=qrl->lchild;
    qrl->rchild=qr;
    qrl->lchild=q;
    q->height=NodeHeight(q);
    qr->height=NodeHeight(qr);
    qrl->height=NodeHeight(qrl);
    if (q==root)
        root=qrl;
    return qrl;
}

Node * Avl::RRRotation(Node *q)
{
    Node *qr=q->rchild;
    Node *qrl=qr->lchild;
    q->rchild=qrl;
    qr->lchild=q;
    q->height=NodeHeight(q);
    qr->height=NodeHeight(qr);
    if (q==root)
        root=qr;
    return qr;
}

Node * Avl::getroot()
{
    return root;
}

void Avl::setroot(Node *q)
{
    root=q;
}
//inorder predecessor
Node * Avl::pre(Node *p)
{
    //p=p->lchild;
    while(p && p->rchild)
        p=p->rchild;
    return p;
}
//inorder successor
Node * Avl::succ(Node *p)
{
    //p=p->rchild;
    while(p && p->lchild)
        p=p->lchild;
    return p;
}

void Avl::draw(Node *q,sf::RenderWindow &window)
{
    if (q)
    {
        window.draw(q->linestrip);
        window.draw(q->circle);
        window.draw(q->text);

        draw(q->lchild,window);

        draw(q->rchild,window);

    }
}

void Avl::setCordinate(Node *q,int dist)
{
    if (q)
    {
        if (q==root)
        {
            q->circle.setPosition(400,140);
            q->text.setPosition(400+18,140+20);
            q->text.setString(to_string(q->data));
        }

        for (int j=0;j<3;j++)
        {
            q->linestrip[j].position=(sf::Vector2f(q->circle.getPosition().x+q->circle.getRadius(),q->circle.getPosition().y+q->circle.getRadius()));
            q->linestrip[j].color=sf::Color::Black; 
        }

        if (q->lchild)
        {
            (q->lchild)->circle.setPosition(sf::Vector2f(q->circle.getPosition().x-dist,q->circle.getPosition().y+100));
            (q->lchild)->text.setPosition(sf::Vector2f(q->circle.getPosition().x-dist+18,q->circle.getPosition().y+100+20));
            q->lchild->text.setString(to_string(q->lchild->data));

           q->linestrip[0].position=(sf::Vector2f(q->lchild->circle.getPosition().x+q->lchild->circle.getRadius(),q->lchild->circle.getPosition().y+q->lchild->circle.getRadius()));
           q->linestrip[0].color=sf::Color::Black; 
           setCordinate(q->lchild,dist/2);  
        }
        
        
        if (q->rchild)
        {
            (q->rchild)->circle.setPosition(sf::Vector2f(q->circle.getPosition().x+dist,q->circle.getPosition().y+100));
            (q->rchild)->text.setPosition(sf::Vector2f(q->circle.getPosition().x+dist+18,q->circle.getPosition().y+100+20));
            q->rchild->text.setString(to_string(q->rchild->data));

            q->linestrip[2].position=(sf::Vector2f(q->rchild->circle.getPosition().x+q->rchild->circle.getRadius(),q->rchild->circle.getPosition().y+q->rchild->circle.getRadius()));
            q->linestrip[2].color=sf::Color::Black; 
            setCordinate(q->rchild,dist/2);
        }
    }
}
Node * Avl::Search(int key,Node *q)
{
    if (q==NULL)
        return q;
    else if (q->data==key)
        return q;
    else if (key<q->data)
        return Search(key,q->lchild);
    else if (key>q->data)
        return Search(key,q->rchild);
    return NULL;
}
void Avl::setspcolor(Node *t,bool &value, sf::Clock &clock)
{
    if (t && value==false)
    {
        t->circle.setFillColor(sf::Color::Yellow);
        value=true;
        clock.restart();
    }
}

void Avl::setbackcolor(Node *t,bool &value)
{
    t->circle.setFillColor(sf::Color::Green);
    value=false;
}