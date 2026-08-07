#include <bits/stdc++.h>
using namespace std;

class Talkable
{
public:
    virtual string talk(string robo_name) = 0;
};

class NormalTalk : public Talkable
{
public:
    string robo_name;

public:
    NormalTalk(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string talk(string robo_name) override
    {
        return (robo_name + " can talk");
    }
};

class NoTalk : public Talkable
{
public:
    string robo_name;

public:
    NoTalk(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string talk(string robo_name) override
    {
        return (robo_name + " can not talk");
    }
};

class Walkable
{
public:
    virtual string walk(string robo_name) = 0;
};

class NormalWalk : public Walkable
{
public:
    string robo_name;

public:
    NormalWalk(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string walk(string robo_name) override
    {
        return (robo_name + " can walk");
    }
};

class NoWalk : public Walkable
{
public:
    string robo_name;

public:
    NoWalk(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string walk(string robo_name) override
    {
        return (robo_name + " can not walk");
    }
};

class Flyable
{
public:
    virtual string fly(string robo_name) = 0;
};

class NormalFly : public Flyable
{
public:
    string robo_name;

public:
    NormalFly(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string fly(string robo_name) override
    {
        return (robo_name + " can fly");
    }
};

class NoFly : public Flyable
{
public:
    string robo_name;

public:
    NoFly(string robo_name)
    {
        this->robo_name = robo_name;
    }

    string fly(string robo_name) override
    {
        return (robo_name + " can not fly");
    }
};

class Projectable
{
public:
    virtual string projection(string robo_name) = 0;
};

class Robot
{
public:
    Talkable *talk;
    Walkable *walk;
    Flyable *fly;
    Projectable *project;

public:
    Robot(Talkable *talk, Walkable *walk, Flyable *fly, Projectable *project)
    {
        this->talk = talk;
        this->walk = walk;
        this->fly = fly;
        this->project = project;
    }

    string talk(string robo_name)
    {
        return talk->talk(robo_name);
    }

    string walk(string robo_name)
    {
        return walk->walk(robo_name);
    }

    string fly(string robo_name)
    {
        return fly->fly(robo_name);
    }

    string projection(string robo_name)
    {
        return project->projection(robo_name);
    }
};

int main()
{
}